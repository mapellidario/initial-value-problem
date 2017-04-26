#ifndef PROBCAUCHY_H
#define PROBCAUCHY_H

#ifndef PROBCAUCHY_C
char problemname[64] = "fabs(y+y*y) / ((1.+exp(x)) * (1.+y*y) )" ;
double f (double *y, double t, double *par) ;
double func (double x, double y) ;
double fz (double *y, double t, double *par) ;
#endif


#endif
