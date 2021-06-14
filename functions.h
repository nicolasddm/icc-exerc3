#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include "resolveED.h"

real_t functionAP(real_t x);

real_t functionAQ(real_t x);

real_t functionAR(real_t x);

real_t functionBPX(real_t x);

real_t functionBPY(real_t x);

real_t functionBQ(real_t x);

real_t functionBR(real_t x);

real_t functionCP(real_t x);

real_t functionCQ(real_t x);

real_t functionCR(real_t x);

real_t functionDPX(real_t x);

real_t functionDPY(real_t x);

real_t functionDQ(real_t x);

real_t functionDR(real_t x);

double timestamp(void);

#endif // __FUNCTION_H__