/*
 * TextTest.hxx
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_TEXTTEST_HXX
#define EDO_TEXTTEST_HXX
#include "edo/common.h"
#include "edo/TestFixture.hpp"
#include "edo/TestRunner.hpp"
#include "edo/Text.hpp"
namespace Edo {


/**
 * Unit test for Text.
 */
class TextTest : public TestFixture {
public:
    void testCount();
    void testFirstWord();
    void testFirstWordCharacter();
    void testFirstNotWordCharacter();
    void testReplacements();
    void testTrim();
    void testStripLeadingSpaces();
    void testStripTrailingSpaces();
    void testSplit();
};

} /* namespace Edo */
#endif
