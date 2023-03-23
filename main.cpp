#include <iostream>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"
#include "LinkedList.h"
#include <vector>
#include <string> 
#include <algorithm>
#include <cctype>

using namespace std;

void removePunctuation(string &word){
  for(int  i = 0; i < word.size(); i++){
    if (islower(word[i])) {
      word[i] = toupper(word[i]);}
    if(!isalnum(word[i]) && word[i] != '-' && word[i] != '\''){
      word.erase(i,1);
      i--;
      }
    } 
  }


int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream out(am.get("output"));
  LinkedList list;
  ifstream iFile;
  string word;
  int count;
  
  //iFile.open("input2.txt");

  /*if(!iFile){

    out << "Unable to open file" << endl;
  }*/

  while(input >> word){
    
    removePunctuation(word);     
    bool search = false;
    search = list.Search(word);
    if(!search){
      list.AddAtHead(word);
      }
      list.Sorting();

    }
    list.Print(out);

    
  


  
  return 0;
  }