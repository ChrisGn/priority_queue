//#include "..\include\schueler.h"
//#include "..\include\schueler.h"
//#include "..\include\schueler.h"
/*


*/

#include "schueler.h"
#include <string>

schueler::schueler(int id, std::string name, double cgpa)
{
    if (name.length() < 2) {
        throw std::length_error{ "error: string name is too short" };
    }
    else if (name.length() > 29) {
        throw std::length_error{ "error: string name is too long" };
    }
    else if (cgpa <= 0) {
        throw std::range_error{ "error: double cgpa is negative" };
    }
    else if (cgpa > 4.0) {
        throw std::range_error{ "error: double cgpa is bigger than 4.0" };
    }
    else if (id < 1) {
        throw std::range_error{ "error: int id is smaller than 1" };
    }
    else if (id > pow(10.0,5.0)) {
        throw std::range_error{ "error: int id is bigger than 10.0000" };
    }

    int_id = id;
    str_name = name;
    d_cgpa = cgpa;
}


schueler::~schueler()
{
    // statement
}

int schueler::getID() const
{
    return this->int_id;
}

std::string schueler::getName() const
{
    return this->str_name;
}

double schueler::getCGPA() const
{
    return this->d_cgpa;
}


bool operator==(const schueler& s1, const schueler& s2)
{
    if ( (s1.getID() == s2.getID()) && 
        (abs(s1.getCGPA() - s2.getCGPA()) < 0.0001) && 
        (s1.getName().compare(s2.getName()) == 0)) {
        return true;
    }
    else {
        return false;
    }
}


