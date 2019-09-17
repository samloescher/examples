from ctypes import cdll, c_double, Structure
from sys import platform

if platform == "linux" or platform == "linux2":
    shared_lib_prefix = "lib"
    shared_lib_suffix = ".so"
elif platform == "darwin":
    shared_lib_prefix = "lib"
    shared_lib_suffix = ".dylib"
elif platform == "win32":
    shared_lib_prefix = ""
    shared_lib_suffix = ".dll"

my_dll = cdll.LoadLibrary("build/" + shared_lib_prefix + "my_lib" + shared_lib_suffix)

my_dll.normal_func.argtypes = [c_double, c_double]
my_dll.normal_func.restype = c_double

class COMPLEX(Structure):
    _fields_ = [("re", c_double), ("im", c_double)]

    def __str__(self):
        return "{" + str(self.re) + ", " + str(self.im) + "}"

my_dll.complex_func.argtypes = [c_double, c_double]
my_dll.complex_func.restype = COMPLEX

print(my_dll)

answer = my_dll.normal_func(1, 2)
print(answer)

answer = my_dll.complex_func(1, 2)
print(answer)
