/*
 * CharacterSetsTest.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/common.h"
#include "edo/CharacterSets.hpp"
#include "edo/TestFixture.hpp"
#include "edo/TestRunner.hpp"
#include "edo/Assert.hpp"
using namespace std;
using namespace Edo;


/// Unit test for CharacterSets.
class CharacterSetsTest : public TestFixture {
public:
    void testAlphabeticCharacterSet();
    void testAlphanumericCharacterSet();
    void testDigitCharacterSet();
    void testLowercaseCharacterSet();
    void testPrintableCharacterSet();
    void testUppercaseCharacterSet();
    void testWhitespaceCharacterSet();
    void testWordCharacterSet();
};

/// Ensures the alphabetic character set works correctly.
void CharacterSetsTest::testAlphabeticCharacterSet() {

    CharacterSet *set = &CharacterSets::alphabetic();

    assertEquals(true, set->contains('a'));
    assertEquals(true, set->contains('A'));
    assertEquals(false, set->contains('1'));
    assertEquals(false, set->contains('!'));
}

/// Ensures the alphanumeric character set works correctly.
void CharacterSetsTest::testAlphanumericCharacterSet() {

    CharacterSet *set = &CharacterSets::alphanumeric();

    assertEquals(true, set->contains('A'));
    assertEquals(true, set->contains('1'));
    assertEquals(false, set->contains(' '));
}

/// Ensures the digit character set works correctly.
void CharacterSetsTest::testDigitCharacterSet() {

    CharacterSet *set = &CharacterSets::digit();

    assertEquals(true, set->contains('1'));
    assertEquals(true, set->contains('9'));
    assertEquals(false, set->contains('a'));
    assertEquals(false, set->contains('A'));
    assertEquals(false, set->contains('!'));
}

/// Ensures the lowercase character set works correctly.
void CharacterSetsTest::testLowercaseCharacterSet() {

    CharacterSet *set = &CharacterSets::lowercase();

    assertEquals(false, set->contains('A'));
    assertEquals(true, set->contains('a'));
    assertEquals(false, set->contains('1'));
    assertEquals(false, set->contains('.'));
    assertEquals(false, set->contains(' '));
}

/// Ensures the printable character set works correctly.
void CharacterSetsTest::testPrintableCharacterSet() {

    CharacterSet *set = &CharacterSets::printable();

    assertEquals(true, set->contains('A'));
    assertEquals(true, set->contains(' '));
    assertEquals(true, set->contains('!'));
    assertEquals(false, set->contains('\t'));
    assertEquals(false, set->contains('\n'));
}

/// Ensures the whitespace character set works correctly.
void CharacterSetsTest::testWhitespaceCharacterSet() {

    CharacterSet *set = &CharacterSets::whitespace();

    assertEquals(true, set->contains(' '));
    assertEquals(true, set->contains('\t'));
    assertEquals(true, set->contains('\n'));
    assertEquals(false, set->contains('a'));
    assertEquals(false, set->contains('A'));
    assertEquals(false, set->contains('1'));
}

/// Ensures the uppercase character set works correctly.
void CharacterSetsTest::testUppercaseCharacterSet() {

    CharacterSet *set = &CharacterSets::uppercase();

    assertEquals(true, set->contains('A'));
    assertEquals(false, set->contains('a'));
    assertEquals(false, set->contains('1'));
    assertEquals(false, set->contains(' '));
    assertEquals(false, set->contains('.'));
}

/// Ensures the word character set works correctly.
void CharacterSetsTest::testWordCharacterSet() {

    CharacterSet *set = &CharacterSets::word();

    assertEquals(true, set->contains('a'));
    assertEquals(true, set->contains('1'));
    assertEquals(true, set->contains('_'));
    assertEquals(false, set->contains(' '));
}

#define EDO_TEST_FIXTURE CharacterSetsTest
EDO_TEST_SUITE
EDO_ADD_TEST(testAlphabeticCharacterSet)
EDO_ADD_TEST(testAlphanumericCharacterSet)
EDO_ADD_TEST(testDigitCharacterSet)
EDO_ADD_TEST(testLowercaseCharacterSet)
EDO_ADD_TEST(testPrintableCharacterSet)
EDO_ADD_TEST(testUppercaseCharacterSet)
EDO_ADD_TEST(testWhitespaceCharacterSet)
EDO_ADD_TEST(testWordCharacterSet)
EDO_RUN_TESTS
