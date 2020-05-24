#include "priorities.h"
#include "schueler.h"
#include "gtest/gtest.h"
#include <string>
#include <list>


TEST(processEventsTest1, invalidEvent) {

    std::list<schueler> listOfSchueler_manuel = { schueler(4, "Zorro",4.0),
                                        schueler(2, "Berta",3.5),
                                        schueler(3, "Claus",3.0),
                                        schueler(1,"Anton",1.0)  
    };


    std::list<std::string> listOfEvents = { "ENTER Anton 1.0 1",
                                        "ENTER Berta 3.5 2",
                                        "ENTER Claus 3.0 3",
                                        "ENTER Zorro 4.0 4",
        // "SERVED",
        // "SERVED",
    };

    priorities myPrio;

    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);

    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
	//EXPECT_THROW(schueler mySchueler(id, name, cgpa); , std::length_error);
}