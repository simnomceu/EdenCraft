#ifndef GL41_EXTENSION_HPP
#define GL41_EXTENSION_HPP

#include <GL/glcorearb.h>

void glVertexAttribL1d(GLuint index, GLdouble v0);
void glVertexAttribL2d(GLuint index, GLdouble v0, GLdouble v1);
void glVertexAttribL3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2);
void glVertexAttribL4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void glVertexAttribL1dv(GLuint index, const GLdouble * v);
void glVertexAttribL2dv(GLuint index, const GLdouble * v);
void glVertexAttribL3dv(GLuint index, const GLdouble * v);
void glVertexAttribL4dv(GLuint index, const GLdouble * v);
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glDepthRangef(GLfloat nearVal, GLfloat farVal);
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params);
void glClearDepthf(GLfloat depth);
void glGetFloati_v(GLenum target, GLuint index, GLfloat * data);
void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data);
void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
void glReleaseShaderCompiler();
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const char **strings);
void glProgramParameteri(GLuint program, GLenum pname, GLint value);
void glGenProgramPipelines(GLsizei n, GLuint *pipelines);
void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines);
GLboolean glIsProgramPipeline(GLuint pipeline);
void glBindProgramPipeline(GLuint pipeline);
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
void glActiveShaderProgram(GLuint pipeline, GLuint program);
void glGetProgramBinary(GLuint program, GLsizei bufsize, GLsizei *length, GLenum *binaryFormat, void *binary);
void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform1i(GLuint program, GLint location, GLint v0);
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
void glProgramUniform2ui(GLuint program, GLint location, GLint v0, GLuint v1);
void glProgramUniform3ui(GLuint program, GLint location, GLint v0, GLint v1, GLuint v2);
void glProgramUniform4ui(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLuint v3);
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value);
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value);
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value);
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params);
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void glGetShaderPrecisionFormat(GLenum shaderType, GLenum precisionType, GLint *range, GLint *precision);

#endif // GL41_EXTENSION_HPP