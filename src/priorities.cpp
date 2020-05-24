/*

*/


#include "priorities.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> 

priorities::priorities()
{
}

priorities::~priorities()
{
}

bool priorities::checkEvents(std::list<std::string> events)
{
    return false;
}

void priorities::push(int id, std::string name, double cgpa)
{
    schueler newSchueler(id, name, cgpa);
    bool elementWasProcessed = false;

    //Create an iterator of std::list
    std::list<schueler>::iterator iter;
    
    if (list_schuelerList.size() == 0) {
        list_schuelerList.push_front(newSchueler);
    }
    else {
        for (iter = list_schuelerList.begin(); iter != list_schuelerList.end(); iter++)
        {

            if (iter->getID() == newSchueler.getID()) {
                throw std::invalid_argument{ "error: ID already exist" };
                elementWasProcessed = true;
                break;
            }

            else if (abs(iter->getCGPA() - newSchueler.getCGPA()) > 0.0001) {
                if (iter->getCGPA() < newSchueler.getCGPA()) {
                    list_schuelerList.insert(iter, newSchueler);
                    elementWasProcessed = true;
                    break;
                }
            }
            else if (iter->getName().compare(newSchueler.getName()) != 0) {
                if (iter->getName().compare(newSchueler.getName()) > 0) {
                    list_schuelerList.insert(iter, newSchueler);
                    elementWasProcessed = true;
                    break;
                }
            }
            else if (iter->getID() > newSchueler.getID()) {
                list_schuelerList.insert(iter, newSchueler);
                elementWasProcessed = true;
                break;
            }

        }
        if (elementWasProcessed == false) {
            list_schuelerList.push_back(newSchueler);
        }
        
    }
}

void priorities::pop()
{
    list_schuelerList.pop_front();
    return;
}

std::list<schueler> priorities::getSchuelerList()
{
    return std::list<schueler>();
}

std::list<schueler> priorities::processEvents(std::list<std::string> events)
{

    std::list<std::string>::iterator iter;

    for (iter = events.begin(); iter != events.end(); iter++)
    {
        try {
            int idxEvent = iter->find_first_of(" ");
            std::string eventName = iter->substr(0, idxEvent);

            if (eventName.compare("ENTER") == 0) {
                std::string subStr = iter->substr(idxEvent, iter->back());
                std::vector<std::string> vec_NameGcpaId;

                std::istringstream iss(subStr);
                for (; iss >> subStr; )
                    vec_NameGcpaId.push_back(subStr);

                if (vec_NameGcpaId.size() != 3) {
                    throw std::invalid_argument{ "error: invalid number of parameter for ENTER event" };
                }

                int int_id = std::stoi(vec_NameGcpaId[2]);
                double d_cgpa = std::stod(vec_NameGcpaId[1]);
                std::string str_name = vec_NameGcpaId[0];
                push(int_id, str_name, d_cgpa);

            }
            else if (eventName.compare("SERVED") == 0) {
                pop();
            }

            else {
                throw std::invalid_argument{ "error: invalid Event" };
            }


        }
        catch (std::invalid_argument e) {
            std::cout << e.what() << std::endl;
        }
    }
    return this->list_schuelerList;
    
}