#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct s_node {
	int data;
	struct s_node *next;
} t_node;

typedef struct s_queue {
	t_node *front;
	t_node *back;
} t_queue;

typedef struct s_stack {
	t_queue *a;
	t_queue *b;
} t_stack;

t_queue *create_queue(void) {
	t_queue *q = malloc(sizeof(t_queue));
	q->front = NULL;
	q->back = NULL;
	return (q);
}

void destroy_queue(t_queue *q) {
	t_node *curr = q->front;
	while (curr != NULL) {
		t_node *tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(q);
}

void print_queue(t_queue *q) {
	for (t_node *curr = q->front; curr != NULL; curr = curr->next)
		printf("%d -> ", curr->data);
	printf("NULL\n");
}

t_node *create_node(int data) {
	t_node *node = malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

void enqueue(t_queue *q, int data) {
	t_node *node = create_node(data);
	if (q->front == NULL || q->back == NULL) {
		assert(q->front == NULL);
		assert(q->back == NULL);
		q->front = node;
		q->back = node;
		return ;
	}
	q->back->next = node;
	q->back = node;
}

void dequeue(t_queue *q) {
	t_node *tmp;
	if (q->front == NULL || q->back == NULL)
		return ;
	tmp = q->front;
	if (q->front == q->back) {
		q->front = NULL;
		q->back = NULL;
	} else
		q->front = q->front->next;
	free(tmp);
}

int queue_peek(t_queue *q) {
	return q->front->data;
}

bool is_empty(t_queue *q) {
	if (q->front == NULL) {
		assert(q->back == NULL);
		return (true);
	}
	return (false);
}

void reverse_queue(t_queue *q) {
	if (is_empty(q))
		return ;
	int data = queue_peek(q);
	dequeue(q);
	reverse_queue(q);
	enqueue(q, data);
}

t_stack *create_stack(void) {
	t_stack *s = malloc(sizeof(t_stack));
	s->a = create_queue();
	s->b = create_queue();
	return (s);
}

void destroy_stack(t_stack *s) {
	destroy_queue(s->a);
	destroy_queue(s->b);
	free(s);
}

void stack_push(t_stack *s, int data) {
	assert(is_empty(s->b));
	enqueue(s->b, data);
	while (!is_empty(s->a)) {
		int data = queue_peek(s->a);
		dequeue(s->a);
		enqueue(s->b, data);
	}
	assert(is_empty(s->a));
	t_queue *tmp = s->a;
	s->a = s->b;
	s->b = tmp;
}

int stack_pop(t_stack *s) {
	int data = queue_peek(s->a);
	dequeue(s->a);
	return data;
}

void print_stack(t_stack *s) {
	print_queue(s->a);
}

void test_queue() {
	printf("\n------QUEUE TEST------\n");
	t_queue *q = create_queue();
	print_queue(q);
	enqueue(q, 1);
	print_queue(q);
	enqueue(q, 2);
	print_queue(q);
	enqueue(q, 3);
	print_queue(q);
	enqueue(q, 4);
	print_queue(q);
	// reverse_queue(q);
	// print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	destroy_queue(q);
	printf("\n------END TEST------\n");
}

void test_stack(void) {
	printf("------STACK TEST------\n\n");
	t_stack *s = create_stack();
	print_stack(s);
	stack_push(s, 1);
	print_stack(s);
	stack_push(s, 2);
	print_stack(s);
	stack_push(s, 3);
	print_stack(s);
	stack_push(s, 4);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
	destroy_stack(s);
	printf("\n------END TEST------\n");
}

int main(void) {
	test_queue();
	test_stack();
	return (0);
}
