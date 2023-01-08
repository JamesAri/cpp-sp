#ifndef CPP_SP_LINE_H
#define CPP_SP_LINE_H

#include "IDrawable.h"

class Line : public IDrawable {
private:
    Point mPoint1;
    Point mPoint2;

public:
    Line(float x1, float y1, float x2, float y2);

    void translate(const Point &point) override;

    void scale(const Point &pivot, float mod) override;

    void rotate(const Point &pivot, float angle) override;

    std::stringstream asSvg() override;

    std::vector<Point> asPgm() override;
};


#endif //CPP_SP_LINE_H
