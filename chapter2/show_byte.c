#include<stdio.h>
#include<string.h>

typedef unsigned char *byte_pointer;
// 2.10
void inplace_swap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

// 2.11
void reverse_array(int a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt-1;
			first < last;
			first++, last--)
		inplace_swap(&a[first], &a[last]);
}

// 2.11_Test
void print_array(int a[], int cnt) {
	for (int i = 0;
			i < cnt;
			i++)
		printf("%2d", a[i]);
}

void show_bytes(byte_pointer start, size_t len) {
	for (int i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main() {
	int a[] = {1, 2, 3, 4, 5};
	reverse_array(a, 5);
	print_array(a, 5);
	return 0;
}
