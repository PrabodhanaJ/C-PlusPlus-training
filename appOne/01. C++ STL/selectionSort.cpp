
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int arr[] = {2, 4, 3, 1, 7, 5, 6, };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	
	for (int i = 0; i <n -1 ; i++) {
		int smallest = i;
		for(int j =i+1; j< n ; j++)
			if (arr[i] > arr[j]) {
				smallest = j;
			}
		if (smallest != i) {
			swap(&arr[smallest], &arr[i]);
		}
		/*
		int temp = arr[smallest];
		arr[smallest] = arr[i];
		arr[i] = temp;
		*/

	}

	cout << "sortedd array: {";

	for (int i =0 ; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << "}";
	return 0;


}
