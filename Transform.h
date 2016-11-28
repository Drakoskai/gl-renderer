#pragma once

#include "Matrix.h"

class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void Translate(Vector3f vector);
	void Translate(float x, float y, float z);
	void Scale(float factor);
	void Scale(float h, float w, float d);
	void Rotate(float angle, Vector3f axis);
	void Rotate(float angle, float x, float y, float z);
	float * GetModelToClipMatrix();

private:
	Matrix translationMatrix;
	Matrix rotationMatrix;
};
