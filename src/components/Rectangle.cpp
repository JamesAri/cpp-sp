#include "Rectangle.h"

using namespace std::string_literals;

Rectangle::Rectangle(float x1, float y1, float width, float height) :
        mLine1(x1, y1, x1 + width, y1),
        mLine2(x1, y1, x1, y1 + height),
        mLine3(x1 + width, y1, x1 + width, y1 + height),
        mLine4(x1, y1 + height, x1 + width, y1 + height) {}

void Rectangle::translate(const Point &point) {
    mLine1.translate(point);
    mLine2.translate(point);
    mLine3.translate(point);
    mLine4.translate(point);
}

void Rectangle::scale(const Point &pivot, float mod) {
    mLine1.scale(pivot, mod);
    mLine2.scale(pivot, mod);
    mLine3.scale(pivot, mod);
    mLine4.scale(pivot, mod);
}

void Rectangle::rotate(const Point &pivot, float angle) {
    mLine1.rotate(pivot, angle);
    mLine2.rotate(pivot, angle);
    mLine3.rotate(pivot, angle);
    mLine4.rotate(pivot, angle);
}

std::stringstream Rectangle::asSvg() {
    std::stringstream ss;
    ss << mLine1.asSvg().str() << "\n"
       << mLine2.asSvg().str() << "\n"
       << mLine3.asSvg().str() << "\n"
       << mLine4.asSvg().str();
    return ss;
}

std::vector <Point> Rectangle::asPgm() {
    return std::vector<Point>();
}


