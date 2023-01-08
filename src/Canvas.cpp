#include "Canvas.h"

Canvas::Canvas(float width, float height) : mWidth(width), mHeight(height) {}

float Canvas::getWidth() const {
    return mWidth;
}

float Canvas::getHeight() const {
    return mHeight;
}

std::stringstream Canvas::asSvg() {
    std::stringstream ss;
    for (auto const &drawable : mDrawables) {
        ss << drawable->asSvg().str() << "\n";
    }
    return ss;
}

std::vector<Point> Canvas::asPgm() {
    return std::vector<Point>();
}

void Canvas::translate(const Point &point) {
    for (auto const &drawable : mDrawables) {
        drawable->translate(point);
    }
}

void Canvas::scale(const Point &pivot, float mod) {
    for (auto const &drawable : mDrawables) {
        drawable->scale(pivot, mod);
    }
}

void Canvas::rotate(const Point &pivot, float angle) {
    for (auto const &drawable : mDrawables) {
        drawable->rotate(pivot, angle);
    }
}


