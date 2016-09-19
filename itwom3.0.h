
void point_to_point_ITM(double elev[], double tht_m, double rht_m, double eps_dielect, 
	double sgm_conductivity, double eno_ns_surfref, double frq_mhz, int radio_climate, 
	int pol, double conf, double rel, double &dbloss, char *strmode, int &errnum);
void point_to_point(double elev[], double tht_m, double rht_m, double eps_dielect, 
	double sgm_conductivity, double eno_ns_surfref, double frq_mhz, int radio_climate, 
	int pol, double conf, double rel, double &dbloss, char *strmode, int &errnum);
void point_to_pointMDH_two (double elev[], double tht_m, double rht_m,
          double eps_dielect, double sgm_conductivity, double eno_ns_surfref, 
	  double enc_ncc_clcref, double clutter_height, double clutter_density, 
	  double delta_h_diff, double frq_mhz, int radio_climate, int pol, int mode_var, 
	  double timepct, double locpct, double confpct, 
	  double &dbloss, int &propmode, double &deltaH, int &errnum);
void point_to_pointDH (double elev[], double tht_m, double rht_m, 
		  double eps_dielect, double sgm_conductivity, double eno_ns_surfref,
		  double enc_ncc_clcref, double clutter_height, double clutter_density, 
		  double delta_h_diff, double frq_mhz, int radio_climate, int pol, 
		  double conf, double rel, double loc,double &dbloss, double &deltaH,
		  int &errnum);
double ITWOMVersion();
