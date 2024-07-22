#pragma once

class VertexBuffer {
private:
	unsigned int u_RenderID;
public:
	VertexBuffer(const void* Data,unsigned int Size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};