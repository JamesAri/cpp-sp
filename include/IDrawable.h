#ifndef CPP_SP_IDRAWABLE_H
#define CPP_SP_IDRAWABLE_H

#include <sstream>
#include <vector>
#include "Position.h"

class IDrawable {
public:
    virtual void translate() = 0;
    virtual void scale() = 0;
    virtual void rotate() = 0;

    virtual std::stringstream asSvg() = 0;
    virtual std::vector<Position> asPgm() = 0;

    virtual ~IDrawable() = default;
};


#endif //CPP_SP_IDRAWABLE_H
