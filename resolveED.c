#include <stdio.h>
#include <stdlib.h>
#include "resolveED.h"
#include "functions.h"

void printaEdoSL(real_t *diagInf, real_t *diag, real_t *diagSup, real_t *termsi, int n, real_t *Y, real_t normaL2) {
    printf("SL:\n");

     for(int i = 0; i < n - 1; i++) {
        printf("  %f ", diagSup[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        printf("%f ", diag[i]);
    }
    printf("\n");

    for(int i = 0; i < n - 1; i++) {
        printf("  %f ", diagInf[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        printf("%f ", termsi[i]);
    }
    printf("\n");

    printf("Y: ");
    for (int i = 0; i < n; ++i) {
        printf("%f ", Y[i]);
    }
    printf("\n");

    printf("Norma L2: %f, ", normaL2);
}

void resolveED (Edo *edoeq, real_t *Y) {
    int n = edoeq->n;
    real_t h, xi, yi;
    real_t *termsi = malloc(sizeof(real_t) * n);
    real_t *diag = malloc(sizeof(real_t) * n);
    real_t *diagInf = malloc(sizeof(real_t) * n);
    real_t *diagSup = malloc(sizeof(real_t) * n);
    h = (edoeq->b - edoeq->a) / (n + 1);
    printf("H = %f\n", h);

    for (int k = 0; k < 50; ++k) { // adicionar a condição de parada;
        for (int i = 0; i < n; ++i) {
            xi = edoeq->a + (i+1) * h;
            termsi[i] = h*h * edoeq->r(xi);
            diagInf[i] = 1 - h * edoeq->p(xi) / 2.0;
            diag[i] = -2 + h*h * edoeq->q(xi);
            diagSup[i] =  1 + h * edoeq->p(xi) / 2.0;

            if (i == 0) termsi[i] -= diagSup[i] * Y[i+1] + edoeq->ya * (1 - h * edoeq->p(edoeq->a + h) / 2.0);
            else if (i == n-1) termsi[i] -= diagInf[i] * Y[i-1] - edoeq->yb * (1 + h * edoeq->p(edoeq->b - h) / 2.0);
            else termsi[i] -= diagSup[i] * Y[i+1] + diagInf[i] * Y[i-1];

            Y[i] = termsi[i] / diag[i];
        }
        
    }
    real_t normaL2 = 0;
    printaEdoSL(diagInf, diag, diagSup, termsi, n, Y, normaL2);
}

Edo* alocaEdoA(int malha) {
    Edo *edoeq = (Edo *) malloc(sizeof(Edo));
    edoeq->n = malha;

    edoeq->a = 0.0;
    edoeq->b = 12.0;
    edoeq->ya = 0;
    edoeq->yb = 0;

    edoeq->p = *functionAP;
    edoeq->q = *functionAQ;
    edoeq->r = *functionAR;

    return edoeq;
}
