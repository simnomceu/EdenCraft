inline void glSpecializeShader(GLuint shader, const GLchar * pEntryPoint​, GLuint numSpecializationConstants​, const GLuint * pConstantIndex​, const GLuint * pConstantValue​)
	{ CALLGL46(PFNGLSPECIALIZESHADERPROC, "glSpecializeShader", shader, pEntryPoint​, numSpecializationConstants​, pConstantIndex​, pConstantValue​); }

inline void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) { CALLGL46(PFNGLPOLYGONOFFSETCLAMPPROC, "glPolygonOffsetClamp", factor, units, clamp); }