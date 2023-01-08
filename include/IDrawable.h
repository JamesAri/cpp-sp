#ifndef CPP_SP_IDRAWABLE_H
#define CPP_SP_IDRAWABLE_H

#include <sstream>
#include <vector>
#include "common/Point.h"

class IDrawable {
public:
    virtual void translate(const Point &point) = 0;
    virtual void scale(const Point &pivot, float mod) = 0;
    virtual void rotate(const Point &pivot, float angle) = 0;

    virtual std::stringstream asSvg() = 0;
    virtual std::vector<Point> asPgm() = 0;

    virtual ~IDrawable() = default;
};


#endif //CPP_SP_IDRAWABLE_H
