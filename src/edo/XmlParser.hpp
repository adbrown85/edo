/*
 * XmlParser.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_XMLPARSER_HPP
#define EDO_XMLPARSER_HPP
#include "edo/common.h"
#include "edo/CharacterSets.hpp"
#include "edo/Pattern.hpp"
#include "edo/Patterns.hpp"
#include "edo/Scanner.hpp"
#include "edo/SimpleCharacterSet.hpp"
#include "edo/SimplePattern.hpp"
#include "edo/XmlHandler.hpp"
namespace Edo {


/**
 * Utility for parsing XML content from streams.
 *
 * <p>@e %XmlParser reads XML content from a stream, notifiying an @e
 * %XmlHandler when it encounters important parts, such as an opening tag, a
 * closing tag, or the text between tags.
 *
 * <p>To use an @e %XmlParser, first create an instance of @e %XmlHandler that
 * will do what you want with the XML content that is parsed.  Then create an @e
 * %XmlParser from that handler.  Next, create a stream, from a file or string
 * for example, and pass it to the parser.  The stream and parser should then
 * fall out of scope.
 *
 * <p>An example of using @e %XmlParser with a file :
 * @code
 *   // Create a parser with your handler
 *   MyXmlHandler handler;
 *   XmlParser parser(&handler);
 *
 *   // Parse a file with it
 *   ifstream stream(file);
 *   parser.parse(stream);
 * @endcode
 *
 * @see XmlHandler
 */
class XmlParser {
    typedef std::string string_t;
    typedef std::map<string_t,string_t> stringmap_t;
public:
    XmlParser(XmlHandler *handler);
    virtual ~XmlParser();
    virtual void parse(std::istream &stream);
private:
    XmlHandler *handler;
// Constants
    static Pattern *CLOSING_ANGLE_BRACKET;
    static Pattern *FORWARD_SLASH;
    static Pattern *NOT_OPEN_ANGLE_BRACKET;
    static Pattern *NOT_QUOTE;
    static Pattern *PRINTABLE;
    static Pattern *OPEN_ANGLE_BRACKET;
    static Pattern *TAG_TERMINATORS;
// Nested classes
    class Attribute;
    class Tag;
// Helpers
    static Pattern* createClosingAngleBracketPattern();
    static Pattern* createForwardSlashPattern();
    static Pattern* createNotOpenAngleBracketPattern();
    static Pattern* createPrintablePattern();
    static Pattern* createNotQuotePattern();
    static Pattern* createOpenAngleBracketPattern();
    static Pattern* createTagTerminatorsPattern();
    void handleTag(Scanner &scanner);
    void handleText(Scanner &scanner);
    static Attribute readAttribute(Scanner &scanner);
    static Tag readTag(Scanner &scanner);
};


/**
 * XML attribute with key and value.
 */
class XmlParser::Attribute {
public:
    Attribute(const std::string &key, const std::string &value);
    std::string getKey() const;
    std::string getValue() const;
private:
    std::string key;
    std::string value;
};


/**
 * XML tag made up of a name and attributes.
 */
class XmlParser::Tag {
public:
    Tag();
    std::string getName() const;
    void setName(const std::string &name);
    void addAttribute(const std::string &key, const std::string &value);
    typedef std::list<Attribute>::const_iterator const_iterator;
    const_iterator begin() const;
    const_iterator end() const;
    bool isClosing() const;
    void setClosing(bool closing);
    bool isOpening() const;
    void setOpening(bool opening);
private:
    std::string name;
    std::list<Attribute> attributes;
    bool closing;
    bool opening;
};

} // namespace Edo
#endif
