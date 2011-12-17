/*
 * XmlParserTest.cxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/XmlParser.hpp"
#include "edo/Assert.hpp"
#include "edo/TestRunner.hpp"
using namespace std;
using namespace Edo;


/**
 * Unit test for XmlParser.
 */
class XmlParserTest : public TestFixture {
public:
    void testParseWithOpeningTagAndSingleAttribute();
    void testParseWithOpeningTagAndMultipleAttributes();
    void testParseWithOpeningTagAndLongAttributes();
    void testParseWithOpeningAndClosingTags();
    void testParseWithShorthandTag();
    void testParseWithTextBetweenOpeningAndClosingTags();
    void testParseWithNestedTags();
private:
    class Handler;
};


/**
 * Basic implementation of XmlHandler for the test.
 */
class XmlParserTest::Handler : public XmlHandler {
public:
    void onXmlOpeningTag(const string &n, const map<string,string> &a);
    void onXmlText(const string &t);
    void onXmlClosingTag(const string &n);
    string operator[](int i) const {return tokens[i];}
    int size() {return tokens.size();}
private:
    vector<string> tokens;
};


/// Ensures parse works correctly with a single attribute.
void XmlParserTest::testParseWithOpeningTagAndSingleAttribute() {

    stringstream stream("<name key='value'>");
    Handler handler;
    XmlParser parser(&handler);

    parser.parse(stream);

    assertEquals(3, handler.size());
    assertEquals("name", handler[0]);
    assertEquals("key", handler[1]);
    assertEquals("value", handler[2]);
}

/// Ensures parse works correctly with multiple attribues.
void XmlParserTest::testParseWithOpeningTagAndMultipleAttributes() {

    stringstream stream("<javac srcdir='src' debug='true'>");
    Handler handler;
    XmlParser parser(&handler);

    parser.parse(stream);

    assertEquals(5, handler.size());
    assertEquals("javac", handler[0]);
    assertEquals("debug", handler[1]);
    assertEquals("true", handler[2]);
    assertEquals("srcdir", handler[3]);
    assertEquals("src", handler[4]);
}

/// Ensures parse works with attributes that have more than one word.
void XmlParserTest::testParseWithOpeningTagAndLongAttributes() {

    stringstream stream("<javac srcdir='src test' debug='lines vars'>");
    Handler handler;
    XmlParser parser(&handler);

    parser.parse(stream);

    assertEquals(5, handler.size());
    assertEquals("javac", handler[0]);
    assertEquals("debug", handler[1]);
    assertEquals("lines vars", handler[2]);
    assertEquals("srcdir", handler[3]);
    assertEquals("src test", handler[4]);
}

/// Ensures parse works with a closing tag.
void XmlParserTest::testParseWithOpeningAndClosingTags() {

    stringstream stream("<target name='clean'></target>");
    Handler handler;
    XmlParser parser(&handler);

    parser.parse(stream);

    assertEquals(4, handler.size());
    assertEquals("target", handler[0]);
    assertEquals("name", handler[1]);
    assertEquals("clean", handler[2]);
    assertEquals("target", handler[3]);
}

/// Ensures parse works with a tag that is both opening and closing.
void XmlParserTest::testParseWithShorthandTag() {

    stringstream stream("<javac debug='lines' />");
    Handler handler;
    XmlParser parser(&handler);

    parser.parse(stream);

    assertEquals(4, handler.size());
    assertEquals("javac", handler[0]);
    assertEquals("debug", handler[1]);
    assertEquals("lines", handler[2]);
    assertEquals("javac", handler[3]);
}

/// Ensures parse works with text between tags.
void XmlParserTest::testParseWithTextBetweenOpeningAndClosingTags() {

   stringstream stream("<javac debug='lines'>Hello, World!</javac>");
   Handler handler;
   XmlParser parser(&handler);

   parser.parse(stream);

   assertEquals(5, handler.size());
   assertEquals("javac", handler[0]);
   assertEquals("debug", handler[1]);
   assertEquals("lines", handler[2]);
   assertEquals("Hello, World!", handler[3]);
   assertEquals("javac", handler[4]);
}

/// Ensures parse works with tags nested in each other.
void XmlParserTest::testParseWithNestedTags() {

    stringstream stream("<target name='compile'><javac srcdir='${src.dir}'></javac></target>");
    Handler handler;
    XmlParser parser(&handler);

    parser.parse(stream);
    assertEquals(8, handler.size());
    assertEquals("target", handler[0]);
    assertEquals("name", handler[1]);
    assertEquals("compile", handler[2]);
    assertEquals("javac", handler[3]);
    assertEquals("srcdir", handler[4]);
    assertEquals("${src.dir}", handler[5]);
    assertEquals("javac", handler[6]);
    assertEquals("target", handler[7]);
}


#define EDO_TEST_FIXTURE XmlParserTest
EDO_TEST_SUITE
EDO_ADD_TEST(testParseWithOpeningTagAndSingleAttribute)
EDO_ADD_TEST(testParseWithOpeningTagAndMultipleAttributes)
EDO_ADD_TEST(testParseWithOpeningTagAndLongAttributes)
EDO_ADD_TEST(testParseWithOpeningAndClosingTags)
EDO_ADD_TEST(testParseWithShorthandTag)
EDO_ADD_TEST(testParseWithTextBetweenOpeningAndClosingTags)
EDO_ADD_TEST(testParseWithNestedTags)
EDO_RUN_TESTS

/// Records an opening XML tag.
void XmlParserTest::Handler::onXmlOpeningTag(const string &n, const map<string,string> &a) {

    map<string,string>::const_iterator it;

    tokens.push_back(n);
    for (it=a.begin(); it!=a.end(); ++it) {
        tokens.push_back(it->first);
        tokens.push_back(it->second);
    }
}

/// Records the text between XML tags.
void XmlParserTest::Handler::onXmlText(const string &t) {
    tokens.push_back(t);
}

/// Records an ending XML tag.
void XmlParserTest::Handler::onXmlClosingTag(const string &n) {
    tokens.push_back(n);
}
