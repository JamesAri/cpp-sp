#ifndef CPP_SP_LINE_H
#define CPP_SP_LINE_H

#include "IDrawable.h"

class Line : public IDrawable {
private:
    Position mPosition;

public:
    Line(float x, float y);

    void translate() override;

    void scale() override;

    void rotate() override;

    std::string asSvg() override;

    std::vector<Position> asPgm() override;
};


#endif //CPP_SP_LINE_H
