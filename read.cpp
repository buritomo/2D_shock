#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "read.h"

void inputSetting(void) {
    FILE* fp;
    fp = fopen("Setting.csv", "r");
    if (fp == NULL) {
        printf("Cannnot Open Setting.csv\n");
        exit(1);
    }
    fscanf(fp, "dx, %lf \n", &x_step);
    fscanf(fp, "dy, %lf \n", &y_step);
    fscanf(fp, "dt, %lf \n", &time_step);
    fscanf(fp, "Gamma, %lf \n", &Gamma);
    fscanf(fp, "TimeLimit, %lf \n", &time_max);
    fscanf(fp, "files, %d \n", &file_num);

    fclose(fp);
    return;
}

void inputInitialValue(void) {
    FILE* fp;
    fp = fopen("initial.csv", "r");
    if (fp == NULL) {
        printf("Cannnot open initial.csv\n");
        exit(1);
    }
    fscanf(fp, "rho, %lf, %lf\n", &rho_0, &rho_N);
    fscanf(fp, "p, %lf, %lf\n", &p_0, &p_N);
    fscanf(fp, "u, %lf, %lf\n", &u_0, &u_N);
    fscanf(fp, "v, %lf, %lf\n", &v_0, &v_N);
    fscanf(fp, "A, %lf, %lf\n", &Ax, &Ay);
    fscanf(fp, "B, %lf, %lf\n", &Bx, &By);

    if ((By - Ay) / (Bx - Ax) > -1) {
        printf("Inverse x and y\n");
        double c = Ax;
        Ax = Bx;
        Bx = c;

        c = Ay;
        Ay = By;
        By = c;
    }

    fclose(fp);
    return;
}