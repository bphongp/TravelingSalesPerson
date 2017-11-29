//Bamphiane Annie Phongphouthai
//bp8qg
//Nov 26, 2017
//topological.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//node in graph that has fields
class node{
public:
  node(string temp);//sets the temp as the name of the node when creating node
  string name; //holds the name of the node
  vector<node*> listAdj; //vector to hold nodes adjacent to the current
  void addNode(node* n);//adds a node adjacent 
  int inDegree;//indegree of the node
};

vector<node*> listNode;
node::node(string temp){ //constructor
  name=temp;
  inDegree=0;
}
void node:: addNode(node* n){ //add node
  listAdj.push_back(n);
}
void topological();

int main(int argc, char **argv){
  if (argc != 2){
    cout<< "Must supply the input file name as the one and only parameter"<< endl;
    return 1;
  }
  ifstream file(argv[1], ifstream::binary);// try opening

  if(!file.is_open()){
    cout<< "Unable to open file '"<< argv[1]<<"'."<<endl;
    return 1;
  }

  while(file.good()){
    string s1, s2;
    bool check1, check2 = false;
    int i, j =0;
    file >> s1;
    file >> s2;
    
    if(s1=="0" && s2=="0"){
      break;
    }

    for(int k=0; k< listNode.size(); k++){
      if(listNode[k]->name==s1){
	i=k;
	check1=true;
      }
    }
    if(check1==false){
      node* tempNode= new node(s1);
      listNode.push_back(tempNode);
      i=listNode.size()-1;
    }

    for(int k=0; k< listNode.size(); k++){
      if(listNode[k]->name==s2){
	j=k;
	check2=true;
      }
    }
    
    if(check2==false){
      node* otherNode = new node(s2);
      listNode.push_back(otherNode);
      j=listNode.size()-1;
    }

    listNode[j]->inDegree++;
    listNode[i]->addNode(listNode[j]);//add s2 to s1
  }//end while

  topological();
  file.close();
}

void topological(){
  queue<node*> q;
  node *temp1;
  node *temp2;

  for(int i=0; i<listNode.size(); i++){
    temp1= listNode[i];
    if(temp1->inDegree==0)
      q.push(temp1);
  }

  while(!q.empty()){
    temp1=q.front();
    q.pop();
    cout<<temp1->name<<" ";
    for(int j=0; j< temp1->listAdj.size(); j++){
      temp2= temp1->listAdj[j];
      temp2->inDegree--;

      if(temp2->inDegree==0)
	q.push(temp2);
    }
  }
  cout<<endl;
}
