#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int *arr, int size)
{
	int l = 0;
	int r = size - 1;
	while (l <= r)
		swap(&arr[l++], &arr[r--]);
}

void print_array(int *arr, int size)
{
	int i = 0;
	printf("[ ");
	while (i < size)
		printf("%d, ", arr[i++]);
	printf(" ]\n");
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, size);
	reverse(arr, size);
	print_array(arr, size);
}
