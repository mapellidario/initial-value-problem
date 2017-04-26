#define PROBCAUCHY_C

// #include <stdio.h>
// #include <stdlib.h>
#include <math.h>
// #include <time.h>
#include "CauchyProblem.h"


// y'(x) = f(x,y(x)).
double func (double x, double y) {
	return sin(x);
} //map

double f (double* y, double t, double* par){
	return sin(t);
}//Rung-Kutta

// z(x) = y(-x) -> z'(x) = - y'(-x) = - f (-x, y(-x)) = -f (-x, z(x))
// QUI: z'(t) = fz (t,z(t)) = -f(-t,z(t))
double fz (double* y, double t, double* par){
	return - sin (-t);
}
