/*
 * TestCase.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_TESTCASE_HPP
#define EDO_TESTCASE_HPP
#include "edo/common.h"
#include "edo/TestFixture.hpp"
namespace Edo {


/**
 * Part of a test that can be called.
 *
 * @ingroup testing
 */
template <class T>
class TestCase {
public:
    typedef void (T::*TMethod)();
public:
    TestCase(const std::string &name, TMethod method);
    void run(T &fixture);
    std::string getName() const;
    TMethod getMethod() const;
private:
    std::string name;
    TMethod method;
};

/**
 * Constructs a test case.
 *
 * @param name Descriptive name
 * @param method Method to call on fixture
 */
template<class T>
inline
TestCase<T>::TestCase(const std::string &name,
                      TMethod method) {
    this->name = name;
    this->method = method;
}

/**
 * Runs the test case on a fixture.
 *
 * @param fixture Test fixture to run test case on
 */
template<class T>
inline
void TestCase<T>::run(T &fixture) {
    fixture.setUp();
    (fixture.*(method))();
    fixture.tearDown();
}

/**
 * Returns copy of the test case's name.
 */
template<class T>
inline
std::string TestCase<T>::getName() const {
    return name;
}

/**
 * Returns copy of the test case's method pointer.
 */
template<class T>
inline
typename TestCase<T>::TMethod
TestCase<T>::getMethod() const {
    return method;
}

} // namespace Edo
#endif
