#pragma once

class IndexBuffer 
{
private:
	unsigned int u_RenderID;
	unsigned int count;
public:
	IndexBuffer(const unsigned int* indecies, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	unsigned int GetCount() const;
};