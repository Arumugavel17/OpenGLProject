#include "VertexBuffer.hpp"
#include "Renderer.hpp"

VertexBuffer::VertexBuffer(const void* Data, unsigned int Size) 
{
	GLCall(glGenBuffers(1, &u_RenderID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, u_RenderID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, Size, Data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() 
{
	GLCall(glDeleteBuffers(1, &u_RenderID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::Bind() const 
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, u_RenderID));
}

void VertexBuffer::UnBind() const 
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}