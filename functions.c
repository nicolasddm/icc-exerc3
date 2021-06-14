#include <stdio.h>
#include <math.h>
#include "resolveED.h"
#include "functions.h"

real_t functionAP(real_t x) {
    return 0.0;
}

real_t functionAQ(real_t x) {
    return 0.0;
}

real_t functionAR(real_t x) {
    return (6 * x - (0.5 * x * x));
}

real_t functionBPX(real_t x) {
    return 0.0;
}

real_t functionBPY(real_t x) {
    return 0.0;
}

real_t functionBQ(real_t x) {
    return 1.5;
}

real_t functionBR(real_t x) {
    return sin(x) * sin(x);
}

real_t functionCP(real_t x) {
    return 0.0;
}

real_t functionCQ(real_t x) {
    return 1.0;
}

real_t functionCR(real_t x) {
    return 0.0;
}

double timestamp(void) {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}
