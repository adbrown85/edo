/*
 * TextTest.cxx
 * 
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/TextTest.hxx"
using namespace std;
using namespace Edo;

void TextTest::testCount() {
    
    int result;
    
    result = Text::count("abracadabra", 'a');
    assert(result == 5);
}

void TextTest::testFirstWordCharacter() {
    
    int result;
    
    result = Text::findFirstWordCharacter("    (foo)", 0);
    assert(result == 5);
}

void TextTest::testFirstNotWordCharacter() {
    
    int result;
    
    result = Text::findFirstNotWordCharacter("    (foo)", 5);
    assert(result == 8);
}

void TextTest::testFirstWord() {
    
    pair<int,int> result;
    string text;
    
    text = "    (foo)";
    result = Text::findFirstWord(text);
    assert(result.first  == 5);
    assert(result.second == 3);
    assert(text.substr(result.first,result.second) == "foo");
    
    text = " 78 * 45";
    result = Text::findFirstWord(text);
    assert(result.first  == -1);
    assert(result.second == 0);
    
    text = " 123foobar";
    result = Text::findFirstWord(text);
    assert(result.first  == 4);
    assert(result.second == 6);
    assert(text.substr(result.first,result.second) == "foobar");
}

void TextTest::testReplacements() {
    
    map<string,string> dictionary;
    string result;
    
    dictionary["PI_CONSTANT"] = "3.14";
    dictionary["E_CONSTANT"] = "2.72";
    result = Text::replace("4*PI_CONSTANT + E_CONSTANT BLAH", dictionary);
    assert(result == "4*3.14 + 2.72 BLAH");
}

void TextTest::testTrim() {
    
    string result;
    
    result = Text::trim("  blah blah blah  ");
    assert(result == "blah blah blah");
    
    result = Text::trim("  \"blah blah blah\"  ", "'\" ");
    assert(result == "blah blah blah");
}

void TextTest::testSplit() {
    
    pair<string,string> result;
    
    result = Text::split("spot.ambient", '.');
    assert(result.first == "spot");
    assert(result.second == "ambient");
}

void TextTest::testStripLeadingSpaces() {
    
    string result;
    
    result = Text::stripLeadingSpaces("\t // This is a comment");
    assert(result == "// This is a comment");
}

void TextTest::testStripTrailingSpaces() {
    
    string result;
    
    result = Text::stripTrailingSpaces("// This is a comment    ");
    assert(result == "// This is a comment");
}

#define EDO_TEST_FIXTURE TextTest
EDO_TEST_SUITE
EDO_ADD_TEST(testCount)
EDO_ADD_TEST(testFirstWordCharacter)
EDO_ADD_TEST(testFirstNotWordCharacter)
EDO_ADD_TEST(testFirstWord)
EDO_ADD_TEST(testReplacements)
EDO_ADD_TEST(testTrim)
EDO_ADD_TEST(testSplit)
EDO_ADD_TEST(testStripLeadingSpaces)
EDO_ADD_TEST(testStripTrailingSpaces)
EDO_RUN_TESTS

