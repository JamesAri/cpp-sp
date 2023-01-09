#include "editor/Canvas.h"
#include "util/vector-util.h"

Canvas::Canvas(float width, float height) : mWidth(width), mHeight(height) {}

void Canvas::add(std::unique_ptr<IDrawable> drawable) {
    mDrawables.push_back(std::move(drawable));
}

float Canvas::getWidth() const {
    return mWidth;
}

float Canvas::getHeight() const {
    return mHeight;
}


std::stringstream Canvas::asSvg() {
    std::stringstream ss;
    for (auto const &drawable: mDrawables) {
        ss << drawable->asSvg().str() << "\n";
    }
    return ss;
}

std::vector<Point> Canvas::asPgm() {
    std::vector<Point> dest = std::vector<Point>();
    for (auto const &drawable: mDrawables) {
        auto src = drawable->asPgm();
        moveVector(src, dest);
    }
    return dest;
}

void Canvas::translate(const Point &point) {
    for (auto const &drawable: mDrawables) {
        drawable->translate(point);
    }
}

void Canvas::scale(const Point &pivot, float mod) {
    for (auto const &drawable: mDrawables) {
        drawable->scale(pivot, mod);
    }
}

void Canvas::rotate(const Point &pivot, float angle) {
    for (auto const &drawable: mDrawables) {
        drawable->rotate(pivot, angle);
    }
}





