#ifndef PARAMETERS_H
#define PARAMETERS_H
	// Parameters both for main-rungekutta and direction-field
	double xmin_glob = -2., xmax_glob = 2. ;
	// points of the approximated solution
	int printpoints_glob=1000;

	// Parameters for direction-field
	double ymin_glob = -3., ymax_glob = 3. ;

	// Parameters for rungekutta
	double minstart_glob = 0.00001, maxstart_glob = 1. ;
	int numstart_glob = 10 ;

#endif
