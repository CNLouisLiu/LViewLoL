#pragma once

struct Vector2 {
	Vector2() {};
	Vector2(float _x, float _y) {
		x = _x;
		y = _y; 
	}

	float x;
	float y;
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
};