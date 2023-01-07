#include <sstream>
#include "Line.h"
#include "common/constants.h"

using namespace std::string_literals;

void Line::translate() {
}

void Line::scale() {
}

void Line::rotate() {
}

std::stringstream Line::asSvg() {
    std::stringstream ss;
    ss << "<line x1=\"" << mPoint1.mX
       << "\" y1=\"" << mPoint1.mY
       << "\" x2=\"" << mPoint2.mX
       << "\" y2=\"" << mPoint2.mY
       << "\" stroke=\"" << STROKE_DEFAULT_COLOR
       << "\"/>";
    return ss;
}

std::vector<Position> Line::asPgm() {
    return {};
}

Line::Line(float x1, float y1, float x2, float y2) : mPoint1(x1, y1), mPoint2(x2, y2) {}

