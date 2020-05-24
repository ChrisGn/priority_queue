/*

Project for application at codemanufaktur
Project: priority queue

*/

#include "schueler.h"
#include "priorities.h"

#include <iostream>
#include <list>
#include <string>

int main() {
    bool b_quit = false;                         //determines when to quit the program
    std::string str_in;                          //Input String from console
    std::list<std::string> listStr_events;       //List with events to modify the priority que
    std::list<schueler> listSchueler_schueler;   //priority que
    priorities prio_myPrio;                      //Object to handle the priority que

    while (b_quit == false)
    {       
        std::cout << "Please enter an event: \n"
            "ENTER Name GCPA ID \t -> Example: ENTER John 3.75 50 -> Insert the item to the priority que \n"
            "SERVED \t\t\t -> Remove the item with the highest prioritie from the que \n"
            "PRINT \t\t\t -> Print the items of the que \n"
            "QUIT \t\t\t -> Close the program \n" << std::endl;
        std::getline(std::cin,str_in);

        int int_idxStrIn = str_in.find_first_of(" ");

        std::string str_eventName = str_in.substr(0, int_idxStrIn);

        if ((str_eventName.compare("ENTER") == 0) || str_eventName.compare("SERVED") == 0) {

            listStr_events.push_front(str_in);
            try {
                listSchueler_schueler = prio_myPrio.processEvents(listStr_events);
            }
            catch (std::exception e) {
                std::cout << e.what() << std::endl;
            }
        }

        else if (str_eventName.compare("PRINT") == 0) {

            if (listSchueler_schueler.size() == 0) {
                std::cout << "LEER" << std::endl;
            }

            std::list<schueler>::iterator iter;
            for (iter = listSchueler_schueler.begin(); iter != listSchueler_schueler.end(); iter++) {
                std::cout << "Name: " << iter->getName() << " CGPA: " << iter->getCGPA() << " ID: " << iter->getID() << std::endl;
            }
        }

        else if (str_eventName.compare("QUIT") == 0) {
            b_quit = true;
        }

        else {
            std::cout << "error: invalid Event"<< std::endl;
        }

        std::cout << "\n" << std::endl;
        str_in.clear();
        listStr_events.clear();
    }    
}
