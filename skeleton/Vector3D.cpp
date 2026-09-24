#include "Vector3D.h"
#include <cmath>
//#include "foundation/Px.h"

Vector3D::Vector3D() : x(0), y(0), z(0) {

}

Vector3D::Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {

}

Vector3D::Vector3D(physx::PxVec3 v3)
	: x(v3.x), y(v3.y), z(v3.z)
{
}

float Vector3D::magnitude() const {
	return sqrtf(x * x + y * y + z * z);
}

Vector3D Vector3D::normalize() const {
	float d = magnitude();

	if (d == 0) {
		return Vector3D();
	}

	return Vector3D(x / d, y / d, z / d);
}

float Vector3D::dot(const Vector3D& v) const {
	return x * v.x + y * v.y + z * v.z;
}

Vector3D Vector3D::cross(const Vector3D& v) const {
	return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3D& Vector3D::operator=(const Vector3D& v) {
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}
Vector3D Vector3D::operator+(const Vector3D& v) const {
	return Vector3D(x + v.x, y + v.y, z + v.z);
}
Vector3D Vector3D::operator-(const Vector3D& v) const {
	return Vector3D(x - v.x, y - v.y, z - v.z);
}
Vector3D Vector3D::operator*(float k) const {
	return Vector3D(x * k, y * k, z * k);
}
Vector3D& Vector3D::operator+=(const Vector3D& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3D::operator physx::PxVec3() const {
	return physx::PxVec3(x, y, z);
}