#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::cout;
using std::endl;
using std::stringstream;
using std::istream_iterator;
using std::map;
using std::set;
using std::unordered_set;

#ifndef _MESH_H_
#define _MESH_H_

class MESH{
 public:
  MESH();
  int nnodes;
  int nelems;
  vector<vector<double> > coords;
  vector<vector<int> > connec;
  vector<vector<string> > tags;
  vector<int> types; 
  map<string, vector<int> > groups_map;
  map<int, vector<int> > types_map;
  vector<string> getGroupsName();
  vector<int> getElemsInGroup(string);
  vector<int> getElem(int);
  vector<vector<double> > getCoords();
};


#endif 
