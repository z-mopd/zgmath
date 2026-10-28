#include <iostream>
#include <zgmath/data_types.hpp>
#include <zgmath/analytic.hpp>

int main() {
   zgm::point2<double> myPoint = {10, 10};

   zgm::Vec2 myVector = {20, 0};
   zgm::Vec2 otherVec{myPoint};
   zgm::Vec2 lengthyVector = {200, 400};

   std::cout << myVector << '\n';
   std::cout << myVector.dot(otherVec) << '\n';
   std::cout << zgm::toDegrees(myVector.radsBetween(otherVec)) << '\n';

   std::cout << "unit: " << myVector.unit() << '\n';
   std::cout << "unit: " << lengthyVector.unit() << '\n';

   std::cout << "reflected: " << lengthyVector.reflectAxisX() << '\n';

   std::cout << "free function dot: " << zgm::dot(myPoint, myVector) << '\n';

   return 0;
}
