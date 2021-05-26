#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "rungekutta.h"

void setAssumedPotential(void) {

    kari = (double*)malloc(sizeof(double) * split * 4);

    return;
}

void releaseAssumedPotential(void) {

    free(kari);

    return;
}

void rungekutta(void) {
    double lam[4];
    lam[0] = 0.25;
    lam[1] = 1.0 / 3.0;
    lam[2] = 0.5;
    lam[3] = 1.0;

    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            kari[k + 0 * split] = Q1[k];
            kari[k + 1 * split] = Q2[k];
            kari[k + 2 * split] = Q3[k];
            kari[k + 3 * split] = Q4[k];
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int lx = 3; lx < x_split - 2; lx++) {
            for (int ly = 0; ly < y_split - 1; ly++) {
                int l = lx + ly * x_split;
                if (l == 51) {
                    printf("");
                }
                for (int m = 0; m < 4; m++) {
                    kari[l + split * m] = kari[l + split * m] - lam[k] * time_step / x_step * (Ehalf[l + split * m] - Ehalf[l + split * m - 1]);
                }
            }
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int lx = 0; lx < x_split - 1; lx++) {
            for (int ly = 3; ly < y_split - 2; ly++) {
                int l = lx + ly * x_split;
                for (int m = 0; m < 4; m++) {
                    kari[l + split * m] = kari[l + split * m] - lam[k] * time_step / y_step * (Fhalf[l + split * m] - Fhalf[l + split * m - x_split]);
                }

            }
        }
    }

    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            Q1[k] = kari[k + split * 0];
            Q2[k] = kari[k + split * 1];
            Q3[k] = kari[k + split * 2];
            Q4[k] = kari[k + split * 3];
        }
    }

    return;
}
