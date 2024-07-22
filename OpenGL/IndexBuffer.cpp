#include "IndexBuffer.h"
#include "Renderer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* indecies, unsigned int count) {
   
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, u_RenderID));
}

void IndexBuffer::UnBind() const {
    GLCall(gl)
}