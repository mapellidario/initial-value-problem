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

/*
double func (double x, double y) {
	return 1./sqrt(x+y) ;
} //mappa
double f (double* x, double t, double* par){
	return 1./sqrt(t+y[0]);
}//Rung-Kutta
double fz (double* x, double t, double* par){
	return - 1./sqrt(-t+y[0]);
}
*/

/*
double func (double x, double y) {
	return sin(x);
} //mappa
double f (double* x, double t, double* par){
	return sin(t);
}//Rung-Kutta
double fz (double* x, double t, double* par){
	return - sin (-t);
}
*/

/*
double func (double x, double y) {
	return fabs(y+y*y) / ((1.+exp(x)) * (1.+y*y) );
} //mappa
double f (double* y, double t, double* par){
	return fabs(y[0]+y[0]*y[0]) / ((1.+exp(t)) * (1.+y[0]*y[0]) );
}//Rung-Kutta
double fz (double* y, double t, double* par){
	return - fabs(y[0]+y[0]*y[0]) / ((1.+exp(-t)) * (1.+y[0]*y[0]) );

}
*/
