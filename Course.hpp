// TODO:  Course class definitions go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

using namespace std;

class Course{
    public:
        string name;
        string location;

    Course();
    Course(string name, string location);
};

#endif