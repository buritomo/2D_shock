#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "output.h"

void areaSet(void) {
    x_split = 1 / x_step + 5;//接点の数として想定，したがってセル中心はx_split-1個
    y_split = 1 / y_step + 5;//仮想格子は両端2点ずつ，よって計算店はx_split-5個
    split = x_split * y_split;
    return;
}

void makeGrid(void) {
    rho = (double*)malloc(sizeof(double) * split);
    u = (double*)malloc(sizeof(double) * split);
    v = (double*)malloc(sizeof(double) * split);
    e = (double*)malloc(sizeof(double) * split);
    p = (double*)malloc(sizeof(double) * split);
    c = (double*)malloc(sizeof(double) * split);
    H = (double*)malloc(sizeof(double) * split);
    area_X = (double*)malloc(sizeof(double) * split);
    area_Y = (double*)malloc(sizeof(double) * split);
    X_half = (double*)malloc(sizeof(double) * split);
    Y_half = (double*)malloc(sizeof(double) * split);
    X_zeta_half = (double*)malloc(sizeof(double) * split);
    Y_zeta_half = (double*)malloc(sizeof(double) * split);
    X_eta_half = (double*)malloc(sizeof(double) * split);
    Y_eta_half = (double*)malloc(sizeof(double) * split);
    J_inv = (double*)malloc(sizeof(double) * split);
    Q1 = (double*)malloc(sizeof(double) * split);
    Q2 = (double*)malloc(sizeof(double) * split);
    Q3 = (double*)malloc(sizeof(double) * split);
    Q4 = (double*)malloc(sizeof(double) * split);
    Ehalf = (double*)malloc(sizeof(double) * split * 4);
    Fhalf = (double*)malloc(sizeof(double) * split * 4);
    return;
}

void defineGrid(void) {
    /*
    for (int kx = 0; kx < x_split; kx++) {
        for (int ky = 0; ky < y_split; ky++) {
            int k = kx + ky * x_split;
            area_X[k] = (double)(kx-2) * 1.0 / (double)(x_split-5);
            area_Y[k] = (double)(ky-2) * 1.0 / (double)(y_split-5);
        }
    }*/
    for (int kx = 0; kx < x_split; kx++) {
        for (int ky = 0; ky < y_split; ky++) {
            int k = kx + ky * x_split;
            X_half[k] = ((double)kx - 2.0) * 1.0 / ((double)x_split - 5.0);
            Y_half[k] = ((double)ky - 2.0) * 1.0 / ((double)y_split - 5.0);
        }
    }
    return;
}

void freeGrid(void) {
    free(rho);
    free(u);
    free(v);
    free(e);
    free(p);
    free(c);
    free(H);
    free(area_X);
    free(area_Y);
    free(X_half);
    free(Y_half);
    free(X_zeta_half);
    free(Y_zeta_half);
    free(X_eta_half);
    free(Y_eta_half);
    free(J_inv);
    free(Q1);
    free(Q2);
    free(Q3);
    free(Q4);
    free(Ehalf);
    free(Fhalf);

    return;
}

void defineGeneralGrid(void) {
    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            area_X[k] = (X_half[k] + X_half[k + 1] + X_half[k + x_split] + X_half[k + x_split + 1]) / 4;
            area_Y[k] = (Y_half[k] + Y_half[k + 1] + Y_half[k + x_split] + Y_half[k + x_split + 1]) / 4;
        }
    }

    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split; ky++) {
            int k = kx + ky * x_split;
            X_zeta_half[k] = X_half[k + 1] - X_half[k];
            Y_zeta_half[k] = Y_half[k + 1] - Y_half[k];
        }
    }

    for (int kx = 0; kx < x_split; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            X_eta_half[k] = X_half[k + x_split] - X_half[k];
            Y_eta_half[k] = Y_half[k + x_split] - Y_half[k];
        }
    }

    for (int kx = 0; kx < x_split - 1; kx++) {
        for (int ky = 0; ky < y_split - 1; ky++) {
            int k = kx + ky * x_split;
            int kp = (kx + 1) + (ky + 1) * x_split;
            J_inv[k] = 0.5 * (X_half[k + x_split + 1] - X_half[k]) * (Y_half[k + x_split] - Y_half[k + 1]);
            J_inv[k] = J_inv[k] - 0.5 * (X_half[k + x_split] - X_half[k+1]) * (Y_half[k + x_split + 1] - Y_half[k]);
        }
    }

    char filename[100];
    sprintf(filename, "J_inv.csv");
    ExportTarget(J_inv, filename, x_split - 1, y_split - 1);
    sprintf(filename, "X_eta.csv");
    ExportTarget(X_eta_half, filename, x_split - 1, y_split);
    sprintf(filename, "Y_eta.csv");
    ExportTarget(Y_eta_half, filename, x_split - 1, y_split);
    sprintf(filename, "X_zeta.csv");
    ExportTarget(X_zeta_half, filename, x_split, y_split - 1);
    sprintf(filename, "Y_zeta.csv");
    ExportTarget(Y_zeta_half, filename, x_split, y_split - 1);
    return;
}