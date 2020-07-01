

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
/*
//set up for vertex shader in GLSL
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"   ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";
*/
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }glfwMakeContextCurrent(window);
     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /*
    // compile vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    //check for errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // compile fragments
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //check for errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    //linker
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    */

    glEnable(GL_DEPTH_TEST);

    Shader ourShader("TextureVS.txt", "TextureFS.txt");

    //define points to render
    float vertices[] = {
        /*
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
        */
        /*
         0.45f,  0.0f, 0.0f,    0.5f, 0.0f, 0.5f,    0.75f, 0.5f, //mid right
        -0.45f,  0.0f, 0.0f,    0.0f, 0.5f, 0.5f,    0.25f, 0.5f, //mid left
         0.00f, -0.9f, 0.0f,    0.5f, 0.5f, 0.0f,    0.50f, 0.0f, //bottom mid
         0.90f, -0.9f, 0.0f,    1.0f, 0.0f, 0.0f,    1.00f, 0.0f, //bottom right
        -0.90f, -0.9f, 0.0f,    0.0f, 1.0f, 0.0f,    0.00f, 0.0f, //bottom left
         0.00f,  0.9f, 0.0f,    0.0f, 0.0f, 1.0f,    0.50f, 1.0f, //top
         */
        -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 0.0f,     1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 1.0f,     0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 1.0f,     0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,     1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 1.0f,     0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,     1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,     0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 1.0f,     0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,     1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 0.0f,     0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 1.0f,     0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 0.0f,     1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 1.0f,     0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,     1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 1.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
    };

    //declare order of drawing triangles 
    /*
    unsigned int index[] = {
        /*
        0,  1,  3,
        1,  2,  3,
        */
        /*
        0, 1, 2,
        0, 2, 3,
        1, 2, 4,
        0, 1, 5,
        
    };
    */
    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

    //Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    unsigned int texture1, texture2;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // flip the y axis
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);


    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    //wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //glUseProgram(shaderProgram);


    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
// either set it manually like so:
    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
    // or set it via the texture class
    ourShader.setInt("texture2", 1);

    while (!glfwWindowShouldClose(window))
    {
        //inputs from keyboard
        processInput(window);

        //rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        
        //glUseProgram(shaderProgram);


        //VeiwPoints
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        unsigned int viewLoc  = glGetUniformLocation(ourShader.ID, "view" );
        // pass them to the shaders (3 different ways)
        //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader.setMat4("projection", projection);
        
        glBindVertexArray(VAO);

        for (unsigned int i = 0; i < 10; i++)
        {

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = (float)glfwGetTime() * 20.0f * (i+1);
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            model = glm::translate(model, (glm::vec3(0.0f, 0.0f, 0.0f) + sin((float)glfwGetTime())));
            ourShader.setMat4("model", model);

            
            glm::vec3 Variance = (glm::vec3(1, 1, 1) * (sin((float)glfwGetTime() )));
            /*
            //Transform
            glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
            transform = glm::translate(transform, (glm::vec3(0.0f, 0.0f, 0.0f) + Variance));
            transform = glm::scale(transform, (glm::vec3(1, 1, 1) + Variance));
            transform = glm::rotate(transform, (float)glfwGetTime() / i, glm::vec3(0.0f, 0.0f, 1.0f));
            */

            ourShader.use();
            
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
            
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
 
        // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        
        // colour change
        /*
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue)/4.0f) + 0.75f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColour");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        */
        //draw elements contains the number of vertices to draw look into automation
        //glDrawElements(GL_TRIANGLES, sizeof(index), GL_UNSIGNED_INT, 0);

        //glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glBindVertexArray(0);

        //draw to screen
        glfwSwapBuffers(window);
        //check keyboard
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(1, &EBO);
    //glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}


    void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
