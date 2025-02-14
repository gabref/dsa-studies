#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum e_type {
	NONE,
	ROUND,
	SQUARE,
	CURLY,
	ANGLE,
} t_type;

typedef struct s_node {
	t_type type;
	struct s_node *next;
} t_node;

typedef struct s_stack {
	struct s_node *head;
} t_stack;

t_stack *create_stack() {
	t_stack *s;

	s = malloc(sizeof(t_stack));
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

void push(t_stack *s, t_type type) {
	t_node *node = malloc(sizeof(t_node));
	node->type = type;
	node->next = s->head;
	s->head = node;
}

t_type pop(t_stack *s) {
	t_type t = s->head->type;
	t_node *tmp = s->head;
	s->head = s->head->next;
	free(tmp);
	return (t);
}

bool is_empty_and_free(t_stack *s) {
	if (s->head == NULL)
	{
		free_stack(s);
		return (true);
	}
	free_stack(s);
	return (false);
}

bool is_open(char c) {
	return c == '{' || c == '[' || c == '(' || c == '<';
}

bool is_close(char c) {
	return c == '}' || c == ']' || c == ')' || c == '>';
}

t_type par_to_type(char c) {
	switch (c) {
		case '{':
		case '}': return CURLY;
		case '[':
		case ']': return SQUARE;
		case '(':
		case ')': return ROUND;
		case '<':
		case '>': return ANGLE;
		default : {
			printf("something went wrong - %c\n", c);
			return NONE;
		}
	}
}

bool check_parenthesis(char *str) {
	t_stack *s = create_stack();
	int i = 0;
	while (str[i]) {
		if (is_open(str[i])) {
			push(s, par_to_type(str[i]));
		} else if (is_close(str[i])) {
			if (par_to_type(str[i]) != pop(s)) {
				free_stack(s);
				return (false);
			}
		}
		i++;
	}
	return (is_empty_and_free(s));
}

int main(int ac, char **av) {
	if (ac != 2) {
		printf("Usage: ./<name_program> \"string with parentheses\"");
		return (1);
	}
	printf("Testing: %s\n", av[1]);
	if (check_parenthesis(av[1]))
	 	printf("GOOD\n");
	else
	 	printf("ERROR\n");
	return (0);
}
