#include <stdio.h>

void rotate(int *arr, int size, int k) {
	int tmp;

	while (k-- > 0) {
		tmp = arr[size - 1];
		for (int i = size - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = tmp;
	}
}

void rotate_recursive(int *arr, int size, int k) {
	int tmp;

	if (k == 0)
		return ;
	tmp = arr[size - 1];
	for (int i = size - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
	rotate_recursive(arr, size, k - 1);
}

void printArray(int *arr, int size) {
	printf("[ ");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf(" ]\n");
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);
	rotate(arr, size, 2);
	printArray(arr, size);
	rotate_recursive(arr, size, 3);
	printArray(arr, size);
	return 0;
}
