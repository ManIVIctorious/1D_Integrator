
#include <stdio.h>
#include <stdlib.h>

int InputFunction(char *inputfile, double **x, double **V);
double TrapezoidalIntegral(double *x, double *y, int dimension, double *inty);

int main(int argc, char **argv){

    int i, dimension;
    double *x, *y, *inty, integralvalue;
    char *inputfile = argv[1];

    x = malloc(sizeof(double));
    y = malloc(sizeof(double));
    dimension = InputFunction(inputfile, &x, &y);

    inty = malloc(dimension*sizeof(double));
    integralvalue = TrapezoidalIntegral(x, y, dimension, inty);

    printf("#\n#            Integral y dx = % 18.12lf\n", integralvalue);
    printf("#        x                    y                  Int(y)\n");
    for(i=0; i<dimension; ++i){
        printf("% 19.12lf  % 19.12lf  % 19.12lf\n", x[i], y[i], inty[i]);
    }

    return 0;
}