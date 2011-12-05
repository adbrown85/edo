/*
 * SimplePatternTest.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Assert.hpp"
#include "edo/CharacterSets.hpp"
#include "edo/SimplePattern.hpp"
#include "edo/TestRunner.hpp"
using namespace std;
using namespace Edo;


/**
 * Unit test for SimplePattern.
 */
class SimplePatternTest : public TestFixture {
public:
    void testMatchesOne();
    void testMatchOne();
    void testMatchesOneOrMore();
    void testMatchOneOrMore();
    void testMatchesZeroOrMore();
    void testMatchZeroOrMore();
    void testMatchesZeroOrOne();
    void testMatchZeroOrOne();
};

/// Ensures that matches works correctly with a single character.
void SimplePatternTest::testMatchesOne() {

    SimplePattern sp(&CharacterSets::alphabetic(), QUANTIFIER_ONE);
    stringstream stream;

    stream << "blah blah blah";
    assertEquals(true, sp.matches(stream));
}

/// Ensures that match works correctly with a single character.
void SimplePatternTest::testMatchOne() {

    SimplePattern sp(&CharacterSets::alphabetic(), QUANTIFIER_ONE);
    stringstream stream;

    stream << "blah blah blah";
    assertEquals("b", sp.match(stream));
    assertEquals("l", sp.match(stream));
    assertEquals("a", sp.match(stream));
    assertEquals("h", sp.match(stream));
}

/// Ensures that matches works correctly with at least one charcter.
void SimplePatternTest::testMatchesOneOrMore() {

    SimplePattern sp(&CharacterSets::alphabetic(), QUANTIFIER_ONE_OR_MORE);
    stringstream stream;

    stream << "blah blah blah";
    assertEquals(true, sp.matches(stream));
}

/// Ensures that match works correctly with at least one character.
void SimplePatternTest::testMatchOneOrMore() {

    SimplePattern sp(&CharacterSets::alphabetic(), QUANTIFIER_ONE_OR_MORE);
    stringstream stream;

    stream << "blah blah blah";
    assertEquals("blah", sp.match(stream));
}

/// Ensures that matches works correctly with any amount of characters.
void SimplePatternTest::testMatchesZeroOrMore() {

    SimplePattern alpha(&CharacterSets::alphabetic(), QUANTIFIER_ZERO_OR_MORE);
    stringstream ss("foo bar baz");

    assertEquals(true, alpha.matches(ss));
}

/// Ensures that match works correctly with any amount of characters.
void SimplePatternTest::testMatchZeroOrMore() {

    SimplePattern alpha(&CharacterSets::alphabetic(), QUANTIFIER_ZERO_OR_MORE);
    SimplePattern space(&CharacterSets::whitespace(), QUANTIFIER_ONE);
    stringstream ss("foo bar baz");

    assertEquals("foo", alpha.match(ss));
    assertEquals(" ", space.match(ss));
    assertEquals("bar", alpha.match(ss));
    assertEquals(" ", space.match(ss));
    assertEquals("baz", alpha.match(ss));
}

/// Ensures that match works correctly with an optional character.
void SimplePatternTest::testMatchesZeroOrOne() {

    SimplePattern letter(&CharacterSets::alphabetic(), QUANTIFIER_ZERO_OR_ONE);
    stringstream ss("foo bar baz");

    assertEquals(true, letter.matches(ss));
}

/// Ensures that match works correctly with an optional character.
void SimplePatternTest::testMatchZeroOrOne() {

    SimplePattern letter(&CharacterSets::alphabetic(), QUANTIFIER_ZERO_OR_ONE);
    stringstream ss("foo bar baz");

    assertEquals("f", letter.match(ss));
    assertEquals("o", letter.match(ss));
    assertEquals("o", letter.match(ss));
}

#define EDO_TEST_FIXTURE SimplePatternTest
EDO_TEST_SUITE
EDO_ADD_TEST(testMatchesOne)
EDO_ADD_TEST(testMatchOne)
EDO_ADD_TEST(testMatchesOneOrMore)
EDO_ADD_TEST(testMatchOneOrMore)
EDO_ADD_TEST(testMatchesZeroOrMore)
EDO_ADD_TEST(testMatchZeroOrMore)
EDO_ADD_TEST(testMatchesZeroOrOne)
EDO_ADD_TEST(testMatchZeroOrOne)
EDO_RUN_TESTS
