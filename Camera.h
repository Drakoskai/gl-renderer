#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "Interfaces.h"
#include "Frustum.h"

class CameraSimpleOrtho
{
public:
	CameraSimpleOrtho();
	~CameraSimpleOrtho();

	void Update(float ratio);
	Matrix GetModelView() const;
private:
	Matrix model;
	Matrix perspective;
	Matrix modelViewPerspective;
};

class CameraPerspective
{
public:
	CameraPerspective();
	~CameraPerspective();

	void Update();

	void GetModelView(Matrix& modelView) const;
	void GetProjection(Matrix& projection) const;

	void GetPosition(Vector3f& pos) const;
	void GetRotation(Vector3f& rot) const;

	void GetUp(Vector3f& up) const;
	void GetForward(Vector3f& forward) const;

private:
	Matrix m_modelView;
	Matrix m_projection;

	Frustum m_frustum;

	Vector3f m_up;
	Vector3f m_lookAt;
	Vector3f m_position;
	Vector3f m_rotation;
	
	float m_nearClip;
	float m_farClip;
	float m_fieldofView;
	float m_screenAspect;

	float m_viewportWidth;
	float m_viewportHeight;

};
