#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <filesystem>
#include <cstdint>
#include <string>

struct ShaderSource
{
    std::string vertex;
    std::string fragment;
};

class Shader
{
public:
    Shader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath);

    ~Shader();

    void Use() const;

    void Unuse() const;

    void SetUniformInt(const char* name, std::uint32_t value) const;

    void SetUniformFloat(const char* name, float value) const;

    std::uint32_t GetProgramID() const;

private:
    static std::string ReadFile(const std::filesystem::path& path);

    void LoadSources(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath);

    void CreateShader();

    std::uint32_t CompileShader(const GLenum shaderType, const std::string& source);

private:
    ShaderSource m_Sources;
    std::uint32_t m_ProgramID;
};
