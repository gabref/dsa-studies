#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 3
#define K 2
#define MIN_USAGE 4

typedef struct s_array {
	int *data;
	int size;
	int capacity;
} t_array;

t_array *create_array() {
	t_array *new_array = malloc(sizeof(t_array));
	new_array->capacity = DEFAULT_CAPACITY;
	new_array->data = malloc(sizeof(int) * new_array->capacity);
	new_array->size = 0;
	return new_array;
}

void resize(t_array *arr) {
	if (arr->size > arr->capacity) {
		arr->capacity *= K;
		int *tmp = malloc(sizeof(int) * arr->capacity);
		for (int i = 0; i < arr->size - 1; i++)
			tmp[i] = arr->data[i];
		free(arr->data);
		arr->data = tmp;
	} else if (arr->capacity / MIN_USAGE > arr->size) {
		arr->capacity /= K;
		int *tmp = malloc(sizeof(int) * arr->capacity);
		for (int i = 0; i < arr->size; i++)
			tmp[i] = arr->data[i];
		free(arr->data);
		arr->data = tmp;
	}
}

void append_end(t_array *arr, int data) {
	arr->size++;
	resize(arr);
	arr->data[arr->size - 1] = data;
}

void append_start(t_array *arr, int data) {
	arr->size++;
	resize(arr);
	int i = arr->size - 1;
	while (i > 0) {
		arr->data[i] = arr->data[i - 1];
		i--;
	}
	arr->data[0] = data;
}

void pop(t_array *arr) {
	arr->size--;
	resize(arr);
}

void print_array(t_array *arr) {
	printf("{\n");
	printf("\t[ ");
	for (int i = 0; i < arr->size - 1; i++)
		printf("%d, ", arr->data[i]);
	if (arr->size > 0)
		printf("%d", arr->data[arr->size - 1]);
	printf(" ]\n");
	printf("\tsize: %d\n\tcapacity: %d\n", arr->size, arr->capacity);
	printf("}\n");
}

void clear_array(t_array *arr) {
	free(arr->data);
	free(arr);
}

int main() {
	t_array *arr = create_array();
	append_end(arr, 2);
	append_end(arr, 3);
	append_start(arr, 1);
	print_array(arr);
	append_start(arr, 0);
	append_end(arr, 4);
	print_array(arr);
	append_end(arr, 5);
	append_end(arr, 6);
	print_array(arr);
	append_end(arr, 7);
	print_array(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	pop(arr);
	print_array(arr);
	pop(arr);
	print_array(arr);
	clear_array(arr);
	return 0;
}
