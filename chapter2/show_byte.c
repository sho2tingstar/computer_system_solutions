#include<stdio.h>
#include<string.h>

typedef unsigned char *byte_pointer;


/* 2.13 
int bis(int x, int y);
int bic(int x, int y);

int bool_or(int x, int y) {
	int result = bis(x, y);
	return result;
}

int bool_xor(int x, int y) {
	int result = bis(bic(x, y), bic(y, x));
	return result;
} */

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

	// 2.12 A
	/* int x = 0x87654321; 
	// int xl = x & 0x000000FF; 워드가 32비트인 환경에서만 적용됨
	int xl = x & 0xFF;
	
	printf("%0.8x", xl);
	printf("\n");

	// 2.12 B [0x789ABC21]
	// int xb = x ^ 0xFFFFFF00;
	int xb = x ^ ~0xFF;
	printf("%0.8X", xb);
	printf("\n");

	// 2.13 C [0x876543FF]
	// int xc = x | 0x000000FF;
	int xc = x | 0xFF;
	printf("%0.8X", xc);
	*/
	short x = 12345;
	short mx = -x;

	show_bytes((byte_pointer) &x, sizeof(short));
	show_bytes((byte_pointer) &mx, sizeof(short));

	short v = -12345;
	unsigned short uv = (unsigned short) v;
	printf("v = %d, uv = %u\n", v, uv);

	return 0;
}
