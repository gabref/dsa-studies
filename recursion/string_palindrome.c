#include <stdio.h>
#include <string.h>

int is_palindrome(char *str, int start, int end) {
	if (start >= end)
		return 1;
	return str[start] == str[end] && is_palindrome(str, start + 1, end - 1);
}

void run(char *str) {
	printf("%s\t%d\n", str, is_palindrome(str, 0, strlen(str) - 1));
}

int main() {
	printf("\nword\ts_palindrome\n");

	run("gabriel");
	run("abba");
	run("bella");
	run("00100");
	run("");

	printf("\n");
	return (0);
}
