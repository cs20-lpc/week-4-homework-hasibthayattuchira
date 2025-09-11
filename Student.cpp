// TODO:  Student class methods implementation here.
#include "Student.hpp"
#include <iostream>

Student::Student(){
    id = 0;
    name = "";
    gpa = 0.0;
    courses = nullptr;
    next = nullptr;
}

Student::Student(int id, string name, double gpa){
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->courses = nullptr;
    this->next = nullptr;
    
}

void Student::addCourse(const string& courseName, const string& location){
    Node* newNode = new Node;
    newNode->course = Course(courseName, location);
    newNode->next = nullptr;

    if(courses == nullptr){
        courses = newNode;
    }
    else {
        Node* temp = courses;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Student::displayCourses() const{
    if(courses == nullptr){
        cout << "No courses to show." << endl;
        return;
    }
    Node* temp = courses;
    while(temp != nullptr){
        cout << temp->course.name << " " << temp->course.location << endl;
        temp = temp->next;
    }
}

Student::~Student(){
    Node* temp = courses;
    while(temp != nullptr){
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete; // prevents memory leak now
    }
}