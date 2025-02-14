#include <stdio.h>

#define MAX 100

typedef struct s_stack {
	int	top;
	int	items[MAX];
}		t_stack;

void	init_stack(t_stack *s) {
	s->top = -1;
}

int 	push(t_stack *s, int new_item) {
	if (s->top == MAX - 1) {
		printf("Stack overflow");
		return -1;
	}
	s->top++;
	s->items[s->top] = new_item;
	return 1;
}

int 	pop_stack(t_stack *s) {
	if (s->top == -1) {
		printf("Stack underflow");
		return -1;
	}
	s->top--;
	return 1;
}

int 	peek(t_stack *s) {
	return s->items[s->top];
}

int	main(void) {
	t_stack	s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", peek(&s));
	push(&s, 4);
	printf("%d\n", peek(&s));
	pop_stack(&s);
	printf("%d\n", peek(&s));
	pop_stack(&s);
	printf("%d\n", peek(&s));
	pop_stack(&s);
	printf("%d\n", peek(&s));
	pop_stack(&s);
	printf("%d\n", peek(&s));
	return (0);
}
