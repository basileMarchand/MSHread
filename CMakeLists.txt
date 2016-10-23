cmake_minimum_required( VERSION 3.3 )
set(CMAKE_BUILD_TYPE Release)

project(pyMSH CXX)

### C++ library part
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11")
include_directories(include)

file(GLOB 
     SOURCES 
     "src/*.cpp")

add_library(mesh STATIC ${SOURCES})

# test part
add_subdirectory(${CMAKE_SOURCE_DIR}/example)

MESSAGE( ${CMAKE_SOURCE_DIR} )

### Cython library part ; for python wrapper
#set(CMAKE_MODULE_PATH /softs/anaconda3/lib/python3.5/site-packages/skbuild/resources/cmake)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/.CythonCMake)

#set(PYTHON_LIBRARY /softs/anaconda3/lib/python3.5)

find_package(Cython)
find_package(PythonInterp)
find_package(PythonLibs)
find_package(PythonExtensions)

###include_directories(./include)
file(GLOB
     SRCCY
     "src/*.pyx")

set(CYTHON_FLAGS -I${CMAKE_SOURCE_DIR}/include)

add_cython_target(py_mesh CXX ${SRCCY}) 

###TODO###  Add the PYTHON_LIBRARY variable 

#include_directories(/softs/anaconda3/include/python3.5m)
add_library(py_mesh MODULE ${py_mesh} )
target_link_libraries(py_mesh mesh)
python_extension_module(py_mesh
                        LINKED_MODULES_VAR linked_module_list
                        FORWARD_DECL_MODULES_VAR fdecl_module_list)

