/**
 * @file main.cpp which runs all the test cases in this test suite
 * @author Rishabh Biyani(rishabh1b)
 * @copyright MIT License (c) 2017 Rishabh Biyani
 */
#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
