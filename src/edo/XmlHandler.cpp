/**
 * XmlHandler.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#include "config.h"
#include "edo/XmlHandler.hpp"
using namespace std;
using namespace Edo;

/**
 * Destroys the handler.
 */
XmlHandler::~XmlHandler() {
    ;
}

/**
 * Responds to an opening XML tag being parsed.
 *
 * @param name Name identifying type of tag
 * @param attributes Mapping of keys to values
 */
void XmlHandler::onXmlOpeningTag(const string &name, const map<string,string> &attributes) {
    ;
}

/**
 * Responds to raw XML text being parsed.
 *
 * @param text %Text found between opening and closing tags
 */
void XmlHandler::onXmlText(const string &text) {
    ;
}

/**
 * Responds to a closing XML tag being parsed.
 *
 * @param name Name identifying type of tag
 */
void XmlHandler::onXmlClosingTag(const string &name) {
    ;
}

