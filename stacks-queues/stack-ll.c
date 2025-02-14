#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int data;
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

void push_stack(t_stack *s, int data) {
	t_node *node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->next = s->head;
	s->head = node;
}

int pop_stack(t_stack *s) {
	int value;
	t_node *tmp;

	if (s->head == NULL)
		return -1;
	value = s->head->data;
	tmp = s->head;
	s->head = s->head->next;
	free(tmp);
	return (value);
}

void free_stack(t_stack *s) {
	t_node *tmp;
	t_node *curr;

	curr = s->head;
	while (curr != NULL) {
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(s);
}

void print_stack(t_stack *s) {
	for (t_node *curr = s->head; curr != NULL; curr = curr->next)
		printf("%d -> ", curr->data);
	printf("NULL\n");
}

int main() {
	t_stack *s;

	s = create_stack();
	print_stack(s);
	push_stack(s, 1);
	push_stack(s, 2);
	push_stack(s, 3);
	print_stack(s);
	pop_stack(s);
	print_stack(s);
	pop_stack(s);
	print_stack(s);
	pop_stack(s);
	print_stack(s);
	pop_stack(s);
	print_stack(s);
	pop_stack(s);
	print_stack(s);
	free_stack(s);
	return (0);
}
