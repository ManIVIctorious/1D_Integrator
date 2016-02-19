
double TrapezoidalIntegral(double *x, double *y, int dimension, double *inty);

double TrapezoidalIntegral(double *x, double *y, int dimension, double *inty){

    int i;

    inty[0] = 0;
    for(i=1; i<dimension; ++i){
        inty[i] = inty[i-1] + 0.5*(x[i]-x[i-1])*(y[i]+y[i-1]);
    }

    return inty[dimension-1];
}
