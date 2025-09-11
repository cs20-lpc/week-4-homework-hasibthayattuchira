// TODO:  Course class methods implementation here.
#include "Course.hpp"

// constructor
Course::Course(){
    name = "";
    location = ""; 
}

Course::Course(string name, string location){
    this->name = name;
    this->location = location;
}