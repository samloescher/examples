#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { UNKNOWN = 0, DOUBLE = 1, COMPLEX = 2 } DataType;
void* create();
void release(void* lib);

double* get(void* lib, const char* id, int* size, DataType* type);

#ifdef __cplusplus
}  // extern "C"
#endif
