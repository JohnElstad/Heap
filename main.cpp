#include <iostream>
#include "Heap.h"
#include <fstream>

using namespace std;
void toLower(char* a);

int main(){
  cout<<"Welcome to the Heap!"<<endl;
  

}

void toLower(char* a){//simply makes everything lowercase.
  while(*a){
    *a = tolower(*a);
    a++;//adds the pointer
  }
}

void configureInput(ifstream &stream, bool &isFile){
  char input[128];
  isFile = false;

  cout<<"Choose to Input from a file or console. Enter f or c"<<endl;
  cin.getline(input,128);
  

  if(input[0] == 'f'){
    cout<<"What file?"<<endl;
    cin.getline(input,128);
    stream.open(input);
    
    if(stream.is_open()){
      isFile = true;
    }
    else{
      cout<<"Was not able to open the file. Instead enter by command line"<<endl;
    }
  }
  else{
    cout<<"Enter it by command line"<<endl;
  }
}
void addNumbers(istream &from, Heap* heap){
  int newInput;
  from >> newInput;
  heap->add(newInput);
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){

    }
  }

}

