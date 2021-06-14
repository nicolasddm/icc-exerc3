#include <stdio.h>
#include <stdlib.h>
#include "resolveED.h"
#include "functions.h"

int main () {
    // resolve e printa edo a) com malha x = 5
    
    Edo *edoEqA = alocaEdoA(5);
    real_t *Ys = (real_t *) malloc(sizeof(real_t) * edoEqA->n);
    
    double tempo;
    tempo = timestamp();
    
    printf("***** item (a): N = 5, ");
    resolveED(edoEqA, Ys);
    
    tempo = timestamp() - tempo;
    printf("Tempo: %f ms\n", tempo);

    // resolve e printa edo a) com malha x = 10
    Edo *edoEqA2 = alocaEdoA(10);
    real_t *YsA2 = (real_t *) malloc(sizeof(real_t) * edoEqA2->n);
    tempo = timestamp();
    
    printf("***** item (a): N = 10, ");
    resolveED(edoEqA2, YsA2);
    
    tempo = timestamp() - tempo;
    printf("Tempo: %f ms\n", tempo);
    
    // // resolve e printa edp b) com malha x = 5 e malha y = 3
    // real_t *Ys;
    // Edp *edpEqB;
    // alocaEdp(edpEqB, 5);
    // resolveED(edpEqB, Ys);
    // printaResult(edpEqB, Ys);
    
    // // resolve e printa edp b) com malha x = 10 e malha y = 3
    // real_t *Ys;
    // Edp *edpEqB;
    // alocaEdp(edpEqB, 10);
    // resolveED(edpEqB, Ys);
    // printaResult(edpEqB, Ys);

    // // resolve e printa edo c) com malha x = 5
    // real_t *Ys;
    // Edo *edoEqC;
    // alocaEdo(edoEqC, 5);
    // resolveED(edoEqC, Ys);
    // printaResult(edoEqC, Ys);

    // // resolve e printa edo c) com malha x = 10
    // real_t *Ys;
    // Edo *edoEqC;
    // alocaEdo(edoEqC, 10);
    // resolveED(edoEqC, Ys);
    // printaResult(edoEqC, Ys);

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