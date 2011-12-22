/*
 * SimpleCharacterSetTest.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Assert.hpp"
#include "edo/SimpleCharacterSet.hpp"
#include "edo/TestRunner.hpp"
using namespace std;
using namespace Edo;


/**
 * Unit test for SimpleCharacterSet.
 */
class SimpleCharacterSetTest : public TestFixture {
public:
    void testContainsWithCharacter();
    void testContainsWithString();
    void testContainsWithSet();
};

/**
 * Ensures contains works when created from a single character.
 */
void SimpleCharacterSetTest::testContainsWithCharacter() {

    SimpleCharacterSet scs('a');

    assertEquals(true, scs.contains('a'));
    assertEquals(false, scs.contains('b'));
}

/**
 * Ensures contains works when created from a string of characters.
 */
void SimpleCharacterSetTest::testContainsWithString() {

    SimpleCharacterSet scs("abc");

    assertEquals(true, scs.contains('a'));
    assertEquals(true, scs.contains('b'));
    assertEquals(true, scs.contains('c'));
    assertEquals(false, scs.contains('d'));
    assertEquals(false, scs.contains('e'));
}

/**
 * Ensures contains works when created from a set of characters.
 */
void SimpleCharacterSetTest::testContainsWithSet() {

    set<char> characters;
    characters.insert('1');
    characters.insert('2');
    characters.insert('3');
    SimpleCharacterSet scs(characters);

    assertEquals(true, scs.contains('1'));
    assertEquals(true, scs.contains('2'));
    assertEquals(true, scs.contains('3'));
    assertEquals(false, scs.contains('4'));
    assertEquals(false, scs.contains('5'));
}

#define EDO_TEST_FIXTURE SimpleCharacterSetTest
EDO_TEST_SUITE
EDO_ADD_TEST(testContainsWithCharacter)
EDO_ADD_TEST(testContainsWithString)
EDO_ADD_TEST(testContainsWithSet)
EDO_RUN_TESTS
