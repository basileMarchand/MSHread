#include "mesh.h"

#define VALPERLINE 100

MESH::MESH(){
}

vector<string> MESH::getGroupsName(){
  vector<string> keys(groups_map.size());
  int i=0;
  for (map<string, vector<int> >::iterator it = groups_map.begin(); it != groups_map.end(); it++)
    {
      keys[i] = it->first;
      i++;
    }
  return keys;
}

vector<int> MESH::getElemsInGroup(string grp_name){
  return this->groups_map[grp_name];
}

vector<int> MESH::getElem(int elem_id){
  return connec[elem_id];
}

vector<vector<double> > MESH::getCoords(){
  return coords;
}


