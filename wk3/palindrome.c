#include <string.h>
#include <stdio.h>

void palindrome(char * string) { // O(n)
	for (int i = 0, j = strlen(string) - 1; i < j; i++, j--) {
		if (string[i] != string[j]) {
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
	return;
}

int main(int argc, char **argv) {
	palindrome(argv[1]);
	return 0;
}