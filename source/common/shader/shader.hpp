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
            //TODO: call opengl to use the program identified by this->program
           
            //* Installs a program object to the current state
            //* the program handle is defaulted to 0
            glUseProgram(program);
        }

        GLuint getUniformLocation(const std::string &name) {
            //TODO: call opengl to get the uniform location for the uniform defined by name from this->program
            
            //* Get the uniform location in the shader file specified by (name)
            //* and in the current program object (0) 
            return glGetUniformLocation(program, name.c_str());
        }

        void set(const std::string &uniform, GLfloat value) {
            //TODO: call opengl to set the value to the uniform defined by name
            
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform1f(getUniformLocation(uniform), value);
        }

        void set(const std::string &uniform, glm::vec2 value) {
            //TODO: call opengl to set the value to the uniform defined by name
            
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform2f(getUniformLocation(uniform), value.x, value.y);
        }

        void set(const std::string &uniform, glm::vec3 value) {
            //TODO: call opengl to set the value to the uniform defined by name
           
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform3f(getUniformLocation(uniform), value.x, value.y, value.z);
        }

        void set(const std::string &uniform, glm::vec4 value) {
            //TODO: call opengl to set the value to the uniform defined by name
           
            //* Set the value to the uniform (called uniform) specified by its location
            glUniform4f(getUniformLocation(uniform), value.x, value.y, value.z, value.w);
        }


        //TODO: Delete the copy constructor and assignment operator
        ShaderProgram(const our::ShaderProgram&) = delete;
        ShaderProgram& operator=(const our::ShaderProgram&) = delete;


        //Question: Why do we do this? Hint: Look at the deconstructor
        /*  
            Answer:

            Because if the ShaderProgram gets copied to another ShaderProgram, 
            the "program" handler (ID) (Data member) would be copied, and then
            the destructor will call openGL function to delete the program
            with two identical handlers (IDs)
        */
    };

}

#endif