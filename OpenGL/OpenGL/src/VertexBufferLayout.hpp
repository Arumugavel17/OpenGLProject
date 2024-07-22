#pragma once

#include <vector>
#include "Renderer.hpp"

struct VertexBufferElements {

	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int SizeOf(unsigned int type) {
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElements> elements;
	unsigned int m_stride;
public:
	VertexBufferLayout() : m_stride{ 0 } {

	}

	template<typename T>
	void Push(unsigned int count) {
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count) {
		elements.push_back({GL_FLOAT,count,GL_FALSE});
		m_stride += count * VertexBufferElements::SizeOf(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_INT,count,GL_FALSE });
		m_stride += count * VertexBufferElements::SizeOf(GL_UNSIGNED_INT);
	}


	template<>
	void Push<unsigned char>(unsigned int count) {
		elements.push_back({ GL_UNSIGNED_BYTE,count,GL_FALSE });
		m_stride += count * VertexBufferElements::SizeOf(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElements> GetElements() const {
		return elements;
	}

	inline const unsigned int GetStride() const { return m_stride; };
};