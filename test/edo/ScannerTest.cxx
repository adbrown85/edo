/*
 * ScannerTest.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/Assert.hpp"
#include "edo/Patterns.hpp"
#include "edo/Scanner.hpp"
#include "edo/SimplePattern.hpp"
#include "edo/TestRunner.hpp"
using namespace std;
using namespace Edo;


/// Unit test for Scanner
class ScannerTest : public TestFixture {
public:
    void testHasNext();
    void testNextWithNoLeadingSpaces();
    void testNextWithLeadingSpaces();
    void testNextWithEndOfStream();
    void testWithXml();
};

void ScannerTest::testHasNext() {

    Scanner scanner("blah blah blah");
    Pattern *pattern = &Patterns::word();

    assertEquals(true, scanner.hasNext(pattern));
}

void ScannerTest::testNextWithNoLeadingSpaces() {

    Scanner scanner("blah blah blah");
    Pattern *pattern = &Patterns::word();

    assertEquals(true, scanner.hasNext(pattern));
    assertEquals("blah", scanner.next(pattern));
}

void ScannerTest::testNextWithLeadingSpaces() {

    Scanner scanner("  blah blah blah");
    Pattern *pattern = &Patterns::word();

    assertEquals(true, scanner.hasNext(pattern));
    assertEquals("blah", scanner.next(pattern));
}

void ScannerTest::testNextWithEndOfStream() {

    Scanner scanner("blah");
    Pattern *pattern = &Patterns::word();

    assertEquals(true, scanner.hasNext(pattern));
    assertEquals("blah", scanner.next(pattern));
    assertEquals(false, scanner.hasNext(pattern));
    try {
        scanner.next(pattern);
    } catch (exception &e) {
        return;
    }
}

void ScannerTest::testWithXml() {

    Scanner scanner("<name key = 'value'>");
    Pattern *punct = &Patterns::punctuation();
    Pattern *word = &Patterns::word();

    assertEquals("<", scanner.next(punct));
    assertEquals("name", scanner.next(word));
    assertEquals("key", scanner.next(word));
    assertEquals("=", scanner.next(punct));
    assertEquals("'", scanner.next(punct));
    assertEquals("value", scanner.next(word));
    assertEquals("'", scanner.next(punct));
    assertEquals(">", scanner.next(punct));
}

#define EDO_TEST_FIXTURE ScannerTest
EDO_TEST_SUITE
EDO_ADD_TEST(testHasNext)
EDO_ADD_TEST(testNextWithNoLeadingSpaces)
EDO_ADD_TEST(testNextWithLeadingSpaces)
EDO_ADD_TEST(testNextWithEndOfStream)
EDO_ADD_TEST(testWithXml)
EDO_RUN_TESTS
