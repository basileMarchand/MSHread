#include "mesh.h"
#include "reader.h"

using std::cout;
using std::endl;


int main(){
  string msh_file = "mesh_ex.msh";
  MSHReader* reader = new MSHReader(msh_file);
  reader->readMesh();
  reader->createGroupsMap();
  reader->createElemsMap();
  MESH* the_mesh;
  the_mesh = reader->getMesh();

  cout << "Mesh nn = " << the_mesh->nnodes << endl;
  cout << "Mesh ne = " << the_mesh->nelems << endl;

  vector<string> groups = the_mesh->getGroupsName();
  for(int i=0; i<groups.size(); i++){
    cout << groups[i] << endl;
  }
  
} 



