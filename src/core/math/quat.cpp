#include <quat.h>

// Understanding these implementations requires a lot of reading (that i gave up on) 
// on how Quaternions works. I think you kinda literally need to ascend to a higher
// being to understand these 4D stuffs.

Quat::Quat() {
    this->w = 0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Quat::Quat(float w, float x, float y, float z) {
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

Quat Quat::identity() {
    return Quat(1,0,0,0);
}

Quat Quat::inverse() const {
    return Quat(w, -x, -y, -z);
}

Quat Quat::normalise() const {
    float m = sqrt(w*w + x*x + y*y + z*z);
    if (m == 0) return *this;
    return Quat(w/m, x/m, y/m, z/m);
}


// Note: angle is in radians
// Not sure how this works either
Quat::Quat(Vec3 axis, float angle) {
    this->w = cos(angle/2);
    Vec3 transformed = axis.normalize() * sin(angle/2);
    this->x = transformed.x;
    this->y = transformed.y;
    this->z = transformed.z;
}

/*
    This magical code rotates vector by the Quaterion. Direction is decided by the right hand rule (omg fiskis)
    I gave up trying to understand why this formula works. But it works

    For example, this code snippet rotates a vector 90 degrees (pi/2 radians) along the up axis (Vec3(0,1,0))
    Rotation direction is counter-clockwise because right hand rule

    Vec3 v = Vec3(2, 0, 0); // Points right
    v = Quat(Vec3::up(), M_PI/2) * v; 
    cout << v << endl; // should be Vec3(0,0,-2), Points into the screen
*/
Vec3 Quat::operator*(Vec3 v) const
{
    Vec3 u(x, y, z);

    Vec3 uv  = u.cross(v);
    Vec3 uuv = u.cross(uv);

    uv  *= (2.0f * w);
    uuv *= 2.0f;

    return v + uv + uuv;
}

// Yeah don't even want to bother with this one as well
Quat Quat::operator*(Quat q) const
{
    return {
        w*q.w - x*q.x - y*q.y - z*q.z,
        w*q.x + x*q.w + y*q.z - z*q.y,
        w*q.y - x*q.z + y*q.w + z*q.x,
        w*q.z + x*q.y - y*q.x + z*q.w
    };
}

Vec3 Quat::up() const {
    return *this * Vec3::up();
}

Vec3 Quat::forward() const {
    return *this * Vec3::forward();
}

Vec3 Quat::right() const {
    return *this * Vec3::right();
}

ostream& operator<<(ostream& os, Quat q) {
    os << "Quat(" << q.w << "," << q.x << "," << q.y << ","  << q.z << ")";
    return os;
}