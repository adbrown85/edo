/*
 * XmlParser.cpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/XmlParser.hpp"
using namespace std;
using namespace Edo;

Pattern *XmlParser::CLOSING_ANGLE_BRACKET = createClosingAngleBracketPattern();
Pattern *XmlParser::FORWARD_SLASH = createForwardSlashPattern();
Pattern *XmlParser::NOT_OPEN_ANGLE_BRACKET = createNotOpenAngleBracketPattern();
Pattern *XmlParser::NOT_QUOTE = createNotQuotePattern();
Pattern *XmlParser::PRINTABLE = createPrintablePattern();
Pattern *XmlParser::OPEN_ANGLE_BRACKET = createOpenAngleBracketPattern();
Pattern *XmlParser::TAG_TERMINATORS = createTagTerminatorsPattern();

/**
 * Constructs an XML parser using a handler.
 *
 * @param handler Handler to send notifications to
 * @throws std::exception if handler is NULL
 */
XmlParser::XmlParser(XmlHandler *handler) {
    if (handler == NULL) {
        throw Exception("Handler is NULL!");
    } else {
        this->handler = handler;
    }
}

/**
 * Destroys an XML parser.
 */
XmlParser::~XmlParser() {
    ;
}

/**
 * Parses XML content from a stream.
 *
 * @param stream Input stream with XML content
 */
void XmlParser::parse(istream &stream) {

    Scanner scanner(stream);

    while (scanner.hasNext(PRINTABLE)) {
        if (scanner.hasNext(OPEN_ANGLE_BRACKET)) {
            handleTag(scanner);
        } else {
            handleText(scanner);
        }
    }
}

// HELPERS

/**
 * Returns a copy of the closing-angle-bracket pattern.
 */
Pattern* XmlParser::createClosingAngleBracketPattern() {

    CharacterSet *characters = new SimpleCharacterSet('>');
    Quantifier quantifier = QUANTIFIER_ONE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Returns a copy of the forward-slash pattern.
 */
Pattern* XmlParser::createForwardSlashPattern() {

    CharacterSet *characters = new SimpleCharacterSet("/");
    Quantifier quantifier = QUANTIFIER_ZERO_OR_ONE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Returns a copy of the not-open-angle-bracket pattern.
 */
Pattern* XmlParser::createNotOpenAngleBracketPattern() {

   CharacterSet *characters = new SimpleCharacterSet('<');
   Quantifier quantifier = QUANTIFIER_ZERO_OR_MORE;
   Pattern *pattern = new SimplePattern(characters, quantifier, true);

   return pattern;
}

/**
 * Returns a copy of the not-quote pattern.
 */
Pattern* XmlParser::createNotQuotePattern() {

    CharacterSet *characters = new SimpleCharacterSet("\'\"");
    Quantifier quantifier = QUANTIFIER_ZERO_OR_MORE;
    Pattern *pattern = new SimplePattern(characters, quantifier, true);

    return pattern;
}

/**
 * Makes the open angle bracket pattern.
 */
Pattern* XmlParser::createOpenAngleBracketPattern() {

    CharacterSet *characters = new SimpleCharacterSet('<');
    Quantifier quantifier = QUANTIFIER_ONE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Returns a copy of the printable pattern.
 */
Pattern* XmlParser::createPrintablePattern() {

    CharacterSet *characters = &CharacterSets::printable();
    Quantifier quantifier = QUANTIFIER_ONE_OR_MORE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Returns a copy of the tag terminators pattern.
 */
Pattern* XmlParser::createTagTerminatorsPattern() {

    CharacterSet *characters = new SimpleCharacterSet("/>");
    Quantifier quantifier = QUANTIFIER_ONE;
    Pattern *pattern = new SimplePattern(characters, quantifier);

    return pattern;
}

/**
 * Responds to the parser encountering a tag.
 */
void XmlParser::handleTag(Scanner &scanner) {

    // Read the tag
    Tag tag = readTag(scanner);

    // Store the name
    string name = tag.getName();

    // Store the attributes
    map<string,string> attributes;
    for (Tag::const_iterator it = tag.begin(); it != tag.end(); ++it) {
        attributes[it->getKey()] = it->getValue();
    }

    // Send to handler
    if (tag.isOpening()) {
        handler->onXmlOpeningTag(name, attributes);
    }
    if (tag.isClosing()) {
        handler->onXmlClosingTag(name);
    }
}

/**
 * Responds to the parser encountering text between tags.
 */
void XmlParser::handleText(Scanner &scanner) {
    string str = scanner.next(NOT_OPEN_ANGLE_BRACKET);
    handler->onXmlText(str);
}

/**
 * Reads an XML attribute from the stream.
 */
XmlParser::Attribute XmlParser::readAttribute(Scanner &scanner) {

    // Read the key
    string key = scanner.next(&Patterns::word());

    // Skip the equals sign
    scanner.next(&Patterns::punctuation());

    // Read the value
    scanner.next(&Patterns::punctuation());
    string value = scanner.next(NOT_QUOTE);
    scanner.next(&Patterns::punctuation());

    // Return the attribute
    return Attribute(key, value);
}

/**
 * Reads an XML tag from the stream.
 */
XmlParser::Tag XmlParser::readTag(Scanner &scanner) {

    string token;
    Tag tag;

    // Handle an opening angle bracket and slash
    scanner.next(&Patterns::punctuation());
    token = scanner.next(FORWARD_SLASH);
    if (token == "/") {
        tag.setClosing(true);
    } else {
        tag.setOpening(true);
    }

    // Read the name
    token = scanner.next(&Patterns::word());
    tag.setName(token);

    // Read the attributes
    while (!scanner.hasNext(TAG_TERMINATORS)) {
        Attribute attribute = readAttribute(scanner);
        tag.addAttribute(attribute.getKey(), attribute.getValue());
    }

    // Consume the end of the tag
    token = scanner.next(TAG_TERMINATORS);
    if (token == "/") {
        tag.setClosing(true);
        scanner.next(TAG_TERMINATORS);
    }

    // Return the tag
    return tag;
}

// NESTED CLASSES

XmlParser::Attribute::Attribute(const string &key, const string &value) {
    if (key.empty()) {
        throw Exception("Key is empty!");
    } else {
        this->key = key;
        this->value = value;
    }
}

string XmlParser::Attribute::getKey() const {
    return key;
}

string XmlParser::Attribute::getValue() const {
    return value;
}

XmlParser::Tag::Tag() {
    this->name.clear();
    this->attributes.clear();
    this->opening = false;
    this->closing = false;
}

void XmlParser::Tag::addAttribute(const string &key, const string &value) {
    attributes.push_back(Attribute(key, value));
}

string XmlParser::Tag::getName() const {
    return name;
}

void XmlParser::Tag::setName(const string &name) {
    this->name = name;
}

XmlParser::Tag::const_iterator XmlParser::Tag::begin() const {
    return attributes.begin();
}

XmlParser::Tag::const_iterator XmlParser::Tag::end() const {
    return attributes.end();
}

bool XmlParser::Tag::isClosing() const {
    return closing;
}

void XmlParser::Tag::setClosing(bool closing) {
    this->closing = closing;
}

bool XmlParser::Tag::isOpening() const {
    return opening;
}

void XmlParser::Tag::setOpening(bool opening) {
    this->opening = opening;
}
