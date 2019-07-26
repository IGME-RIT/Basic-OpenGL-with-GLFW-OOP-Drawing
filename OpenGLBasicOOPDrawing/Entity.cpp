#include "Entity.h"



void Entity::CalcWorldMatrix()
{
	rotMat = glm::yawPitchRoll(glm::radians(eulerRotation.y), glm::radians(eulerRotation.x), glm::radians(eulerRotation.z));//creates a rotation matrix based on a yaw(y rotation), pitch (x rotation) and roll (z rotation)

	//WORLD MATRIX CALCULATION
		//We want to create a 4x4 matrix for our triangle
		//This matrix will have 3 main components
		//Translation matrix - tells us where to move our vertices
		//Rotation matrix -	tells us how to rotate the model
		//Scale matrix - tells us the size of the model
		//World Matrix = Translation Matrix* Rotation Matrix *Scale Matrix  ***IN ORDER***
		//With matrix multiplication, order matters.
		//Otherwise we manipulate vertices incorrectly
	worldMatrix = glm::translate(position) *													//creates a translation matrix taking our position as the parameter
				  rotMat*    
				  glm::scale(scale);															//creates a scale matrix taking our scale vector

	recalculateWMatrix = false;
}

Entity::Entity()
{
	
}


Entity::~Entity()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Entity::Update()
{
	if(recalculateWMatrix)
		CalcWorldMatrix();

	glUniformMatrix4fv(2, 1, GL_FALSE, &worldMatrix[0][0]);
}

void Entity::LoadBuffers()
{
	glGenVertexArrays(1, &VAO);

	glGenBuffers(1, &VBO);				//Generating VBO
	glBindVertexArray(VAO);				//Binding the VAO so we can manipulate it
	glBindBuffer(GL_ARRAY_BUFFER, VBO);	//Binding the VBO so we can manipulate it

	//Defining VBO data
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(glm::vec3)*vertices.size(), //The data size is the size of one vec3 multiplied by the number of vertices
		&vertices[0],					  //We want to start at the first index of the vector, so we point to it
		GL_STATIC_DRAW);

	//Defining our vertex data

	//Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * 2, 0);

	//New Color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * 2, (GLvoid *)(sizeof(glm::vec3)));
	// Enable the generic vertex attribute array created above using the the function glEnableVertexAttributeArray,
	// passing in the index of the vertex attribute array

	//Unbinding both our OpenGL objects
	glBindBuffer(0, VBO);
	glBindVertexArray(0);

}

void Entity::RenderEntity()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glBindVertexArray(0);	//Unbind after we're finished drawing this entity.
}

std::vector<glm::vec3> & Entity::SetVertices()
{
	return vertices;
}
