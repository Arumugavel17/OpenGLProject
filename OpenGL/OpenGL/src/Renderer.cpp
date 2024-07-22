#include "Renderer.hpp"
#include <iostream>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << ") " << function << " " << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::Draw(const VertexArray& vertexarray,const IndexBuffer& indexbuffer, const Shader& shader) {
    vertexarray.Bind();
    indexbuffer.Bind();
    shader.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, indexbuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

Renderer::Renderer() {

}

Renderer::~Renderer() {

}