#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

List createNode(int data) {
	List newNode = malloc(sizeof(struct node));
	assert(newNode != NULL);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

List addNode(List l, int data) {
	List newNode = createNode(data);
	newNode->next = l;
	l = newNode;
	return l;
}

int listLength(List l) {
	if (l == NULL) {
		return 0;
	}
	return 1 + listLength(l->next);
}

int listCountOdds(List l) {
	if (l == NULL) {
		return 0;
	}
	return l->data%2 + listCountOdds(l->next);
}

bool listIsSorted(List l) {
	if (l == NULL || l->next == NULL) {
		return true;
	}
	return (l->data <= l->next->data) && listIsSorted(l->next);
}

List listDelete(List l, int value) {
	if (l == NULL) return NULL;
	if (l->data == value) {
		List next = l->next;
		free(l);
		return next;
	}
	l->next = listDelete(l->next, value);
	return l;
}

int main(void) {
	List l = NULL;
	l = addNode(l, 4);
	l = addNode(l, 1996);
	l = addNode(l, 1987);
	l = addNode(l, 8);
	printf("Length = %d\n", listLength(l));
	printf("Odds = %d\n", listCountOdds(l));
	printf("Sorted = %d\n", listIsSorted(l));
	l = listDelete(l, 1987);
	printf("Length = %d\n", listLength(l));
	return 0;
}