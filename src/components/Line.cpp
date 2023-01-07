#include "Line.h"

void Line::translate() {
}

void Line::scale() {
}

void Line::rotate() {
}

std::string Line::asSvg() {
    return "";
}

std::vector<Position> Line::asPgm() {
    return {};
}

Line::Line(float x, float y) : mPosition(x, y) {}

