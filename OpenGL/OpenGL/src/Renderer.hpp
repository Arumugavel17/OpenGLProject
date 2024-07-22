#include <Gl/glew.h>
#include "Shader.hpp"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
//
//class Renderer {
//public:
//    Renderer();
//    ~Renderer();
//
//    void Draw(const VertexArray& vertexarray, const IndexBuffer& indexbuffer,const Shader& shader) ;
//    void Clear() const;
//};