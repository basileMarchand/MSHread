#include "reader.h"


MSHReader::MSHReader(string mesh_file){
  m_file = mesh_file;
}

void MSHReader::readMesh(){
  int nnodes;
  int nelems;
  /*
  vector<vector<double> > coords;
  vector<vector<int> > connec;
  vector<vector<string> > tags;
  vector<int> types; 
  */
  ifstream fid;
  fid.open(this->m_file);
  if(fid.is_open()){
    cout << "File " << this->m_file << " successfuly open" << endl;
    string line;
    while ( getline(fid,line) ){
      //cout << line << endl;
      if (line == "$Nodes"){
	cout << "Read nodes section" << endl;
	this->extractNodesInfo(fid);
      }
      else if (line == "$Elements"){
	cout << "Read elements section" << endl;
	this->extractElemsInfo(fid);
      }
    }
    fid.close();
  }
  else{
    cout << "Error --- file " << this->m_file << "not open" << endl;
    exit(1);
  }
}

void MSHReader::extractNodesInfo(ifstream& fid){
  string line;
  vector<string> linevec;
  getline(fid,line);
  nnodes = stoi(line);
  cout << "Number of Nodes : " << nnodes << endl;
  this->coords.resize(nnodes);
  getline(fid, line);
  int n=0;
  while( line != "$EndNodes"){
    linevec = this->_split(line) ;
    coords[n].resize(3);
    for(int i=0; i<3; i++){
      this->coords[n][i] = stod(linevec[i+1]);
    }
    n++;
    getline(fid,line);
  }  
}

void MSHReader::extractElemsInfo(ifstream& fid){
  string line;
  int nperelem, n_tags;
  int e=0;
  vector<string> linevec;
  getline(fid,line);
  this->nelems = stoi(line);
  this->connec.resize(nelems);
  this->types.resize(nelems);
  this->tags.resize(nelems);
  cout << "Number of Elements : " << nelems << endl;
  getline(fid, line);
  while( line != "$EndElements"){
    linevec = this->_split(line) ;
    n_tags = stoi(linevec[2]);
    this->tags[e].resize(n_tags);
    // Extract elem type
    this->types[e] = stoi(linevec[1]);
    // Extract tags associated to element e
    for(int j=0; j<n_tags; j++){
      this->tags[e][j] = linevec[3+j];
    }
    nperelem = linevec.size()-(3 + n_tags);
    this->connec[e].resize(nperelem);
    for(int i=0; i<nperelem; i++){
      this->connec[e][i] = stoi(linevec[5+i])-1;
    }
    e++;
    getline(fid,line);
  }
}

void MSHReader::createGroupsMap(){
  cout << "Create the map of defined groups" << endl;
  // First extract list of existing groups
  unordered_set<string> groups_set;
  for(int i=0; i<tags.size(); i++){
    groups_set.insert(tags[i][0]);
  }
  for(int i=0; i<tags.size(); i++){
    groups_map[tags[i][0]].push_back(i);
  }
}

void MSHReader::createElemsMap(){
  cout << "Create the map of used elements types" << endl;
  // First extract list of existing elements
  unordered_set<int> elems_set;
  for(int i=0; i<types.size(); i++){
    elems_set.insert(types[i]);
  }
  for(int i=0; i<tags.size(); i++){
    types_map[types[i]].push_back(i);
  }
}

vector<string> MSHReader::_split(string line){
  stringstream sline(line);
  istream_iterator<string> begin(sline);
  istream_iterator<string> end;
  vector<string> vec(begin, end);
 return vec;
}

MESH* MSHReader::getMesh(){
  MESH* mesh = new MESH();
  mesh->nnodes = this->nnodes;
  mesh->nelems = this->nelems;
  mesh->coords = this->coords;
  mesh->connec = this->connec;
  mesh->tags   = this->tags;
  mesh->types  = this->types;
  mesh->groups_map = this->groups_map;
  mesh->types_map = this->types_map;
  return mesh;
}
