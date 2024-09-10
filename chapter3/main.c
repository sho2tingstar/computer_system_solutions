#include <stdio.h>

long cread(long *xp) {
	return (xp ? *xp : 0);
}
/*
void decode1(long *xp, long *yp, long *zp) {
	long temp = *yp;
	*yp = *xp;
	*xp = *zp;
	*zp = temp;
}


short scale3(short x, short y, short z) {
	short t = x + 11y + 2z;
	return t;
} */

int main() {
	long *p = 0;
	cread(p);
	return 0;
}
