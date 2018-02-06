#ifndef GL42_EXTENSION_HPP
#define GL42_EXTENSION_HPP

#include <GL/glcorearb.h>

void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
void glMemoryBarrier(GLbitfield barriers);

#endif // GL42_EXTENSION_HPP