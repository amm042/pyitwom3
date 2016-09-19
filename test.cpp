#include <stdio.h>
#include <math.h>
#include "itwom3.0.h"
#define FOUR_THIRDS 1.3333333333333
#define EARTHRADIUS 20902230.97
#define METERS_PER_FOOT 0.3048

int main(){
	
	// simple test for itwom3
	printf("ITWOM version: %2.1f\n", ITWOMVersion() );


/* taken from splat run from breakiron to 1401 jeff

$ ./splat -t breakiron.qth -r 1401jeff.qth -s ../splat/sdf -f 900 -l passloss.png

-----------------------------------------------------------------------
point_to_point: 
  elev[0] = 18.000000
  elev[1] = 70.000208
  elev[2..n] =  159.000005, 165.000005, 166.000005, 167.000005, 164.000005, 156.000005, 151.000005, 150.000005, 150.000005, 149.000005, 148.000005, 148.000005, 148.000005, 150.000005, 149.000005, 151.000005, 160.000005, 162.000005,
tht_m: 7.620000
rht_m: 6.096000
eps_dielect: 15.000000
sgm_conductivity: 0.005000
eno_ns_surfref: 301.000000
freq_mhz: 900.000000
radio climate: 5
pol: 0
conf: 0.500000
rel: 0.500000
dbloss: 98.19
strmode: 1_Hrzn_Diff
errnum: 0
-----------------------------------------------------------------------

 */

	// inputs
	double elev[] = {	18, 			// num points -1
						70.000208,		// distance in meters *between elev. samples*			
										// path length = 18 * 70.000208 			

						// a total of elev[0] + 1 heights follow:

						// [2] is the elevation at the transmitter (x=0)
						159.000005, 

						// elev[0] - 1 points here:
						// [3] is the first path elev. x=elev[1] from transmitter
						165.000005, 166.000005, 167.000005, 164.000005, 156.000005, 
						151.000005, 150.000005, 150.000005, 149.000005, 148.000005, 
						148.000005,	148.000005, 150.000005, 149.000005, 151.000005, 
						160.000005, 162.000005, 

						// distance from transmitter is: x=elev[0]*elev[1] 
						// [20]=[2+elev[0]] elevetion of receiver
						160.000005, 
						
						};
	double tht_m = 7.62; 				// transmit height
	double rht_m = 6.096; 				// receive height
	double eps_dielect = 15; 		// earth dialectric constant
	double sgm_conductivity = 0.005;// earth conductivity
	double eno_ns_surfref = 301; 	// atmospheric refractivity at seal leavel 301 nominal
	double frq_mhz = 900; 			// frequency
	int radio_climate = 5; 			// continental temperate
	int pol = 0; 					// 0 = horiz, 1 = vert see itwom source
	double conf = 0.50; 			// 0.01 to 0.99 from itwom source
	double rel = 0.50;  			// 0.01 to 0.99 from itwom source

	// outputs
	double loss=0;
	char strmode[64];
	int errno=0;

	// run
	point_to_point(elev, tht_m, rht_m, eps_dielect, sgm_conductivity, eno_ns_surfref, 
		frq_mhz, radio_climate, pol, conf, rel,
		loss, &strmode[0], errno);

	printf("dbloss: %8.2f, mode: %s, errno: %d\n", loss, strmode, errno);

/* check a short path
-----------------------------------------------------------------------
point_to_point: 
  elev[0] = 1.000000
  elev[1] = 70.000208
  elev[2..n] =  159.000005,
  elev[n..100] =  165.000005, 166.000005, 167.000005, 164.000005, 156.000005, 151.000005, 150.000005, 150.000005, 149.000005, 148.000005, 148.000005, 148.000005, 150.000005, 149.000005, 151.000005, 160.000005, 162.000005, 160.000005, 159.000005, 157.000005, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000,
tht_m: 7.620000
rht_m: 6.096000
eps_dielect: 15.000000
sgm_conductivity: 0.005000
eno_ns_surfref: 301.000000
freq_mhz: 900.000000
radio climate: 5
pol: 0
conf: 0.500000
rel: 0.500000
dbloss: 90.45
strmode: L-o-S
errnum: 4
-----------------------------------------------------------------------
*/
	double elev2[] = {1,	// number of intervals between tx site and rx site.
					70.000208,
					165,	// tx height
					// elev[0] - 1 points go here. 
					165, 	// rx height [elev[0]*elev[1] distance away]
					INFINITY, 	// height of first interval
					NAN,
					//167, 	// receive height, 70 meters awawy
					//99999
				};
	// run
	point_to_point(elev2, tht_m, rht_m, eps_dielect, sgm_conductivity, eno_ns_surfref, 
		frq_mhz, radio_climate, pol, conf, rel,
		loss, &strmode[0], errno);

	printf("dbloss: %8.2f, mode: %s, errno: %d\n", loss, strmode, errno);
	return 0;

}