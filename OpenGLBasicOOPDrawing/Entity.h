//2D Entity

#pragma once

#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//GLM provides new data types and math helper functions for any vector math we want to do.
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

class Entity
{
	glm::vec3 position;
	glm::vec3 scale = glm::vec3(1.f,1.f,1.f);
	glm::vec3 eulerRotation;
	glm::mat4 rotMat;
	glm::mat4 worldMatrix;

	std::vector<glm::vec3> vertices;
	GLuint VAO;
	GLuint VBO;

	bool recalculateWMatrix = true;

	void CalcWorldMatrix();
public:
	Entity();
	virtual ~Entity();



	void Update();
	void LoadBuffers();
	void RenderEntity();
	std::vector<glm::vec3>& SetVertices();

	
};

