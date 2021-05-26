#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"

void calcInternalValues(void) {
    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            e[k] = rho[k] * (p[k] / (rho[k] * (Gamma - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]));
            c[k] = sqrt(Gamma * p[k] / rho[k]);
            H[k] = Gamma * p[k] / (rho[k] * (Gamma - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]);
        }
    }
    return;
}

void makePotential(void) {
    /*for (int kx = 0; kx < x_split; kx++) {
        for (int ky = 0; ky < y_split; ky++) {
            int k = kx + ky * x_split;
            Q1[k] = rho[k];
            Q2[k] = rho[k] * u[k];
            Q3[k] = rho[k] * v[k];
            Q4[k] = e[k];
        }
    }*/
    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            Q1[k] = J_inv[k] * rho[k];
            Q2[k] = J_inv[k] * rho[k] * u[k];
            Q3[k] = J_inv[k] * rho[k] * v[k];
            Q4[k] = J_inv[k] * e[k];
        }
    }

    return;
}

void inversePotentialToParams(void) {
    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            rho[k] = Q1[k] / J_inv[k];
            u[k] = Q2[k] / rho[k] / J_inv[k];
            v[k] = Q3[k] / rho[k] / J_inv[k];
            e[k] = Q4[k] / J_inv[k];
            p[k] = (e[k] - 0.5 * rho[k] * (u[k] * u[k] + v[k] * v[k])) * (Gamma - 1);
            c[k] = sqrt(Gamma * p[k] / rho[k]);
            H[k] = Gamma * p[k] / (rho[k] * (Gamma - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]);

            /*
            rho[k] = Q1[k];
            u[k] = Q2[k] / rho[k];
            v[k] = Q3[k] / rho[k];
            e[k] = Q4[k];
            p[k] = (e[k] - 0.5 * rho[k] * (u[k] * u[k] + v[k] * v[k])) * (Gamma - 1);
            c[k] = sqrt(Gamma * p[k] / rho[k]);
            H[k] = Gamma * p[k] / (rho[k] * (Gamma - 1)) + 0.5 * (u[k] * u[k] + v[k] * v[k]);
            */
            /*
            if(isnan(c[k])){
                printf("Error C is here!\n");
            }
            if(ky>0 && rho[k] > rho[k-1]){
                printf("Reverse Happen here!!\n");
            }
            */
        }
    }
    return;
}

void printTimer(void) {
    if ((time - time_flag) > (time_max / 100)) {
        double rate = time / time_max * 100;
        printf("%.1f %% is finished....\n", rate);
        time_flag = time;
    }
    return;
}