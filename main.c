#include <stdio.h>
#include <stdlib.h>
#include "resolveED.h"
#include "functions.h"

int main () {
    double tempo;
    // resolve e printa edo a) com malha x = 5
    // Edo *edoEqA = alocaEdoA(5);
    // real_t *Ys = (real_t *) malloc(sizeof(real_t) * edoEqA->n);
    
    // double tempo;
    // tempo = timestamp();
    
    // printf("***** item (a): N = 5, ");
    // resolveED(edoEqA, Ys);
    
    // tempo = timestamp() - tempo;
    // printf("Tempo: %f ms\n\n\n", tempo);
    // free(edoEqA);

    // resolve e printa edo a) com malha x = 10
    Edo *edoEqA2 = alocaEdoA(10);
    real_t *YsA2 = (real_t *) malloc(sizeof(real_t) * edoEqA2->n);
    tempo = timestamp();
    
    printf("***** item (a): N = 10, ");
    resolveED(edoEqA2, YsA2);
    
    tempo = timestamp() - tempo;
    printf("Tempo: %f ms\n\n\n", tempo);
    free(edoEqA2);
    
    // resolve e printa edp b) com malha x = 5 e malha y = 3
    Edp *edpEqB = alocaEdpB(5);
    real_t *T = (real_t *) malloc(sizeof(real_t) * (edpEqB->nX * edpEqB->nY));
    
    tempo = timestamp();
    
    printf("***** item (b): L = 6, W = 8, n = 5, m = 3, ");
    resolveEDP(edpEqB, T);
    
    tempo = timestamp() - tempo;
    printf("Tempo: %f ms\n\n\n", tempo);
    free(edpEqB);
    
    
    // resolve e printa edp b) com malha x = 10 e malha y = 3
    // Edp *edpEqB2 = alocaEdpB(10);
    // real_t *T2 = (real_t *) malloc(sizeof(real_t) * edpEqB2->n);
    
    // double tempo;
    // tempo = timestamp();
    
    // printf("***** item (b): L = 6, W = 8, n = 5, m = 3, ");
    // resolveEDP(edpEqB2, T);
    
    // tempo = timestamp() - tempo;
    // printf("Tempo: %f ms\n\n\n", tempo);
    // free(edpEqB2);

    // // resolve e printa edo c) com malha x = 5
    // Edo *edoEqC = alocaEdoC(5);
    // real_t *YsC = (real_t *) malloc(sizeof(real_t) * edoEqC->n);
    // tempo = timestamp();
    
    // printf("***** item (c): N = 5, ");
    // resolveED(edoEqC, YsC);
    
    // tempo = timestamp() - tempo;
    // printf("Tempo: %f ms\n\n\n", tempo);
    // free(edoEqC);

    // // resolve e printa edo c) com malha x = 10
    // Edo *edoEqC2 = alocaEdoC(10);
    // real_t *YsC2 = (real_t *) malloc(sizeof(real_t) * edoEqC2->n);
    // tempo = timestamp();
    
    // printf("***** item (c): N = 10, ");
    // resolveED(edoEqC2, YsC2);
    
    // tempo = timestamp() - tempo;
    // printf("Tempo: %f ms\n\n\n", tempo);
    // free(edoEqC2);

    // // resolve e printa edp d) com malha x = 5 e malha y = 3
    // real_t *Ys;
    // Edp *edpEqD;
    // alocaEdp(edpEqD, 5);
    // resolveED(edpEqD, Ys);
    // printaResult(edpEqD, Ys);

    // // resolve e printa edp d) com malha x = 10 e malha y = 3
    // real_t *Ys;
    // Edp *edpEqD;
    // alocaEdp(edpEqD, 10);
    // resolveED(edpEqD, Ys);
    // printaResult(edpEqD, Ys);
}