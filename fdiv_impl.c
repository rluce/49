#include<math.h>
#include<stdio.h>

#define NDIGITS 64

double
fdiv_nr(double x) {
    int num_iter, i;
    double scale, pow_exp, v, updt;
    
    pow_exp = (int) ceil(log2(x));
    scale = 1.0 / pow(2.0, pow_exp);
    updt = x * scale;
    v = (48 - 32*updt) / 17.0;

    num_iter = (int) ceil(log2( (NDIGITS + 1) / log2(17)));

    for (i=0; i<num_iter; i++) {
        v += v * (1.0 - updt * v);
    }

    return v * scale;
}

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
