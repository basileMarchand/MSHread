
from libcpp.vector cimport vector
from libcpp.string cimport string 
from libcpp.map cimport map

cdef extern from "mesh.h":
    cdef cppclass MESH:
        MESH();
        int nnodes;
        int nelems;
        vector[vector[double]] coords;
        vector[vector[int]] connec;
        vector[vector[string]] tags;
        vector[int] types;
        map[string, vector[int]] groups_map;
        map[int, vector[int]] types_map;
        vector[string] getGroupsName();
        vector[int] getElemsInGroup(string);
        vector[vector[double]] getCoords();
        vector[int] getElem(int);

cdef extern from "reader.h":
    cdef cppclass MSHReader:
        MSHReader(string);
        void readMesh();
        void createGroupsMap();
        void createElemsMap();
        MESH* getMesh();


