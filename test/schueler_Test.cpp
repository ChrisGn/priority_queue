#include "schueler.h"
#include "gtest/gtest.h"
#include <string>


TEST(ConstructorTest1,NameExceedLowerBoundary){
    /* string name too short */
    const std::string name = "a";
    const int id = 5;
	const double cgpa = 2.0;    
	EXPECT_THROW(schueler mySchueler(id, name, cgpa);,std::length_error);
}

TEST(ConstructorTest2, NameExceedUpperBoundary) {
    /* string name too long */
    std::string name;
    for (unsigned int i = 0; i < 30; ++i){
        name += "a";
    }
    const int id = 5;
    const double cgpa = 2.0;    
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::length_error);
}

TEST(ConstructorTest3, CGPAExceedLowerBoundary) {
    /* double CGPA too small */
    const std::string name = "test";
    const int id = 5;
    const double cgpa = 0;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(ConstructorTest4, CGPAExceedUpperBoundary) {
    /* double CGPA too big */
    const std::string name = "test";
    const int id = 5;
    const double cgpa = 4.10;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(ConstructorTest5, IdExceedLowerBoundary) {
    /* double ID too small */
    const std::string name = "test";
    const int id = 0;
    const double cgpa = 0;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(ConstructorTest6, IdExceedUpperBoundary) {
    /* double ID too big */
    const std::string name = "test";
    const int id = pow(10,5) + 1;
    const double cgpa = 4.00;
    EXPECT_THROW(schueler mySchueler(id, name, cgpa);, std::range_error);
}

TEST(getIdTest, returnCorrectId) {
    /* getIdTest() test */
    const std::string name = "test";
    const int id = 10;
    const double cgpa = 3.0;
    schueler mySchueler(id, name, cgpa);
    EXPECT_EQ(id, mySchueler.getID());
}

TEST(getNameTest, returnCorrectName) {
    /* getNameTest() test */
    const std::string name = "Peter";
    const int id = 10;
    const double cgpa = 3.0;
    schueler mySchueler(id, name, cgpa);
    EXPECT_EQ(name, mySchueler.getName());
}

TEST(getCGPATest, returnCorrectCGPA) {
    /* getCGPATest() test */
    const std::string name = "Hans";
    const int id = 10;
    const double cgpa = 2.5;
    schueler mySchueler(id, name, cgpa);
    EXPECT_EQ(cgpa, mySchueler.getCGPA());
}

TEST(overloadedOpertorTest1, equalTrue) {
    /* compare two equal schueler objects */
    const std::string name = "Hans";
    const int id = 10;
    const double cgpa = 2.5;
    schueler mySchueler1(id, name, cgpa);
    schueler mySchueler2(id, name, cgpa);
    EXPECT_TRUE(mySchueler1 == mySchueler2);
}

TEST(overloadedOpertorTest2, equalFales) {
    /* compare two different schueler objects (name is different) */
    schueler mySchueler1(5, "Hans", 3.0);
    schueler mySchueler2(5, "Peter", 3.0);
    EXPECT_FALSE(mySchueler1 == mySchueler2);
}

TEST(overloadedOpertorTest3, equalFales) {
    /* compare two different schueler objects (ID is different) */
    schueler mySchueler1(5, "Hans", 3.0);
    schueler mySchueler2(6, "Hans", 3.0);
    EXPECT_FALSE(mySchueler1 == mySchueler2);
}

TEST(overloadedOpertorTest4, equalFales) {
    /* compare two different schueler objects (CGPA is different) */
    schueler mySchueler1(5, "Hans", 3.0);
    schueler mySchueler2(5, "Hans", 3.1);
    EXPECT_FALSE(mySchueler1 == mySchueler2);
}