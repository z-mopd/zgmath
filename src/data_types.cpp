#include "zgmath/data_types.hpp"
#include "zgmath/analytic.hpp"

#include <cmath>

#define MAG2(x, y) sqrt((x*x) + (y*y))

namespace zgm {

// Vec2 start
Vec2::Vec2() : point2(0, 0), magnitude(0) {}
Vec2::Vec2(double x, double y) : point2(x, y), magnitude(MAG2(x, y)) {}
Vec2::Vec2(point2<double> p) : point2(p.x, p.y), magnitude(MAG2(x, y)) {}
Vec2::Vec2(point2<const double> p) : point2(p), magnitude(MAG2(x, y)) {}

Vec2::operator point2<double>() const {
   return {x, y};
}

Vec2 Vec2::unit() const {
   return {x / magnitude, y / magnitude};
}

double Vec2::dot(Vec2 vec) const {
   return x * vec.x + y * vec.y;
}

Vec2 Vec2::reflect(Vec2 normal) const {
   double dotProduct = dot(normal);
   return {
      x - (2.0*normal.x)*dotProduct,
      y - (2.0*normal.y)*dotProduct
   };
}

Vec2 Vec2::reflectAxisX() const { return {x, -y}; }
Vec2 Vec2::reflectAxisY() const { return {-x, y}; }

double Vec2::cosRadsBetween(Vec2 vec) const {
   return dot(vec) / (magnitude * vec.magnitude);
}

double Vec2::radsBetween(Vec2 vec) const { return acos(cosRadsBetween(vec)); }

Vec2 Vec2::operator*(double scalar) const { return {x * scalar, y * scalar}; }

Vec2 Vec2::operator/(double scalar) const {
   if (scalar == 0)
      return {};
   return {x / scalar, y / scalar};
}

Vec2 Vec2::operator+(Vec2 vec) const { return {x + vec.x, y + vec.y}; }
Vec2 Vec2::operator-(Vec2 vec) const { return {x - vec.x, y - vec.y}; }

std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
   return os << '(' << vec.x << ", " << vec.y << ')';
}
// Vec2 end


// Vec3 start
Vec3::Vec3() : point3(0, 0, 0), magnitude(0) {}
Vec3::Vec3(double x, double y, double z) : point3(x, y, z), magnitude(sqrt(x*x + y*y + z*z)) {}

Vec3 Vec3::cross(Vec3 other) const {
   return {
      (y*other.z) - (z*other.y),
      (z*other.x) - (x*other.z),
      (x*other.y) - (y*other.x)
   };
}

Matrix::Matrix(
      float r11, float r12, float r13, float r14,
      float r21, float r22, float r23, float r24,
      float r31, float r32, float r33, float r34,
      float r41, float r42, float r43, float r44
) {
   data[0]  = r11; data[1]  = r12; data[2]  = r13; data[3]  = r14;
   data[4]  = r21; data[5]  = r22; data[6]  = r23; data[7]  = r24;
   data[8]  = r31; data[9]  = r32; data[10] = r33; data[11] = r34;
   data[12] = r41; data[13] = r42; data[14] = r43; data[15] = r44;
}

Matrix Matrix::orthographic(float left, float right, float bottom, float top, float zNear, float zFar) {
   float xScale = 2 / (right - left);
   float yScale = 2 / (top - bottom);
   float zScale = 2 / (zFar - zNear);
   float xOff = -(right + left) / (right - left);
   float yOff = -(top + bottom) / (top - bottom);
   float zOff = -(zFar + zNear) / (zFar - zNear);

   return {
      xScale, 0, 0, xOff,
      0, yScale, 0, yOff,
      0, 0, zScale, zOff,
      0, 0, 0, 1
   };
}

} // namespace zgm
