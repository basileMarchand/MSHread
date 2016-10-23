Welcome to MSHread
==================

MSHread is a minimalistic library for reading meshes created by [GMSH](www.gmsh.info).

More than its use for mesh reading, the purpose of this repository is to provide a relatively simple example of creating a C ++ library and wrapping them into python using cython. And also how to simply manage the build process and dependencies using [CMake](https://cmake.org).

----------


Requirements
------------
  - gcc (with c++11 support)
  - cmake (minimal version 3.3)
  - python (developped for 3.X but surely works for 2.7+)
  - cython

###### in addition but not required
  - scikit-build : for the CMake support of Cython
not absolutely required since the necessary cmake module files are included in the .CythonCMake directory on the repository


Installation
------------
To install the MSHread library firstly download sources or clone the git repository
```
git clone https://github.com/basileMarchand/MSHread.git
```
Go to the MSHread directory and create a build directory
```
cd MSHread  
mkdir build
```
Then generate the build process using CMake and launch the compilation with make
```
cd build  
cmake ..
make
```
To try the install you can go to the example directory and launch the two examples :  
  - for the c++ example (compiled in the same time as sources)
```
./example
```
  - for the python example, which used the python wrapping
  ```
  python example2.py
  ```




Project tree
------------
The MSHread project is organized as follow
```
MSHread  
|  
|-- .CythonCMake
|   |-- FindCython.cmake
|   |-- FindNumPy.cmake
|   |-- FindPythonExtensions.cmake
|   |-- targetLinkLibrariesWithDynamicLookup.cmake
|   `-- UseCython.cmake
|-- example  
|   |-- CMakeLists.txt  
|   |-- example.cpp  
|   |-- example2.py  
|   `-- mesh_ex.msh      
|-- include  
|   |-- mesh.h  
|   |-- mesh_type.pxd  
|   |-- py_mesh.pxd  
|   `-- reader.h  
|-- src  
|   |-- mesh.cpp  
|   |-- py_mesh.pyx  
|   `-- reader.cpp  
|-- CMakeLists.txt  
`-- README.md  
```
