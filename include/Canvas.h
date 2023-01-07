#ifndef CPP_SP_CANVAS_H
#define CPP_SP_CANVAS_H

#include "IDrawable.h"
#include "constants.h"

class Canvas: IDrawable {
private:
    float mWidth;
    float mHeight;

    Canvas(float width, float height);

    std::vector<IDrawable> mDrawables;

public:
    [[nodiscard]] const std::vector<IDrawable> &getDrawables() {
        return mDrawables;
    }

    [[nodiscard]] float getWidth() const;

    [[nodiscard]] float getHeight() const;

    void setWidth(float width);

    void setHeight(float height);

    void setSize(float width, float height);

    void translate() override;

    void scale() override;

    void rotate() override;

    std::string asSvg() override;

    std::vector<Position> asPgm() override;

};


#endif //CPP_SP_CANVAS_H
