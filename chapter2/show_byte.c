#include<stdio.h>
#include<string.h>

typedef unsigned char *byte_pointer;

/* 2.42 */
int div16(int x) {
	return (x < 0 ? x + (1 << k) - 1 : x) >> k;
}

/* Determine whether arguments can be added without overflow */
/* 2.30 */
int tadd_ok(int x, int y) {
	int s = x + y;
	if (x > 0 & y > 0 & s > 0)
		return 1;
	if (x < 0 & y < 0 & s < 0)
		return 1;
}

/* 2.30 solution 
int tadd_ok(int x, int y) {
	int sum = x + y;
	int neg_over = x < 0 && y < 0 && sum >= 0;
	int pos_over = x > 0 && y > 0 && sum < 0;
	return !neg_over && !pos_over;
} */

// 2.32
int tsub_ok(int x, int y) {
	if (y == TMin) {
		return tadd_ok(x, -(y+1));
	}
}
/* WARNING: This is buggy code */
float sum_elements(float a[], int length) {
	int i;
	float result = 0;

	for (i = 0; i <= length-1; i++)
		result += a[i];
	return result;
}

int fun1(unsigned word) {
	return (int)((word << 24) >> 24);
}

int fun2(unsigned word) {
	return ((int) word << 24) >> 24;
}

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
	
	short x = 12345;
	short mx = -x;

	show_bytes((byte_pointer) &x, sizeof(short));
	show_bytes((byte_pointer) &mx, sizeof(short));

	short v = -12345;
	unsigned short uv = (unsigned short) v;
	printf("v = %d, uv = %u\n", v, uv);

	unsigned u = 4294967295u; //  UMax 
	int 	 tu = (int) u;
	printf("u = %u, tu = %d\n", u, tu);


	int x = -1;
	unsigned u = 2147483648;

	printf("x = %u = %d\n", x, x);
	printf("u = %u = %d\n", u, u);

	
	// -1 < 0U --> 0 Test
	unsigned char result = -1 < 0U;
	printf("result = %d\n", result);


	short sx = -12345;
	unsigned short usx = sx;
	int x = sx;
	unsigned ux = usx;

	printf("sx	=	%d:\t", sx);
	show_bytes((byte_pointer) &sx, sizeof(short));
	printf("usx	=	%u:\t", usx);
	show_bytes((byte_pointer) &usx, sizeof(unsigned short));

	printf("x	=	%d:\t", x);
	show_bytes((byte_pointer) &x, sizeof(int));
	printf("ux	=	%u:\t", ux);
	show_bytes((byte_pointer) &ux, sizeof(unsigned int));

	*/

	short sx = -12345;
	unsigned uy = sx;
	printf("uy	=	%u:\t", uy);
	show_bytes((byte_pointer) &uy, sizeof(unsigned));

	int result = fun2(0x000000C9);
	printf("fun2(0x000000C9):\t");
	show_bytes((byte_pointer) &result, sizeof(int));

	return 0;
}
