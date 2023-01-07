#ifndef CPP_SP_CANVAS_H
#define CPP_SP_CANVAS_H

#include "IDrawable.h"
#include "common/constants.h"

class Canvas : IDrawable {
private:
    float mWidth;
    float mHeight;

    std::vector<std::shared_ptr<IDrawable>> mDrawables;

public:

    Canvas(float width, float height);

    [[nodiscard]] const std::vector<std::shared_ptr<IDrawable>> &getDrawables() {
        return mDrawables;
    }

    void add(std::shared_ptr<IDrawable> &drawable) {
        mDrawables.push_back(drawable);
    }

    [[nodiscard]] float getWidth() const;

    [[nodiscard]] float getHeight() const;

    void setWidth(float width);

    void setHeight(float height);

    void setSize(float width, float height);

    void translate() override;

    void scale() override;

    void rotate() override;

    std::stringstream asSvg() override;

    std::vector<Position> asPgm() override;

};


#endif //CPP_SP_CANVAS_H
