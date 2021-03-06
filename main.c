
#include <stdio.h>
#include <stdlib.h>

int InputFunction(char *inputfile, double **x, double **V);
double TrapezoidalIntegral(double *x, double *y, int dimension, double *inty);

int main(int argc, char **argv){

    if(argc != 3){
        fprintf(stderr,
            "\n (-) Error: Please enter input file"
            "\n     Aborting...\n\n"
        );
        exit(1);
    }

    int i, dimension;
    double *x, *y, *inty, integralvalue;
    char *inputfile = argv[1];

    x = malloc(sizeof(double));
    y = malloc(sizeof(double));
    dimension = InputFunction(inputfile, &x, &y);

    inty = malloc(dimension*sizeof(double));
    integralvalue = TrapezoidalIntegral(x, y, dimension, inty);

    printf("#\n#                      Integral y dx = % 24.16lf\n", integralvalue);
    printf("#              x");
    printf("                         y");
    printf("                      Int(y)\n");
    for(i=0; i<dimension; ++i){
        printf("% 24.16lf  % 24.16lf  % 24.16lf\n", x[i], y[i], inty[i]);
    }

    return 0;
}
