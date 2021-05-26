#ifndef GLOBAL_H_
#define GLOBAL_H_

//#define x_step    0.01
//#define y_step    0.01
//#define time_step 0.00001
//#define Gamma 1.4
//#define time_max  0.1
//#define MAX_STEP_CNT (int)(time_max / time_step / 10)
/*
#define RHO_0 1.0
#define P_0 1.0
#define U_0 0.0
#define V_0 0.0
#define RHO_N 0.125
#define P_N 0.1
#define U_N 0.0
#define V_N 0.0
*/

#define KAPPA 1.0 / 3.0
#define EPSILON 1.0

#define X_DIR 1
#define Y_DIR 2

#ifdef MAIN_C_
double* rho;
double* u;
double* v;
double* e;
double* p;
double* H;
double* c;
double* area_X;
double* area_Y;
double* X_half;
double* Y_half;
double* X_zeta_half;
double* Y_zeta_half;
double* X_eta_half;
double* Y_eta_half;
double* J_inv;
double time;
double time_flag;
double* Q1;
double* Q2;
double* Q3;
double* Q4;
double* Ehalf;
double* Fhalf;
volatile double x_step;
volatile double y_step;
volatile int x_split;
volatile int y_split;
volatile double time_step;
volatile int split;
volatile double Gamma;
volatile double time_max;
volatile int file_num;
volatile double rho_N;
volatile double rho_0;
volatile double p_N;
volatile double p_0;
volatile double u_N;
volatile double u_0;
volatile double v_N;
volatile double v_0;
volatile double Ax, Ay;
volatile double Bx, By;
#else
extern double* rho;
extern double* u;
extern double* v;
extern double* e;
extern double* p;
extern double* H;
extern double* c;
extern double* area_X;
extern double* area_Y;
extern double* X_half;
extern double* Y_half;
extern double* X_zeta_half;
extern double* Y_zeta_half;
extern double* X_eta_half;
extern double* Y_eta_half;
extern double* J_inv;
extern double time;
extern double time_flag;
extern double* Q1;
extern double* Q2;
extern double* Q3;
extern double* Q4;
extern double* Ehalf;
extern double* Fhalf;
extern volatile double x_step;
extern volatile double y_step;
extern volatile int x_split;
extern volatile int y_split;
extern volatile double time_step;
extern volatile int split;
extern volatile double Gamma;
extern volatile double time_max;
extern volatile int file_num;
extern volatile double rho_N;
extern volatile double rho_0;
extern volatile double p_N;
extern volatile double p_0;
extern volatile double u_N;
extern volatile double u_0;
extern volatile double v_N;
extern volatile double v_0;
extern volatile double Ax, Ay;
extern volatile double Bx, By;

#endif

#endif //GLOBAL_H_