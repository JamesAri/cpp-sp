#include <cmath>
#include "common/Point.h"
#include <numbers>

constexpr auto RADS_MUL = std::numbers::pi / 180.0;

float Point::getX() const {
    return mX;
}

float Point::getY() const {
    return mY;
}

Point Point::operator+(const Point &first) const {
    return Point{mX + first.mX, mY + first.mY};
}

void Point::operator+=(const Point &first) {
    mX += first.mX;
    mY += first.mY;
}

Point Point::operator-(const Point &first) const {
    return Point{mX - first.mX, mY - first.mY};
}

void Point::operator-=(const Point &first) {
    mX -= first.mX;
    mY -= first.mY;
}

Point Point::operator*(const float &mod) const {
    return Point{mX * mod, mY * mod};
}

void Point::operator*=(const float &mod) {
    mX *= mod;
    mY *= mod;
}

void Point::translate(const Point &point) {
    *this += point;
}

void Point::rotate(const Point &pivot, float angle) {
    // https://stackoverflow.com/a/2259502/14934056 (⌐■_■)
    auto t = angle * RADS_MUL;
    auto s = static_cast<float>(sin(t));
    auto c = static_cast<float>(cos(t));

    *this -= pivot;
    mX = mX * c - mY * s;
    mY = mX * s + mY * c;
    *this += pivot;
}

void Point::scale(const Point &pivot, float mod) {
    *this -= pivot;
    *this *= mod;
    *this += pivot;
}
