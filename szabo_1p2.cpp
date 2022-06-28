#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *A = malloc(9 * sizeof(int));
	int *B = malloc(9 * sizeof(int));

	*A = {{1, 1, 0}, {1, 2, 2}, {0, 2, -1}};
	*B = {{1, -1, 1}, {-1, 0, 0}, {1,  0, 1}};

	free(A);
	free(B);
}
