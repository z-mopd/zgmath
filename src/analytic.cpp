#include "zgmath/data_types.hpp"
#include "zgmath/analytic.hpp"

#include <cmath>

namespace zgm {
   double toRadians(double d) {
      return d * (M_PI / 180.0);
   }

   double toDegrees(double r) {
      return r * (180.0 / M_PI);
   }

   double     magnitude(point2<double>, point2<double>);
   double     magnitude(point3<double>, point3<double>);

   double     dot(point2<double> p1, point2<double> p2) {
      return p1.x * p2.x + p1.y * p2.y;
   }

   point3<double>  cross(point3<double>, point3<double>);
};
