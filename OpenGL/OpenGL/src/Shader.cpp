#include <iostream>
#include <sstream>
#include <fstream>


#include "Shader.hpp"
#include "Renderer.hpp"

Shader::Shader(const std::string& filepath) : m_FilePath(filepath), m_RenderID{ 0 } 
{
    ShaderProgramSource source = Shader::ParseShader(filepath);
    m_RenderID = Shader::CreateShader(source.VertexShader, source.FragmentShader);
}

Shader::~Shader() 
{
    GLCall(glDeleteProgram(m_RenderID));
}

void Shader::Bind() const 
{
    GLCall(glUseProgram(m_RenderID));
}

void Shader::UnBind() const 
{
    GLCall(glUseProgram(0));
}


unsigned int Shader::CompileShader(unsigned int type, const std::string& shader)
{
    unsigned int id = glCreateShader(type);
    const char* src = shader.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to Compile Shader! " << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

ShaderProgramSource Shader::ParseShader(std::string FilePath)
{
    enum class Type {
        None = -1, Vertex = 0, Fragment = 1
    };
    std::ifstream shader(FilePath);

    std::string line;
    std::stringstream ss[2];
    Type mode = Type::None;
    while (getline(shader, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("Vertex") != std::string::npos)
            {
                mode = Type::Vertex;
            }
            else if (line.find("Fragment") != std::string::npos)
            {
                mode = Type::Fragment;
            }
        }
        else
        {
            ss[(int)mode] << line << "\n";
        }
    }

    return { ss[0].str() , ss[1].str() };
}

unsigned int Shader::CreateShader(const std::string& VertexShader, const std::string& FragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = Shader::CompileShader(GL_VERTEX_SHADER, VertexShader);
    unsigned int fs = Shader::CompileShader(GL_FRAGMENT_SHADER, FragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) 
{
    GLCall(glUniform4f(Shader::GetUniformLocation(name), v1, v2, v3, v4));
}

unsigned int Shader::GetUniformLocation(const std::string& name) 
{
    if (m_UniformLocationCacher.find(name) != m_UniformLocationCacher.end()) {
        return m_UniformLocationCacher[name];
    }
    
    GLCall(int Location = glGetUniformLocation(m_RenderID,name.c_str()));
    if (Location == -1) {
        std::cout << "Warning Uniform " << name << " Does not exist " << std::endl;
    }

    m_UniformLocationCacher[name] = Location;
    return Location;
}