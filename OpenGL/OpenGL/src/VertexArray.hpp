#pragma once

#include "VertexBuffer.hpp"
class VertexBufferLayout;

class VertexArray {
private:
	unsigned int RendererID;
public:
	VertexArray();
	~VertexArray();

	void AddVertexBuffer(const VertexBuffer& v_buffer,const VertexBufferLayout& v_bufferlayout);

	void Bind() const;
	void UnBind() const;
};