#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
	char c;
	struct s_node *next;
} t_node;

typedef struct s_stack {
	t_node *head;
} t_stack;

t_stack *create_stack() {
	t_stack *s = malloc(sizeof(t_stack));
	s->head = NULL;
	return (s);
}

void free_stack(t_stack *s) {
	t_node *curr = s->head;
	while (curr != NULL) {
		t_node *tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(s);
}

void push_stack(t_stack *s, char c) {
	t_node *node = malloc(sizeof(t_node));
	node->c = c;
	node->next = s->head;
	s->head = node;
}

char pop_stack(t_stack *s) {
	if (s->head == NULL)
		return -1;
	char c = s->head->c;
	t_node *tmp = s->head;
	s->head = s->head->next;
	free(tmp);
	return (c);
}

void reverse_str(char *str) {
	t_stack *s = create_stack();
	for (int i = 0; str[i] != '\0'; i++)
		push_stack(s, str[i]);
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = pop_stack(s);
	free_stack(s);
}

void run(char *src) {
	char *str = malloc(sizeof(char) * strlen(src) + 1);
	strncpy(str, src, strlen(src) + 1);
	printf("%s\n", str);
	reverse_str(str);
	printf("%s\n\n", str);
	free(str);
}

int main() {
	run("ciao");
	run("bellaa");
	run("gabriel");
	run("intereseting");
	return (0);
}
