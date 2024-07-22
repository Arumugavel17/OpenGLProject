#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

class VertexArray {
private:
	unsigned int RendererID;
public:
	VertexArray();
	~VertexArray();

	void AddVertexBuffer(const VertexBuffer& v_buffer,const VertexBufferLayout& v_bufferlayout);

	void Bind();
	void UnBind();
};