#include "Canvas.h"

Canvas::Canvas(float width, float height) : mWidth(width), mHeight(height) {}

void Canvas::setSize(float width, float height) {
    setWidth(width);
    setHeight(height);
}

float Canvas::getWidth() const {
    return mWidth;
}

float Canvas::getHeight() const {
    return mHeight;
}

void Canvas::setWidth(float width) {
    Canvas::mWidth = width;
}

void Canvas::setHeight(float height) {
    Canvas::mHeight = height;
}

void Canvas::translate() {

}

void Canvas::scale() {

}

void Canvas::rotate() {

}

std::string Canvas::asSvg() {
    return std::string();
}

std::vector<Position> Canvas::asPgm() {
    return std::vector<Position>();
}
