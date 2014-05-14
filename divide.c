#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<float.h>
#include<math.h>

#include "fdiv.h"

#define IEEE_D_SIGN(b)  ((b) & (1ul)<<63)>>63


void print_bit_pattern(unsigned long l);
unsigned long get_kth_bit(unsigned long l, int k);
unsigned long get_range_mask(unsigned long l, unsigned long k);
long get_ieee_exponent(double d);

void print_double(double d) {
    unsigned long di;
    memcpy(&di, &d, sizeof(double));

    printf ("val: %.15e\n", d);

    print_bit_pattern(di);

    printf ("    long  :   %ld\n", di);
    printf ("    hex   :   %lx\n", di);
    printf ("    base16:   %a\n", d);
    printf ("    sign:     %lu\n", IEEE_D_SIGN(di));

    printf ("    b2 exp:   %ld\n", get_ieee_exponent(d));
    return;
}

void print_bit_pattern(unsigned long l) {
    printf("    base2: %lu ", get_kth_bit(l, 63));
    int k;
    for (k=62; k>=52; k--) {
        printf("%lu", get_kth_bit(l, k));
    }

    printf(" ");

    for (k=51; k>=0; k--) {
        printf("%lu", get_kth_bit(l, k));
    }

    printf("\n");
}

long get_ieee_exponent(double d)
{
    unsigned long di;
    long exponent;
    memcpy(&di, &d, sizeof(double));
    
    exponent = (long)((di & get_range_mask(62, 52)) >> 52);
    if (exponent == 0) {
        return 0l;
    }

    /* Apply bias */

    exponent -= 1023;


    return exponent;

}

unsigned long get_kth_bit(unsigned long l, int k) {
    return (l & ( 1ul<<k)) >> k;
}


unsigned long ones_from_right(unsigned long k)
{
    /* CAUTION:  Before changing this, check for side effects on
     * get_range_mask
     */
    return ((1ul<<(k+1)) - 1);
}

/* Bounds included in range */
unsigned long get_range_mask(unsigned long left_bit, unsigned long right_bit)
{
    /* right_bit - 1 is correct (even for 0) because of the implementation
     * of ones_from_right
     */
    return ones_from_right(left_bit) ^ ones_from_right(right_bit-1);
}

int main() {
    int ret;
    double asdf;

    double d1;
    double d2;

    while( (ret = scanf("%lf", &asdf)) ) {
        print_double(asdf);

        /* Do stuff to prevent possible compiler optimziation */
        d1 = asdf;
        if (d1 > sqrt(0.72))
            d2 = 1./d1;
        else
            d2 = -1;


        printf("Input number\n");
        print_double(d1);
        printf("Builtin inverse\n");
        print_double(d2);
        printf("1.0 - number * inverse\n");
        print_double(1.0 - d1 * d2);

        if (d1*d2 == 1.0)
            printf("Exact\n");
        else
            printf("Not exact\n");

        d2 = fdiv_nr(d1);
        printf("Own NR inverse\n");
        print_double(d2);
        printf("1.0 - number * inverse\n");
        print_double(1.0 - d1 * d2);

        if (d1*d2 == 1.0)
            printf("Exact\n");
        else
            printf("Not exact\n");

    }

    return ret;
}
