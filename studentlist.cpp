#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
struct Student{
  char firstname[15];
  char lastname[15];
  int id;
  double gpa;
};
void print(vector<Student*> students);
void add(vector<Student*> &students, Student* toAdd);
void deleteStudent(vector<Student*> &students, int toDelete);

int main(){
  vector<Student*> students;
  char in[15];

  cout << "student list. Commands: print, add, delete, quit" << endl;

  while(true){
    cout << "input a command: " << endl;
    cin >> in;
    if(strcmp(in,"print") == 0){
      cout << "print" << endl;
      //call the print function to print out the vector
    }
    else if(strcmp(in, "add") == 0){
      cout << "add" << endl;
      //prompt user for name, id, and gpa
      //then, call function to add the student
    }
    else if(strcmp(in, "delete") == 0){
      cout << "delete" << endl;
      //while true loop, prompt for id, if not in vector, redo loop
      //otherwise, call delete function
    }
    else if(strcmp(in, "quit") == 0){
      cout << "bye!" << endl;
      return 0;
    }
    else{
      cout << "unknown input, please try again." << endl;
    }
  }
  return 0;
}
//add, print, delete
void print(vector<Student*> students){
  //print the vector
}
void add(vector<Student*> &students, Student* student){
  //add a student
}
void deleteStudent(vector<Student*> &students, int toDelete){
  //delete a student by id
}
