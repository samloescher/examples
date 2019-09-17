lib = mex_create();
fprintf('\n')

e = mex_get(lib, "empty")
fprintf('\n')

d = mex_get(lib, "double")
fprintf('\n')

c = mex_get(lib, "complex")
fprintf('\n')

i = mex_get(lib, "invalid")
fprintf('\n')

mex_release(lib)
