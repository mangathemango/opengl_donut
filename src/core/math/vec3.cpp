#include <vec3.h>

Vec3::Vec3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Operator overrides:
// Basic operations
Vec3 Vec3::operator-() const {
    return Vec3(-x, -y, -z);
}
Vec3 Vec3::operator+(const Vec3 &other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
};
Vec3 Vec3::operator-(const Vec3 &other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}
Vec3 Vec3::operator*(float scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}
Vec3 Vec3::operator/(float scalar) const {
    return Vec3(x / scalar, y / scalar, z / scalar);
}
// Some syntax sugar operations
Vec3& Vec3::operator+=(const Vec3 &other){
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
};

Vec3& Vec3::operator-=(const Vec3 &other){
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
};

Vec3& Vec3::operator*=(float scalar){
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
};

Vec3& Vec3::operator/=(float scalar){
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    return *this;
};

// Equality
bool Vec3::operator==(const Vec3 &other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vec3::operator!=(const Vec3 &other) const {
    return !(*this == other);
}
// <<
ostream& operator<<(ostream& os, const Vec3& v) {
    // I hate how this looks
    // for some reason #include <format> doesn't work lol
    os << "Vec3(" << v.x << "," << v.y << "," << v.z << ")";
    return os; 
}


// Direction vector
Vec3 Vec3::up()         {
    return Vec3(0,1,0); 
}
Vec3 Vec3::down()       {
    return Vec3(0,-1,0);
}
Vec3 Vec3::right()      {
    return Vec3(1,0,0); 
}
Vec3 Vec3::left()       {
    return Vec3(-1,0,0);
}
Vec3 Vec3::forward()    {
    return Vec3(0,0,1); 
}
Vec3 Vec3::backward()   {
    return Vec3(0,0,-1);
}

// More operations
Vec3 Vec3::cross(const Vec3 &other) const {
    return Vec3(y*other.z - other.y*z, other.x*z - other.z*x, x*other.y - y*other.x);
};
Vec3 Vec3::dot(const Vec3 &other) const {
    return Vec3(x*other.x, y*other.y, z*other.z);
}
Vec3 Vec3::normalize() const {
    float m = magnitude();
    if (m == 0) return *this;
    return *this / magnitude();
}
float Vec3::magnitude() const {
     return sqrt(x*x + y*y + z*z);
}

float Vec3::distance(const Vec3 &other) const {
	return (*this - other).magnitude();
}
Vec3 Vec3::lerp(const Vec3 &other, float t){
	return *this + (other - *this) * t;	
};
