#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node {
    int value;
    struct node *next;
} *Node;

typedef struct list {
    Node head;
} *List;

void append(List l, int x) {
    Node new = malloc(sizeof(struct node));
    new->value = x;
    new->next = l->head;
    l->head = new;
}

void show(List l) {
    Node curr = l->head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

typedef int (*FilterFunc)(int);

int filterOdds(int x) {
    if (x%2 == 1) {
        return 0;
    }
    return 1;
}

int filterEvens(int x) {
    if (x%2 == 0) {
        return 0;
    }
    return 1;
}

Node doListFilter(Node n, int (*fp)(int)) {
    if (n == NULL) return NULL;
    if (fp(n->value) == 0) { // delete the node
        Node next = n->next;
        free(n);
        return doListFilter(next, fp);
    }
    n->next = doListFilter(n->next, fp);
    return n;
}

void listFilter(List l, FilterFunc fp) {
    l->head = doListFilter(l->head, fp);
}



int main(int argc, char** argv) {
    List l = malloc(sizeof(struct list));
    assert(l != NULL);
    l->head = NULL;
    for (int i = argc - 1; i > 0; i--) append(l, atoi(argv[i]));
    show(l);
    listFilter(l, filterOdds);
    show(l);
    return 0;
}