#include "schueler.h"
#include "gtest/gtest.h"
#include <string>


class schuelerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST (ConstructorTest,NameExceedLowerBoundary){
    const std::string name = "a";
    const int id = 5;
	const double cgpq = 2.0;
    schueler mySchueler(id, name, cgpa);
	EXPECT_THROW("string name is too short",std::exception)
}

TEST(ConstructorTest, NameExceedUpperBoundary) {
    const std::string name;
    for (unsigned int i = 0; i < 30; ++i)
    {
        name += "a";

    }
    const int id = 5;
    const double cgpq = 2.0;
    schueler mySchueler(id, name, cgpa);
    EXPECT_THROW("string name is too short", std::exception)
}