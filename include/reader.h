#include "mesh.h"


#ifndef _READER_H_
#define _READER_


class MSHReader{
 public:
  MSHReader(string mesh_file);
  void readMesh();
  void createGroupsMap();
  void createElemsMap();
  MESH* getMesh();
 private:
  string m_file;
  int nnodes, nelems;
  vector<vector<double> > coords;
  vector<vector<int> > connec;
  vector<vector<string> > tags;
  vector<int> types; 
  map<string, vector<int> > groups_map;
  map<int, vector<int> > types_map;
  void extractNodesInfo(ifstream&);
  void extractElemsInfo(ifstream&);
  vector<string> _split(string, string);
  vector<string> _split(string);
};


#endif 
