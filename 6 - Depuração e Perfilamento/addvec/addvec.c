#include <malloc.h>
#include <stdio.h>

int *add_vec(int v1[], int v2[], int len) {
	int *vec_res = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; ++i) {
		vec_res[i] = v1[i] + v2[i];
	}
	return vec_res;
}

int main()
{
	int len = 5;
	int v1[] = {1, 2, 3, 4, 5};
	int v2[] = {2, 4, 6, 8, 10};

	int *vec_res = add_vec(v1, v2, len);
	for (int i = 0; i < len; ++i) {
		printf("%d ", vec_res[i]);
	}
	printf("\n");
}
