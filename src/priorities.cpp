#include "priorities.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> 


priorities::priorities()
{
    int_itemCounter = 0;
}

priorities::~priorities()
{
}

void priorities::push(int int_id, std::string str_name, double d_cgpa)
{
    schueler schueler_newItem(int_id, str_name, d_cgpa);
    bool b_elementWasProcessed = false;

    std::list<schueler>::iterator iter;
    
    if (list_schuelerList.size() == 0) {
        list_schuelerList.push_front(schueler_newItem);
        this->int_itemCounter++;
    }
    else {
        for (iter = list_schuelerList.begin(); iter != list_schuelerList.end(); iter++)
        {

            if (iter->getID() == schueler_newItem.getID()) {
                throw std::invalid_argument{ "error: ID already exist" };
                b_elementWasProcessed = true;
                break;
            }

            else if (abs(iter->getCGPA() - schueler_newItem.getCGPA()) > 0.0001) {
                if (iter->getCGPA() < schueler_newItem.getCGPA()) {
                    list_schuelerList.insert(iter, schueler_newItem);
                    this->int_itemCounter++;
                    b_elementWasProcessed = true;
                    break;
                }
            }
            else if (iter->getName().compare(schueler_newItem.getName()) != 0) {
                if (iter->getName().compare(schueler_newItem.getName()) > 0) {
                    list_schuelerList.insert(iter, schueler_newItem);
                    this->int_itemCounter++;
                    b_elementWasProcessed = true;
                    break;
                }
            }
            else if (iter->getID() > schueler_newItem.getID()) {
                list_schuelerList.insert(iter, schueler_newItem);
                this->int_itemCounter++;
                b_elementWasProcessed = true;
                break;
            }

        }
        if (b_elementWasProcessed == false) {
            list_schuelerList.push_back(schueler_newItem);
            this->int_itemCounter++;
            b_elementWasProcessed = true;
        }
        
    }
}

void priorities::pop()
{
    list_schuelerList.pop_front();
    this->int_itemCounter--;
    return;
}

std::list<schueler> priorities::processEvents(std::list<std::string> events)
{

    std::list<std::string>::iterator iter;

    for (iter = events.begin(); iter != events.end(); iter++)
    {
        int int_idxEvent = iter->find_first_of(" ");
        std::string eventName = iter->substr(0, int_idxEvent);

        if (eventName.compare("ENTER") == 0) {
            if (this->int_itemCounter >= 1000) {
                throw std::length_error{ "error: priotriy que is full" };
            }

            std::string subStr = iter->substr(int_idxEvent, iter->back());
            std::vector<std::string> vec_eventParameter;

            std::istringstream iss_eventParameter(subStr); //create a string stream of the Event parameters
            for (; iss_eventParameter >> subStr; ) {
                vec_eventParameter.push_back(subStr);          //Seperate all event parameters
            }

            /* Check if parameter for the "Enter"-event are valid, skip the event if it cointains invalid parameters */

            if (vec_eventParameter.size() != 3) {
                std::cout << "error: invalid number of parameter for ENTER event || Given Input-Event: " << iter->data() << std::endl;
                continue;
            }

            bool b_invalidId = false; //indicates the detection of an invlaid ID parameter

            for (int i = 0; i < vec_eventParameter[2].size(); i++)
            {
                if (isdigit(vec_eventParameter[2][i]) == 0) {
                    std::cout << "error: invalid Id || Given Input-Event: " << iter->data() << std::endl;
                    b_invalidId = true;
                    break;
                }
            }

            if (b_invalidId == true) {
                continue;
            }

            if (vec_eventParameter[1].size() != 4) {
                std::cout << "error: invalid CGPA - wrong length || Given Input-Event: " << iter->data() << std::endl;
                continue;
            }
            else if ((isdigit(vec_eventParameter[1][0]) == 0) ||
                (vec_eventParameter[1][1] != '.') ||
                (isdigit(vec_eventParameter[1][2]) == 0) ||
                (isdigit(vec_eventParameter[1][3]) == 0)) {
                std::cout << "error: invalid CGPA || Given Input-Event: " << iter->data() << std::endl;
                continue;
            }

            /* Convert the input-string-parameter and push the data on the priority que */

            int int_id = std::stoi(vec_eventParameter[2]);
            double d_cgpa = std::stod(vec_eventParameter[1]);
            std::string str_name = vec_eventParameter[0];
            push(int_id, str_name, d_cgpa);

        }
        else if (eventName.compare("SERVED") == 0) {
            if (this->int_itemCounter > 0) {
                pop();
            }
            else {
                throw std::length_error{ "error: priotriy que is empty" };
            }
        }

        else {
            /* Skip the Event if its invalid */
            std::cout << "error: invalid Event  " << iter->data() << std::endl;
            continue;
        }

    }
    return this->list_schuelerList;
    
}