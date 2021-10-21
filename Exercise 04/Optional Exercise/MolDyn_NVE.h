/****************************************************************
*****************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
*****************************************************************
*****************************************************************/


const int m_props=4;
int n_props;  //Number of observables
int nbins;  //Number of bins for the 
	    //calculation of g(r)
double bin_size;
int iv, ik, ie, it, iw;
double stima_pot, stima_kin, stima_etot, stima_temp;  //Istantaneous values
double stima_pres, stima_gofr, r;
double acc, att, vtail, ptail;


//Configuration variables
const int m_part=108;  //Number of particles in the system
double x[m_part], y[m_part], z[m_part];
double xold[m_part], yold[m_part], zold[m_part];  //this is for the restart option
double vx[m_part], vy[m_part], vz[m_part];


//Thermodynamical state variables
int npart;  //Number of the total particles
	    //m_part to use in a simulation
double energy, temp, vol, rho, box, rcut;
int restart;  //if = 1 Equilibrate
int blocking;  //if = 1 Blocking Method


//Simulation variables
int nstep, iprint, seed;  //nstep --> number of integration steps
double delta;  //Infinitesimal time step
	       //for the integration of the 
	       //equations of motion
	     

//Blocking variables
int n_blks, counter;
double sum_epot, sum_ekin, sum_etot, sum_temp, sum_pres;
double prog_epot=0, prog_ekin=0, prog_etot=0, prog_temp=0, prog_pres=0;
double prog2_epot=0, prog2_ekin=0, prog2_etot=0, prog2_temp=0, prog2_pres=0;
double ave_epot, ave_ekin, ave_etot, ave_temp, ave_pres;
double ave2_epot, ave2_ekin, ave2_etot, ave2_temp, ave2_pres;
double err_epot, err_ekin, err_etot, err_temp, err_pres;
double *gofr, *sum_gofr, *ave_gofr, *ave2_gofr;  //Measure of g(r)


//Functions
void Input(std::string);
void Move(void);
void ConfFinal(std::string);
void ConfXYZ(int, std::string);
void Measure(std::string);
double Force(int, int);
double Pbc(double);
void Accumulate(void);
void Blocking(int, std::string);
void Delete_g(void);


/****************************************************************
*****************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
*****************************************************************
*****************************************************************/
