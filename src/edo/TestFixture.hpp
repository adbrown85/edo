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
};

} // namespace Edo
#endif
