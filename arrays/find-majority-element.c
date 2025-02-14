#include <stdio.h>

/* boyer-moore voting algorithm */

int find_most_present_number(int *arr, int size) {
	int candidate = -1;
	int votes = 0;
	for (int i = 0; i < size; i++) {
		if (votes == 0) {
			candidate = arr[i];
			votes = 1;
		} else {
			if (candidate == arr[i])
				votes++;
			else
				votes--;
		}
	}
	int count = 0;
	for (int i = 0; i < size; i++)
		if (candidate == arr[i])
			count++;
	if (count >= size / 2)
		return candidate;
	return -1;
}

int main() {
	int arr[7] = { 3, 3, 4, 2, 3, 3, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("most present element: %d\n", find_most_present_number(arr, size));
	return (0);
}
