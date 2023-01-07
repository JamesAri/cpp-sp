#ifndef CPP_SP_LINE_H
#define CPP_SP_LINE_H

#include "IDrawable.h"

class Line : public IDrawable {
private:
    Position mPoint1;
    Position mPoint2;

public:
    Line(float x1, float y1, float x2, float y2);

    void translate() override;

    void scale() override;

    void rotate() override;

    std::stringstream asSvg() override;

    std::vector<Position> asPgm() override;
};


#endif //CPP_SP_LINE_H
