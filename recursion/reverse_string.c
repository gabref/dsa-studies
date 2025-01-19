#include <stdio.h>
#include <string.h>

void reverse_string_iterative(char *str, int start, int end) {
	char temp;
	while (start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void reverse_string_recursive(char *str, int start, int end) {
	char temp;

	if (start >= end)
		return ;
	temp = str[start];
	str[start] = str[end];
	str[end] = temp;
	return reverse_string_recursive(str, start + 1, end - 1);
}

void run(char *original) {
	char dest[1000];
	strcpy(dest, original);
	printf("Original string:\t<%s>\n", original);
	reverse_string_iterative(dest, 0, strlen(dest) - 1);
	printf("Reversed string:\t<%s>\n", dest);
	reverse_string_recursive(original, 0, strlen(original) - 1);
	printf("Reversed string:\t<%s>\n", original);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: <name_of_program> <string to be reverse>\n");
		return (1);
	}
	run(av[1]);
	printf("\n");
}
