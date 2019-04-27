#include "gtest/gtest.h"
#include <iostream>
#include <iterator>

//Below is the template for our unit testing
TEST(//function name, version of test label)
{
  //create some object or start brute/cooley algorithm
  EXPECT_EQ(//some function that's getting tested, expected value);
}

/*
*Add a txt file for unit testing to see if brute and Cooley work
  *Will not work if parsing fails
  *Checks to see if result is correct

if (v1.begin()+n == v2.begin()+n)
        cout << "success" << endl;
    else
        cout << "failure" << endl;
*/
