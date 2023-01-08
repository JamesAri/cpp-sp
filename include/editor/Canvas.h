#ifndef CPP_SP_CANVAS_H
#define CPP_SP_CANVAS_H

#include "components/IDrawable.h"
#include "common/constants.h"

class Canvas : public IDrawable {
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

    void translate(const Point &point) override;

    void scale(const Point &pivot, float mod) override;

    void rotate(const Point &pivot, float angle) override;

    std::stringstream asSvg() override;

    std::vector<Point> asPgm() override;

};


#endif //CPP_SP_CANVAS_H
