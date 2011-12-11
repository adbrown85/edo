/*
 * PatternsTest.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include <sstream>
#include "edo/Assert.hpp"
#include "edo/Patterns.hpp"
#include "edo/TestRunner.hpp"
using namespace std;
using namespace Edo;


/// Unit test for Patterns.
class PatternsTest : public TestFixture {
public:
    void testPunctuation();
    void testWhitespace();
    void testWord();
};

/// Ensures the punctuation pattern works as expected.
void PatternsTest::testPunctuation() {

    stringstream ss("!.");
    Pattern *pattern = &Patterns::punctuation();

    assertEquals(true, pattern->matches(ss));
    assertEquals("!", pattern->match(ss));
    assertEquals(true, pattern->matches(ss));
    assertEquals(".", pattern->match(ss));
    assertEquals(false, pattern->matches(ss));
}

/// Ensures the whitespace pattern works as expected.
void PatternsTest::testWhitespace() {

    stringstream ss("  blah blah blah");
    Pattern *pattern = &Patterns::whitespace();

    assertEquals(true, pattern->matches(ss));
    assertEquals("  ", pattern->matches(ss));
}

/// Ensures the word pattern works as expected.
void PatternsTest::testWord() {

    stringstream ss("blah blah blah");
    Pattern *pattern = &Patterns::word();

    assertEquals(true, pattern->matches(ss));
    assertEquals("blah", pattern->match(ss));
}

#define EDO_TEST_FIXTURE PatternsTest
EDO_TEST_SUITE
EDO_ADD_TEST(testPunctuation)
EDO_ADD_TEST(testWhitespace)
EDO_ADD_TEST(testWord)
EDO_RUN_TESTS
