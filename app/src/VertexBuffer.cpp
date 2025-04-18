#include <glad/gl.h>

#include "VertexBuffer.h"
#include "Utils.h"

VertexBuffer::VertexBuffer(const void* data, const std::size_t size)
{
    GL_CHECK(glGenBuffers(1, &m_BufferID));
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, m_BufferID));
    GL_CHECK(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
    GL_CHECK(glDeleteBuffers(1, &m_BufferID));
}

void VertexBuffer::Bind() const
{
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, m_BufferID));
}

void VertexBuffer::Unbind() const
{
    GL_CHECK(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void VertexBuffer::UpdateData(const void* data, const std::size_t size) const
{
    Bind();
    GL_CHECK(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
}
