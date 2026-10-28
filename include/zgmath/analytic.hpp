#ifndef ANALYTIC_HPP
#define ANALYTIC_HPP

#include "data_types.hpp"

namespace zgm {
   double toRadians(double deg);
   double toDegrees(double rad);

   double     magnitude(point2<double>, point2<double>);
   double     magnitude(point3<double>, point3<double>);

   double     dot(point2<double>, point2<double>);

   point3<double>  cross(point3<double>, point3<double>);
};

#endif
