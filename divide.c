#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<float.h>
#include<math.h>

#include "fdiv.h"

int main() {
    int ret;
    double asdf;

    double d1;
    double d2;
    double d2_nr;

    while( (ret = scanf("%lf", &asdf)) ) {

        /* Do stuff to prevent possible compiler optimziation */
        d1 = asdf;
        if (d1 > sqrt(0.72))
            d2 = 1./d1;
        else
            d2 = -1;

        printf("Input number: %e\n", d1);

        d2_nr = fdiv_nr(d1);
        printf("inverse == inverse_nr? %d\n", d2_nr == d2);
        printf("inverse - inverse_nr: %e\n", d2_nr - d2);
    }

    return ret;
}
