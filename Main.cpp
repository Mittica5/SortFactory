#include "pch.h"
#include "SortFactory.h"
#include <iostream>

void SortArray(SortFactory::SortType sortType, int ar[], int length) {
	unique_ptr <Sort> sort = SortFactory::SelectSort(sortType);
	 sort->SortImp(ar,length);
}

void print(int ar[],int length) {
	cout << "Array to be sorted: ";
	for (int i = 0; i < length;i++) {
		cout <<ar[i];
		if (i != length - 1)
			cout << ", ";
		else

			cout << "\n";

	};
	cout << "\n";
};

int main()
{
	int a[] = { 9,3,8,4,6,2,1,7 };
	int lengthA = (sizeof(a) / sizeof(*a));
	print(a, lengthA);
	SortArray(SortFactory::Merge, a, lengthA);

	int b[] = { 9,3,8,4,6,2,1,7 };
	int lengthB = (sizeof(b) / sizeof(*b));
	print(b, lengthB);
	SortArray(SortFactory::Quick, b, lengthB);

	int c[] = { 9,3,8,4,6,2,1,7 };
	int lengthC = (sizeof(c) / sizeof(*c));
	print(c, lengthC);
	SortArray(SortFactory::Bubble, a, lengthC);

}