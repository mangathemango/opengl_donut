#include <vec4.h>

Vec4::Vec4() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

Vec4::Vec4(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vec4::Vec4(Vec3 v, float w) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = w;
}

Vec4 Vec4::fromVec3(Vec3 v, float w) {
    return Vec4(v,w);
}

Vec3 Vec4::toVec3() {
    return Vec3(x,y,z);
}

// Operator overrides:
// Basic operations
Vec4 Vec4::operator-() const {
    return Vec4(-x, -y, -z, -w);
}
Vec4 Vec4::operator+(const Vec4 &other) const {
    return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
};
Vec4 Vec4::operator-(const Vec4 &other) const {
    return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}
Vec4 Vec4::operator*(float scalar) const {
    return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}
Vec4 Vec4::operator/(float scalar) const {
    return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
}
// Some syntax sugar operations
Vec4& Vec4::operator+=(const Vec4 &other){
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;
    return *this;
};

Vec4& Vec4::operator-=(const Vec4 &other){
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;
    return *this;
};

Vec4& Vec4::operator*=(float scalar){
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    this->w *= scalar;
    return *this;
};

Vec4& Vec4::operator/=(float scalar){
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    this->w /= scalar;
    return *this;
};

// Equality
bool Vec4::operator==(const Vec4 &other) const {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vec4::operator!=(const Vec4 &other) const {
    return !(*this == other);
}
// <<
ostream& operator<<(ostream& os, const Vec4& v) {
    // I hate how this looks
    // for some reason #include <format> doesn't work lol
    os << "Vec4(" << v.x << "," << v.y << "," << v.z << "," << v.w << ")";
    return os; 
}


