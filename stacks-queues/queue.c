#include <stdio.h>

#define MAX 100

typedef struct s_queue {
	int front;
	int back;
	int items[MAX];
} t_queue;

t_queue create_queue(void) {
	t_queue q;
	q.front = 0;
	q.back = -1;
	return (q);
}

void enqueue(t_queue *q, int data) {
	if (q->back == MAX - 1) {
		printf("could not enqueue %d, overflow\n", data);
		return ;
	}
	q->back++;
	q->items[q->back] = data;
}

void dequeue(t_queue *q) {
	if (q->front != -1 && q->front > q->back) {
		printf("could not dequeue, underflow\n");
		return ;
	}
	q->front++;
}

void print_queue(t_queue *q) {
	for (int i = q->front; i < q->back + 1; i++) {
		printf("%d -> ", q->items[i]);
	}
	printf("NULL\n");
}

int main(void) {
	t_queue q = create_queue();
	print_queue(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	print_queue(&q);
	dequeue(&q);
	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);
	return 0;
}
