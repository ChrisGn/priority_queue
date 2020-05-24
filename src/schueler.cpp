#include "schueler.h"


schueler::schueler(const int int_id, const std::string str_name, const double d_cgpa)
{
    if (str_name.length() < 2) {
        throw std::length_error{ "error: string name is too short" };
    }
    else if (str_name.length() > 29) {
        throw std::length_error{ "error: string name is too long" };
    }
    else if (d_cgpa <= 0) {
        throw std::range_error{ "error: double cgpa is negative" };
    }
    else if (d_cgpa > 4.0) {
        throw std::range_error{ "error: double cgpa is bigger than 4.0" };
    }
    else if (int_id < 1) {
        throw std::range_error{ "error: int id is smaller than 1" };
    }
    else if (int_id > pow(10.0,5.0)) {
        throw std::range_error{ "error: int id is bigger than 10.0000" };
    }

    this->int_id = int_id;
    this->str_name = str_name;
    this->d_cgpa = d_cgpa;
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


bool operator==(const schueler &s1, const schueler &s2)
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
