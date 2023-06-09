#include <cmath>
#include <cstdio>

#include "lbm_model.hpp"
#include "utils.hpp"

void ValidateModel(float wall_velocity[D_LBM], int domain_size, float tau,
                   float Vel, float Rho) {
    float mach_number, reynolds_number;
    /* Compute Mach number and Reynolds number */
    // Vel = sqrt(wall_velocity[0] * wall_velocity[0] +
    //          wall_velocity[1] * wall_velocity[1] +
    //          wall_velocity[2] * wall_velocity[2]);
    mach_number = Vel * SQRT3;
    // reynolds_number = u_wall_length*domain_size*C_S_POW2_INV/(tau-0.5);
    reynolds_number =
        C_S_POW2_INV * Vel * domain_size / (C * C * DT * (tau - 0.5));
    printf("Computed Mach number: %f\n", mach_number);
    printf("Computed Reynolds number: %f\n", reynolds_number);
    printf("Computed relaxation time: %f\n", tau);

    /* Check if characteristic numbers are correct */
    if (mach_number >= 1)
        ERROR("Computed Mach number is too large.");
    if (reynolds_number > 500)
        ERROR("Computed Reynolds number is too large for simulation to be run "
              "on a laptop/pc.");
}
