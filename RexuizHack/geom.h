#pragma once
#include <algorithm>



class Vector3
{
public:

	float x, y, z;

	Vector3() {};
	Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
	Vector3 operator + (const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	Vector3 operator - (const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
	Vector3 operator * (const float& rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }
	Vector3 operator / (const float& rhs) const { return Vector3(x / rhs, y / rhs, z / rhs); }
	Vector3& operator += (const Vector3& rhs) { return *this = *this + rhs; }
	Vector3& operator -= (const Vector3& rhs) { return *this = *this - rhs; }
	Vector3& operator *= (const float& rhs) { return *this = *this * rhs; }
	Vector3& operator /= (const float& rhs) { return *this = *this / rhs; }
	float Length() const { return sqrtf(x * x + y * y + z * z); }
	Vector3 Normalize() const { return *this * (1 / Length()); }
	float Distance(const Vector3& rhs) const { return (*this - rhs).Length(); }
};



struct ScreenCords
{
	int x, y;
};

struct Vec4
{
	float x, y, z, w;
};

struct pmatrix 
{
	float v[16];
};

using Vec3 = Vector3;
using vec3 = Vector3;
using Vec = Vector3;
using vec = Vector3;


struct refdef_t
{
	int            x, y, width, height;
	float        fov_x, fov_y;
	vec3        vieworg;
	vec3        viewaxis[3];        // transformation matrix
};

vec3 Subtract(vec3 src, vec3 dst);
bool WorldToScreen(vec3 src, vec3 dst, vec3& screen, float fovx, float fovy, int windowWidth, int windowHeight, vec3 left, vec3 up, vec3 forward);

