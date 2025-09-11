// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"

using namespace std;

struct Node{
    Course course;
    Node* next;
};

class Student{
    public:
        int id;
        string name;
        double gpa;
        
        Node* courses;
        Student* next; // pointer to the next student

        Student();
        Student(int id, string name, double gpa);
        ~Student(); // I almost keep forgetting to add a destructor

        void addCourse(const string& courseName, const string& location);
        void displayCourses() const;
};

#endif