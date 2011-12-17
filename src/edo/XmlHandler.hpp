/*
 * XmlHandler.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_XMLHANDLER_HPP
#define EDO_XMLHANDLER_HPP
#include "edo/common.h"
namespace Edo {


/**
 * Observer of an XML parser.
 *
 * <p>An instance of an @e %XmlHandler receives notifications from an @e
 * %XmlParser while it parses XML content.  An @e %XmlHandler will receive an
 * event from an @e %XmlParser when it encounters an opening tag, a closing tag,
 * or the text between tags.  Users should create a concrete @e %XmlHandler that
 * responds to the events, register it with a parser, and then parse a stream
 * using the parser.
 *
 * @see XmlParser
 */
class XmlHandler {
    typedef std::string string_t;
    typedef std::map<string_t,string_t> stringmap_t;
public:
    virtual void onXmlOpeningTag(const string_t &name, const stringmap_t &attributes) = 0;
    virtual void onXmlText(const string_t &text) = 0;
    virtual void onXmlClosingTag(const string_t &name) = 0;
protected:
    virtual ~XmlHandler();
};

} // namespace Edo
#endif
