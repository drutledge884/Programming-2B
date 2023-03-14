//===================================
// Daniel Rutledge
// Program 3
// Merge Sorter
//===================================
#include <iostream>
using namespace std;

void initialize(int arr[], int size);
void display(int arr[], int size);
void mergesort(int arr[], int lowBound, int upperBound, int size);
void merge(int arr[], int lowBound, int upperBound, int mid, int size);

int main()
{
	/*int size, *arr;
	cout << "How many values are to be sorted?\n";
	cin >> size;
	arr = new int[size];*/
	//initialize(arr, size);
	//mergesort(arr, 0, (size - 1), size);
	//display(arr, size);

	cout << "do the thing.\n";
	int ducktape;
	cin >> ducktape;
	cout << "hi\n";
	//return 0;
}

void initialize(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 9005 - 5 * (i + 1);
	}
}

void display(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void mergesort(int arr[], int lowBound, int upperBound, int size)
{
	int mid;

	if (lowBound < upperBound)
	{
		mid = (lowBound + upperBound) / 2;
		mergesort(arr, lowBound, mid);
		mergesort(arr, (mid + 1), upperBound);
		merge(arr, lowBound, upperBound, mid, size);
	}
}

void merge(int arr[], int lowBound, int upperBound, int mid, int size)
{
	int p1 = lowBound, p2 = mid + 1, p3 = 0, *temp = nullptr;
	temp = new int[size];
	while ((p1 <= mid) && (p2 <= size))
	{
		if (arr[p1] < arr[p2])
		{
			temp[p3] = arr[p2];
			p2++;
		}
		p3++;
	}
	delete temp;
}