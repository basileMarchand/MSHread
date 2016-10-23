from libcpp.string cimport string

#from mesh_type cimport MESH, MSHReader
cimport mesh_type
from py_mesh cimport pyMESH, pyMSHReader

cdef class pyMESH:
   def __cinit__(self):
       #self._thisptr = new mesh_type.MESH()
       #self._thisptr = the_mesh
       pass

   def __dealloc__(self):
       if self._thisptr != NULL:
           del self._thisptr

   cpdef int getNE(self):
       cdef int ne = self._thisptr.nelems
       return ne

   cpdef int getNN(self):
       cdef int nn = self._thisptr.nnodes
       return nn

   cpdef list getGroupsName(self):
       cdef vector[string] groups = self._thisptr.getGroupsName()
       cdef list groups_str = [ x.decode("utf-8") for x in groups]
       return groups_str

   cpdef list getElemsInGroup(self, str grp_name):
       cdef string group = <string> grp_name.encode("utf-8")
       cdef vector[int] elems = self._thisptr.getElemsInGroup(group)
       return elems

   cpdef list getElem(self, int elem_id):
       cdef vector[int] connec = self._thisptr.getElem(elem_id)
       return connec

   cpdef list getCoords(self):
       cdef vector[vector[double]] coords = self._thisptr.getCoords()
       return coords
       



cdef class pyMSHReader:
   def __cinit__(self, str file_name):
       cdef string fname = <string> file_name.encode('utf-8')
       self._thisptr = new mesh_type.MSHReader(fname)
 
   def __dealloc__(self):
       if self._thisptr != NULL:
           del self._thisptr

   cpdef void readMesh(self):
       self._thisptr.readMesh()
       
   cpdef void createGroupsMap(self):
       self._thisptr.createGroupsMap()

   cpdef void createElemsMap(self):
       self._thisptr.createElemsMap()
       
   cpdef pyMESH getMesh(self):
       cdef mesh_type.MESH* the_mesh = self._thisptr.getMesh()
       cdef pyMESH res_mesh = pyMESH()
       res_mesh._thisptr = the_mesh
       return res_mesh

