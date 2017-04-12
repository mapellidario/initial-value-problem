#ifndef PARAMETERS_H
#define PARAMETERS_H
	// Parameters both for main-rungekutta and vector-field
	double xmin_glob = -4., xmax_glob = 10. ;
	// points of the approximated solution
	int printpoints_glob=1000;

	// Parameters for vector-field
//	double ymin_glob = -0.99999, ymax_glob=0.9999 ;
	double ymin_glob = -7., ymax_glob = 7. ;

	// Parameters for rungekutta
	double minstart_glob = -6., maxstart_glob = 6. ;
	int numstart_glob = 20 ;

#endif
