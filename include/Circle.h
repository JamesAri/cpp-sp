#ifndef CPP_SP_CIRCLE_H
#define CPP_SP_CIRCLE_H


#include "IDrawable.h"

class Circle : public IDrawable {
private:
    Point mPoint;
    float mRadius;
public:
    Circle(float x, float y, float mRadius);

    void translate(const Point &point) override;

    void scale(const Point &pivot, float mod) override;

    void rotate(const Point &pivot, float angle) override;

    std::stringstream asSvg() override;

    std::vector<Point> asPgm() override;
};


#endif //CPP_SP_CIRCLE_H
