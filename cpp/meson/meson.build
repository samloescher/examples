project('hello_meson', 'cpp', default_options : ['warning_level=3', 'cpp_std=c++17'])

boost_dep = dependency('boost', modules : ['filesystem', 'system'])

executable('hello_meson', 'main.cpp', dependencies : boost_dep, install : true)
