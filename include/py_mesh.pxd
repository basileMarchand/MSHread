from libcpp.vector cimport vector
from libcpp.string cimport string

from mesh_type cimport MESH, MSHReader

cdef class pyMESH:
   cpdef MESH* _thisptr;
   cpdef int getNE(self);
   cpdef int getNN(self);
   cpdef list getGroupsName(self);
   cpdef list getElemsInGroup(self, str);
   cpdef list getCoords(self);
   cpdef list getElem(self, int);

cdef class pyMSHReader:
   cdef MSHReader* _thisptr;
   cpdef void readMesh(self);
   cpdef void createGroupsMap(self);
   cpdef void createElemsMap(self);
   cpdef pyMESH getMesh(self);


