#ifndef PROBCAUCHY_H
#define PROBCAUCHY_H

#ifndef PROBCAUCHY_C
char problemname[64] = "sin(y) / (1.+cos(y)*cos(y))" ;
double f (double *y, double t, double *par) ;
double func (double x, double y) ;
double fz (double *y, double t, double *par) ;
#endif


#endif
