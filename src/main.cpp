/*

Project for application at codemanufaktur
Project: priority queue

*/

#include "schueler.h"
#include "priorities.h"

#include <iostream>
#include <conio.h>
#include <list>

int main() {
    try {
        schueler mySchueler(5, "b", 2);
    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << " Hello World" << std::endl;

    std::list<std::string> events;
    std::list<std::string>::iterator iter;

    iter = events.begin();
    events.insert(iter, "SERVED");
    events.insert(iter, "ENTER Peter 4.00 50");
    iter--;
    events.insert(iter, "ENTER Hans 3.00 40");

    int k = 0;
    schueler mySchueler1(5, "anton", 2);
    schueler mySchueler2(5, "anton", 2);
    if (mySchueler1 == mySchueler2) {
        k = 10;
    }


    std::list<schueler> listOfSchueler_manuel = { schueler(4, "Zorro",4.0),
                                    schueler(2, "Berta",3.5),
                                    schueler(3, "Claus",3.0),
                                    schueler(1,"Anton",1.0)
    };


    std::list<std::string> listOfEvents1 = { "ENTER Anton 1.0 1",
                                        "ENTER Berta 3.5 2",
                                        "ENTER Claus 3.0 3",
                                        "ENTER Zorro 4.0 4",
        // "SERVED",
        // "SERVED",
    };

    priorities myPrio1;

    std::list<schueler> listOfSchueler_generated = myPrio1.processEvents(listOfEvents1);

    std::list<schueler> listOfSchueler = { schueler(22, "Sido",3.8),
                                        schueler(3, "Lauren",3),
                                        schueler(43, "Riti",1),
                                        schueler(30,"Angel",1.5),
                                        schueler(2, "Laura",3.5)
                                        };


    std::list<std::string> listOfEvents = { "ENTER David 3.0 50",
                                        "ENTER Carl 4.0 49",
                                        "ENTER Peter 1.0 48",
                                        "ENTER David 3.0 47",
                                       // "SERVED",
                                       // "SERVED",
    };

    priorities myPrio;
    listOfSchueler = myPrio.processEvents(listOfEvents);


    schueler newSchueler(2, "Lauren", 3);

    //Create an iterator of std::list
    std::list<schueler>::iterator it;
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (it = listOfSchueler.begin(); it != listOfSchueler.end(); it++)
    {
        if (abs(it->getCGPA() - newSchueler.getCGPA() > 0.0001)) {
            if (it->getCGPA() < newSchueler.getCGPA()) {
                listOfSchueler.insert(it, newSchueler);
                break;
            }
        }
        else if (it->getName().compare(newSchueler.getName()) != 0) {
            if (it->getName().compare(newSchueler.getName()) > 0) {
                listOfSchueler.insert(it, newSchueler);
                break;
            }
        }
        else if (it->getID() > newSchueler.getID()) {
                listOfSchueler.insert(it, newSchueler);
                break;            
        }
    }



    getch();
}
