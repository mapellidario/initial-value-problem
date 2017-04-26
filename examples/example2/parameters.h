#ifndef PARAMETERS_H
#define PARAMETERS_H
	// Parameters both for main-rungekutta and direction-field
	double xmin_glob = -2., xmax_glob = 2. ;
	// points of the approximated solution
	int printpoints_glob=1000;

	// Parameters for direction-field
	double ymin_glob = -0.99999, ymax_glob = 0.999999 ;

	// Parameters for rungekutta
	double minstart_glob = -0.99999, maxstart_glob = 0.99999 ;
	int numstart_glob = 20 ;

#endif
