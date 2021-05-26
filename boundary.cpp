#include <stdio.h>
#include "global.h"
#include "boundary.h"

#include <stdio.h>
#include "global.h"
#include "boundary.h"

void boundaryValue(void) {
    /*
    for (int ky = 0; ky < x_split; ky++) {
        rho[0 + ky * x_split] = rho_0;
        rho[1 + ky * x_split] = rho_0;
        rho[(x_split - 1) + ky * x_split] = rho_N;
        rho[(x_split - 2) + ky * x_split] = rho_N;
    }*/

    /*“üŒû‹«ŠEF*/
    for (int ky = 0; ky < x_split - 1; ky++) {
        int k = ky * x_split;
        rho[k] = rho_0;
        rho[k + 1] = rho_0;
        p[k] = p_0;
        p[k + 1] = p_0;
    }

    /*oŒû‹«ŠE*/
    for (int ky = 0; ky < y_split - 1; ky++) {
        int k = x_split - 2 + ky * x_split;
        rho[k] = rho_N;
        rho[k - 1] = rho_N;
        p[k] = p_N;
        p[k - 1] = p_N;
    }

    /*•Ç–Ê‹«ŠE*/
    for (int kx = 2; kx < x_split-3; kx++) {
        int ku = kx + 0 * x_split;
        int ko = kx + (y_split - 2) * x_split;

        u[ku] = u[ku + 3 * x_split];
        u[ku + x_split] = u[ku + 2 * x_split];
        v[ku] = v[ku + 3 * x_split];
        v[ku + x_split] = v[ku + 2 * x_split];

        u[ko] = u[ko - 3 * x_split];
        u[ko - x_split] = u[ko - 2 * x_split];
        v[ko] = v[ko - 3 * x_split];
        v[ko - x_split] = v[ko - 2 * x_split];
    }

    return;
}