#include <vec2.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

Vec2::Vec2() {
    this->x = 0;
    this->y = 0;
}

Vec2::Vec2(float size) {
    this->x = size;
    this->y = size;
}

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator-() const {
    return Vec2(
        -x,
        -y
    );
}
Vec2 Vec2::operator+(const Vec2 &other) const{ 
    return Vec2(
        x + other.x, 
        y + other.y
    );
}

Vec2 Vec2::operator-(const Vec2 &other) const{
    return Vec2(
        x - other.x, 
        y - other.y
    );
}
Vec2 Vec2::operator*(float scalar) const {
    return Vec2(
        x * scalar, 
        y * scalar
    );   
}
Vec2 Vec2::operator/(float scalar) const {
    return Vec2(
        x / scalar, 
        y / scalar
    );   
}
// Some syntax sugar operations
Vec2& Vec2::operator+=(const Vec2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}
Vec2& Vec2::operator-=(const Vec2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
Vec2& Vec2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}
Vec2& Vec2::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
// Equality
bool Vec2::operator==(const Vec2 &other) const {
    return x == other.x && y == other.y;
};
bool Vec2::operator!=(const Vec2 &other) const {
    return x != other.x || y != other.y;
};
// Direction vector
Vec2 Vec2::up() {
    return Vec2(0,-1);
};
Vec2 Vec2::down() {
    return Vec2(0, 1);
};
Vec2 Vec2::right() {
    return Vec2(1, 0);
};
Vec2 Vec2::left() {
    return Vec2(-1, 0);
};
// More operations
float Vec2::cross(const Vec2 &other) const {
    return x * other.y - y * other.x; 
};
float Vec2::dot(const Vec2 &other) const {
    return x * other.x + y * other.y;
};
Vec2 Vec2::abs() const {
    return Vec2(std::abs(x), std::abs(y));
};
Vec2 Vec2::normalize() const {
    float m = magnitude();
    if (m == 0) return *this;
    return (*this) / m;
}
float Vec2::magnitude() const {
    return std::sqrt(x*x + y*y);
}
float Vec2::distance(const Vec2 &other) const {
    return (*this - other).magnitude();
}
Vec2 Vec2::lerp(const Vec2 &other, float t) const {
    return *this + (other - *this) * t;
}

Vec2 Vec2::rotateRadian(float angle) const {
    return Vec2(
        x * cos(angle) - y * sin(angle),
        x * sin(angle) + y * cos(angle)
    );
}

Vec2 Vec2::rotateDegrees(float angle) const {
    float radian = angle * M_PI / 180;
    return rotateRadian(radian);
}

Vec2 Vec2::rotateRadianAround(float angle, const Vec2& other) const {
    return (*this - other).rotateRadian(angle) + other;
}
Vec2 Vec2::rotateDegreesAround(float angle, const Vec2& other) const {
    float radian = angle * M_PI / 180;
    return rotateRadianAround(radian, other);
}

float Vec2::angleBetween(const Vec2& other) const
{
    float cross = x * other.y - y * other.x;
    float dot   = x * other.x + y * other.y;

    return atan2f(cross, dot);
}

ostream& operator<<(ostream& os, Vec2& v) {
    os << "Vec2(" << v.x << "," << v.y << ")";
    return os;
}