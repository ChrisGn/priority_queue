#ifndef SCHUELER_HPP
#define SCHUELER_HPP


#include <string>
#include <stdexcept>

/// <summary>
/// This class defines the item-type of the priority que
/// </summary>
class schueler
{
private:
    int int_id;           // Unique id of the item. Limits: 1 <= id <= pow(10,5)
    std::string str_name; // Name of the items:   Limits: 2 <= letter count <= 30
    double d_cgpa;        // Culmulative Grade Point Average of the items. Limits: 0 <= cgpa <= 4.00
 
public:	
    /// <summary>
    /// Constructor of the class
    /// </summary>
    /// <param name="id"> Unique id of the item. Limits: 1 <= id <= pow(10,5)    </param>
    /// <param name="name"> Name of the items:   Limits: 2 <= letter count <= 30 </param>
    /// <param name="cgpa">Culmulative Grade Point Average of the items. Limits: 0 <= cgpa <= 4.00 </param>
    /// <returns></returns>
    schueler(const int int_id, const std::string str_name, const double d_cgpa);
    ~schueler();

    int getID() const;
    std::string getName() const;
    double getCGPA() const;

    /// <summary>
    /// overload of the == operator. Compares the three private variables int_id, str_name, and d_cgpa with eachother
    /// </summary>
    /// <param name="s1"></param>
    /// <param name="s2"></param>
    /// <returns></returns>
    friend bool operator== (const schueler &s1, const schueler &s2);
};

#endif // SCHUELER_HPP