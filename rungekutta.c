/*
Approximation of an initial value problem with RK4 method

notation: y=y(x), not x=x(t) (which is commonly found elsewhere)

The initial values are of the form y(0) = y_0,
in [minstart, maxstart] range on the y axis.
RK4 work from 0 to x>0 and from 0 to x<0.
It cannot work from x<0 to x>0 because the form of the problem changes
whether the independent variable is positive or negative, since

z(x) = y(-x) -> z'(x) = - y'(-x) = - f (-x, y(-x)) = -f (-x, z(x))

ACHTUNG: this program requires the presence of a directory called
'data' in the same directory of the executable

compile and execute only this
 gcc -o rungekutta -lm -O3 -IRungeKutta -ICauchyProblem RungeKutta/RungeKutta.c CauchyProblem/CauchyProblem.c  rungekutta.c
mkdir data
./rungekutta

*/

#include <stdio.h>
#include <stdlib.h> // malloc
#include <math.h>

#include "RungeKutta.h"
#include "CauchyProblem.h"
#include "parameters.h"

int main (int numArg, char * listArg[])
{

	printf( "starting runge-kutta\n" ) ;

	//Setting the problem parameters
	// function parameters
	double par[3] = {0.5, 0.5, 0.5} ;
	// number of scalar first order differential equation
	int dimensions = 1 ;

    // Initial Conditions
	// number of initial values
	int numstart = numstart_glob ;
	// range inside which the initial values are set
	double minstart = minstart_glob, maxstart = maxstart_glob ;
	//there only is one independent variable
	double starting[1] = {minstart} ;

	//Evolution Parameters
	double xneg = xmin_glob ; // this should be negative
	double xpos = xmax_glob ; // this should be positive
	double h=0.0001 ; //time step
	int NstepPos = (int) (xpos)/h ;
	int NstepNeg = (int) (-xneg)/h ;
	printf("Evolution Pos:\n xpos %f\n h %f\n NstepPos %d\n", xpos, h, NstepPos);
	printf("Evolution Pos:\n xneg %f\n h %f\n NstepNeg %d\n", xneg, h, NstepNeg);
	int printpoints = printpoints_glob; // both pos and neg

	while (starting[0] <= maxstart) {
		printf("Initial Cond: %f\n", starting[0]) ;
	// X > 0
		// define the array of the funcions of ODEs
		double (*func[dimensions]) (double* x, double t, double* par) ;
		func[0] = &f; // x>0

		// define some auxiliary variables
		int n=0 ; // index on the time steps
		int i=0 ; // index on the dimensions

		double *y ; // initial status
		y = (double *) malloc ( sizeof(double) * dimensions ) ;
		double *y1 ; // evolved status
		y1 = (double *) malloc ( sizeof(double) * dimensions ) ;

		for (i=0; i<dimensions; i++)
			y [i] = starting[i] ;
		for (i=0; i<dimensions; i++)
			y1 [i] = 0 ;

		char filename[64];
		sprintf (filename, "data/out_%f.txt", starting[0]);
		FILE *output = fopen (filename, "w+");

		// evolve the system
		for (n=0; n<NstepPos; n++)	{
			rungekutta4 (y, y1, dimensions, n*h, h, par, func) ;
			for(i=0; i<dimensions; i++)
				y[i] = y1[i] ;
			//print result
			if ((n%(NstepPos/printpoints))==0) {
				int isnan=0;
				for(i=0; i<dimensions; i++) if ( isnan(y1[i]) ) isnan=1;
				if (isnan==0) {
					//printf("%f ", n*h);
					fprintf (output, "%f ", n*h);
					for(i=0; i<dimensions; i++) {
					//printf("%2.15f ", x1[i] ) ;
						fprintf (output, "%2.15f ", y1[i]);
					}
					//printf("\n");
					fprintf (output, "\n");
				}
			}
		}


	// X < 0
		// reinitialize what has been used for X > 0
		func[0] = &fz;
		// auxiliary variables
		n=0 ; // index on the time steps
		i=0 ; // index on the dimensions

		for (i=0; i<dimensions; i++)
			y[i] = starting[i] ;
		for (i=0; i<dimensions; i++)
			y1 [i] = 0 ;

		// evolve the system
		for (n=0; n<NstepNeg; n++)	{
			rungekutta4 (y, y1, dimensions, n*h, h, par, func) ;
			for(i=0; i<dimensions; i++)
				y[i] = y1[i] ;
			//print result
			if ((n%(NstepNeg/printpoints))==0) {
				int isnan=0;
				for(i=0; i<dimensions; i++) if ( isnan(y1[i]) ) isnan=1;
				if (isnan==0) {
					//printf("%f ", -n*h );
					fprintf (output, "%f ", -n*h);
					for(i=0; i<dimensions; i++) {
					//printf("%2.15f ", y1[i] ) ;
						fprintf (output, "%2.15f ", y1[i]);
					}
					//printf("\n");
					fprintf (output, "\n");
				}
			}
		}

		fclose (output) ;
		free(y);
		free(y1);

		starting[0] += (maxstart - minstart) / (double) numstart ;
	}

	return 0;
}
