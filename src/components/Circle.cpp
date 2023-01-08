#include "Circle.h"
#include "common/constants.h"

Circle::Circle(float x, float y, float mRadius) : mPoint(x, y), mRadius(mRadius) {}


void Circle::translate(const Point &point) {
    mPoint.translate(point);
}

void Circle::scale(const Point &pivot, float mod) {
    mPoint *= mod;
    mRadius *= mod;
}

void Circle::rotate(const Point &pivot, float angle) {
    mPoint.rotate(pivot, angle);
}

std::stringstream Circle::asSvg() {
    std::stringstream ss;

    ss << "<circle" << DEFAULT_BRUSH_STYLE
       << "cx=\"" << mPoint.getX() << "\" "
       << "cy=\"" << mPoint.getY() << "\" "
       << "r=\"" << mRadius << "\" "
       << "fill=\"transparent\""
       << "/>";

    return ss;
}

std::vector<Point> Circle::asPgm() {
    return std::vector<Point>();
}

