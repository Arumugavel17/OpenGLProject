#include "VertexArray.hpp"
#include "Renderer.hpp"

VertexArray::VertexArray() {
	GLCall(glGenVertexArrays(1, &RendererID));
}

VertexArray::~VertexArray() {

}

void VertexArray::AddVertexBuffer(const VertexBuffer& v_buffer, const VertexBufferLayout& v_bufferlayout) {
	Bind();
	v_buffer.Bind();
	const auto& elements = v_bufferlayout.GetElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized,v_bufferlayout.GetStride(), (const void*)offset));
		offset += VertexBufferElements::SizeOf(element.type);
	}
}

void VertexArray::Bind() {
	GLCall(glBindVertexArray(RendererID));
}

void VertexArray::UnBind() {
	GLCall(glBindVertexArray(0));
}