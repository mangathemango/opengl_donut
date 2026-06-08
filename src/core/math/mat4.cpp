#include <mat4.h>

Mat4::Mat4() {
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++) 
            this->m[y][x] = 0;
}

Mat4::Mat4(float m[4][4]) {
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++) 
            this->m[y][x] = m[y][x];
}

Mat4 Mat4::identity() {
    Mat4 result = Mat4();
    for (int i = 0; i < 4; i++) {
        result.m[i][i] = 1;
    }
    return result;
}

Mat4 Mat4::operator*(const Mat4& other) const {
    Mat4 result = Mat4();
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            for (int z = 0; z < 4; z++) {
                result.m[y][x] += this->m[y][z] * other.m[z][x];
            }
        }
    }
    return result;
}

// How did they even come up with this
Mat4::Mat4(Vec3 t, Quat r, Vec3 s) {
    float m[4][4] = {
        {
            s.x * (1 - 2*r.y*r.y - 2*r.z*r.z),
            s.y * (2*r.x*r.y - 2*r.z*r.w),
            s.z * (2*r.x*r.z + 2*r.y*r.w),
            t.x
        },
        {
            s.x * (2*r.x*r.y + 2*r.z*r.w),
            s.y * (1 - 2*r.x*r.x - 2*r.z*r.z),
            s.z * (2*r.y*r.z - 2*r.x*r.w),
            t.y
        },
        {
            s.x * (2*r.x*r.z - 2*r.y*r.w),
            s.y * (2*r.y*r.z + 2*r.x*r.w),
            s.z * (1 - 2*r.x*r.x - 2*r.y*r.y),
            t.z
        },
        {
            0,
            0,
            0,
            1
        }
    };
    *this = Mat4(m);
}
Mat4 Mat4::TRS(Vec3 translate, Quat rotate, Vec3 scale) {
    return Mat4(translate, rotate, scale);
}

Mat4 Mat4::translate(Vec3 v) const {
    Mat4 result = *this;
    result.m[0][3] += v.x;
    result.m[1][3] += v.y;
    result.m[2][3] += v.z;
    return result;
}

Mat4 Mat4::rotate(Quat q) const {
    float m[4][4] = {
        {
            (1 - 2*q.y*q.y - 2*q.z*q.z),
            (2*q.x*q.y - 2*q.z*q.w),
            (2*q.x*q.z + 2*q.y*q.w),
            0
        },
        {
            (2*q.x*q.y + 2*q.z*q.w),
            (1 - 2*q.x*q.x - 2*q.z*q.z),
            (2*q.y*q.z - 2*q.x*q.w),
            0
        },
        {
            (2*q.x*q.z - 2*q.y*q.w),
            (2*q.y*q.z + 2*q.x*q.w),
            (1 - 2*q.x*q.x - 2*q.y*q.y),
            0
        },
        {
            0,
            0,
            0,
            1
        }
    };
    return *this * Mat4(m);
}

Mat4 Mat4::scale(Vec3 v) const {
    Mat4 result = *this;
    for (int y = 0; y < 3; y++) {
        result.m[y][0] *= v.x;
        result.m[y][1] *= v.y;
        result.m[y][2] *= v.z;
    }
    return result;
    
};

Vec4 Mat4::operator*(Vec4 v) const {
    Vec4 result = Vec4();
    result.x = this->m[0][0] * v.x + this->m[0][1] * v.y + this->m[0][2] * v.z + this->m[0][3] * v.w;
    result.y = this->m[1][0] * v.x + this->m[1][1] * v.y + this->m[1][2] * v.z + this->m[1][3] * v.w;
    result.z = this->m[2][0] * v.x + this->m[2][1] * v.y + this->m[2][2] * v.z + this->m[2][3] * v.w;
    result.w = this->m[3][0] * v.x + this->m[3][1] * v.y + this->m[3][2] * v.z + this->m[3][3] * v.w;
    return result;
}

Vec3 Mat4::operator*(Vec3 v) const {
    return (*this * Vec4::fromVec3(v, 1)).toVec3();
}

ostream& operator<<(ostream& os, const Mat4& mat) {
    os << "Mat4 ";
    for (int y = 0; y < 4; y++) {
        os << "[";
        for (int x = 0; x < 4; x++) {
            os << mat.m[x][y];
            if (x != 3) os << ",";
        }
        os << "]" << endl << "     ";
    }
    return os;
}