4! = 4*3*2*1

5! = 5*4!


10! = 10*9!

n! = n*(n-1)!

int factorial(int n) {
	// Base case
	if (n == 1)
		return 1;
	// Recursion
	int f = n*factorial(n-1);
	return f;
}

int main(void) {
	int n = 4;
	int f = factorial(n);
	return 0;
}