#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Texture.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "VertexBufferLayout.hpp"

int main()
{
#define MAIN
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error";
    }

    {
        float positions[] =
        {
            // positions          // texture coords
            -0.5f, -0.5f,   0.0f, 0.0f, // Top left
             0.5f, -0.5f,   1.0f, 1.0f, // Bottom left
             0.5f,  0.5f,   0.0f, 1.0f, // Botthom right
            -0.5f,  0.5f,   1.0f, 0.0f  // Top right 
        };

        unsigned int indecies[] = {
            3,0,1,
            1,2,3
        };
        VertexArray vao;
        VertexBufferLayout VBL;

        VertexBuffer v_buffer(positions, 4 * 4 * sizeof(float));
        IndexBuffer i_buffer(indecies, 6);
        VBL.Push<float>(2);
        VBL.Push<float>(2);
        vao.AddVertexBuffer(v_buffer, VBL);


        Shader shader("rcs/Shader/Basic.shader");
        shader.Bind();
       // shader.SetUniform4f("u_Color", 0.0, 1.0, 0.0, 1.0);
        std::string str = "C:\\Users\\arumu\\OpenGLProject\\OpenGL\\OpenGL\\src\\texture.jpeg";
        Texture tex(str);
        tex.Bind(2);
        shader.SetUniform1i("u_Texture",2);

        Renderer m_Renderer;

        vao.UnBind();
        v_buffer.UnBind();
        i_buffer.UnBind();
        shader.UnBind();
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            m_Renderer.Clear();

            i_buffer.Bind();
            tex.Bind();
            shader.Bind();
            vao.Bind();
            m_Renderer.Draw(vao, i_buffer, shader);

            //shader.SetUniform4f("u_Color", 0.0, 1.0, 0.0, 1.0);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);
            /* Poll for and process events */
            glfwPollEvents();
        }
        shader.UnBind();
    }
    glfwTerminate();
    return 0;
}