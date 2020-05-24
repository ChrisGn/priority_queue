#pragma once
#include <stdexcept>


class schueler
{
private:
    int int_id;
    std::string str_name;
    double d_cgpa;
 
public:	
    schueler();
    schueler(int id, std::string name, double cgpa);
    ~schueler();

    int getID() const;
    std::string getName() const;
    double getCGPA() const;

    //Overload operatos
    friend bool operator == (const schueler& s1, const schueler& s2);
};
