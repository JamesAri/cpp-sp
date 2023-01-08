#include <sstream>
#include "Line.h"
#include "common/constants.h"

using namespace std::string_literals;

Line::Line(float x1, float y1, float x2, float y2) : mPoint1(x1, y1), mPoint2(x2, y2) {}

void Line::translate(const Point &point) {
    mPoint1.translate(point);
    mPoint2.translate(point);
}

void Line::scale(const Point &pivot, float mod) {
    mPoint1.scale(pivot, mod);
    mPoint2.scale(pivot, mod);
}

void Line::rotate(const Point &pivot, float angle) {
    mPoint1.rotate(pivot, angle);
    mPoint2.rotate(pivot, angle);
}

std::stringstream Line::asSvg() {
    std::stringstream ss;
    ss << "<line" << DEFAULT_BRUSH_STYLE
       << "x1=\"" << mPoint1.getX() << "\" "
       << "y1=\"" << mPoint1.getY() << "\" "
       << "x2=\"" << mPoint2.getX() << "\" "
       << "y2=\"" << mPoint2.getY() << "\" "
       << "/>";
    return ss;
}

std::vector<Point> Line::asPgm() {
    return {};
}