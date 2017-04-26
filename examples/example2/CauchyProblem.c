#define PROBCAUCHY_C

// #include <stdio.h>
// #include <stdlib.h>
#include <math.h>
// #include <time.h>
#include "CauchyProblem.h"


// y'(x) = f(x,y(x)).
double func (double x, double y) {
	return y*exp(y+x) / sqrt(1.-y*y);
} //mappa

double f (double* y, double t, double* par){
	return ( y[0] * exp (y[0]) * exp (t) ) / ( sqrt (1. - y[0]*y[0]) );
}//Rung-Kutta

// z(x) = y(-x) -> z'(x) = - y'(-x) = - f (-x, y(-x)) = -f (-x, z(x))
// QUI: z'(t) = fz (t,z(t)) = -f(-t,z(t))
double fz (double* y, double t, double* par){
	return -( y[0] * exp (y[0]) * exp (-t) ) / ( sqrt (1. - y[0]*y[0]) );
}
