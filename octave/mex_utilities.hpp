#pragma once

long long encode(void * pointer)
{
    union {long long i; void *p;} ivp;
    ivp.p = pointer;
    return ivp.i;
}

void * decode(long long encodedPointer)
{
    union {long long i; void *p;} ivp;
    ivp.i = encodedPointer;
    return ivp.p;
}
