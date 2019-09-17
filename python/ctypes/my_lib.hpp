#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct Complex
{
    double re;
    double im;
};

double normal_func(double a, double b);
Complex complex_func(double re, double im);

#ifdef __cplusplus
}  // extern "C"
#endif
