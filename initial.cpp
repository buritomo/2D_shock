#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "initial.h"

void initialValue(void) {
    //double x1 = (Ax / x_step);
    //double y1 = (Ay / y_step);
    //double x2 = (Bx / x_step);
    //double y2 = (By / y_step);

    /*
    for (int ky = 0; ky < y_split; ky++) {
        for (int kx = 0; kx < (x1 + (x2 - x1) / (y2 - y1) * (ky - y1)); kx++) {
            int k = kx + ky * x_split;
            rho[k] = rho_0;
            p[k] = p_0;
            u[k] = u_0;
            v[k] = v_0;
        }
    }
    for (int ky = 0; ky < y_split; ky++) {
        for (int kx = (x1 + (x2 - x1) / (y2 - y1) * (ky - y1)); kx < x_split; kx++) {
            int k = kx + ky * x_split;
            rho[k] = rho_N;
            p[k] = p_N;
            u[k] = u_N;
            v[k] = v_N;
        }
    }*/
    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            if (area_X[k] < (Ax + (Bx - Ax) / (By - Ay) * (area_Y[k] - Ay)) ){
                rho[k] = rho_0;
                p[k] = p_0;
                u[k] = u_0;
                v[k] = v_0;
            }
            else {
                rho[k] = rho_N;
                p[k] = p_N;
                u[k] = u_N;
                v[k] = v_N;
            }
        }
    }

    
    return;
}