#include <sstream>
#include "components/Line.h"
#include "common/constants.h"

Line::Line(float x1, float y1, float x2, float y2) : mPoint1(x1, y1), mPoint2(x2, y2) {
    if (!(x1 != x2 || y1 != y2)) {
        throw std::runtime_error(INVALID_LINE_POINTS_ERROR);
    }
}

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
    ss << "<line" << SVG_DEFAULT_BRUSH_STYLE
       << "x1=\"" << mPoint1.getX() << "\" "
       << "y1=\"" << mPoint1.getY() << "\" "
       << "x2=\"" << mPoint2.getX() << "\" "
       << "y2=\"" << mPoint2.getY() << "\" "
       << "/>";
    return ss;
}

std::vector<Point> Line::asPgm() {
    auto points = std::vector<Point>();

    auto x1 = static_cast<int>(mPoint1.getX());
    auto y1 = static_cast<int>(mPoint1.getY());
    auto x2 = static_cast<int>(mPoint2.getX());
    auto y2 = static_cast<int>(mPoint2.getY());

    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    for (;;) {
        points.emplace_back(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y1 += sy;
        }
    }

    return points;
}