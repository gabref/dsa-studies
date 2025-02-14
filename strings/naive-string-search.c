#include <stdio.h>
#include <string.h>

void naive_search(char *text, char *pattern) {
	int n = strlen(text);
	int m = strlen(pattern);
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < m; j++)
			if (text[i + j] != pattern[j])
				break ;
		if (j == m)
			printf("found pattern at: %d - %s\n", i, text + i);
	}
}

int main(int ac, char **av) {
	if (ac != 3) {
		printf("usage: <name_program> \"hello world\" \"world\"\n");
		return (1);
	}
	naive_search(av[1], av[2]);
	return (0);
}
