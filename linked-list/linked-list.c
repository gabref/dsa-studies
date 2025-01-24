#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
  int data;
  struct s_node *next;
} t_node;

void print_ll(t_node *head) {
  for (t_node *current = head; current != NULL; current = current->next)
    printf("%d -> ", current->data);
  printf("NULL\n");
}

t_node *create_node(int data) {
  t_node *new_node;

  new_node = malloc(sizeof(t_node));
  new_node->data = data;
  new_node->next = NULL;
  return (new_node);
}

void insert_start(t_node **head, t_node *new_node) {
  if (*head != NULL)
    new_node->next = *head;
  *head = new_node;
}

void insert_end(t_node *head, t_node *new_node) {
  t_node *current = head;
  while (current->next != NULL)
    current = current->next;
  current->next = new_node;
}

void clear_ll(t_node *head) {
  t_node *current;
  t_node *tmp;

  current = head;
  while (current != NULL) {
    tmp = current;
    current = current->next;
    free(tmp);
  }
}

t_node *reverse_recursive(t_node *head) {
	if (head == NULL || head->next == NULL)
		return head;
	t_node *rest = reverse_recursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

void reverse(t_node **head) {
  t_node *prev = NULL;
  t_node *curr = (*head);
  t_node *next = (*head)->next;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

int main(void) {
  t_node *head;

  head = NULL;
  insert_start(&head, create_node(2));
  insert_start(&head, create_node(1));
  insert_start(&head, create_node(0));
  insert_end(head, create_node(3));
  insert_end(head, create_node(4));
  insert_end(head, create_node(5));
  print_ll(head);

  reverse(&head);
  print_ll(head);

  head = reverse_recursive(head);
  print_ll(head);

  clear_ll(head);
}
