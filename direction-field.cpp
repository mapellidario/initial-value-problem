/*

Draws a graphical representation of the direction field associated with
the ODE

ACHTUNG: this program requires the presence of a directory called
'data' in the same directory of the executable

*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "TCanvas.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TFrame.h"
#include "TLine.h"
#include "TApplication.h"

extern "C" {
	#include "CauchyProblem.h"
}
#include "parameters.h"

int main(int numArg, char * listArg[]) {

	std::cout << "start vector field represetations" << std::endl ;

	// graph parameters
	double xmin = xmin_glob, xmax = xmax_glob;
	double ymin = ymin_glob, ymax = ymax_glob ;
	int printpoints = printpoints_glob; // both pos and neg
	double minstart = minstart_glob, maxstart = maxstart_glob ;
	int numstart = numstart_glob ;
	double starting[1] = {minstart} ;  // a single independent var

	// parameters of the vector grid
	int xpts=35, ypts=20;
	int linewidht = 2 ;

	// ROOT basic declarations
//	TApplication* theApp = new TApplication("App", &numArg, listArg);
	TCanvas *c1 = new TCanvas("c1","mappa ODE I ordine",200,10,1900,1000);
	c1->SetGrid();
	int colorcanvas=1 ;

	//PART I: Import RK4 files
	TGraph *gr = new TGraph() ;
	double x[2*printpoints*(numstart+1)] ;
	double y[2*printpoints*(numstart+1)] ;
	int counter=0;

	while (starting[0] <= maxstart) {
		printf("Initial Cond: %f\n", starting[0]) ;
		char filename[64];
		sprintf (filename, "data/out_%f.txt", starting[0]);
		std::ifstream input (filename) ;
		while (1) {
			input >> x[counter] >> y[counter];
			if (input.eof()==1) break;
//			std::cout << counter << " " << x[counter] << " " << y[counter] << std::endl ;
			gr->SetPoint(counter, x[counter], y[counter]);
			counter++ ;
		}
		starting[0] += (maxstart - minstart) / (double) numstart ;
	}

	gr->SetPoint(counter+1, xmin, ymin);
	gr->SetPoint(counter+2, xmax, ymax);
	gr->SetTitle(Form("Direction field first order ODE: %s", problemname)) ;
	gr->SetMarkerStyle(7);
	gr->SetMarkerColor(kRed);
	gr->GetXaxis()->SetTitle("X");
	gr->GetYaxis()->SetTitle("Y(x)");
//	gr->GetXaxis()->SetRangeUser(xmin, xmax);
//	gr->GetYaxis()->SetRangeUser(ymin, ymax);
	gr->Draw("AP");

	//Part II: vector field ofthe first order ODE
	TLine* line[(xpts+1)*(ypts+1)];
	for (int i=0; i<=xpts ; i++) {
		for (int j=0; j<=ypts ; j++) {
			double xctr = xmin+(double)i/xpts*(xmax-xmin) ;
			double yctr = ymin+(double)j/ypts*(ymax-ymin) ;
			double tan = func(xctr,yctr); // = y'(x) \in (-inf, +inf)
				// it correspond to theta \in (-pi/2, pi/2)
				// hence cos(theta)>0 here
			double cos = sqrt ( 1. / (1.+tan*tan) ) ;
			double sin = 2.;
			// since tan = sin/cos, cos>0, then sign(sin) = sign(tan)
			if (tan >= 0) sin = sqrt ( tan*tan / (1.+tan*tan) );
			else if(tan < 0) sin = - sqrt ( tan*tan / (1.+tan*tan) ) ;
			if (sin==2.) std::cout << "error in computing the sin of a line" << std::endl ;
			// double l = (xmax-xmin)/xpts*0.33 / (1.+sin*sin) ;
			double l = (xmax-xmin)/xpts*0.33 ;
			line[i*ypts+j] =
				new TLine(xctr-l*cos,yctr-l*sin,xctr+l*cos,yctr+l*sin) ;
//			line->SetLineColor(kRed);
			line[i*ypts+j]->SetLineWidth(linewidht);
			line[i*ypts+j]->Draw();
//			double xa=xctr-l*cos, ya=yctr-l*sin, xb=xctr+l*cos, yb=yctr+l*sin ;
//			std::cout << i << " " << j << " " << xctr << " " << yctr << std::endl ;
//			std::cout << sqrt (4*l*cos*l*cos+4*l*sin*l*sin) << " " <<
//						sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya)) << " " << 2*l << std::endl ;
		}
	}

	// TCanvas::Update() draws the frame, after which one can change it
	if (colorcanvas) {
		c1->Update();
		c1->SetFillColor(42);
		c1->SetGrid();
		c1->GetFrame()->SetFillColor(21);
		c1->GetFrame()->SetBorderSize(12);
		c1->Modified();
	}
	c1->Print("map.png", "png");

//	theApp->Run() ;

	return 0;
}
