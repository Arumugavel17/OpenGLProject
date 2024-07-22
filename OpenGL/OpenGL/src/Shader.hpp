#pragma once
#include <string>
#include <GL/glew.h>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexShader;
	std::string FragmentShader;
};


class Shader {
private:
	std::unordered_map<std::string, int> m_UniformLocationCacher;
	std::string  m_FilePath;
	unsigned int m_RenderID;

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const ;
	void UnBind() const ;
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);

private:
    ShaderProgramSource ParseShader(std::string FilePath);
    unsigned int CompileShader(unsigned int type, const std::string& shader);
	unsigned int CreateShader(const std::string& VertexShader, const std::string& FragmentShader);
	unsigned int GetUniformLocation(const std::string& name);
};