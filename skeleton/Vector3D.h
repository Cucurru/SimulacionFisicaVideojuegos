#pragma once
#include <foundation/Px.h>



class Vector3D
{
public:
	//Atributos publicos
	float x, y, z;
	float atrib;
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
	void operator=(Vector3D& v);
	Vector3D operator+(Vector3D& v1);
	Vector3D operator-(Vector3D& v);
	Vector3D operator*(float k);
	Vector3D operator+=(Vector3D& v);

	//Wrapper
	operator physx::PxVec3() const;

};

