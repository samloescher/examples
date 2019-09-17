#include "mex.h"
#include "shared_workspace.h"
#include "mex_utilities.hpp"

#include <cstring>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    auto state = decode(*(long long *) mxGetData(prhs[0]));
    auto id = mxArrayToString(prhs[1]);
    mexPrintf("Get \"%s\"\n", id);

    int size = 0;
    DataType type;
    auto out = get(state, id, &size, &type);

    if (type == DataType::DOUBLE)
    {
        mexPrintf("Double data\n");
        mexPrintf("%i elements\n", size);
        plhs[0] = mxCreateNumericMatrix(size, 1, mxDOUBLE_CLASS, mxREAL);
        std::memcpy(mxGetData(plhs[0]), out, size * sizeof(double));
    }
    else if (type == DataType::COMPLEX)
    {
        size /= 2; // Split in imag and real
        mexPrintf("Complex data\n");
        mexPrintf("%i elements\n", size);
        plhs[0] = mxCreateNumericMatrix(size, 1, mxDOUBLE_CLASS, mxCOMPLEX);
        auto r = mxGetPr(plhs[0]);
        std::memcpy(r, out, size * sizeof(double));
        auto i = mxGetPi(plhs[0]);
        std::memcpy(i, out + size, size * sizeof(double)); // imag offset by size (real)
    }
    else
    {
        mexPrintf("Key not found\n");
        plhs[0] = mxCreateNumericMatrix(0, 0, mxDOUBLE_CLASS, mxREAL);
    }
}
