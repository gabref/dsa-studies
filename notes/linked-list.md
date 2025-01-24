# Linked List

## What is
* linkedlist is a collection of nodes, where each node contains
    * data
    * pointer - a reference to the next node

## Types
    * Singly Linked list: each node points to the next
    * Doubly Linked list: nodes have pointers to both the next and previous nodes
    * Circular Linked list: last node points back to the first node

## Characteristics
    * Dynamic size
    * Sequential access: no direct indexing, traversal required
    * Effitient insertion / deletions: faster than arrays when inserting/deleting in the middle

## Operations
    * Traversal
        visit each node - O(n)
    * Insertion
        at the head: O(1)
        at the tail or middle: O(n)
    * Deletion
        at the head: O(1)
        at the tail or middle: O(n)
