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

void printaEdpSL(real_t *diagInfInf, real_t *diagInf, real_t *diag, real_t *diagSup, real_t *diagSupSup, real_t *termsi, int n, real_t *T, real_t normaL2) {
    printf("SL:\n");

    for(int i = 0; i < n - 1; i++) {
        printf("     %f ", diagSupSup[i]);
    }
    printf("\n");

    for(int i = 0; i < n - 1; i++) {
        printf("   %f ", diagSup[i]);
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

    for(int i = 0; i < n - 1; i++) {
        printf("     %f ", diagInfInf[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++) {
        printf("%f ", termsi[i]);
    }
    printf("\n");

    printf("Y: ");
    for (int i = 0; i < n; ++i) {
        printf("%f ", T[i]);
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

real_t getSomeX(int i, Edp *edpEq, real_t Hx) {
    int multX = ((i + 1) % edpEq->nX);
    if(((i + 1) % edpEq->nX) == 0){
        multX = edpEq->nX;
    }

    real_t someX = edpEq->aX + (multX * Hx);

    return someX;
}

real_t getSomeY(int i, Edp *edpEq, real_t Hy) {
    int adjY = 1;
    if(((i + 1) % edpEq->nX) == 0){
        adjY = 0;
    }

    real_t someY = edpEq->aY + ((floor((i + 1) / edpEq->nX) + adjY) * Hy);

    return someY;
}

real_t getInternPoint(int i, Edp *edpEq, real_t Hx, real_t Hy) {

    real_t someX = getSomeX(i, edpEq, Hx);
    real_t someY = getSomeY(i, edpEq, Hy);

    printf("someX: %f, someY: %f \n", someX, someY);

    return someX + someY;
}

void resolveEDP (Edp *edpEq, real_t *T) {
    int n = edpEq->nX * edpEq->nY;

    real_t Hx, Hy, xi, yi;
    real_t *termsi = malloc(sizeof(real_t) * n);
    real_t *diag = malloc(sizeof(real_t) * n);
    real_t *diagInf = malloc(sizeof(real_t) * n);
    real_t *diagSup = malloc(sizeof(real_t) * n);
    real_t *diagInfInf = malloc(sizeof(real_t) * n);
    real_t *diagSupSup = malloc(sizeof(real_t) * n);
    
    Hx = (edpEq->bX - edpEq->aX) / (edpEq->nX + 1);
    Hy = (edpEq->bY - edpEq->aY) / (edpEq->nY + 1);
    printf("Hx = %f, Hy = %f\n", Hx, Hy);

    for (int k = 0; k < 50; ++k) { // adicionar a condição de parada;
        for (int i = 0; i < n; ++i) {
            xi = getInternPoint(i, edpEq, Hx, Hy);
            termsi[i] = Hx*Hx * Hy*Hy * edpEq->r(xi);
            diagInfInf[i] = Hx*Hx * edpEq->pX(xi);
            diagInf[i] = Hy*Hy * edpEq->pY(xi);
            diag[i] = -2 * (Hx*Hx + Hy*Hy) * edpEq->q(xi);
            diagSup[i] = Hy*Hy * edpEq->pY(xi);
            diagSupSup[i] = Hx*Hx * edpEq->pX(xi);
            if (getSomeX(i, edpEq, Hx) == getSomeX(0, edpEq, Hx)) {
                diagInf[i] = 0.0;
                termsi[i] -= edpEq->uaY;
            } else if (getSomeX(i, edpEq, Hx) == getSomeX(n-1, edpEq, Hx)) {
                diagSup[i] = 0.0;
                termsi[i] -= edpEq->ubY;
            }
            if (getSomeY(i, edpEq, Hy) == getSomeY(0, edpEq, Hy)) {
                diagInfInf[i] = 0.0;
                termsi[i] -= edpEq->uaX;
            } else if(getSomeY(i, edpEq, Hy) == getSomeY(n-1, edpEq, Hy)) {
                diagSupSup[i] = 0.0;
                termsi[i] -= edpEq->ubX;
            }
            

            // if (i == 0) termsi[i] -= diagSup[i] * Y[i+1] + edoeq->ya * (1 - h * edoeq->p(edoeq->a + h) / 2.0);
            // else if (i == n-1) termsi[i] -= diagInf[i] * Y[i-1] - edoeq->yb * (1 + h * edoeq->p(edoeq->b - h) / 2.0);
            // else termsi[i] -= diagSup[i] * Y[i+1] + diagInf[i] * Y[i-1];

            T[i] = termsi[i] / diag[i];
        }
    }

    real_t normaL2 = 0;
    printaEdpSL(diagInfInf, diagInf, diag, diagSup, diagSupSup, termsi, n, T, normaL2);
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

Edp* alocaEdpB(int malha) {
    Edp *edpEq = (Edp *) malloc(sizeof(Edp));

    edpEq->nX = malha;
    edpEq->nY = 3;
    
    edpEq->aX = 0;
    edpEq->bX = 6;

    edpEq->aY = 0;
    edpEq->bY = 8;

    edpEq->uaX = 20;
    edpEq->ubX = 45;
    edpEq->uaY = 0;
    edpEq->ubY = 100;

    edpEq->pX = *functionBPX;
    edpEq->pY = *functionBPY;
    edpEq->q = *functionBQ;
    edpEq->r = *functionBR;

    return edpEq;
}

Edo* alocaEdoC(int malha) {
    Edo *edoeq = (Edo *) malloc(sizeof(Edo));
    edoeq->n = malha;

    edoeq->a = 0.0;
    edoeq->b = 1.0;
    edoeq->ya = 0;
    edoeq->yb = 1;

    edoeq->p = *functionCP;
    edoeq->q = *functionCQ;
    edoeq->r = *functionCR;

    return edoeq;
}
