#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

#include <ostream>

namespace zgm {

template <typename T>
struct point2 {
   T x;
   T y;
};

template <typename T>
struct point3 {
   T x;
   T y;
   T z;
};

template <typename T>
struct line2 {
   point2<T> p1;
   point2<T> p2;
};

template <typename T>
struct line3 {
   point3<T> p1;
   point3<T> p2;
};

// Vectors
class Vec2 : public point2<const double> {
   public:
      const double magnitude;

      Vec2();
      Vec2(double x, double y);
      Vec2(point2<double> p);
      Vec2(point2<const double> p);

      Vec2   unit()         const;
      double dot(Vec2)      const;
      Vec2   reflect(Vec2)  const;
      Vec2   reflectAxisX() const;
      Vec2   reflectAxisY() const;

      double cosRadsBetween(Vec2) const;
      double radsBetween(Vec2)    const;

      Vec2 operator*(double) const;
      Vec2 operator/(double) const;

      Vec2 operator+(Vec2) const;
      Vec2 operator-(Vec2) const;

      operator point2<double>() const;

      friend std::ostream& operator<<(std::ostream&, const Vec2&);
};

class Vec3 : public point3<const double> {
   public:
      const double magnitude;

      Vec3();
      Vec3(double x, double y, double z);

      Vec3   unit()  const;
      double dot()   const;
      Vec3   cross(Vec3) const;

      operator point3<double>() const;
};

class Uniform {};

class Matrix {
   public:
      static Matrix orthographic(float left, float right, float bottom, float top, float zNear, float zFar);

      float data[4*4];

      Matrix(
         float r11, float r12, float r13, float r14,
         float r21, float r22, float r23, float r24,
         float r31, float r32, float r33, float r34,
         float r41, float r42, float r43, float r44
      );
};

} // namespace zgm

#endif
