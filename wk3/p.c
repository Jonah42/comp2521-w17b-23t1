#include <stdio.h>
#include <stdlib.h>

int p(int *A, int n, int x) { // O(n)
	int sum = A[0];
	int x_cumulative = 1;
	for (int i = 1; i <= n; i++) {
		x_cumulative *= x;
		sum += x_cumulative*A[i];
	}
	return sum;
}

int main(int argc, char **argv) {
	int A[4];
	A[0] = 4;
	A[1] = 2;
	A[2] = 1;
	A[3] = 1;
	printf("%d\n", p(A, 3, atoi(argv[1])));
	return 0;
}