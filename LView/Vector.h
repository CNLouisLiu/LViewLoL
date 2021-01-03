#pragma once
#include "math.h"

struct Vector2 {
	Vector2() {};
	Vector2(float _x, float _y) {
		x = _x;
		y = _y; 
	}

	float x;
	float y;

	float length() {
		return sqrt(x*x + y * y);
	}
	void normalize() {
		float l = length();
		x = x / l;
		y = y / l;
	}

	float distance(const Vector2& o) {
		return sqrt(pow(x - o.x, 2) + pow(y - o.y, 2));
	}

	void scale(float s) {
		x *= s;
		y *= s;
	}

	void add(const Vector2& o) {
		x += o.x;
		y += o.y;
	}
};

struct Vector3 {
	Vector3() {};
	Vector3(float _x, float _y, float _z) {
		x = _x; 
		y = _y;
		z = _z; 
	}

	float x;
	float y;
	float z;

	float length() {
		return sqrt(x*x + y*y + z*z);
	}
	void normalize() {
		float l = length();
		x = x / l;
		y = y / l;
		z = z / l;
	}

	float distance(const Vector3& o) {
		return sqrt(pow(x - o.x, 2) + pow(y - o.y, 2) + pow(z - o.z, 2));
	}

	void scale(float s) {
		x *= s;
		y *= s;
		z *= s;
	}

	void rotate_x(float angle) {
		float ny = y * cos(angle) - z * sin(angle);
		float nz = y * sin(angle) + z * cos(angle);

		y = ny;
		z = nz;
	}

	void rotate_y(float angle) {
		float nx = x * cos(angle) + z * sin(angle);
		float nz = -x * sin(angle) + z * cos(angle);

		x = nx;
		z = nz;
	}

	void rotate_z(float angle) {
		float nx = x * cos(angle) - y * sin(angle);
		float ny = x * sin(angle) + y * cos(angle);
		
		x = nx;
		y = ny;
	}

	void add(const Vector3& o) {
		x += o.x;
		y += o.y;
		z += o.z;
	}
};

struct Vector4 {
	Vector4() {};
	Vector4(float _x, float _y, float _z, float _w) { 
		x = _x; 
		y = _y; 
		z = _z; 
		w = _w; 
	}

	float x;
	float y;
	float z;
	float w;

	float length() {
		return sqrt(x*x + y*y + z*z + w*w);
	}
	
	void normalize() {
		float l = length();
		x = x / l;
		y = y / l;
		z = z / l;
		w = w / l;
	}

	float distance(const Vector4& o) {
		return sqrt(pow(x - o.x, 2) + pow(y - o.y, 2) + pow(z - o.z, 2) + pow(w - o.w, 2));
	}

	void scale(float s) {
		x *= s;
		y *= s;
		z *= s;
		w *= s;
	}

	void add(const Vector4& o) {
		x += o.x;
		y += o.y;
		z += o.z;
		w += o.w;
	}
};