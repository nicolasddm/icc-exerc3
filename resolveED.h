#ifndef __RESOLVEED_H__
#define __RESOLVEED_H__

#include <stdio.h>

typedef float real_t;

typedef struct {
    int n; //número de pontos internos na malha
    real_t a, b; //intervalo
    real_t ya, yb; //condições de contorno
    real_t (* p) (real_t), (* q) (real_t), (* r) (real_t);
} Edo;

typedef struct {
    int nX, nY; //número de pontos internos na malha
    real_t aX, bX, aY, bY; //intervalo
    real_t uaX, ubX, uaY, ubY; //condições de contorno
    real_t (* pX) (real_t), (* pY) (real_t), (* q) (real_t), (* r) (real_t);
} Edp;

real_t *diag, *diagInf, *diagSup, *diagInfInf, *diagSupSup, *termsi;

typedef struct {
    int n;
    real_t *termsi, *diag, *diagInf, *diagSup;
} SL_tridiag;

void resolveED (Edo *edoeq, real_t *Y);

void resolveEDP (Edp *edpEq, real_t *Y);

Edo* alocaEdoA(int malha);

Edp* alocaEdpB(int malha);

Edo* alocaEdoC(int malha);

void printaEdoResult(Edo *edoEq, real_t *Y);

#endif // __RESOLVEED_H__