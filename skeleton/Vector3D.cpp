#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D() : x(0), y(0), z(0) {

}

Vector3D::Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {

}

float Vector3D::magnitude() const {
	return sqrtf(x * x + y * y + z * z);
}

Vector3D Vector3D::normalize() const {
	float d = magnitude();
	return Vector3D(x / d, y / d, z / d);
}

float Vector3D::dot(const Vector3D& v) const {
	Vector3D v1 = normalize();
	float d1 = v1.magnitude();
	Vector3D v2 = v.normalize();
	float d2 = v2.magnitude();
	return d1 * d2;
}

Vector3D Vector3D::cross(const Vector3D& v) const {
	return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

void Vector3D::operator=(Vector3D& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}
Vector3D Vector3D::operator+(Vector3D& v) {
	return Vector3D(x + v.x, y + v.y, z + v.z);
}
Vector3D Vector3D::operator-(Vector3D& v) {
	return Vector3D(x - v.x, y - v.y, z - v.z);
}
Vector3D Vector3D::operator*(float k) {
	return Vector3D(x * k, y * k, z * k);
}
Vector3D Vector3D::operator+=(Vector3D& v) {

	//return 
}