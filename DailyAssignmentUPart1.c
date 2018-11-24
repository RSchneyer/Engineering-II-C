// Reid Schneyer
// Daily Assignment U
// 11-14-2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double not_quadratic(double x);

int main(void){
    double num = not_quadratic(-3.03);
    printf("\n%f\n", num);
    return 0;
}

double not_quadratic(double x){
    double foo = log(fabs(x));
    return (20*foo);
}
