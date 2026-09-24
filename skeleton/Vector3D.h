#pragma once
#include <foundation/PxVec3.h>



class Vector3D
{
public:
	//Atributos publicos
	float x, y, z;

	//Constructores
	Vector3D();
	Vector3D(float _x, float _y, float _z);
	Vector3D(physx::PxVec3 v3);

	//Modulo y normalizacion
	float magnitude() const;
	Vector3D normalize() const;

	//Operaciones algebraicas
	float dot(const Vector3D& v) const;
	Vector3D cross(const Vector3D& v) const;
	//sobrecarga operadores
	Vector3D& operator=(const Vector3D& v);
	Vector3D operator+(const Vector3D& v1) const;
	Vector3D operator-(const Vector3D& v) const;
	Vector3D operator*(float k) const;
	Vector3D& operator+=(const Vector3D& v);

	//Wrapper
	operator physx::PxVec3() const;
};

