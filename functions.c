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

double timestamp(void) {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}
