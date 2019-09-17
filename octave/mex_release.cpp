#include "mex.h"
#include "shared_workspace.h"
#include "mex_utilities.hpp"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    auto state = decode(*(long long *)mxGetData(prhs[0]));
    if (state != nullptr)
    {
        mexPrintf("Release ");
        mexPrintf("%p\n", state);
        release(state);
    }
    else
    {
        mexPrintf("Can't release nullptr\n");
    }
}
