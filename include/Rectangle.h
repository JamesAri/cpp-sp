#ifndef CPP_SP_RECTANGLE_H
#define CPP_SP_RECTANGLE_H


#include "IDrawable.h"
#include "Line.h"

class Rectangle: public IDrawable {
private:
    Line mLine1;
    Line mLine2;
    Line mLine3;
    Line mLine4;
public:
    Rectangle(float x1, float y1, float width, float height);

    void translate(const Point &point) override;

    void scale(const Point &pivot, float mod) override;

    void rotate(const Point &pivot, float angle) override;

    std::stringstream asSvg() override;

    std::vector<Point> asPgm() override;
};


#endif //CPP_SP_RECTANGLE_H
