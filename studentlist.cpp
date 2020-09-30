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
Student* add();
void deleteStudent(vector<Student*> &students);

int main(){
  vector<Student*> students;
  char in[15];

  cout << "student list. Commands: print, add, delete, quit" << endl;

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
//add, print, delete
void print(vector<Student*> students){
  for(int i = 0; i < students.size(); i++){
    cout << students[i]->firstname << " ";
    cout << students[i]->lastname << ", ";
    cout << students[i]->id << ", ";
    cout << students[i]->gpa << endl;
  }
}
Student* add(){
  //add a student
  Student* newStudent = new Student;
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
  bool tobreak = false;
  cout << "what is the id of the student you would like to remove? " << endl;
  while(true){
    cin >> toremove;
    for(int i = 0; i < students.size(); i++){
      if(students[i]->id == toremove){
	toremove = i;
	tobreak = true;
	break;
      }
    }
    if(tobreak){
      break;
    }
    cout << "invalid id, try again: " << endl;
  }
  cout << students[toremove]->firstname << "was removed" << endl;
  students.erase(students.begin() + toremove);
}
