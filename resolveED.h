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
    int n; //número de pontos internos na malha
    real_t a, b; //intervalo
    real_t ya, yb; //condições de contorno
    real_t (* p) (real_t), (* q) (real_t), (* r) (real_t);
    real_t *diag, *diagInf, *diagSup, *diagInfInf, *diagSupSup;
} Edp;

typedef struct {
    int n;
    real_t *termsi, *diag, *diagInf, *diagSup;
} SL_tridiag;

void resolveED (Edo *edoeq, real_t *Y);

Edo* alocaEdoA(int malha);

void printaEdoResult(Edo *edoEq, real_t *Y);

#endif // __RESOLVEED_H__