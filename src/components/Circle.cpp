#include "components/Circle.h"
#include "common/constants.h"

Circle::Circle(float x, float y, float radius) : mPoint(x, y), mRadius(radius) {
    if (radius <= 0) {
        throw std::runtime_error(INVALID_CIRCLE_RADIUS_ERROR);
    }
}


void Circle::translate(const Point &point) {
    mPoint.translate(point);
}

void Circle::scale(const Point &pivot, float mod) {
    mRadius *= mod;
    mPoint *= mod;
}

void Circle::rotate(const Point &pivot, float angle) {
    mPoint.rotate(pivot, angle);
}

std::stringstream Circle::asSvg() {
    std::stringstream ss;

    ss << "<circle" << SVG_DEFAULT_BRUSH_STYLE
       << "cx=\"" << mPoint.getX() << "\" "
       << "cy=\"" << mPoint.getY() << "\" "
       << "r=\"" << mRadius << "\" "
       << "fill=\"transparent\""
       << "/>";

    return ss;
}

std::vector<Point> Circle::asPgm() {
    auto points = std::vector<Point>();

    auto xm = static_cast<int>(mPoint.getX());
    auto ym = static_cast<int>(mPoint.getY());
    auto r = static_cast<int>(mRadius);

    int x = -r, y = 0, err = 2 - 2 * r;
    do {
        points.emplace_back(xm - x, ym + y);
        points.emplace_back(xm - y, ym - x);
        points.emplace_back(xm + x, ym - y);
        points.emplace_back(xm + y, ym + x);
        r = err;
        if (r <= y) err += ++y * 2 + 1;
        if (r > x || err > y) err += ++x * 2 + 1;
    } while (x < 0);
    return points;
}
