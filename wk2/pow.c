// x^n = x^(n/2) * x^(n/2)
#include <stdio.h>

int pow2(int x, unsigned int n) {
	if (n == 1) return x;
	int res;
	if (n%2 == 1) {
		res = pow2(x, n/2);
		res = res*res*x;
	} else {
		res = pow2(x, n/2);
		res = res*res;
	}
	return res;

}

int main(void) {

	int res = pow2(2, 5);
	printf("Result is %d\n", res);
	return 0;
}