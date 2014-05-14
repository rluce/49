#include<math.h>

#define NDIGITS 53

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
