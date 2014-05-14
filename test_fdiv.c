#include<stdio.h>
#include "fdiv.h"

/* Basic functionality test */
int main() {
	double a,b;
	a = 1;
	printf("a:    %.15e\n", a);
	b = fdiv_nr(a);
	printf("ainv: %.15e\n", b);
	printf("prod: %.15e\n", a*b);

	a = 2;
	printf("a:    %.15e\n", a);
	b = fdiv_nr(a);
	printf("ainv: %.15e\n", b);
	printf("prod: %.15e\n", a*b);

	a = 3;
	printf("a:    %.15e\n", a);
	b = fdiv_nr(a);
	printf("ainv: %.15e\n", b);
	printf("prod: %.15e\n", a*b);

	a = 7;
	printf("a:    %.15e\n", a);
	b = fdiv_nr(a);
	printf("ainv: %.15e\n", b);
	printf("prod: %.15e\n", a*b);

	return 0;
}
