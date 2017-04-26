#ifndef PARAMETERS_H
#define PARAMETERS_H
	// Parameters both for main-rungekutta and direction-field
	double xmin_glob = -4., xmax_glob = 4. ;
	// points of the approximated solution
	int printpoints_glob=1000;

	// Parameters for direction-field
	double ymin_glob = -4., ymax_glob = 3. ;

	// Parameters for rungekutta
	double minstart_glob = -2., maxstart_glob = 2. ;
	int numstart_glob = 20 ;

#endif
