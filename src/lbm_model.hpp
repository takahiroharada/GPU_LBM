#ifndef _LBM_MODEL_H_
#define _LBM_MODEL_H_

#define VERBOSE 0
#define MLUPS_MIN_CELLS 300
#define MLUPS_EXPONENT 1000000
/* simulation parameters */
//#define D3Q19
#define D2Q9
#ifdef D3Q19
#define D_LBM 3
#define Q_LBM 19
#endif //D3Q19

#ifdef D2Q9
#define D_LBM 3
#define Q_LBM 9
#endif //D2Q9

/* arbitrary cell identifiers */
#define FLUID 0
#define NO_SLIP 1
#define MOVING_WALL 2
/* computation enhancing values */
#define EPS 0.05
#define C_S_POW2_INV 3.0
#define C_S_POW4_INV 9.0
/* reference values, not used in actual computation */
#define SQRT3 1.73205080756887729
static const float C_S = 1.0/SQRT3;
/* predefined simulation parameters */

/* set constant value reference discretized velocity and time*/
static const int C = 1;
static const int DT = 1;

/* set boundary velocity direction at moving wall */
#define VEL_BOUNDARY_DIR 5

#ifdef D3Q19
static const int LATTICE_VELOCITIES[19][3] = {
    {0,-C,-C},{-C,0,-C},{0,0,-C},{C,0,-C},{0,C,-C},{-C,-C,0},{0,-C,0},{C,-C,0},
    {-C,0,0}, {0,0,0},  {C,0,0}, {-C,C,0},{0,C,0}, {C,C,0},  {0,-C,C},{-C,0,C},
    {0,0,C},  {C,0,C},  {0,C,C}
};
static const float LATTICE_WEIGHTS[19] = {
    1.0/36.0, 1.0/36.0, 2.0/36.0, 1.0/36.0, 1.0/36.0, 1.0/36.0, 2.0/36.0, 1.0/36.0, 
    2.0/36.0, 12.0/36.0,2.0/36.0, 1.0/36.0, 2.0/36.0, 1.0/36.0, 1.0/36.0, 1.0/36.0, 
    2.0/36.0, 1.0/36.0, 1.0/36.0
};
#endif //D3Q19

#ifdef D2Q9
static const int LATTICE_VELOCITIES[9][3] = {
    {-C,-C,0},{C,-C,0},{0,-C,0},{-C,0,0},{0,0,0},{C,0,0},{0,C,0},{-C,C,0},{C,C,0}
};
static const float LATTICE_WEIGHTS[9] = {
    1.0/36.0, 1.0/36.0, 1.0/9.0, 1.0/9.0, 4.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/36.0, 1.0/36.0
};
#endif //D2Q9


/* additional cell definitions */
#define LEFT_BOUNDARY 5100
#define RIGHT_BOUNDARY 5900
#define BOTTOM_BOUNDARY 5010
#define TOP_BOUNDARY 5090
#define BACK_BOUNDARY 5001
#define FRONT_BOUNDARY 5009

#define LEFT_BOTTOM_EDGE 5110
#define LEFT_UPPER_EDGE 5190
#define RIGHT_BOTTOM_EDGE 5910
#define RIGHT_UPPER_EDGE 5990

#define BACK_BOTTOM_EDGE 5011
#define BACK_UPPER_EDGE 5091
#define FRONT_BOTTOM_EDGE 5019
#define FRONT_UPPER_EDGE 5099

#define LEFT_BACK_EDGE 5101
#define LEFT_FRONT_EDGE 5109
#define RIGHT_BACK_EDGE 5901
#define RIGHT_FRONT_EDGE 5909

#define LEFT_BOTTOM_BACK_CORNER 5111
#define LEFT_BOTTOM_FRONT_CORNER 5119
#define LEFT_UPPER_BACK_CORNER 5191
#define LEFT_UPPER_FRONT_CORNER 5199
#define RIGHT_BOTTOM_BACK_CORNER 5911
#define RIGHT_BOTTOM_FRONT_CORNER 5919
#define RIGHT_UPPER_BACK_CORNER 5991
#define RIGHT_UPPER_FRONT_CORNER 5999

/**
 * Validates the configured physical model by calculating characteristic numbers
 */
void ValidateModel(float wall_velocity[D_LBM], int domain_size, float tau, float Vel, float Rho);

#endif
