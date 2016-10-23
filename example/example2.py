
import sys
sys.path.insert(0, "../build")

from py_mesh import pyMSHReader

reader = pyMSHReader("mesh_ex.msh")
reader.readMesh()
reader.createGroupsMap()
reader.createElemsMap()

the_mesh = reader.getMesh()


groups = the_mesh.getGroupsName()

print("Defined groups : {}".format("; ".join(groups)))
