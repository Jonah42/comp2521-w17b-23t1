#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NOT_HEIGHT_BALANCED -99
#define max(a, b) (a > b ? a : b)

typedef struct node BSTNode;
typedef Tree BSTree;

int BSTreeNumNodes(BSTree t) {
	if (t == NULL) return 0;
	return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}

int BSTreeCountOdds(BSTree t) {
	if (t == NULL) return 0;
	return t->value%2 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
}

int BSTreeHeight(BSTree t) {
	if (t == NULL) return 0;
	return max(BSTreeHeight(t->left), BSTreeHeight(t->right)) + 1;
}

int BSTreeCountInternal(BSTree t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;
	return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
}

int BSTreeNodeLevel(BSTree t, int key) {
	if (t == NULL) return -1;
	if (t->value == key) return 0;
	if (key > t->value) {
		int ret = BSTreeNodeLevel(t->right, key);
		return ret == -1 ? -1 : 1 + ret;
	} else {
		int ret = BSTreeNodeLevel(t->left, key);
		return ret == -1 ? -1 : 1 + ret;
	}
}

int BSTreeCountGreater(BSTree t, int key) {
	if (t == NULL) return 0;
	if (key >= t->value) {
		return BSTreeCountGreater(t->right, key);
	}
	return 1 + BSTreeCountGreater(t->left, key) + BSTreeCountGreater(t->right, key);
}

int isHeightBalanced(BSTree t) {
	if (t == NULL) return 0;
	int left = isHeightBalanced(t->left);
	int right = isHeightBalanced(t->right);
	if (abs(left-right) > 1) return NOT_HEIGHT_BALANCED;
	return 1 + max(left, right);
}

BSTree createNode(int value) {
	BSTree new = malloc(sizeof(*new));
	new->left = new->right = NULL;
	new->value = value;
	return new;
}

BSTree insert(BSTree t, int value) {
	if (t == NULL) return createNode(value);
	if (value < t->value) t->left = insert(t->left, value);
	else t->right = insert(t->right, value);
	return t;
}

int main(int argc, char **argv) {
	BSTree t = NULL;
	for (int i = 1; i < argc; i++) t = insert(t, atoi(argv[i]));
	printTree(t);
	printf("NumNodes: %d\n", BSTreeNumNodes(t));
	printf("CountOdds: %d\n", BSTreeCountOdds(t));
	printf("Height: %d\n", BSTreeHeight(t));
	printf("CountInternal: %d\n", BSTreeCountInternal(t));
	printf("NodeLevel: %d\n", BSTreeNodeLevel(t, 42));
	printf("CountGreater: %d\n", BSTreeCountGreater(t, 5));
	printf("HeightBalanced: %d\n", isHeightBalanced(t));
	return 0;
}