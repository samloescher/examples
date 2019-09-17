#include "mex.h"
#include "shared_workspace.h"
#include "mex_utilities.hpp"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    mexPrintf("Create ");
    auto state = create();
    mexPrintf("%p\n", state);

    plhs[0] = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
    auto ip = (long long *) mxGetData(plhs[0]);
    *ip = encode(state);
}


