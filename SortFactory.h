#include <iostream>

using namespace std;

class Sort {

public:
	virtual void SortImp(int ar[],int length) {
		cout << "No Search Type Implemented.";
	};
	 void PrintArray(int ar[],int length) {
		cout << "Sorted Array: ";
		for (int i = 0; i < length;i++) {
			cout << ar[i];
			if (i != length - 1)
				cout << ", ";
			else
				cout << "\n";
		};
		cout << "\n";
	 };

	virtual ~Sort() {};
private:
	virtual void PerfromSort() {};
};

class MergeSort : public Sort {

public:
	virtual void SortImp(int ar[],int length) {
		PerformSort(ar,0, length -1);
		PrintArray(ar, length);
	};

	virtual ~MergeSort() {};

private:
	virtual void PerformSort(int ar[],int lowIndex, int highIndex) {
		if (lowIndex < highIndex){
			int midIndex = floor((lowIndex+highIndex)/2);
			PerformSort(ar, lowIndex, midIndex);
			PerformSort(ar, midIndex + 1, highIndex);
			Merge(ar,lowIndex,midIndex,highIndex);
			
		};
	};

	void Merge(int arr[], int lo, int  mi, int hi) {
		int *temp = new int[hi - lo + 1];
		int i = lo, j = mi + 1;
		int k = 0;
		
		while (i <= mi && j <= hi) {
			if (arr[i] <= arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		};

		while (i <= mi)
			temp[k++] = arr[i++];

		while (j <= hi)
			temp[k++] = arr[j++];

		for (k = 0, i = lo; i <= hi; ++i, ++k)
			arr[i] = temp[k];

		delete[]temp;
	};

};

class QuickSort : public Sort {

public:
	virtual void SortImp(int ar[],int length) {
		PerformSort(ar, 0, length-1);
		PrintArray(ar, length);

	};

	virtual ~QuickSort() {};

private:
	virtual void PerformSort(int ar[], int left, int right) {
		if (left < right) {
			int bound = Partition(ar,left,right);
			PerformSort(ar, left, bound - 1);
			PerformSort(ar, bound + 1, right);
		};
	};

	int Partition(int ar[], int left, int right) {
		int pivot = ar[right];
		int temp;
		int i = left;

		for (int j = left;j < right; j++) {
			if (ar[j] <= pivot) {
				temp = ar[j];
				ar[j] = ar[i];
				ar[i] = temp;
				i++;
			};
		};

		ar[right] = ar[i];
		ar[i] = pivot;
		return i;
	};
};

class BubbleSort : public Sort {

public:
	virtual void SortImp(int ar[],int length) {
		PerformSort(ar, length);
	};

	virtual ~BubbleSort() {};

private:
	virtual void PerformSort(int ar[], int length) {
		int i, j, temp;

		for (i = length-1; i >= 0;i--) {
			for (j = 0;j <= i - 1;j++) {
				if( ar[j] > ar[j + 1]){
					temp = ar[j];
					ar[j] = ar[j + 1];
					ar[j+1] = temp;
				};
			};
		};
		PrintArray(ar, length);
	};
};

class SortFactory {
public:
	enum SortType {
	Merge,
	Quick,
	Bubble
	};

	static unique_ptr<Sort> SelectSort(SortType sortType) {
		switch (sortType) {
			case Merge: return make_unique<MergeSort>();
			case Quick : return make_unique<QuickSort>();
			case Bubble: return make_unique<BubbleSort>();
		};
		throw "Invalid Sort.";
	};
};

