#pragma once
#include "Renderer.hpp"

class Texture
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BitsPerPixel;
public:
	Texture(std::string filepath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void UnBind() const;

	inline unsigned int GetWidth() const { return m_Width; }
	inline unsigned int GetHeight() const { return m_Height; }
	inline unsigned int GetBPP() const { return m_BitsPerPixel; }
};