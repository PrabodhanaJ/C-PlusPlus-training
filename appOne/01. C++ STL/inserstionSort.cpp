
#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int arr[] = { 2, 4, 3, 1, 7, 5, 6, };
	int n = sizeof(arr) / sizeof(arr[0]);


	for (int i = 1; i < n - 1; i++) {
		int j = i;
		while (j >= 0 && arr[j - 1] > arr[j]) {
			swap(&arr[j], &arr[j - 1]);
			j = j - 1;
		}

	}

	cout << "inserstion sortedd array: {";

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << "}";
	return 0;


}
