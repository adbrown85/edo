/*
 * Math.hpp
 *
 * Author
 *     Andrew Brown <adb1413@rit.edu>
 */
#ifndef EDO_MATH_HPP
#define EDO_MATH_HPP
#include "edo/common.h"
#include <cmath>
namespace Edo {

/*
 * Constants
 */
const double PI = 355.0 / 113.0;
const double SQRT_TWO = sqrt(2.0);

/*
 * Functions
 */
double toRadians(double degrees);
double toDegrees(double radians);

} /* namespace Edo */
#endif
