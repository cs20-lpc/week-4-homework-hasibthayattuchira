#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

Student* head = nullptr;

// prototypes
void insertStudent(int, const string&, double);
void displayStudents();
Student* findStudent(int);
void deleteStudent(int);
int countStudents();


int main()
{
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
    int choice;

    do{
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Student Count" << endl;
        cout << "6. Add Course" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;

        if(choice == 1){
            int id;
            string name;
            double gpa;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            insertStudent(id, name, gpa);
        }
        else if(choice == 2){
            int id;

            cout << "To delete, enter ID: ";
            cin >> id;

            deleteStudent(id);
        }
        else if(choice == 3){
            int id;

            cout << "To search, enter ID: ";
            cin >> id;

            Student* student = findStudent(id);
            if(student != nullptr){
                cout << "Found: " << student->id << " " << student->name << " " << student->gpa << endl;
                student->displayCourses();
            }
            else {
                cout << "Student does not exist." << endl;
            }
        }    
        else if(choice == 4){
            displayStudents();
        }
        else if(choice == 5){
            cout << "Total students: " << countStudents() << endl;
        }
        else if(choice == 6){
            int id;
            string courseName, courseLocation;

            cout << "To enter course, enter ID: ";
            cin >> id;
            cin.ignore();

            Student* student = findStudent(id);
            if(student != nullptr){
                cout << "Enter course name: ";
                getline(cin, courseName);
                cout << "Enter location: ";
                getline(cin, courseLocation);
                student->addCourse(courseName, courseLocation);
            }
            else {
                cout << "Student does not exist." << endl;
            }    
        }
    } while (choice != 7);

    while(head != nullptr){
        Student* toDelete = head;
        head = head->next;
        delete toDelete; // fully clears up memory by calling destructor
    }

    // terminate
    return 0;
}

void insertStudent(int id, const string& name, double gpa){
    Student* newStudent = new Student(id, name, gpa);
    newStudent->next = nullptr;

    if(head == nullptr){
        head = newStudent;
    }
    else {
        Student* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void displayStudents(){
    if(head == nullptr){
        cout << "No students stored in list." << endl;
        return;
    }
    Student* temp = head;
    while(temp != nullptr){
        cout << temp->id << " " << temp->name << " " << temp->gpa << endl;
        temp->displayCourses();
        temp = temp->next;
    }
}

Student* findStudent(int id){
    Student* temp = head;
    while(temp != nullptr){
        if(temp->id == id){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void deleteStudent(int id){
    if(head == nullptr){
        return;
    }
    if(head-> id == id){
        Student* temp = head;
        head = head->next;

        Node* course = temp->courses;
        while(course != nullptr) {
            Node* toDelete = course;
            course = course->next;
            delete toDelete;
        }
        delete temp;
        cout << "Deleted student, " << id << endl;
        return;
    }

    Student* temp = head;
    while(temp-> next != nullptr && temp->next->id != id){
        temp = temp->next;
    }
    if(temp->next != nullptr){
        Student* toDelete = temp->next;
        temp->next = temp->next->next;

        Node* course = toDelete->courses;
        while(course != nullptr){
            Node* nextCourse = course->next;
            delete course;
            course = nextCourse;
        }
        delete toDelete;
        cout << "Deleted student with id, " << id << endl;
    } else {
        cout << "Student does not exist" << endl;
    }
}

int countStudents(){
    int count = 0;
    Student* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}