#include "priorities.h"
#include "schueler.h"
#include "gtest/gtest.h"
#include <string>
#include <list>


TEST(processEventsTest1, validEnterEvents) {
    /* four different schueler with different cgpa, id */
    std::list<schueler> listOfSchueler_manuel = { schueler(4, "Zorro",4.00),
                                        schueler(2, "Berta",3.50),
                                        schueler(3, "Claus",3.00),
                                        schueler(1,"Anton",1.00)  
                                        };


    std::list<std::string> listOfEvents = { "ENTER Anton 1.00 1",
                                        "ENTER Berta 3.50 2",
                                        "ENTER Claus 3.00 3",
                                        "ENTER Zorro 4.00 4",
                                        };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);	
}

TEST(processEventsTest2, invalidEnterEvent) {
    /* 3 vaild enter events, one enter event with invalid cgpa */
    std::list<schueler> listOfSchueler_manuel = { schueler(4, "Zorro",4.00),  
                                        schueler(3, "Claus",3.00),
                                        schueler(1,"Anton",1.00)
    };


    std::list<std::string> listOfEvents = { "ENTER Anton 1.00 1",
                                        "ENTER Berta aa3.50 2",
                                        "ENTER Claus 3.00 3",
                                        "ENTER Zorro 4.00 4",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}


TEST(processEventsTest3, invalidEnterEvent) {
    /* 3 vaild enter events, one enter event with invalid id */
    std::list<schueler> listOfSchueler_manuel = { schueler(2, "Berta",3.50),
                                        schueler(3, "Claus",3.00),
                                        schueler(1,"Anton",1.00)
                                        };


    std::list<std::string> listOfEvents = { "ENTER Anton 1.00 1",
                                        "ENTER Berta 3.50 2",
                                        "ENTER Claus 3.00 3",
                                        "ENTER Zorro 4.00 aa4",
                                        };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}

TEST(processEventsTest4, validEnterEvent) {
    /* four different schueler with different cgpa, id */
    std::list<schueler> listOfSchueler_manuel = { schueler(4, "Zorro",4.00),
                                        schueler(2, "Berta",3.50),
                                        schueler(3, "Claus",3.00),
                                        schueler(1,"Anton",1.00)
    };


    std::list<std::string> listOfEvents = { "ENTER Anton 1.00 1",
                                        "ENTER Berta 3.50 2",
                                        "ENTER Claus 3.00 3",
                                        "ENTER Zorro 4.00 4",
    };

    priorities myPrio;
  
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}

TEST(processEventsTest5, invalidEnterEvent) {
    /* four invalid events */
    std::list<std::string> listOfEvents = { "ENTERAA Anton 1.00 1",
                                        "kskjkjsrir",
                                        "878954422121",
                                        "ENTER00112 Zorroddd 4.00 4sssss",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated;
    ASSERT_NO_THROW(listOfSchueler_generated = myPrio.processEvents(listOfEvents));
    EXPECT_EQ(listOfSchueler_generated.size(), 0);
}

TEST(processEventsTest6, validEnterEvents) {
    /* input with four diffent event-lists: four different schueler with different cgpa, id */
    std::list<schueler> listOfSchueler_manuel = { schueler(4, "Zorro",4.00),
                                        schueler(2, "Berta",3.50),
                                        schueler(3, "Claus",3.00),
                                        schueler(1,"Anton",1.00)
    };


    std::list<std::string> listOfEvents1 = { "ENTER Anton 1.00 1" };
    std::list<std::string> listOfEvents2 = { "ENTER Berta 3.50 2" };
    std::list<std::string> listOfEvents3 = { "ENTER Claus 3.00 3" };
    std::list<std::string> listOfEvents4 = { "ENTER Zorro 4.00 4" };


    priorities myPrio;  

    myPrio.processEvents(listOfEvents1);
    myPrio.processEvents(listOfEvents2);
    myPrio.processEvents(listOfEvents3);
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents4);

    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}

TEST(processEventsTest7, lowerBoundaryQue) {
    /* lower boundery of priority que -> pop of empty que */
    std::list<std::string> listOfEvents = { "SERVED" };
    priorities myPrio;
    EXPECT_THROW(std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents), std::length_error);
}

TEST(processEventsTest7, upperBoundaryQue) {
    /* upper boundery of priority que -> 1000 items */
    std::list<std::string> listOfEvents;
    std::string s;
    for (int i = 1; i <= 1000; i++) {
        s = "ENTER Anton 2.00 " + std::to_string(i);
        listOfEvents.push_back(s);
    }

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated;
    ASSERT_NO_THROW(listOfSchueler_generated = myPrio.processEvents(listOfEvents));
    EXPECT_EQ(listOfSchueler_generated.size(), 1000);
}

TEST(processEventsTest8, upperBoundaryQue) {
    /* upper boundery of priority que -> exceed the upper boundary by one */
    std::list<std::string> listOfEvents;
    std::string s;
    for (int i = 1; i <= 1001; i++) {
        s = "ENTER Anton 2.00 " + std::to_string(i);
        listOfEvents.push_back(s);
    }

    priorities myPrio;
    ASSERT_THROW(std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents), std::length_error);
}


TEST(processEventsTest9, SERVED_Event) {
    /* fill the que with four items than serve 1 item, than serve 2 items*/
    std::list<schueler> listOfSchueler_manuel1 = { schueler(4, "Zorro",4.00),
                                        schueler(2, "Berta",3.50),
                                        schueler(3, "Claus",3.00),
                                        schueler(1,"Anton",1.00)
    };

    std::list<schueler> listOfSchueler_manuel2 = { schueler(2, "Berta",3.50),
                                    schueler(3, "Claus",3.00),
                                    schueler(1,"Anton",1.00)
    };

    std::list<schueler> listOfSchueler_manuel3 = { schueler(1,"Anton",1.00) }; 

    std::list<std::string> listOfEvents1 = { "ENTER Anton 1.00 1",
                                        "ENTER Berta 3.50 2",
                                        "ENTER Claus 3.00 3",
                                        "ENTER Zorro 4.00 4",
    };

    std::list<std::string> listOfEvents2 = { "SERVED" };

    std::list<std::string> listOfEvents3 = { "SERVED",
                                        "SERVED",
    };
    
    priorities myPrio;
    std::list<schueler> listOfSchueler_generated1;
    std::list<schueler> listOfSchueler_generated2;
    std::list<schueler> listOfSchueler_generated3;

    listOfSchueler_generated1 = myPrio.processEvents(listOfEvents1);
    EXPECT_EQ(listOfSchueler_manuel1, listOfSchueler_generated1);

    listOfSchueler_generated2 = myPrio.processEvents(listOfEvents2);
    EXPECT_EQ(listOfSchueler_manuel2, listOfSchueler_generated2);

    listOfSchueler_generated3 = myPrio.processEvents(listOfEvents3);
    EXPECT_EQ(listOfSchueler_manuel3, listOfSchueler_generated3);
}

TEST(processEventsTest10, SERVED_Event) {
    /* one list of events: 3 enter -> 1 serve -> 1 enter */
    std::list<schueler> listOfSchueler_manuel = { schueler(3, "Claus",2.70),
                                        schueler(1, "Anton",2.50),
                                        schueler(4,"Zorro",1.30)
    };


    std::list<std::string> listOfEvents = { "ENTER Anton 2.50 1",
                                        "ENTER Berta 3.90 2",
                                        "ENTER Claus 2.70 3",
                                        "SERVED",
                                        "ENTER Zorro 1.30 4",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}

TEST(processEventsTest11, SERVED_Event) {
    /* enter four items, serve them all */
    std::list<schueler> listOfSchueler_manuel1 = { schueler(2, "Berta",3.90),
                                        schueler(3, "Claus",2.70),
                                        schueler(1, "Anton",2.50),
                                        schueler(4,"Zorro",1.30)
    };


    std::list<std::string> listOfEvents1 = { "ENTER Anton 2.50 1",
                                        "ENTER Berta 3.90 2",
                                        "ENTER Claus 2.70 3",
                                        "ENTER Zorro 1.30 4",
    };

    std::list<std::string> listOfEvents2 = { "SERVED",
                                    "SERVED",
                                    "SERVED",
                                    "SERVED",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated1;
    std::list<schueler> listOfSchueler_generated2;

    listOfSchueler_generated1 = myPrio.processEvents(listOfEvents1);
    EXPECT_EQ(listOfSchueler_manuel1, listOfSchueler_generated1);

    listOfSchueler_generated2 = myPrio.processEvents(listOfEvents2);
    EXPECT_EQ(0, listOfSchueler_generated2.size());
}

TEST(processEventsTest12, enterSameCGPA) {
    /* six items, two of them with the same CGPA */
    std::list<schueler> listOfSchueler_manuel = { schueler(22, "Steffi",4.00),
                                        schueler(15, "Tom",3.90),
                                        schueler(115, "Arnold",3.10),
                                        schueler(100, "Lisa",3.10),
                                        schueler(35,"Andreas",2.70),
                                        schueler(3,"Katharina",1.50),
    };


    std::list<std::string> listOfEvents = { "ENTER Katharina 1.50 3",
                                        "ENTER Tom 3.90 15",
                                        "ENTER Andreas 2.70 35",
                                        "ENTER Lisa 3.10 100",
                                        "ENTER Steffi 4.00 22",
                                        "ENTER Arnold 3.10 115",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}

TEST(processEventsTest12, enterSameCGPA_similarName) {
    /* six items, two of them with the same CGPA and a similar name*/
    std::list<schueler> listOfSchueler_manuel = { schueler(22, "Steffi",4.00),                                        
                                        schueler(115, "Arnold",3.20),
                                        schueler(100, "Lisa",3.10),
                                        schueler(15, "Andrea",2.70),
                                        schueler(35,"Andreas",2.70),
                                        schueler(3,"Katharina",1.50),
    };


    std::list<std::string> listOfEvents = { "ENTER Katharina 1.50 3",
                                        "ENTER Andrea 2.70 15",
                                        "ENTER Andreas 2.70 35",
                                        "ENTER Lisa 3.10 100",
                                        "ENTER Steffi 4.00 22",
                                        "ENTER Arnold 3.20 115",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}


TEST(processEventsTest13, enterSameCGPA_similarStartLetter) {
    /* six items, all the same CGPA, same start letter*/
    std::list<schueler> listOfSchueler_manuel = { schueler(115, "Adrian",4.00),
                                        schueler(35, "Alexander",4.00),
                                        schueler(100, "Alina",4.00),
                                        schueler(15, "Amelie",4.00),
                                        schueler(3,"Anna",4.00),
                                        schueler(22,"Ava",4.00),
    };


    std::list<std::string> listOfEvents = { "ENTER Anna 4.00 3",
                                        "ENTER Amelie 4.00 15",
                                        "ENTER Alexander 4.00 35",
                                        "ENTER Alina 4.00 100",
                                        "ENTER Ava 4.00 22",
                                        "ENTER Adrian 4.00 115",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}


TEST(processEventsTest14, enterSameCGPA_sameName) {
    /* six items, all the same CGPA, same start letter*/
    std::list<schueler> listOfSchueler_manuel = { schueler(3, "Anna",4.00),
                                        schueler(15, "Anna",4.00),
                                        schueler(22, "Anna",4.00),
                                        schueler(35, "Anna",4.00),
                                        schueler(100,"Anna",4.00),
                                        schueler(115,"Anna",4.00),
    };


    std::list<std::string> listOfEvents = { "ENTER Anna 4.00 3",
                                        "ENTER Anna 4.00 15",
                                        "ENTER Anna 4.00 35",
                                        "ENTER Anna 4.00 100",
                                        "ENTER Anna 4.00 22",
                                        "ENTER Anna 4.00 115",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}


TEST(processEventsTest15, enterSameCGPA_sameName) {
    /* enter event: add an item to the beginning of the que*/
    std::list<schueler> listOfSchueler_manuel = { schueler(1, "Anna",4.00),
                                        schueler(3, "Anna",4.00),
                                        schueler(15, "Anna",4.00),
                                        schueler(22, "Anna",4.00),
                                        schueler(35, "Anna",4.00),
                                        schueler(100,"Anna",4.00),
                                        schueler(115,"Anna",4.00),
    };


    std::list<std::string> listOfEvents = { "ENTER Anna 4.00 3",
                                        "ENTER Anna 4.00 15",
                                        "ENTER Anna 4.00 35",
                                        "ENTER Anna 4.00 100",
                                        "ENTER Anna 4.00 22",
                                        "ENTER Anna 4.00 115",
                                        "ENTER Anna 4.00 1",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}


TEST(processEventsTest16, enterSameCGPA_sameName) {
    /* enter event: add an item to the end of the que*/
    std::list<schueler> listOfSchueler_manuel = { schueler(1, "Anna",4.00),
                                        schueler(3, "Anna",4.00),
                                        schueler(15, "Anna",4.00),
                                        schueler(22, "Anna",4.00),
                                        schueler(35, "Anna",4.00),
                                        schueler(100,"Anna",4.00),
                                        schueler(115,"Anna",4.00),
                                        schueler(900, "Anna",4.00)
    };


    std::list<std::string> listOfEvents = { "ENTER Anna 4.00 3",
                                        "ENTER Anna 4.00 15",
                                        "ENTER Anna 4.00 35",
                                        "ENTER Anna 4.00 100",
                                        "ENTER Anna 4.00 22",
                                        "ENTER Anna 4.00 115",
                                        "ENTER Anna 4.00 1",
                                        "ENTER Anna 4.00 900",
    };

    priorities myPrio;
    std::list<schueler> listOfSchueler_generated = myPrio.processEvents(listOfEvents);
    EXPECT_EQ(listOfSchueler_manuel, listOfSchueler_generated);
}