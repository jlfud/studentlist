#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;
//student struct
struct Student{
  char firstname[15];
  char lastname[15];
  int id;
  double gpa;
};
//function prototypes
void print(vector<Student*> students);
Student* add();
void deleteStudent(vector<Student*> &students);

int main(){
  vector<Student*> students;
  char in[15];

  cout << "student list. Commands: print, add, delete, quit" << endl;
  //until the user quits, keep on running
  while(true){
    cout << "input a command: " << endl;
    cin >> in;
    if(strcmp(in,"print") == 0){
      print(students);
      //call the print function to print out the vector
    }
    else if(strcmp(in, "add") == 0){
      students.push_back(add());
    }
    else if(strcmp(in, "delete") == 0){
      deleteStudent(students);
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
void print(vector<Student*> students){
  //print out all students in the vector
  if(students.size() == 0){
    cout << "no students!" << endl;
  }
  for(int i = 0; i < students.size(); i++){
    cout << students[i]->firstname << " ";
    cout << students[i]->lastname << ", ";
    cout << students[i]->id << ", ";
    cout << fixed << setprecision(2) << students[i]->gpa << endl;
  }
}
Student* add(){
  //add a student
  Student* newStudent = new Student;
  //initialize a new student, then get names, id, and gpa
  //return the student so we can push_back on the vector
  cout << "Student first name: " << endl;
  cin >> newStudent->firstname;
  cout << "Student last name: " << endl;
  cin >> newStudent->lastname;
  cout << "Student ID: " << endl;
  cin >> newStudent->id;
  cout << "Student GPA: " << endl;
  cin >> newStudent->gpa;
  cout << "student added." << endl;
  return newStudent;
  
}
void deleteStudent(vector<Student*> &students){
  int toremove;
  bool tobreak = false; //for the while looop
  cout << "what is the id of the student you would like to remove? " << endl;
  while(true){
    cin >> toremove; //get the id to remove
    for(int i = 0; i < students.size(); i++){
      if(students[i]->id == toremove){
	toremove = i;
	tobreak = true; //if it's in the vector, we're good
	break;
      }
    }
    if(tobreak){
      break; //to break out of the while loop
    }
    cout << "invalid id, try again: " << endl; //otherwise, it's invalid
  }
  cout << students[toremove]->firstname << " was removed" << endl; //indicate which student was removed
  delete students[toremove];
  students.erase(students.begin() + toremove); //remove the student
}
