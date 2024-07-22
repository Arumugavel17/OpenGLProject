#include "IndexBuffer.hpp"
#include "Renderer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* indecies, unsigned int count) 
{
	this->count = count;
	GLCall(glGenBuffers(1, &u_RenderID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, u_RenderID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indecies, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() 
{
	GLCall(glDeleteBuffers(1,&u_RenderID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0));
}

void IndexBuffer::Bind() const 
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, u_RenderID));
}

void IndexBuffer::UnBind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount() const { return count; };