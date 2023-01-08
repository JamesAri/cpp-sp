#ifndef CPP_SP_POINT_H
#define CPP_SP_POINT_H

class Point {
private:
    float mX;
    float mY;
public:
    Point(const float mX, const float mY) : mX(mX), mY(mY) {};

    [[nodiscard]] float getX() const;

    [[nodiscard]] float getY() const;

    Point operator+(const Point &first) const;

    void operator+=(const Point &first);

    Point operator-(const Point &first) const;

    void operator-=(const Point &first);

    Point operator*(const float &mod) const;

    void operator*=(const float &mod);

    void translate(const Point &point);

    void rotate(const Point &pivot, float angle);

    void scale(const Point &pivot, float mod);
};


#endif //CPP_SP_POINT_H
