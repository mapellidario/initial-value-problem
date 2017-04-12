#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

#ifndef RUNGEKUTTA_C
void rungekutta4(double *x, double *x1, int dim, double t, double h, double *par, double (*f[dim]) (double *, double, double*) ) ;
#endif

#endif
