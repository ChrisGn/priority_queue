#include "schueler.h"
#include "gtest/gtest.h"
#include <string>


TEST(ConstructorTest1,NameExceedLowerBoundary){
    const std::string name = "a";
    const int id = 5;
	const double cgpa = 2.0;    
	EXPECT_THROW(schueler mySchueler(id, name, cgpa);,std::length_error);
}

TEST(ConstructorTest2, NameExceedUpperBoundary) {
    std::string name;
    for (unsigned int i = 0; i < 30; ++i){
        name += "a";
    }
    const int id = 5;
    const double cgpa = 2.0;    
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::length_error);
}

TEST(ConstructorTest3, CGPAExceedLowerBoundary) {
    const std::string name = "test";
    const int id = 5;
    const double cgpa = 0;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(ConstructorTest4, CGPAExceedUpperBoundary) {
    const std::string name = "test";
    const int id = 5;
    const double cgpa = 4.1;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(ConstructorTest5, IdExceedLowerBoundary) {
    const std::string name = "test";
    const int id = 0;
    const double cgpa = 0;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(ConstructorTest6, IdExceedUpperBoundary) {
    const std::string name = "test";
    const int id = pow(10,5);
    const double cgpa = 4.1;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(getIdTest, returnCorrectId) {
    const std::string name = "test";
    const int id = 10;
    const double cgpa = 3.0;
    schueler mySchueler(id, name, cgpa);
    EXPECT_EQ(id, mySchueler.getID());
}

TEST(getNameTest, returnCorrectName) {
    const std::string name = "Peter";
    const int id = 10;
    const double cgpa = 3.0;
    schueler mySchueler(id, name, cgpa);
    EXPECT_EQ(name, mySchueler.getName());
}

TEST(getCGPATest, returnCorrectCGPA) {
    const std::string name = "Hans";
    const int id = 10;
    const double cgpa = 2.5;
    schueler mySchueler(id, name, cgpa);
    EXPECT_EQ(cgpa, mySchueler.getCGPA());
}

TEST(overloadedOpertorTest1, equalTrue) {
    const std::string name = "Hans";
    const int id = 10;
    const double cgpa = 2.5;
    schueler mySchueler1(id, name, cgpa);
    schueler mySchueler2(id, name, cgpa);
    EXPECT_TRUE(mySchueler1 == mySchueler2);
    //EXPECT_EQ(mySchueler1, mySchueler2);
}

TEST(overloadedOpertorTest2, equalFales) {
    schueler mySchueler1(5, "Hans", 3.0);
    schueler mySchueler2(5, "Peter", 3.0);
    EXPECT_FALSE(mySchueler1 == mySchueler2);
}

TEST(overloadedOpertorTest3, equalFales) {
    schueler mySchueler1(5, "Hans", 3.0);
    schueler mySchueler2(6, "Hans", 3.0);
    EXPECT_FALSE(mySchueler1 == mySchueler2);
}

TEST(overloadedOpertorTest4, equalFales) {
    schueler mySchueler1(5, "Hans", 3.0);
    schueler mySchueler2(5, "Hans", 3.1);
    EXPECT_FALSE(mySchueler1 == mySchueler2);
}