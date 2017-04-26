#ifndef PARAMETERS_H
#define PARAMETERS_H
	// Parameters both for main-rungekutta and direction-field
	double xmin_glob = -7., xmax_glob = 7. ;
	// points of the approximated solution
	int printpoints_glob=1000;

	// Parameters for direction-field
	double ymin_glob = -2., ymax_glob = 2. ;

	// Parameters for rungekutta
	double minstart_glob = -2., maxstart_glob = 0. ;
	int numstart_glob = 10 ;

#endif
