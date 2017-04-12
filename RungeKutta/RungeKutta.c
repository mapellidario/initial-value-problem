#define RUNGEKUTTA_C

#include "RungeKutta.h" 

/* LEGENDA
double *x: vettore lungo dimensioni=dim, contiene lo stato allo step n
double *x1: vettore lungo dimensioni, contiene lostato allo step n+1
dim: numero di dimensioni
t: variabile evolutiva del sistema
h: lunghezza step temporale
double (*f): array di funzioni, contiene le funzioni che descrivono l'evoluzione
	del sistema
double *par: contiene i parametri da passare alla f
*/

void rungekutta4(double *x, double *x1, int dim, double t, double h, double *par,
			double (*f[dim]) (double *, double, double*) ) {
	//definisco delle variabili ausilairie
	int i=0;
	double aux[dim];

	//calcolo le quattro variabili vettoriali k
	double k1[dim];
	for (i=0; i<dim; i++)
		aux [i] = x[i] ;
	for (i=0; i<dim; i++)
		k1[i] = h * (*f[i]) (aux, t, par) ;

	double k2[dim];
	for (i=0; i<dim; i++)
		aux [i] = x[i] + k1[i]/2. ;
	for (i=0; i<dim; i++)
		k2[i] = h * (*f[i]) (aux, t+h/2., par) ;

	double k3[dim];
	for (i=0; i<dim; i++)
		aux [i] = x[i] + k2[i]/2. ;
	for (i=0; i<dim; i++)
		k3[i] = h * (*f[i]) (aux, t+h/2., par) ;

	double k4[dim] ;
	for (i=0; i<dim; i++)
		aux [i] = x[i] + k3[i] ;
	for (i=0; i<dim; i++)
		k4[i] = h * (*f[i]) (aux, t+h, par);

	//faccio evolvere il sistema attraverso le variabili ausiliare
	for (i=0; i<dim; i++)
		x1[i] = x[i] + (k1[i] + 2.*k2[i] + 2.*k3[i] + k4[i])/6. ;

}
