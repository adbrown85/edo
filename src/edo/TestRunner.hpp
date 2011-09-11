/*
 * TestRunner.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_TESTRUNNER_HPP
#define EDO_TESTRUNNER_HPP
#include "edo/common.h"
#include "edo/TestFixture.hpp"
#include "edo/TestCase.hpp"
#include "edo/TestSuite.hpp"
namespace Edo {

/* Macro for making a test runner */
#define EDO_TEST_SUITE \
int main(int argc, char *argv[]) { \
    TestSuite<EDO_TEST_FIXTURE> testSuite; \
    TestRunner<EDO_TEST_FIXTURE> testRunner;

/* Macro for adding a test case */
#define EDO_ADD_TEST(X) \
    testSuite.addTestCase(#X, &EDO_TEST_FIXTURE::X);

/* Macro for running the fixture */
#define EDO_RUN_TESTS \
    testRunner.runTestSuite(testSuite); \
    return 0; \
}


/**
 * Utility for running tests.
 *
 * @ingroup testing
 */
template <typename T>
class TestRunner {
public:
    TestRunner() {}
    virtual ~TestRunner() {}
    void runTestSuite(TestSuite<T> &testSuite);
};

/**
 * Runs each test case in a suite.
 * 
 * @param testSuite Collection of test cases to run
 */
template <typename T>
inline
void TestRunner<T>::runTestSuite(TestSuite<T> &testSuite) {
    
    T testFixture;
    typename TestSuite<T>::iterator it;
    
    try {
        for (it=testSuite.begin(); it!=testSuite.end(); ++it) {
            std::cout << "RUNNING " << it->getName() << std::endl;
            it->run(testFixture);
            std::cout << "PASSED" << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "FAILED!" << std::endl;
        exit(1);
    }
}


} // namespace Edo
#endif
