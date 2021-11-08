#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace our {

    class ShaderProgram {

    private:
        //Shader Program Handle
        GLuint program;

    public:
        void create();
        void destroy();

        ShaderProgram(){ program = 0; }
        ~ShaderProgram(){ destroy(); }

        bool attach(const std::string &filename, GLenum type) const;

        bool link() const;

        void use() {            
            //* Installs a program object to the current state
            //* the program handle is defaulted to 0
            glUseProgram(program);
        }

        GLuint getUniformLocation(const std::string &name) {            
            //* Get the uniform location in the shader file specified by (name)
            //* and in the current program object (0) 
            return glGetUniformLocation(program, name.c_str());
        }

        void set(const std::string &uniform, GLfloat value) {            
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform1f(getUniformLocation(uniform), value);
        }

        void set(const std::string &uniform, glm::vec2 value) {            
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform2f(getUniformLocation(uniform), value.x, value.y);
        }

        void set(const std::string &uniform, glm::vec3 value) {           
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform3f(getUniformLocation(uniform), value.x, value.y, value.z);
        }

        void set(const std::string &uniform, glm::vec4 value) {           
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform4f(getUniformLocation(uniform), value.x, value.y, value.z, value.w);
        }

        ShaderProgram(const our::ShaderProgram&) = delete;
        ShaderProgram& operator=(const our::ShaderProgram&) = delete;


        //Question: Why do we do this? Hint: Look at the deconstructor
        /*  
            Answer:

            Because if the ShaderProgram gets copied to another ShaderProgram, 
            the "program" handler (ID) (Data member) would be copied. So now we have
            like two pointers point to the same data, and then when 
            the destructor of the copied ShaderProgram calls openGL function to destroy 
            the program, there will be nothing left to delete because it would be already
            deleted by the original program.
        */
    };

}

#endif