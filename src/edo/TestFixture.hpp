/*
 * TestFixture.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_TESTFIXTURE_HPP
#define EDO_TESTFIXTURE_HPP
#include <cassert>
#include <cmath>
#include <sstream>
#include "edo/common.h"
#include "edo/Exception.hpp"
namespace Edo {


/**
 * Utility for testing a class.
 *
 * @ingroup testing
 */
class TestFixture {
public:
    TestFixture();
    virtual ~TestFixture();
    virtual void setUp();
    virtual void tearDown();
protected:
    static void assertEquals(float x, float y);
    static void assertEquals(float x, float y, float epsilon);
    static void assertEquals(const std::string &s1, const std::string &s2);
private:
    static const float DEFAULT_EPSILON = 0.001;
// Helpers
    static std::string createMessage(float x, float y);
    static std::string createMessage(const std::string&, const std::string&);
};

} // namespace Edo
#endif