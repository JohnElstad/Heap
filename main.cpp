#include <iostream>
#include "Heap.h"
#include <fstream>
//John Elstad: Heap/ mid-March
using namespace std;
void toLower(char* a);
void configureInput(ifstream &stream, bool &isFile);
void addNumbers(istream &from, Heap* heap);
// main loop
int main(){
  cout<<"Welcome to the Heap!\n Quit, ADD, TREE and OUTPUT are valid commands"<<endl;
  Heap heap;
  char input[128];
  bool running = true;
  
  while(running){
    cin.getline(input,128);
    toLower(input);
    if(input[0] == 'a'){
      ifstream stream;
      bool isFile;
      configureInput(stream, isFile);
      addNumbers(isFile ? stream : cin, &heap);
      if(isFile){
	stream.close();
      }
      cin.ignore();

    }
    else if(input[0] == 'o'){
      while(heap.getCount()>0){
	cout << heap.pop() << " ";
      }
      cout <<endl;
    }
    else if(input[0] == 't'){
      heap.print(0,0);
    }
    else if(input[0] == 'q'){
      running = false;
    }
    else{
      cout<<"The possible commands are QUIT, ADD, TREE and OUTPUT"<<endl;
    }    


  }


}

void toLower(char* a){//simply makes everything lowercase.
  while(*a){
    *a = tolower(*a);
    a++;//adds the pointer
  }
}
//deals with the inputs. File and console
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
//adds the numbers/
void addNumbers(istream &from, Heap* heap){
  int newInput;
  from >> newInput;
  heap->add(newInput);
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){
      from>>newInput;
      heap->add(newInput);
    }
    else{
      from.ignore();
    }
  }
}


