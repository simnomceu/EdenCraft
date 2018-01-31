#include "renderer/opengl/opengl_extension.hpp"

#include "utility/log/service_logger.hpp"

namespace ece
{
	bool OpenGLExtension::loadExtensions(const OptionOpenGL options)
	{
		bool allLoaded = true;
		if ((options & COMMAND_EXECUTION) != 0 && !this->isLoaded(COMMAND_EXECUTION)) {
			try {
				this->loadCommandExecutionExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Command Execution extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= COMMAND_EXECUTION;
		}
		if ((options & TIMER_QUERIES) != 0 && !this->isLoaded(TIMER_QUERIES)) {
			try {
				this->loadTimerQueriesExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Timer Queries extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= TIMER_QUERIES;
		}
		if ((options & SYNCHRONIZATION) != 0 && !this->isLoaded(SYNCHRONIZATION)) {
			try {
				this->loadSynchronizationExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Synchronization extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= SYNCHRONIZATION;
		}
		if ((options & ASYNCHRONOUS_QUERIES) != 0 && !this->isLoaded(ASYNCHRONOUS_QUERIES)) {
			try {
				this->loadAsynchronousQueries();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Asynchronous Queries extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= ASYNCHRONOUS_QUERIES;
		}
		if ((options & BUFFER_OBJECTS) != 0 && !this->isLoaded(BUFFER_OBJECTS)) {
			try {
				this->loadBufferObjectsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Buffer Objects extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= BUFFER_OBJECTS;
		}
		if ((options & SHADERS_AND_PROGRAMS) != 0 && !this->isLoaded(SHADERS_AND_PROGRAMS)) {
			try {
				this->loadShadersAndProgramsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Shaders And Programs extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= SHADERS_AND_PROGRAMS;
		}
		if ((options & TEXTURES_AND_SAMPLERS) != 0 && !this->isLoaded(TEXTURES_AND_SAMPLERS)) {
			try {
				this->loadTexturesAndSamplersExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Textures And Samplers extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= TEXTURES_AND_SAMPLERS;
		}
		if ((options & FRAMEBUFFER_OBJECTS) != 0 && !this->isLoaded(FRAMEBUFFER_OBJECTS)) {
			try {
				this->loadFramebufferObjectsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Framebuffer Objects extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= FRAMEBUFFER_OBJECTS;
		}
		if ((options & VERTICES) != 0 && !this->isLoaded(VERTICES)) {
			try {
				this->loadVerticesExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Vertices extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= VERTICES;
		}
		if ((options & VERTEX_ARRAYS) != 0 && !this->isLoaded(VERTEX_ARRAYS)) {
			try {
				this->loadVertexArraysExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Vertex Arrays extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= VERTEX_ARRAYS;
		}
		if ((options & VERTEX_ATTRIBUTES) != 0 && !this->isLoaded(VERTEX_ATTRIBUTES)) {
			try {
				this->loadVertexAttributesExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Vertex Attributes extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= VERTEX_ATTRIBUTES;
		}
		if ((options & VERTEX_POST_PROCESSING) != 0 && !this->isLoaded(VERTEX_POST_PROCESSING)) {
			try {
				this->loadVertexPostProcessingExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Vertex Post-Processing extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= VERTEX_POST_PROCESSING;
		}
		if ((options & RASTERIZATION) != 0 && !this->isLoaded(RASTERIZATION)) {
			try {
				this->loadRasterizationExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Rasterization extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= RASTERIZATION;
		}
		if ((options & FRAGMENT_SHADERS) != 0 && !this->isLoaded(FRAGMENT_SHADERS)) {
			try {
				this->loadFragmentShadersExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Fragment Shaders extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= FRAGMENT_SHADERS;
		}
		if ((options & COMPUTE_SHADERS) != 0 && !this->isLoaded(COMPUTE_SHADERS)) {
			try {
				this->loadComputeShadersExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Compute Shaders extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= COMPUTE_SHADERS;
		}
		if ((options & PER_FRAGMENT_OPERATIONS) != 0 && !this->isLoaded(PER_FRAGMENT_OPERATIONS)) {
			try {
				this->loadPerFragmentOperationsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Per-Fragment Operations extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= PER_FRAGMENT_OPERATIONS;
		}
		if ((options & HINTS) != 0 && !this->isLoaded(HINTS)) {
			try {
				this->loadHintsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Hints extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= HINTS;
		}
		if ((options & WHOLE_FRAMEBUFFER) != 0 && !this->isLoaded(WHOLE_FRAMEBUFFER)) {
			try {
				this->loadWholeFramebufferExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Whole Framebuffer extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= WHOLE_FRAMEBUFFER;
		}
		if ((options & READING_AND_COPYING_PIXELS) != 0 && !this->isLoaded(READING_AND_COPYING_PIXELS)) {
			try {
				this->loadReadingAndCopyingPixelsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Reading And Copying Pixels extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= READING_AND_COPYING_PIXELS;
		}
		if ((options & DEBUG_OUTPUT) != 0 && !this->isLoaded(DEBUG_OUTPUT)) {
			try {
				this->loadDebugOutputExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Debug Output extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= DEBUG_OUTPUT;
		}
		if ((options & STATE_AND_STATE_REQUESTS) != 0 && !this->isLoaded(STATE_AND_STATE_REQUESTS)) {
			try {
				this->loadStateAndStateRequestsExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading State And State Requests extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= STATE_AND_STATE_REQUESTS;
		}
		if ((options & PLATFORM) != 0 && !this->isLoaded(PLATFORM)) {
			try {
				this->loadPlatformExtensions();
			}
			catch (std::runtime_error & e) {
				ServiceLoggerLocator::getService().logError(e.what());
				ServiceLoggerLocator::getService().logError("Loading Platform extensions for OpenGL has been interrupted.");
				allLoaded = false;
			}
			this->_loaded |= PLATFORM;
		}
		return allLoaded;
	}

	void OpenGLExtension::loadCommandExecutionExtensions()
	{
	//	glGetError = reinterpret_cast<PFNGLGETERRORPROC>(this->loadOpenGLProc("glGetError")); glGetError();
		glGetGraphicsResetStatus = reinterpret_cast<PFNGLGETGRAPHICSRESETSTATUSPROC>(this->loadOpenGLProc("glGetGraphicsResetStatus"));
		glFlush = reinterpret_cast<PFNGLFLUSHPROC>(this->loadOpenGLProc("glFlush"));
		glFinish = reinterpret_cast<PFNGLFINISHPROC>(this->loadOpenGLProc("glFinish"));
	}

	void OpenGLExtension::loadTimerQueriesExtensions()
	{
		glQueryCounter = reinterpret_cast<PFNGLQUERYCOUNTERPROC>(this->loadOpenGLProc("glQueryCounter"));
	}

	void OpenGLExtension::loadSynchronizationExtensions()
	{
		glDeleteSync = reinterpret_cast<PFNGLDELETESYNCPROC>(this->loadOpenGLProc("glDeleteSync"));
		glFenceSync = reinterpret_cast<PFNGLFENCESYNCPROC>(this->loadOpenGLProc("glFenceSync"));
		glClientWaitSync = reinterpret_cast<PFNGLCLIENTWAITSYNCPROC>(this->loadOpenGLProc("glClientWaitSync"));
		glWaitSync = reinterpret_cast<PFNGLWAITSYNCPROC>(this->loadOpenGLProc("glWaitSync"));
		glGetSynciv = reinterpret_cast<PFNGLGETSYNCIVPROC>(this->loadOpenGLProc("glGetSynciv"));
		glIsSync = reinterpret_cast<PFNGLISSYNCPROC>(this->loadOpenGLProc("glIsSync"));
	}

	void OpenGLExtension::loadAsynchronousQueries()
	{
		glGenQueries = reinterpret_cast<PFNGLGENQUERIESPROC>(this->loadOpenGLProc("glGenQueries"));
		glCreateQueries = reinterpret_cast<PFNGLCREATEQUERIESPROC>(this->loadOpenGLProc("glCreateQueries"));
		glDeleteQueries = reinterpret_cast<PFNGLDELETEQUERIESPROC>(this->loadOpenGLProc("glDeleteQueries"));
		glBeginQuery = reinterpret_cast<PFNGLBEGINQUERYPROC>(this->loadOpenGLProc("glBeginQuery"));
		glBeginQueryIndexed = reinterpret_cast<PFNGLBEGINQUERYINDEXEDPROC>(this->loadOpenGLProc("glBeginQueryIndexed"));
		glEndQuery = reinterpret_cast<PFNGLENDQUERYPROC>(this->loadOpenGLProc("glEndQuery"));
		glEndQueryIndexed = reinterpret_cast<PFNGLENDQUERYINDEXEDPROC>(this->loadOpenGLProc("glEndQueryIndexed"));
		glIsQuery = reinterpret_cast<PFNGLISQUERYPROC>(this->loadOpenGLProc("glIsQuery"));
		glGetQueryiv = reinterpret_cast<PFNGLGETQUERYIVPROC>(this->loadOpenGLProc("glGetQueryiv"));
		glGetQueryIndexediv = reinterpret_cast<PFNGLGETQUERYINDEXEDIVPROC>(this->loadOpenGLProc("glGetQueryIndexediv"));
		glGetQueryObjectiv = reinterpret_cast<PFNGLGETQUERYOBJECTIVPROC>(this->loadOpenGLProc("glGetQueryObjectiv"));
		glGetQueryObjectuiv = reinterpret_cast<PFNGLGETQUERYOBJECTUIVPROC>(this->loadOpenGLProc("glGetQueryObjectuiv"));
		glGetQueryObjecti64v = reinterpret_cast<PFNGLGETQUERYOBJECTI64VPROC>(this->loadOpenGLProc("glGetQueryObjecti64v"));
		glGetQueryObjectui64v = reinterpret_cast<PFNGLGETQUERYOBJECTUI64VPROC>(this->loadOpenGLProc("glGetQueryObjectui64v"));
	}

	void OpenGLExtension::loadBufferObjectsExtensions()
	{
		glGenBuffers = reinterpret_cast<PFNGLGENBUFFERSPROC>(this->loadOpenGLProc("glGenBuffers"));
		glCreateBuffers = reinterpret_cast<PFNGLCREATEBUFFERSPROC>(this->loadOpenGLProc("glCreateBuffers"));
		glDeleteBuffers = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(this->loadOpenGLProc("glDeleteBuffers"));
		glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>(this->loadOpenGLProc("glBindBuffer"));
		glBindBufferRange = reinterpret_cast<PFNGLBINDBUFFERRANGEPROC>(this->loadOpenGLProc("glBindBufferRange"));
		glBindBufferBase = reinterpret_cast<PFNGLBINDBUFFERBASEPROC>(this->loadOpenGLProc("glBindBufferBase"));
		glBindBuffersRange = reinterpret_cast<PFNGLBINDBUFFERSRANGEPROC>(this->loadOpenGLProc("glBindBuffersRange"));
		glBindBuffersBase = reinterpret_cast<PFNGLBINDBUFFERSBASEPROC>(this->loadOpenGLProc("glBindBuffersBase"));
		glBufferStorage = reinterpret_cast<PFNGLBUFFERSTORAGEPROC>(this->loadOpenGLProc("glBufferStorage"));
		glNamedBufferStorage = reinterpret_cast<PFNGLNAMEDBUFFERSTORAGEPROC>(this->loadOpenGLProc("glNamedBufferStorage"));
		glBufferData = reinterpret_cast<PFNGLBUFFERDATAPROC>(this->loadOpenGLProc("glBufferData"));
		glNamedBufferData = reinterpret_cast<PFNGLNAMEDBUFFERDATAPROC>(this->loadOpenGLProc("glNamedBufferData"));
		glBufferSubData = reinterpret_cast<PFNGLBUFFERSUBDATAPROC>(this->loadOpenGLProc("glBufferSubData"));
		glNamedBufferSubData = reinterpret_cast<PFNGLNAMEDBUFFERSUBDATAPROC>(this->loadOpenGLProc("glNamedBufferSubData"));
		glClearBufferSubData = reinterpret_cast<PFNGLCLEARBUFFERSUBDATAPROC>(this->loadOpenGLProc("glClearBufferSubData"));
		glClearNamedBufferSubData = reinterpret_cast<PFNGLCLEARNAMEDBUFFERSUBDATAPROC>(this->loadOpenGLProc("glClearNamedBufferSubData"));
		glClearBufferData = reinterpret_cast<PFNGLCLEARBUFFERDATAPROC>(this->loadOpenGLProc("glClearBufferData"));
		glClearNamedBufferData = reinterpret_cast<PFNGLCLEARNAMEDBUFFERDATAPROC>(this->loadOpenGLProc("glClearNamedBufferData"));
		glMapBufferRange = reinterpret_cast<PFNGLMAPBUFFERRANGEPROC>(this->loadOpenGLProc("glMapBufferRange"));
		glMapNamedBufferRange = reinterpret_cast<PFNGLMAPNAMEDBUFFERRANGEPROC>(this->loadOpenGLProc("glMapNamedBufferRange"));
		glMapBuffer = reinterpret_cast<PFNGLMAPBUFFERPROC>(this->loadOpenGLProc("glMapBuffer"));
		glMapNamedBuffer = reinterpret_cast<PFNGLMAPNAMEDBUFFERPROC>(this->loadOpenGLProc("glMapNamedBuffer"));
		glFlushMappedBufferRange = reinterpret_cast<PFNGLFLUSHMAPPEDBUFFERRANGEPROC>(this->loadOpenGLProc("glFlushMappedBufferRange"));
		glFlushMappedNamedBufferRange = reinterpret_cast<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>(this->loadOpenGLProc("glFlushMappedNamedBufferRange"));
		glUnmapBuffer = reinterpret_cast<PFNGLUNMAPBUFFERPROC>(this->loadOpenGLProc("glUnmapBuffer"));
		glUnmapNamedBuffer = reinterpret_cast<PFNGLUNMAPNAMEDBUFFERPROC>(this->loadOpenGLProc("glUnmapNamedBuffer"));
		glInvalidateBufferSubData = reinterpret_cast<PFNGLINVALIDATEBUFFERSUBDATAPROC>(this->loadOpenGLProc("glInvalidateBufferSubData"));
		glInvalidateBufferData = reinterpret_cast<PFNGLINVALIDATEBUFFERDATAPROC>(this->loadOpenGLProc("glInvalidateBufferData"));
		glIsBuffer = reinterpret_cast<PFNGLISBUFFERPROC>(this->loadOpenGLProc("glIsBuffer"));
		glGetBufferSubData = reinterpret_cast<PFNGLGETBUFFERSUBDATAPROC>(this->loadOpenGLProc("glGetBufferSubData"));
		glGetNamedBufferSubData = reinterpret_cast<PFNGLGETNAMEDBUFFERSUBDATAPROC>(this->loadOpenGLProc("glGetNamedBufferSubData"));
		glGetBufferParameteriv = reinterpret_cast<PFNGLGETBUFFERPARAMETERIVPROC>(this->loadOpenGLProc("glGetBufferParameteriv"));
		glGetBufferParameteri64v = reinterpret_cast<PFNGLGETBUFFERPARAMETERI64VPROC>(this->loadOpenGLProc("glGetBufferParameteri64v"));
		glGetNamedBufferParameteriv = reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERIVPROC>(this->loadOpenGLProc("glGetNamedBufferParameteriv"));
		glGetNamedBufferParameteri64v = reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERI64VPROC>(this->loadOpenGLProc("glGetNamedBufferParameteri64v"));
		glGetBufferPointerv = reinterpret_cast<PFNGLGETBUFFERPOINTERVPROC>(this->loadOpenGLProc("glGetBufferPointerv"));
		glGetNamedBufferPointerv = reinterpret_cast<PFNGLGETNAMEDBUFFERPOINTERVPROC>(this->loadOpenGLProc("glGetNamedBufferPointerv"));
		glCopyBufferSubData = reinterpret_cast<PFNGLCOPYBUFFERSUBDATAPROC>(this->loadOpenGLProc("glCopyBufferSubData"));
		glCopyNamedBufferSubData = reinterpret_cast<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>(this->loadOpenGLProc("glCopyNamedBufferSubData"));
	}

	void OpenGLExtension::loadShadersAndProgramsExtensions()
	{
		glCreateShader = reinterpret_cast<PFNGLCREATESHADERPROC>(this->loadOpenGLProc("glCreateShader"));
		glShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>(this->loadOpenGLProc("glShaderSource"));
		glCompileShader = reinterpret_cast<PFNGLCOMPILESHADERPROC>(this->loadOpenGLProc("glCompileShader"));
		glReleaseShaderCompiler = reinterpret_cast<PFNGLRELEASESHADERCOMPILERPROC>(this->loadOpenGLProc("glReleaseShaderCompiler"));
		glDeleteShader = reinterpret_cast<PFNGLDELETESHADERPROC>(this->loadOpenGLProc("glDeleteShader"));
		glIsShader = reinterpret_cast<PFNGLISSHADERPROC>(this->loadOpenGLProc("glIsShader"));
		glShaderBinary = reinterpret_cast<PFNGLSHADERBINARYPROC>(this->loadOpenGLProc("glShaderBinary"));
		glSpecializeShader = reinterpret_cast<PFNGLSPECIALIZESHADERPROC>(this->loadOpenGLProc("glSpecializeShader"));
		glCreateProgram = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(this->loadOpenGLProc("glCreateProgram"));
		glAttachShader = reinterpret_cast<PFNGLATTACHSHADERPROC>(this->loadOpenGLProc("glAttachShader"));
		glDetachShader = reinterpret_cast<PFNGLDETACHSHADERPROC>(this->loadOpenGLProc("glDetachShader"));
		glLinkProgram = reinterpret_cast<PFNGLLINKPROGRAMPROC>(this->loadOpenGLProc("glLinkProgram"));
		glUseProgram = reinterpret_cast<PFNGLUSEPROGRAMPROC>(this->loadOpenGLProc("glUseProgram"));
		glCreateShaderProgramv = reinterpret_cast<PFNGLCREATESHADERPROGRAMVPROC>(this->loadOpenGLProc("glCreateShaderProgramv"));
		glProgramParameteri = reinterpret_cast<PFNGLPROGRAMPARAMETERIPROC>(this->loadOpenGLProc("glProgramParameteri"));
		glDeleteProgram = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(this->loadOpenGLProc("glDeleteProgram"));
		glIsProgram = reinterpret_cast<PFNGLISPROGRAMPROC>(this->loadOpenGLProc("glIsProgram"));
		glGetProgramInterfaceiv = reinterpret_cast<PFNGLGETPROGRAMINTERFACEIVPROC>(this->loadOpenGLProc("glGetProgramInterfaceiv"));
		glGetProgramResourceIndex = reinterpret_cast<PFNGLGETPROGRAMRESOURCEINDEXPROC>(this->loadOpenGLProc("glGetProgramResourceIndex"));
		glGetProgramResourceName = reinterpret_cast<PFNGLGETPROGRAMRESOURCENAMEPROC>(this->loadOpenGLProc("glGetProgramResourceName"));
		glGetProgramResourceiv = reinterpret_cast<PFNGLGETPROGRAMRESOURCEIVPROC>(this->loadOpenGLProc("glGetProgramResourceiv"));
		glGetProgramResourceLocation = reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONPROC>(this->loadOpenGLProc("glGetProgramResourceLocation"));
		glGetProgramResourceLocationIndex = reinterpret_cast<PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC>(this->loadOpenGLProc("glGetProgramResourceLocationIndex"));
		glGenProgramPipelines = reinterpret_cast<PFNGLGENPROGRAMPIPELINESPROC>(this->loadOpenGLProc("glGenProgramPipelines"));
		glDeleteProgramPipelines = reinterpret_cast<PFNGLDELETEPROGRAMPIPELINESPROC>(this->loadOpenGLProc("glDeleteProgramPipelines"));
		glIsProgramPipeline = reinterpret_cast<PFNGLISPROGRAMPIPELINEPROC>(this->loadOpenGLProc("glIsProgramPipeline"));
		glBindProgramPipeline = reinterpret_cast<PFNGLBINDPROGRAMPIPELINEPROC>(this->loadOpenGLProc("glBindProgramPipeline"));
		glCreateProgramPipelines = reinterpret_cast<PFNGLCREATEPROGRAMPIPELINESPROC>(this->loadOpenGLProc("glCreateProgramPipelines"));
		glUseProgramStages = reinterpret_cast<PFNGLUSEPROGRAMSTAGESPROC>(this->loadOpenGLProc("glUseProgramStages"));
		glActiveShaderProgram = reinterpret_cast<PFNGLACTIVESHADERPROGRAMPROC>(this->loadOpenGLProc("glActiveShaderProgram"));
		glGetProgramBinary = reinterpret_cast<PFNGLGETPROGRAMBINARYPROC>(this->loadOpenGLProc("glGetProgramBinary"));
		glProgramBinary = reinterpret_cast<PFNGLPROGRAMBINARYPROC>(this->loadOpenGLProc("glProgramBinary"));
		glGetUniformLocation = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(this->loadOpenGLProc("glGetUniformLocation"));
		glGetActiveUniformName = reinterpret_cast<PFNGLGETACTIVEUNIFORMNAMEPROC>(this->loadOpenGLProc("glGetActiveUniformName"));
		glGetUniformIndices = reinterpret_cast<PFNGLGETUNIFORMINDICESPROC>(this->loadOpenGLProc("glGetUniformIndices"));
		glGetActiveUniform = reinterpret_cast<PFNGLGETACTIVEUNIFORMPROC>(this->loadOpenGLProc("glGetActiveUniform"));
		glGetActiveUniformsiv = reinterpret_cast<PFNGLGETACTIVEUNIFORMSIVPROC>(this->loadOpenGLProc("glGetActiveUniformsiv"));
		glGetUniformBlockIndex = reinterpret_cast<PFNGLGETUNIFORMBLOCKINDEXPROC>(this->loadOpenGLProc("glGetUniformBlockIndex"));
		glGetActiveUniformBlockName = reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>(this->loadOpenGLProc("glGetActiveUniformBlockName"));
		glGetActiveUniformBlockiv = reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>(this->loadOpenGLProc("glGetActiveUniformBlockiv"));
		glGetActiveAtomicCounterBufferiv = reinterpret_cast<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>(this->loadOpenGLProc("glGetActiveAtomicCounterBufferiv"));
		glUniform1i = reinterpret_cast<PFNGLUNIFORM1IPROC>(this->loadOpenGLProc("glUniform1i"));
		glUniform1iv = reinterpret_cast<PFNGLUNIFORM1IVPROC>(this->loadOpenGLProc("glUniform1iv"));
		glUniform1f = reinterpret_cast<PFNGLUNIFORM1FPROC>(this->loadOpenGLProc("glUniform1f"));
		glUniform1fv = reinterpret_cast<PFNGLUNIFORM1FVPROC>(this->loadOpenGLProc("glUniform1fv"));
		glUniform1d = reinterpret_cast<PFNGLUNIFORM1DPROC>(this->loadOpenGLProc("glUniform1d"));
		glUniform1dv = reinterpret_cast<PFNGLUNIFORM1DVPROC>(this->loadOpenGLProc("glUniform1dv"));
		glUniform1ui = reinterpret_cast<PFNGLUNIFORM1UIPROC>(this->loadOpenGLProc("glUniform1ui"));
		glUniform1uiv = reinterpret_cast<PFNGLUNIFORM1UIVPROC>(this->loadOpenGLProc("glUniform1uiv"));
		glUniform2i = reinterpret_cast<PFNGLUNIFORM2IPROC>(this->loadOpenGLProc("glUniform2i"));
		glUniform2iv = reinterpret_cast<PFNGLUNIFORM2IVPROC>(this->loadOpenGLProc("glUniform2iv"));
		glUniform2f = reinterpret_cast<PFNGLUNIFORM2FPROC>(this->loadOpenGLProc("glUniform2f"));
		glUniform2fv = reinterpret_cast<PFNGLUNIFORM2FVPROC>(this->loadOpenGLProc("glUniform2fv"));
		glUniform2d = reinterpret_cast<PFNGLUNIFORM2DPROC>(this->loadOpenGLProc("glUniform2d"));
		glUniform2dv = reinterpret_cast<PFNGLUNIFORM2DVPROC>(this->loadOpenGLProc("glUniform2dv"));
		glUniform2ui = reinterpret_cast<PFNGLUNIFORM2UIPROC>(this->loadOpenGLProc("glUniform2ui"));
		glUniform2uiv = reinterpret_cast<PFNGLUNIFORM2UIVPROC>(this->loadOpenGLProc("glUniform2uiv"));
		glUniform3i = reinterpret_cast<PFNGLUNIFORM3IPROC>(this->loadOpenGLProc("glUniform3i"));
		glUniform3iv = reinterpret_cast<PFNGLUNIFORM3IVPROC>(this->loadOpenGLProc("glUniform3iv"));
		glUniform3f = reinterpret_cast<PFNGLUNIFORM3FPROC>(this->loadOpenGLProc("glUniform3f"));
		glUniform3fv = reinterpret_cast<PFNGLUNIFORM3FVPROC>(this->loadOpenGLProc("glUniform3fv"));
		glUniform3d = reinterpret_cast<PFNGLUNIFORM3DPROC>(this->loadOpenGLProc("glUniform3d"));
		glUniform3dv = reinterpret_cast<PFNGLUNIFORM3DVPROC>(this->loadOpenGLProc("glUniform3dv"));
		glUniform3ui = reinterpret_cast<PFNGLUNIFORM3UIPROC>(this->loadOpenGLProc("glUniform3ui"));
		glUniform3uiv = reinterpret_cast<PFNGLUNIFORM3UIVPROC>(this->loadOpenGLProc("glUniform3uiv"));
		glUniform4i = reinterpret_cast<PFNGLUNIFORM4IPROC>(this->loadOpenGLProc("glUniform4i"));
		glUniform4iv = reinterpret_cast<PFNGLUNIFORM4IVPROC>(this->loadOpenGLProc("glUniform4iv"));
		glUniform4f = reinterpret_cast<PFNGLUNIFORM4FPROC>(this->loadOpenGLProc("glUniform4f"));
		glUniform4fv = reinterpret_cast<PFNGLUNIFORM4FVPROC>(this->loadOpenGLProc("glUniform4fv"));
		glUniform4d = reinterpret_cast<PFNGLUNIFORM4DPROC>(this->loadOpenGLProc("glUniform4d"));
		glUniform4dv = reinterpret_cast<PFNGLUNIFORM4DVPROC>(this->loadOpenGLProc("glUniform4dv"));
		glUniform4ui = reinterpret_cast<PFNGLUNIFORM4UIPROC>(this->loadOpenGLProc("glUniform4ui"));
		glUniform4uiv = reinterpret_cast<PFNGLUNIFORM4UIVPROC>(this->loadOpenGLProc("glUniform4uiv"));
		glUniformMatrix2fv = reinterpret_cast<PFNGLUNIFORMMATRIX2FVPROC>(this->loadOpenGLProc("glUniformMatrix2fv"));
		glUniformMatrix2dv = reinterpret_cast<PFNGLUNIFORMMATRIX2DVPROC>(this->loadOpenGLProc("glUniformMatrix2dv"));
		glUniformMatrix3fv = reinterpret_cast<PFNGLUNIFORMMATRIX3FVPROC>(this->loadOpenGLProc("glUniformMatrix3fv"));
		glUniformMatrix3dv = reinterpret_cast<PFNGLUNIFORMMATRIX3DVPROC>(this->loadOpenGLProc("glUniformMatrix3dv"));
		glUniformMatrix4fv = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(this->loadOpenGLProc("glUniformMatrix4fv"));
		glUniformMatrix4dv = reinterpret_cast<PFNGLUNIFORMMATRIX4DVPROC>(this->loadOpenGLProc("glUniformMatrix4dv"));
		glUniformMatrix2x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X3FVPROC>(this->loadOpenGLProc("glUniformMatrix2x3fv"));
		glUniformMatrix2x3dv = reinterpret_cast<PFNGLUNIFORMMATRIX2X3DVPROC>(this->loadOpenGLProc("glUniformMatrix2x3dv"));
		glUniformMatrix3x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X2FVPROC>(this->loadOpenGLProc("glUniformMatrix3x2fv"));
		glUniformMatrix3x2dv = reinterpret_cast<PFNGLUNIFORMMATRIX3X2DVPROC>(this->loadOpenGLProc("glUniformMatrix3x2dv"));
		glUniformMatrix2x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX2X4FVPROC>(this->loadOpenGLProc("glUniformMatrix2x4fv"));
		glUniformMatrix2x4dv = reinterpret_cast<PFNGLUNIFORMMATRIX2X4DVPROC>(this->loadOpenGLProc("glUniformMatrix2x4dv"));
		glUniformMatrix4x2fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X2FVPROC>(this->loadOpenGLProc("glUniformMatrix4x2fv"));
		glUniformMatrix4x2dv = reinterpret_cast<PFNGLUNIFORMMATRIX4X2DVPROC>(this->loadOpenGLProc("glUniformMatrix4x2dv"));
		glUniformMatrix3x4fv = reinterpret_cast<PFNGLUNIFORMMATRIX3X4FVPROC>(this->loadOpenGLProc("glUniformMatrix3x4fv"));
		glUniformMatrix3x4dv = reinterpret_cast<PFNGLUNIFORMMATRIX3X4DVPROC>(this->loadOpenGLProc("glUniformMatrix3x4dv"));
		glUniformMatrix4x3fv = reinterpret_cast<PFNGLUNIFORMMATRIX4X3FVPROC>(this->loadOpenGLProc("glUniformMatrix4x3fv"));
		glUniformMatrix4x3dv = reinterpret_cast<PFNGLUNIFORMMATRIX4X3DVPROC>(this->loadOpenGLProc("glUniformMatrix4x3dv"));
		glProgramUniform1i = reinterpret_cast<PFNGLPROGRAMUNIFORM1IPROC>(this->loadOpenGLProc("glProgramUniform1i"));
		glProgramUniform1f = reinterpret_cast<PFNGLPROGRAMUNIFORM1FPROC>(this->loadOpenGLProc("glProgramUniform1f"));
		glProgramUniform1d = reinterpret_cast<PFNGLPROGRAMUNIFORM1DPROC>(this->loadOpenGLProc("glProgramUniform1d"));
		glProgramUniform2i = reinterpret_cast<PFNGLPROGRAMUNIFORM2IPROC>(this->loadOpenGLProc("glProgramUniform2i"));
		glProgramUniform2f = reinterpret_cast<PFNGLPROGRAMUNIFORM2FPROC>(this->loadOpenGLProc("glProgramUniform2f"));
		glProgramUniform2d = reinterpret_cast<PFNGLPROGRAMUNIFORM2DPROC>(this->loadOpenGLProc("glProgramUniform2d"));
		glProgramUniform3i = reinterpret_cast<PFNGLPROGRAMUNIFORM3IPROC>(this->loadOpenGLProc("glProgramUniform3i"));
		glProgramUniform3f = reinterpret_cast<PFNGLPROGRAMUNIFORM3FPROC>(this->loadOpenGLProc("glProgramUniform3f"));
		glProgramUniform3d = reinterpret_cast<PFNGLPROGRAMUNIFORM3DPROC>(this->loadOpenGLProc("glProgramUniform3d"));
		glProgramUniform4i = reinterpret_cast<PFNGLPROGRAMUNIFORM4IPROC>(this->loadOpenGLProc("glProgramUniform4i"));
		glProgramUniform4f = reinterpret_cast<PFNGLPROGRAMUNIFORM4FPROC>(this->loadOpenGLProc("glProgramUniform4f"));
		glProgramUniform4d = reinterpret_cast<PFNGLPROGRAMUNIFORM4DPROC>(this->loadOpenGLProc("glProgramUniform4d"));
		glProgramUniform1iv = reinterpret_cast<PFNGLPROGRAMUNIFORM1IVPROC>(this->loadOpenGLProc("glProgramUniform1iv"));
		glProgramUniform1fv = reinterpret_cast<PFNGLPROGRAMUNIFORM1FVPROC>(this->loadOpenGLProc("glProgramUniform1fv"));
		glProgramUniform1dv = reinterpret_cast<PFNGLPROGRAMUNIFORM1DVPROC>(this->loadOpenGLProc("glProgramUniform1dv"));
		glProgramUniform2iv = reinterpret_cast<PFNGLPROGRAMUNIFORM2IVPROC>(this->loadOpenGLProc("glProgramUniform2iv"));
		glProgramUniform2fv = reinterpret_cast<PFNGLPROGRAMUNIFORM2FVPROC>(this->loadOpenGLProc("glProgramUniform2fv"));
		glProgramUniform2dv = reinterpret_cast<PFNGLPROGRAMUNIFORM2DVPROC>(this->loadOpenGLProc("glProgramUniform2dv"));
		glProgramUniform3iv = reinterpret_cast<PFNGLPROGRAMUNIFORM3IVPROC>(this->loadOpenGLProc("glProgramUniform3iv"));
		glProgramUniform3fv = reinterpret_cast<PFNGLPROGRAMUNIFORM3FVPROC>(this->loadOpenGLProc("glProgramUniform3fv"));
		glProgramUniform3dv = reinterpret_cast<PFNGLPROGRAMUNIFORM3DVPROC>(this->loadOpenGLProc("glProgramUniform3dv"));
		glProgramUniform4iv = reinterpret_cast<PFNGLPROGRAMUNIFORM4IVPROC>(this->loadOpenGLProc("glProgramUniform4iv"));
		glProgramUniform4fv = reinterpret_cast<PFNGLPROGRAMUNIFORM4FVPROC>(this->loadOpenGLProc("glProgramUniform4fv"));
		glProgramUniform4dv = reinterpret_cast<PFNGLPROGRAMUNIFORM4DVPROC>(this->loadOpenGLProc("glProgramUniform4dv"));
		glProgramUniform1uiv = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIVPROC>(this->loadOpenGLProc("glProgramUniform1uiv"));
		glProgramUniform2uiv = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIVPROC>(this->loadOpenGLProc("glProgramUniform2uiv"));
		glProgramUniform3uiv = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIVPROC>(this->loadOpenGLProc("glProgramUniform3uiv"));
		glProgramUniform4uiv = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIVPROC>(this->loadOpenGLProc("glProgramUniform4uiv"));
		glProgramUniform1ui = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIPROC>(this->loadOpenGLProc("glProgramUniform1ui"));
		glProgramUniform2ui = reinterpret_cast<PFNGLPROGRAMUNIFORM2UIPROC>(this->loadOpenGLProc("glProgramUniform2ui"));
		glProgramUniform3ui = reinterpret_cast<PFNGLPROGRAMUNIFORM3UIPROC>(this->loadOpenGLProc("glProgramUniform3ui"));
		glProgramUniform4ui = reinterpret_cast<PFNGLPROGRAMUNIFORM4UIPROC>(this->loadOpenGLProc("glProgramUniform4ui"));
		glProgramUniformMatrix2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix2fv"));
		glProgramUniformMatrix2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix2dv"));
		glProgramUniformMatrix3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix3fv"));
		glProgramUniformMatrix3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix3dv"));
		glProgramUniformMatrix4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix4fv"));
		glProgramUniformMatrix4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix4dv"));
		glProgramUniformMatrix2x3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix2x3fv"));
		glProgramUniformMatrix2x3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix2x3dv"));
		glProgramUniformMatrix3x2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix3x2fv"));
		glProgramUniformMatrix3x2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix3x2dv"));
		glProgramUniformMatrix2x4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix2x4fv"));
		glProgramUniformMatrix2x4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix2x4dv"));
		glProgramUniformMatrix4x2fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix4x2fv"));
		glProgramUniformMatrix4x2dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix4x2dv"));
		glProgramUniformMatrix3x4fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix3x4fv"));
		glProgramUniformMatrix3x4dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix3x4dv"));
		glProgramUniformMatrix4x3fv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC>(this->loadOpenGLProc("glProgramUniformMatrix4x3fv"));
		glProgramUniformMatrix4x3dv = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC>(this->loadOpenGLProc("glProgramUniformMatrix4x3dv"));
		glUniformBlockBinding = reinterpret_cast<PFNGLUNIFORMBLOCKBINDINGPROC>(this->loadOpenGLProc("glUniformBlockBinding"));
		glShaderStorageBlockBinding = reinterpret_cast<PFNGLSHADERSTORAGEBLOCKBINDINGPROC>(this->loadOpenGLProc("glShaderStorageBlockBinding"));
		glGetSubroutineUniformLocation = reinterpret_cast<PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC>(this->loadOpenGLProc("glGetSubroutineUniformLocation"));
		glGetSubroutineIndex = reinterpret_cast<PFNGLGETSUBROUTINEINDEXPROC>(this->loadOpenGLProc("glGetSubroutineIndex"));
		glGetActiveSubroutineName = reinterpret_cast<PFNGLGETACTIVESUBROUTINENAMEPROC>(this->loadOpenGLProc("glGetActiveSubroutineName"));
		glGetActiveSubroutineUniformName = reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC>(this->loadOpenGLProc("glGetActiveSubroutineUniformName"));
		glGetActiveSubroutineUniformiv = reinterpret_cast<PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC>(this->loadOpenGLProc("glGetActiveSubroutineUniformiv"));
		glUniformSubroutinesuiv = reinterpret_cast<PFNGLUNIFORMSUBROUTINESUIVPROC>(this->loadOpenGLProc("glUniformSubroutinesuiv"));
		glMemoryBarrier = reinterpret_cast<PFNGLMEMORYBARRIERPROC>(this->loadOpenGLProc("glMemoryBarrier"));
		glMemoryBarrierByRegion = reinterpret_cast<PFNGLMEMORYBARRIERBYREGIONPROC>(this->loadOpenGLProc("glMemoryBarrierByRegion"));
		glGetShaderiv = reinterpret_cast<PFNGLGETSHADERIVPROC>(this->loadOpenGLProc("glGetShaderiv"));
		glGetProgramiv = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(this->loadOpenGLProc("glGetProgramiv"));
		glGetProgramPipelineiv = reinterpret_cast<PFNGLGETPROGRAMPIPELINEIVPROC>(this->loadOpenGLProc("glGetProgramPipelineiv"));
		glGetAttachedShaders = reinterpret_cast<PFNGLGETATTACHEDSHADERSPROC>(this->loadOpenGLProc("glGetAttachedShaders"));
		glGetShaderInfoLog = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(this->loadOpenGLProc("glGetShaderInfoLog"));
		glGetProgramInfoLog = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(this->loadOpenGLProc("glGetProgramInfoLog"));
		glGetProgramPipelineInfoLog = reinterpret_cast<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>(this->loadOpenGLProc("glGetProgramPipelineInfoLog"));
		glGetShaderSource = reinterpret_cast<PFNGLGETSHADERSOURCEPROC>(this->loadOpenGLProc("glGetShaderSource"));
		glGetShaderPrecisionFormat = reinterpret_cast<PFNGLGETSHADERPRECISIONFORMATPROC>(this->loadOpenGLProc("glGetShaderPrecisionFormat"));
		glGetUniformfv = reinterpret_cast<PFNGLGETUNIFORMFVPROC>(this->loadOpenGLProc("glGetUniformfv"));
		glGetUniformdv = reinterpret_cast<PFNGLGETUNIFORMDVPROC>(this->loadOpenGLProc("glGetUniformdv"));
		glGetUniformiv = reinterpret_cast<PFNGLGETUNIFORMIVPROC>(this->loadOpenGLProc("glGetUniformiv"));
		glGetUniformuiv = reinterpret_cast<PFNGLGETUNIFORMUIVPROC>(this->loadOpenGLProc("glGetUniformuiv"));
		glGetnUniformfv = reinterpret_cast<PFNGLGETNUNIFORMFVPROC>(this->loadOpenGLProc("glGetnUniformfv"));
		glGetnUniformdv = reinterpret_cast<PFNGLGETNUNIFORMDVPROC>(this->loadOpenGLProc("glGetnUniformdv"));
		glGetnUniformiv = reinterpret_cast<PFNGLGETNUNIFORMIVPROC>(this->loadOpenGLProc("glGetnUniformiv"));
		glGetnUniformuiv = reinterpret_cast<PFNGLGETNUNIFORMUIVPROC>(this->loadOpenGLProc("glGetnUniformuiv"));
		glGetUniformSubroutineuiv = reinterpret_cast<PFNGLGETUNIFORMSUBROUTINEUIVPROC>(this->loadOpenGLProc("glGetUniformSubroutineuiv"));
		glGetProgramStageiv = reinterpret_cast<PFNGLGETPROGRAMSTAGEIVPROC>(this->loadOpenGLProc("glGetProgramStageiv"));
	}

	void OpenGLExtension::loadTexturesAndSamplersExtensions()
	{
		glActiveTexture = reinterpret_cast<PFNGLACTIVETEXTUREPROC>(this->loadOpenGLProc("glActiveTexture"));
		glGenTextures = reinterpret_cast<PFNGLGENTEXTURESPROC>(this->loadOpenGLProc("glGenTextures"));
		glBindTexture = reinterpret_cast<PFNGLBINDTEXTUREPROC>(this->loadOpenGLProc("glBindTexture"));
		glBindTextures = reinterpret_cast<PFNGLBINDTEXTURESPROC>(this->loadOpenGLProc("glBindTextures"));
		glBindTextureUnit = reinterpret_cast<PFNGLBINDTEXTUREUNITPROC>(this->loadOpenGLProc("glBindTextureUnit"));
		glCreateTextures = reinterpret_cast<PFNGLCREATETEXTURESPROC>(this->loadOpenGLProc("glCreateTextures"));
		glDeleteTextures = reinterpret_cast<PFNGLDELETETEXTURESPROC>(this->loadOpenGLProc("glDeleteTextures"));
		glIsTexture = reinterpret_cast<PFNGLISTEXTUREPROC>(this->loadOpenGLProc("glIsTexture"));
		glGenSamplers = reinterpret_cast<PFNGLGENSAMPLERSPROC>(this->loadOpenGLProc("glGenSamplers"));
		glCreateSamplers = reinterpret_cast<PFNGLCREATESAMPLERSPROC>(this->loadOpenGLProc("glCreateSamplers"));
		glBindSampler = reinterpret_cast<PFNGLBINDSAMPLERPROC>(this->loadOpenGLProc("glBindSampler"));
		glBindSamplers = reinterpret_cast<PFNGLBINDSAMPLERSPROC>(this->loadOpenGLProc("glBindSamplers"));
		glSamplerParameteri = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>(this->loadOpenGLProc("glSamplerParameteri"));
		glSamplerParameterf = reinterpret_cast<PFNGLSAMPLERPARAMETERFPROC>(this->loadOpenGLProc("glSamplerParameterf"));
		glSamplerParameteriv = reinterpret_cast<PFNGLSAMPLERPARAMETERIVPROC>(this->loadOpenGLProc("glSamplerParameteriv"));
		glSamplerParameterfv = reinterpret_cast<PFNGLSAMPLERPARAMETERFVPROC>(this->loadOpenGLProc("glSamplerParameterfv"));
		glSamplerParameterIiv = reinterpret_cast<PFNGLSAMPLERPARAMETERIIVPROC>(this->loadOpenGLProc("glSamplerParameterIiv"));
		glSamplerParameterIuiv = reinterpret_cast<PFNGLSAMPLERPARAMETERIUIVPROC>(this->loadOpenGLProc("glSamplerParameterIuiv"));
		glDeleteSamplers = reinterpret_cast<PFNGLDELETESAMPLERSPROC>(this->loadOpenGLProc("glDeleteSamplers"));
		glIsSampler = reinterpret_cast<PFNGLISSAMPLERPROC>(this->loadOpenGLProc("glIsSampler"));
		glGetSamplerParameteriv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIVPROC>(this->loadOpenGLProc("glGetSamplerParameteriv"));
		glGetSamplerParameterfv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERFVPROC>(this->loadOpenGLProc("glGetSamplerParameterfv"));
		glGetSamplerParameterIiv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIIVPROC>(this->loadOpenGLProc("glGetSamplerParameterIiv"));
		glGetSamplerParameterIuiv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIUIVPROC>(this->loadOpenGLProc("glGetSamplerParameterIuiv"));
		glPixelStorei = reinterpret_cast<PFNGLPIXELSTOREIPROC>(this->loadOpenGLProc("glPixelStorei"));
		glPixelStoref = reinterpret_cast<PFNGLPIXELSTOREFPROC>(this->loadOpenGLProc("glPixelStoref"));
		glTexImage3D = reinterpret_cast<PFNGLTEXIMAGE3DPROC>(this->loadOpenGLProc("glTexImage3D"));
		glTexImage2D = reinterpret_cast<PFNGLTEXIMAGE2DPROC>(this->loadOpenGLProc("glTexImage2D"));
		glTexImage1D = reinterpret_cast<PFNGLTEXIMAGE1DPROC>(this->loadOpenGLProc("glTexImage1D"));
		glCopyTexImage2D = reinterpret_cast<PFNGLCOPYTEXIMAGE2DPROC>(this->loadOpenGLProc("glCopyTexImage2D"));
		glCopyTexImage1D = reinterpret_cast<PFNGLCOPYTEXIMAGE1DPROC>(this->loadOpenGLProc("glCopyTexImage1D"));
		glTexSubImage3D = reinterpret_cast<PFNGLTEXSUBIMAGE3DPROC>(this->loadOpenGLProc("glTexSubImage3D"));
		glTexSubImage2D = reinterpret_cast<PFNGLTEXSUBIMAGE2DPROC>(this->loadOpenGLProc("glTexSubImage2D"));
		glTexSubImage1D = reinterpret_cast<PFNGLTEXSUBIMAGE1DPROC>(this->loadOpenGLProc("glTexSubImage1D"));
		glCopyTexSubImage3D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE3DPROC>(this->loadOpenGLProc("glCopyTexSubImage3D"));
		glCopyTexSubImage2D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE2DPROC>(this->loadOpenGLProc("glCopyTexSubImage2D"));
		glCopyTexSubImage1D = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE1DPROC>(this->loadOpenGLProc("glCopyTexSubImage1D"));
		glTextureSubImage3D = reinterpret_cast<PFNGLTEXTURESUBIMAGE3DPROC>(this->loadOpenGLProc("glTextureSubImage3D"));
		glTextureSubImage2D = reinterpret_cast<PFNGLTEXTURESUBIMAGE2DPROC>(this->loadOpenGLProc("glTextureSubImage2D"));
		glTextureSubImage1D = reinterpret_cast<PFNGLTEXTURESUBIMAGE1DPROC>(this->loadOpenGLProc("glTextureSubImage1D"));
		glCopyTextureSubImage3D = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE3DPROC>(this->loadOpenGLProc("glCopyTextureSubImage3D"));
		glCopyTextureSubImage2D = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE2DPROC>(this->loadOpenGLProc("glCopyTextureSubImage2D"));
		glCopyTextureSubImage1D = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE1DPROC>(this->loadOpenGLProc("glCopyTextureSubImage1D"));
		glCompressedTexImage3D = reinterpret_cast<PFNGLCOMPRESSEDTEXIMAGE3DPROC>(this->loadOpenGLProc("glCompressedTexImage3D"));
		glCompressedTexImage2D = reinterpret_cast<PFNGLCOMPRESSEDTEXIMAGE2DPROC>(this->loadOpenGLProc("glCompressedTexImage2D"));
		glCompressedTexImage1D = reinterpret_cast<PFNGLCOMPRESSEDTEXIMAGE1DPROC>(this->loadOpenGLProc("glCompressedTexImage1D"));
		glCompressedTexSubImage3D = reinterpret_cast<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>(this->loadOpenGLProc("glCompressedTexSubImage3D"));
		glCompressedTexSubImage2D = reinterpret_cast<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>(this->loadOpenGLProc("glCompressedTexSubImage2D"));
		glCompressedTexSubImage1D = reinterpret_cast<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>(this->loadOpenGLProc("glCompressedTexSubImage1D"));
		glCompressedTextureSubImage3D = reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC>(this->loadOpenGLProc("glCompressedTextureSubImage3D"));
		glCompressedTextureSubImage2D = reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC>(this->loadOpenGLProc("glCompressedTextureSubImage2D"));
		glCompressedTextureSubImage1D = reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC>(this->loadOpenGLProc("glCompressedTextureSubImage1D"));
		glTexImage3DMultisample = reinterpret_cast<PFNGLTEXIMAGE3DMULTISAMPLEPROC>(this->loadOpenGLProc("glTexImage3DMultisample"));
		glTexImage2DMultisample = reinterpret_cast<PFNGLTEXIMAGE2DMULTISAMPLEPROC>(this->loadOpenGLProc("glTexImage2DMultisample"));
		glTexBufferRange = reinterpret_cast<PFNGLTEXBUFFERRANGEPROC>(this->loadOpenGLProc("glTexBufferRange"));
		glTextureBufferRange = reinterpret_cast<PFNGLTEXTUREBUFFERRANGEPROC>(this->loadOpenGLProc("glTextureBufferRange"));
		glTexBuffer = reinterpret_cast<PFNGLTEXBUFFERPROC>(this->loadOpenGLProc("glTexBuffer"));
		glTextureBuffer = reinterpret_cast<PFNGLTEXTUREBUFFERPROC>(this->loadOpenGLProc("glTextureBuffer"));
		glTexParameteri = reinterpret_cast<PFNGLTEXPARAMETERIPROC>(this->loadOpenGLProc("glTexParameteri"));
		glTexParameterf = reinterpret_cast<PFNGLTEXPARAMETERFPROC>(this->loadOpenGLProc("glTexParameterf"));
		glTexParameteriv = reinterpret_cast<PFNGLTEXPARAMETERIVPROC>(this->loadOpenGLProc("glTexParameteriv"));
		glTexParameterfv = reinterpret_cast<PFNGLTEXPARAMETERFVPROC>(this->loadOpenGLProc("glTexParameterfv"));
		glTexParameterIiv = reinterpret_cast<PFNGLTEXPARAMETERIIVPROC>(this->loadOpenGLProc("glTexParameterIiv"));
		glTexParameterIuiv = reinterpret_cast<PFNGLTEXPARAMETERIUIVPROC>(this->loadOpenGLProc("glTexParameterIuiv"));
		glTextureParameteri = reinterpret_cast<PFNGLTEXTUREPARAMETERIPROC>(this->loadOpenGLProc("glTextureParameteri"));
		glTextureParameterf = reinterpret_cast<PFNGLTEXTUREPARAMETERFPROC>(this->loadOpenGLProc("glTextureParameterf"));
		glTextureParameteriv = reinterpret_cast<PFNGLTEXTUREPARAMETERIVPROC>(this->loadOpenGLProc("glTextureParameteriv"));
		glTextureParameterfv = reinterpret_cast<PFNGLTEXTUREPARAMETERFVPROC>(this->loadOpenGLProc("glTextureParameterfv"));
		glTextureParameterIiv = reinterpret_cast<PFNGLTEXTUREPARAMETERIIVPROC>(this->loadOpenGLProc("glTextureParameterIiv"));
		glTextureParameterIuiv = reinterpret_cast<PFNGLTEXTUREPARAMETERIUIVPROC>(this->loadOpenGLProc("glTextureParameterIuiv"));
		glGetTexParameteriv = reinterpret_cast<PFNGLGETTEXPARAMETERIVPROC>(this->loadOpenGLProc("glGetTexParameteriv"));
		glGetTexParameterfv = reinterpret_cast<PFNGLGETTEXPARAMETERFVPROC>(this->loadOpenGLProc("glGetTexParameterfv"));
		glGetTexParameterIiv = reinterpret_cast<PFNGLGETTEXPARAMETERIIVPROC>(this->loadOpenGLProc("glGetTexParameterIiv"));
		glGetTexParameterIuiv = reinterpret_cast<PFNGLGETTEXPARAMETERIUIVPROC>(this->loadOpenGLProc("glGetTexParameterIuiv"));
		glGetTextureParameteriv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIVPROC>(this->loadOpenGLProc("glGetTextureParameteriv"));
		glGetTextureParameterfv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERFVPROC>(this->loadOpenGLProc("glGetTextureParameterfv"));
		glGetTextureParameterIiv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIIVPROC>(this->loadOpenGLProc("glGetTextureParameterIiv"));
		glGetTextureParameterIuiv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIUIVPROC>(this->loadOpenGLProc("glGetTextureParameterIuiv"));
		glGetTexLevelParameteriv = reinterpret_cast<PFNGLGETTEXLEVELPARAMETERIVPROC>(this->loadOpenGLProc("glGetTexLevelParameteriv"));
		glGetTexLevelParameterfv = reinterpret_cast<PFNGLGETTEXLEVELPARAMETERFVPROC>(this->loadOpenGLProc("glGetTexLevelParameterfv"));
		glGetTextureLevelParameteriv = reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERIVPROC>(this->loadOpenGLProc("glGetTextureLevelParameteriv"));
		glGetTextureLevelParameterfv = reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERFVPROC>(this->loadOpenGLProc("glGetTextureLevelParameterfv"));
		glGetTexImage = reinterpret_cast<PFNGLGETTEXIMAGEPROC>(this->loadOpenGLProc("glGetTexImage"));
		glGetTextureImage = reinterpret_cast<PFNGLGETTEXTUREIMAGEPROC>(this->loadOpenGLProc("glGetTextureImage"));
		glGetnTexImage = reinterpret_cast<PFNGLGETNTEXIMAGEPROC>(this->loadOpenGLProc("glGetnTexImage"));
		glGetTextureSubImage = reinterpret_cast<PFNGLGETTEXTURESUBIMAGEPROC>(this->loadOpenGLProc("glGetTextureSubImage"));
		glGetCompressedTexImage = reinterpret_cast<PFNGLGETCOMPRESSEDTEXIMAGEPROC>(this->loadOpenGLProc("glGetCompressedTexImage"));
		glGetCompressedTextureImage = reinterpret_cast<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>(this->loadOpenGLProc("glGetCompressedTextureImage"));
		glGetnCompressedTexImage = reinterpret_cast<PFNGLGETNCOMPRESSEDTEXIMAGEPROC>(this->loadOpenGLProc("glGetnCompressedTexImage"));
		glGetCompressedTextureSubImage = reinterpret_cast<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>(this->loadOpenGLProc("glGetCompressedTextureSubImage"));
		glEnable = reinterpret_cast<PFNGLENABLEPROC>(this->loadOpenGLProc("glEnable"));
		glDisable = reinterpret_cast<PFNGLDISABLEPROC>(this->loadOpenGLProc("glDisable"));
		glIsEnabled = reinterpret_cast<PFNGLISENABLEDPROC>(this->loadOpenGLProc("glIsEnabled"));
		glGenerateMipmap = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(this->loadOpenGLProc("glGenerateMipmap"));
		glGenerateTextureMipmap = reinterpret_cast<PFNGLGENERATETEXTUREMIPMAPPROC>(this->loadOpenGLProc("glGenerateTextureMipmap"));
		glTextureView = reinterpret_cast<PFNGLTEXTUREVIEWPROC>(this->loadOpenGLProc("glTextureView"));
		glTexStorage1D = reinterpret_cast<PFNGLTEXSTORAGE1DPROC>(this->loadOpenGLProc("glTexStorage1D"));
		glTexStorage2D = reinterpret_cast<PFNGLTEXSTORAGE2DPROC>(this->loadOpenGLProc("glTexStorage2D"));
		glTexStorage3D = reinterpret_cast<PFNGLTEXSTORAGE3DPROC>(this->loadOpenGLProc("glTexStorage3D"));
		glTextureStorage1D = reinterpret_cast<PFNGLTEXTURESTORAGE1DPROC>(this->loadOpenGLProc("glTextureStorage1D"));
		glTextureStorage2D = reinterpret_cast<PFNGLTEXTURESTORAGE2DPROC>(this->loadOpenGLProc("glTextureStorage2D"));
		glTextureStorage3D = reinterpret_cast<PFNGLTEXTURESTORAGE3DPROC>(this->loadOpenGLProc("glTextureStorage3D"));
		glTexStorage2DMultisample = reinterpret_cast<PFNGLTEXSTORAGE2DMULTISAMPLEPROC>(this->loadOpenGLProc("glTexStorage2DMultisample"));
		glTexStorage3DMultisample = reinterpret_cast<PFNGLTEXSTORAGE3DMULTISAMPLEPROC>(this->loadOpenGLProc("glTexStorage3DMultisample"));
		glTextureStorage2DMultisample = reinterpret_cast<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>(this->loadOpenGLProc("glTextureStorage2DMultisample"));
		glTextureStorage3DMultisample = reinterpret_cast<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>(this->loadOpenGLProc("glTextureStorage3DMultisample"));
		glInvalidateTexSubImage = reinterpret_cast<PFNGLINVALIDATETEXSUBIMAGEPROC>(this->loadOpenGLProc("glInvalidateTexSubImage"));
		glInvalidateTexImage = reinterpret_cast<PFNGLINVALIDATETEXIMAGEPROC>(this->loadOpenGLProc("glInvalidateTexImage"));
		glClearTexSubImage = reinterpret_cast<PFNGLCLEARTEXSUBIMAGEPROC>(this->loadOpenGLProc("glClearTexSubImage"));
		glClearTexImage = reinterpret_cast<PFNGLCLEARTEXIMAGEPROC>(this->loadOpenGLProc("glClearTexImage"));
		glBindImageTexture = reinterpret_cast<PFNGLBINDIMAGETEXTUREPROC>(this->loadOpenGLProc("glBindImageTexture"));
		glBindImageTextures = reinterpret_cast<PFNGLBINDIMAGETEXTURESPROC>(this->loadOpenGLProc("glBindImageTextures"));
	}

	void OpenGLExtension::loadFramebufferObjectsExtensions()
	{
		glBindFramebuffer = reinterpret_cast<PFNGLBINDFRAMEBUFFERPROC>(this->loadOpenGLProc("glBindFramebuffer"));
		glCreateFramebuffers = reinterpret_cast<PFNGLCREATEFRAMEBUFFERSPROC>(this->loadOpenGLProc("glCreateFramebuffers"));
		glGenFramebuffers = reinterpret_cast<PFNGLGENFRAMEBUFFERSPROC>(this->loadOpenGLProc("glGenFramebuffers"));
		glDeleteFramebuffers = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>(this->loadOpenGLProc("glDeleteFramebuffers"));
		glIsFramebuffer = reinterpret_cast<PFNGLISFRAMEBUFFERPROC>(this->loadOpenGLProc("glIsFramebuffer"));
		glFramebufferParameteri = reinterpret_cast<PFNGLFRAMEBUFFERPARAMETERIPROC>(this->loadOpenGLProc("glFramebufferParameteri"));
		glNamedFramebufferParameteri = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC>(this->loadOpenGLProc("glNamedFramebufferParameteri"));
		glGetFramebufferParameteriv = reinterpret_cast<PFNGLGETFRAMEBUFFERPARAMETERIVPROC>(this->loadOpenGLProc("glGetFramebufferParameteriv"));
		glGetNamedFramebufferParameteriv = reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC>(this->loadOpenGLProc("glGetNamedFramebufferParameteriv"));
		glGetFramebufferAttachmentParameteriv = reinterpret_cast<PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(this->loadOpenGLProc("glGetFramebufferAttachmentParameteriv"));
		glGetNamedFramebufferAttachmentParameteriv = reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(this->loadOpenGLProc("glGetNamedFramebufferAttachmentParameteriv"));
		glBindRenderbuffer = reinterpret_cast<PFNGLBINDRENDERBUFFERPROC>(this->loadOpenGLProc("glBindRenderbuffer"));
		glCreateRenderbuffers = reinterpret_cast<PFNGLCREATERENDERBUFFERSPROC>(this->loadOpenGLProc("glCreateRenderbuffers"));
		glGenRenderbuffers = reinterpret_cast<PFNGLGENRENDERBUFFERSPROC>(this->loadOpenGLProc("glGenRenderbuffers"));
		glDeleteRenderbuffers = reinterpret_cast<PFNGLDELETERENDERBUFFERSPROC>(this->loadOpenGLProc("glDeleteRenderbuffers"));
		glIsRenderbuffer = reinterpret_cast<PFNGLISRENDERBUFFERPROC>(this->loadOpenGLProc("glIsRenderbuffer"));
		glRenderbufferStorageMultisample = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC>(this->loadOpenGLProc("glRenderbufferStorageMultisample"));
		glNamedRenderbufferStorageMultisample = reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>(this->loadOpenGLProc("glNamedRenderbufferStorageMultisample"));
		glRenderbufferStorage = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEPROC>(this->loadOpenGLProc("glRenderbufferStorage"));
		glNamedRenderbufferStorage = reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>(this->loadOpenGLProc("glNamedRenderbufferStorage"));
		glGetRenderbufferParameteriv = reinterpret_cast<PFNGLGETRENDERBUFFERPARAMETERIVPROC>(this->loadOpenGLProc("glGetRenderbufferParameteriv"));
		glGetNamedRenderbufferParameteriv = reinterpret_cast<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>(this->loadOpenGLProc("glGetNamedRenderbufferParameteriv"));
		glFramebufferRenderbuffer = reinterpret_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>(this->loadOpenGLProc("glFramebufferRenderbuffer"));
		glNamedFramebufferRenderbuffer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>(this->loadOpenGLProc("glNamedFramebufferRenderbuffer"));
		glFramebufferTexture = reinterpret_cast<PFNGLFRAMEBUFFERTEXTUREPROC>(this->loadOpenGLProc("glFramebufferTexture"));
		glNamedFramebufferTexture = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>(this->loadOpenGLProc("glNamedFramebufferTexture"));
		glFramebufferTexture1D = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>(this->loadOpenGLProc("glFramebufferTexture1D"));
		glFramebufferTexture2D = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>(this->loadOpenGLProc("glFramebufferTexture2D"));
		glFramebufferTexture3D = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>(this->loadOpenGLProc("glFramebufferTexture3D"));
		glFramebufferTextureLayer = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>(this->loadOpenGLProc("glFramebufferTextureLayer"));
		glNamedFramebufferTextureLayer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>(this->loadOpenGLProc("glNamedFramebufferTextureLayer"));
		glTextureBarrier = reinterpret_cast<PFNGLTEXTUREBARRIERPROC>(this->loadOpenGLProc("glTextureBarrier"));
		glCheckFramebufferStatus = reinterpret_cast<PFNGLCHECKFRAMEBUFFERSTATUSPROC>(this->loadOpenGLProc("glCheckFramebufferStatus"));
		glCheckNamedFramebufferStatus = reinterpret_cast<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>(this->loadOpenGLProc("glCheckNamedFramebufferStatus"));
	}

	void OpenGLExtension::loadVerticesExtensions()
	{
		glPatchParameteri = reinterpret_cast<PFNGLPATCHPARAMETERIPROC>(this->loadOpenGLProc("glPatchParameteri"));
		glVertexAttrib1s = reinterpret_cast<PFNGLVERTEXATTRIB1SPROC>(this->loadOpenGLProc("glVertexAttrib1s"));
		glVertexAttrib2s = reinterpret_cast<PFNGLVERTEXATTRIB2SPROC>(this->loadOpenGLProc("glVertexAttrib2s"));
		glVertexAttrib3s = reinterpret_cast<PFNGLVERTEXATTRIB3SPROC>(this->loadOpenGLProc("glVertexAttrib3s"));
		glVertexAttrib4s = reinterpret_cast<PFNGLVERTEXATTRIB4SPROC>(this->loadOpenGLProc("glVertexAttrib4s"));
		glVertexAttrib1f = reinterpret_cast<PFNGLVERTEXATTRIB1FPROC>(this->loadOpenGLProc("glVertexAttrib1f"));
		glVertexAttrib2f = reinterpret_cast<PFNGLVERTEXATTRIB2FPROC>(this->loadOpenGLProc("glVertexAttrib2f"));
		glVertexAttrib3f = reinterpret_cast<PFNGLVERTEXATTRIB3FPROC>(this->loadOpenGLProc("glVertexAttrib3f"));
		glVertexAttrib4f = reinterpret_cast<PFNGLVERTEXATTRIB4FPROC>(this->loadOpenGLProc("glVertexAttrib4f"));
		glVertexAttrib1d = reinterpret_cast<PFNGLVERTEXATTRIB1DPROC>(this->loadOpenGLProc("glVertexAttrib1d"));
		glVertexAttrib2d = reinterpret_cast<PFNGLVERTEXATTRIB2DPROC>(this->loadOpenGLProc("glVertexAttrib2d"));
		glVertexAttrib3d = reinterpret_cast<PFNGLVERTEXATTRIB3DPROC>(this->loadOpenGLProc("glVertexAttrib3d"));
		glVertexAttrib4d = reinterpret_cast<PFNGLVERTEXATTRIB4DPROC>(this->loadOpenGLProc("glVertexAttrib4d"));
		glVertexAttrib1sv = reinterpret_cast<PFNGLVERTEXATTRIB1SVPROC>(this->loadOpenGLProc("glVertexAttrib1sv"));
		glVertexAttrib2sv = reinterpret_cast<PFNGLVERTEXATTRIB2SVPROC>(this->loadOpenGLProc("glVertexAttrib2sv"));
		glVertexAttrib3sv = reinterpret_cast<PFNGLVERTEXATTRIB3SVPROC>(this->loadOpenGLProc("glVertexAttrib3sv"));
		glVertexAttrib1fv = reinterpret_cast<PFNGLVERTEXATTRIB1FVPROC>(this->loadOpenGLProc("glVertexAttrib1fv"));
		glVertexAttrib2fv = reinterpret_cast<PFNGLVERTEXATTRIB2FVPROC>(this->loadOpenGLProc("glVertexAttrib2fv"));
		glVertexAttrib3fv = reinterpret_cast<PFNGLVERTEXATTRIB3FVPROC>(this->loadOpenGLProc("glVertexAttrib3fv"));
		glVertexAttrib1dv = reinterpret_cast<PFNGLVERTEXATTRIB1DVPROC>(this->loadOpenGLProc("glVertexAttrib1dv"));
		glVertexAttrib2dv = reinterpret_cast<PFNGLVERTEXATTRIB2DVPROC>(this->loadOpenGLProc("glVertexAttrib2dv"));
		glVertexAttrib3dv = reinterpret_cast<PFNGLVERTEXATTRIB3DVPROC>(this->loadOpenGLProc("glVertexAttrib3dv"));
		glVertexAttrib4bv = reinterpret_cast<PFNGLVERTEXATTRIB4BVPROC>(this->loadOpenGLProc("glVertexAttrib4bv"));
		glVertexAttrib4sv = reinterpret_cast<PFNGLVERTEXATTRIB4SVPROC>(this->loadOpenGLProc("glVertexAttrib4sv"));
		glVertexAttrib4fv = reinterpret_cast<PFNGLVERTEXATTRIB4FVPROC>(this->loadOpenGLProc("glVertexAttrib4fv"));
		glVertexAttrib4iv = reinterpret_cast<PFNGLVERTEXATTRIB4IVPROC>(this->loadOpenGLProc("glVertexAttrib4iv"));
		glVertexAttrib4dv = reinterpret_cast<PFNGLVERTEXATTRIB4DVPROC>(this->loadOpenGLProc("glVertexAttrib4dv"));
		glVertexAttrib4ubv = reinterpret_cast<PFNGLVERTEXATTRIB4UBVPROC>(this->loadOpenGLProc("glVertexAttrib4ubv"));
		glVertexAttrib4usv = reinterpret_cast<PFNGLVERTEXATTRIB4USVPROC>(this->loadOpenGLProc("glVertexAttrib4usv"));
		glVertexAttrib4uiv = reinterpret_cast<PFNGLVERTEXATTRIB4UIVPROC>(this->loadOpenGLProc("glVertexAttrib4uiv"));
		glVertexAttrib4Nub = reinterpret_cast<PFNGLVERTEXATTRIB4NUBPROC>(this->loadOpenGLProc("glVertexAttrib4Nub"));
		glVertexAttrib4Nbv = reinterpret_cast<PFNGLVERTEXATTRIB4NBVPROC>(this->loadOpenGLProc("glVertexAttrib4Nbv"));
		glVertexAttrib4Nsv = reinterpret_cast<PFNGLVERTEXATTRIB4NSVPROC>(this->loadOpenGLProc("glVertexAttrib4Nsv"));
		glVertexAttrib4Niv = reinterpret_cast<PFNGLVERTEXATTRIB4NIVPROC>(this->loadOpenGLProc("glVertexAttrib4Niv"));
		glVertexAttrib4Nusv = reinterpret_cast<PFNGLVERTEXATTRIB4NUSVPROC>(this->loadOpenGLProc("glVertexAttrib4Nusv"));
		glVertexAttrib4Nuiv = reinterpret_cast<PFNGLVERTEXATTRIB4NUIVPROC>(this->loadOpenGLProc("glVertexAttrib4Nuiv"));
		glVertexAttribI1i = reinterpret_cast<PFNGLVERTEXATTRIBI1IPROC>(this->loadOpenGLProc("glVertexAttribI1i"));
		glVertexAttribI1ui = reinterpret_cast<PFNGLVERTEXATTRIBI1UIPROC>(this->loadOpenGLProc("glVertexAttribI1ui"));
		glVertexAttribI2i = reinterpret_cast<PFNGLVERTEXATTRIBI2IPROC>(this->loadOpenGLProc("glVertexAttribI2i"));
		glVertexAttribI2ui = reinterpret_cast<PFNGLVERTEXATTRIBI2UIPROC>(this->loadOpenGLProc("glVertexAttribI2ui"));
		glVertexAttribI3i = reinterpret_cast<PFNGLVERTEXATTRIBI3IPROC>(this->loadOpenGLProc("glVertexAttribI3i"));
		glVertexAttribI3ui = reinterpret_cast<PFNGLVERTEXATTRIBI3UIPROC>(this->loadOpenGLProc("glVertexAttribI3ui"));
		glVertexAttribI4i = reinterpret_cast<PFNGLVERTEXATTRIBI4IPROC>(this->loadOpenGLProc("glVertexAttribI4i"));
		glVertexAttribI4ui = reinterpret_cast<PFNGLVERTEXATTRIBI4UIPROC>(this->loadOpenGLProc("glVertexAttribI4ui"));
		glVertexAttribI1iv = reinterpret_cast<PFNGLVERTEXATTRIBI1IVPROC>(this->loadOpenGLProc("glVertexAttribI1iv"));
		glVertexAttribI1uiv = reinterpret_cast<PFNGLVERTEXATTRIBI1UIVPROC>(this->loadOpenGLProc("glVertexAttribI1uiv"));
		glVertexAttribI2iv = reinterpret_cast<PFNGLVERTEXATTRIBI2IVPROC>(this->loadOpenGLProc("glVertexAttribI2iv"));
		glVertexAttribI2uiv = reinterpret_cast<PFNGLVERTEXATTRIBI2UIVPROC>(this->loadOpenGLProc("glVertexAttribI2uiv"));
		glVertexAttribI3iv = reinterpret_cast<PFNGLVERTEXATTRIBI3IVPROC>(this->loadOpenGLProc("glVertexAttribI3iv"));
		glVertexAttribI3uiv = reinterpret_cast<PFNGLVERTEXATTRIBI3UIVPROC>(this->loadOpenGLProc("glVertexAttribI3uiv"));
		glVertexAttribI4iv = reinterpret_cast<PFNGLVERTEXATTRIBI4IVPROC>(this->loadOpenGLProc("glVertexAttribI4iv"));
		glVertexAttribI4uiv = reinterpret_cast<PFNGLVERTEXATTRIBI4UIVPROC>(this->loadOpenGLProc("glVertexAttribI4uiv"));
		glVertexAttribI4bv = reinterpret_cast<PFNGLVERTEXATTRIBI4BVPROC>(this->loadOpenGLProc("glVertexAttribI4bv"));
		glVertexAttribI4sv = reinterpret_cast<PFNGLVERTEXATTRIBI4SVPROC>(this->loadOpenGLProc("glVertexAttribI4sv"));
		glVertexAttribI4ubv = reinterpret_cast<PFNGLVERTEXATTRIBI4UBVPROC>(this->loadOpenGLProc("glVertexAttribI4ubv"));
		glVertexAttribI4usv = reinterpret_cast<PFNGLVERTEXATTRIBI4USVPROC>(this->loadOpenGLProc("glVertexAttribI4usv"));
		glVertexAttribL1d = reinterpret_cast<PFNGLVERTEXATTRIBL1DPROC>(this->loadOpenGLProc("glVertexAttribL1d"));
		glVertexAttribL2d = reinterpret_cast<PFNGLVERTEXATTRIBL2DPROC>(this->loadOpenGLProc("glVertexAttribL2d"));
		glVertexAttribL3d = reinterpret_cast<PFNGLVERTEXATTRIBL3DPROC>(this->loadOpenGLProc("glVertexAttribL3d"));
		glVertexAttribL4d = reinterpret_cast<PFNGLVERTEXATTRIBL4DPROC>(this->loadOpenGLProc("glVertexAttribL4d"));
		glVertexAttribL1dv = reinterpret_cast<PFNGLVERTEXATTRIBL1DVPROC>(this->loadOpenGLProc("glVertexAttribL1dv"));
		glVertexAttribL2dv = reinterpret_cast<PFNGLVERTEXATTRIBL2DVPROC>(this->loadOpenGLProc("glVertexAttribL2dv"));
		glVertexAttribL3dv = reinterpret_cast<PFNGLVERTEXATTRIBL3DVPROC>(this->loadOpenGLProc("glVertexAttribL3dv"));
		glVertexAttribL4dv = reinterpret_cast<PFNGLVERTEXATTRIBL4DVPROC>(this->loadOpenGLProc("glVertexAttribL4dv"));
		glVertexAttribP1ui = reinterpret_cast<PFNGLVERTEXATTRIBP1UIPROC>(this->loadOpenGLProc("glVertexAttribP1ui"));
		glVertexAttribP2ui = reinterpret_cast<PFNGLVERTEXATTRIBP2UIPROC>(this->loadOpenGLProc("glVertexAttribP2ui"));
		glVertexAttribP3ui = reinterpret_cast<PFNGLVERTEXATTRIBP3UIPROC>(this->loadOpenGLProc("glVertexAttribP3ui"));
		glVertexAttribP4ui = reinterpret_cast<PFNGLVERTEXATTRIBP4UIPROC>(this->loadOpenGLProc("glVertexAttribP4ui"));
		glVertexAttribP1uiv = reinterpret_cast<PFNGLVERTEXATTRIBP1UIVPROC>(this->loadOpenGLProc("glVertexAttribP1uiv"));
		glVertexAttribP2uiv = reinterpret_cast<PFNGLVERTEXATTRIBP2UIVPROC>(this->loadOpenGLProc("glVertexAttribP2uiv"));
		glVertexAttribP3uiv = reinterpret_cast<PFNGLVERTEXATTRIBP3UIVPROC>(this->loadOpenGLProc("glVertexAttribP3uiv"));
		glVertexAttribP4uiv = reinterpret_cast<PFNGLVERTEXATTRIBP4UIVPROC>(this->loadOpenGLProc("glVertexAttribP4uiv"));
	}

	void OpenGLExtension::loadVertexArraysExtensions()
	{
		glGenVertexArrays = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(this->loadOpenGLProc("glGenVertexArrays"));
		glDeleteVertexArrays = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(this->loadOpenGLProc("glDeleteVertexArrays"));
		glBindVertexArray = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(this->loadOpenGLProc("glBindVertexArray"));
		glCreateVertexArrays = reinterpret_cast<PFNGLCREATEVERTEXARRAYSPROC>(this->loadOpenGLProc("glCreateVertexArrays"));
		glIsVertexArray = reinterpret_cast<PFNGLISVERTEXARRAYPROC>(this->loadOpenGLProc("glIsVertexArray"));
		glVertexArrayElementBuffer = reinterpret_cast<PFNGLVERTEXARRAYELEMENTBUFFERPROC>(this->loadOpenGLProc("glVertexArrayElementBuffer"));
		glVertexAttribFormat = reinterpret_cast<PFNGLVERTEXATTRIBFORMATPROC>(this->loadOpenGLProc("glVertexAttribFormat"));
		glVertexAttribIFormat = reinterpret_cast<PFNGLVERTEXATTRIBIFORMATPROC>(this->loadOpenGLProc("glVertexAttribIFormat"));
		glVertexAttribLFormat = reinterpret_cast<PFNGLVERTEXATTRIBLFORMATPROC>(this->loadOpenGLProc("glVertexAttribLFormat"));
		glVertexArrayAttribFormat = reinterpret_cast<PFNGLVERTEXARRAYATTRIBFORMATPROC>(this->loadOpenGLProc("glVertexArrayAttribFormat"));
		glVertexArrayAttribIFormat = reinterpret_cast<PFNGLVERTEXARRAYATTRIBIFORMATPROC>(this->loadOpenGLProc("glVertexArrayAttribIFormat"));
		glVertexArrayAttribLFormat = reinterpret_cast<PFNGLVERTEXARRAYATTRIBLFORMATPROC>(this->loadOpenGLProc("glVertexArrayAttribLFormat"));
		glBindVertexBuffer = reinterpret_cast<PFNGLBINDVERTEXBUFFERPROC>(this->loadOpenGLProc("glBindVertexBuffer"));
		glVertexArrayVertexBuffer = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERPROC>(this->loadOpenGLProc("glVertexArrayVertexBuffer"));
		glBindVertexBuffers = reinterpret_cast<PFNGLBINDVERTEXBUFFERSPROC>(this->loadOpenGLProc("glBindVertexBuffers"));
		glVertexArrayVertexBuffers = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>(this->loadOpenGLProc("glVertexArrayVertexBuffers"));
		glVertexAttribBinding = reinterpret_cast<PFNGLVERTEXATTRIBBINDINGPROC>(this->loadOpenGLProc("glVertexAttribBinding"));
		glVertexArrayAttribBinding = reinterpret_cast<PFNGLVERTEXARRAYATTRIBBINDINGPROC>(this->loadOpenGLProc("glVertexArrayAttribBinding"));
		glVertexAttribPointer = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(this->loadOpenGLProc("glVertexAttribPointer"));
		glVertexAttribIPointer = reinterpret_cast<PFNGLVERTEXATTRIBIPOINTERPROC>(this->loadOpenGLProc("glVertexAttribIPointer"));
		glVertexAttribLPointer = reinterpret_cast<PFNGLVERTEXATTRIBLPOINTERPROC>(this->loadOpenGLProc("glVertexAttribLPointer"));
		glEnableVertexAttribArray = reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(this->loadOpenGLProc("glEnableVertexAttribArray"));
		glEnableVertexArrayAttrib = reinterpret_cast<PFNGLENABLEVERTEXARRAYATTRIBPROC>(this->loadOpenGLProc("glEnableVertexArrayAttrib"));
		glDisableVertexAttribArray = reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(this->loadOpenGLProc("glDisableVertexAttribArray"));
		glDisableVertexArrayAttrib = reinterpret_cast<PFNGLDISABLEVERTEXARRAYATTRIBPROC>(this->loadOpenGLProc("glDisableVertexArrayAttrib"));
		glVertexBindingDivisor = reinterpret_cast<PFNGLVERTEXBINDINGDIVISORPROC>(this->loadOpenGLProc("glVertexBindingDivisor"));
		glVertexArrayBindingDivisor = reinterpret_cast<PFNGLVERTEXARRAYBINDINGDIVISORPROC>(this->loadOpenGLProc("glVertexArrayBindingDivisor"));
		glVertexAttribDivisor = reinterpret_cast<PFNGLVERTEXATTRIBDIVISORPROC>(this->loadOpenGLProc("glVertexAttribDivisor"));
		glPrimitiveRestartIndex = reinterpret_cast<PFNGLPRIMITIVERESTARTINDEXPROC>(this->loadOpenGLProc("glPrimitiveRestartIndex"));
		glDrawArrays = reinterpret_cast<PFNGLDRAWARRAYSPROC>(this->loadOpenGLProc("glDrawArrays"));
		glDrawArraysInstancedBaseInstance = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>(this->loadOpenGLProc("glDrawArraysInstancedBaseInstance"));
		glDrawArraysInstanced = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDPROC>(this->loadOpenGLProc("glDrawArraysInstanced"));
		glDrawArraysIndirect = reinterpret_cast<PFNGLDRAWARRAYSINDIRECTPROC>(this->loadOpenGLProc("glDrawArraysIndirect"));
		glMultiDrawArrays = reinterpret_cast<PFNGLMULTIDRAWARRAYSPROC>(this->loadOpenGLProc("glMultiDrawArrays"));
		glMultiDrawArraysIndirect = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTPROC>(this->loadOpenGLProc("glMultiDrawArraysIndirect"));
		glMultiDrawArraysIndirectCount = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>(this->loadOpenGLProc("glMultiDrawArraysIndirectCount"));
		glDrawElements = reinterpret_cast<PFNGLDRAWELEMENTSPROC>(this->loadOpenGLProc("glDrawElements"));
		glDrawElementsInstancedBaseInstance = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>(this->loadOpenGLProc("glDrawElementsInstancedBaseInstance"));
		glDrawElementsInstanced = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>(this->loadOpenGLProc("glDrawElementsInstanced"));
		glMultiDrawElements = reinterpret_cast<PFNGLMULTIDRAWELEMENTSPROC>(this->loadOpenGLProc("glMultiDrawElements"));
		glDrawRangeElements = reinterpret_cast<PFNGLDRAWRANGEELEMENTSPROC>(this->loadOpenGLProc("glDrawRangeElements"));
		glDrawElementsBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSBASEVERTEXPROC>(this->loadOpenGLProc("glDrawElementsBaseVertex"));
		glDrawRangeElementsBaseVertex = reinterpret_cast<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>(this->loadOpenGLProc("glDrawRangeElementsBaseVertex"));
		glDrawElementsInstancedBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>(this->loadOpenGLProc("glDrawElementsInstancedBaseVertex"));
		glDrawElementsInstancedBaseVertexBaseInstance = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>(this->loadOpenGLProc("glDrawElementsInstancedBaseVertexBaseInstance"));
		glDrawElementsIndirect = reinterpret_cast<PFNGLDRAWELEMENTSINDIRECTPROC>(this->loadOpenGLProc("glDrawElementsIndirect"));
		glMultiDrawElementsIndirect = reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>(this->loadOpenGLProc("glMultiDrawElementsIndirect"));
		glMultiDrawElementsIndirectCount = reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>(this->loadOpenGLProc("glMultiDrawElementsIndirectCount"));
		glMultiDrawElementsBaseVertex = reinterpret_cast<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>(this->loadOpenGLProc("glMultiDrawElementsBaseVertex"));
		glGetVertexArrayiv = reinterpret_cast<PFNGLGETVERTEXARRAYIVPROC>(this->loadOpenGLProc("glGetVertexArrayiv"));
		glGetVertexArrayIndexediv = reinterpret_cast<PFNGLGETVERTEXARRAYINDEXEDIVPROC>(this->loadOpenGLProc("glGetVertexArrayIndexediv"));
		glGetVertexArrayIndexed64iv = reinterpret_cast<PFNGLGETVERTEXARRAYINDEXED64IVPROC>(this->loadOpenGLProc("glGetVertexArrayIndexed64iv"));
		glGetVertexAttribdv = reinterpret_cast<PFNGLGETVERTEXATTRIBDVPROC>(this->loadOpenGLProc("glGetVertexAttribdv"));
		glGetVertexAttribfv = reinterpret_cast<PFNGLGETVERTEXATTRIBFVPROC>(this->loadOpenGLProc("glGetVertexAttribfv"));
		glGetVertexAttribiv = reinterpret_cast<PFNGLGETVERTEXATTRIBIVPROC>(this->loadOpenGLProc("glGetVertexAttribiv"));
		glGetVertexAttribIiv = reinterpret_cast<PFNGLGETVERTEXATTRIBIIVPROC>(this->loadOpenGLProc("glGetVertexAttribIiv"));
		glGetVertexAttribIuiv = reinterpret_cast<PFNGLGETVERTEXATTRIBIUIVPROC>(this->loadOpenGLProc("glGetVertexAttribIuiv"));
		glGetVertexAttribLdv = reinterpret_cast<PFNGLGETVERTEXATTRIBLDVPROC>(this->loadOpenGLProc("glGetVertexAttribLdv"));
		glGetVertexAttribPointerv = reinterpret_cast<PFNGLGETVERTEXATTRIBPOINTERVPROC>(this->loadOpenGLProc("glGetVertexAttribPointerv"));
		glBeginConditionalRender = reinterpret_cast<PFNGLBEGINCONDITIONALRENDERPROC>(this->loadOpenGLProc("glBeginConditionalRender"));
		glEndConditionalRender = reinterpret_cast<PFNGLENDCONDITIONALRENDERPROC>(this->loadOpenGLProc("glEndConditionalRender"));
	}

	void OpenGLExtension::loadVertexAttributesExtensions()
	{
		glBindAttribLocation = reinterpret_cast<PFNGLBINDATTRIBLOCATIONPROC>(this->loadOpenGLProc("glBindAttribLocation"));
		glGetActiveAttrib = reinterpret_cast<PFNGLGETACTIVEATTRIBPROC>(this->loadOpenGLProc("glGetActiveAttrib"));
		glGetAttribLocation = reinterpret_cast<PFNGLGETATTRIBLOCATIONPROC>(this->loadOpenGLProc("glGetAttribLocation"));
		glTransformFeedbackVaryings = reinterpret_cast<PFNGLTRANSFORMFEEDBACKVARYINGSPROC>(this->loadOpenGLProc("glTransformFeedbackVaryings"));
		glGetTransformFeedbackVarying = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKVARYINGPROC>(this->loadOpenGLProc("glGetTransformFeedbackVarying"));
		glValidateProgram = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>(this->loadOpenGLProc("glValidateProgram"));
		glValidateProgramPipeline = reinterpret_cast<PFNGLVALIDATEPROGRAMPIPELINEPROC>(this->loadOpenGLProc("glValidateProgramPipeline"));
		glPatchParameterfv = reinterpret_cast<PFNGLPATCHPARAMETERFVPROC>(this->loadOpenGLProc("glPatchParameterfv"));
	}

	void OpenGLExtension::loadVertexPostProcessingExtensions()
	{
		glGenTransformFeedbacks = reinterpret_cast<PFNGLGENTRANSFORMFEEDBACKSPROC>(this->loadOpenGLProc("glGenTransformFeedbacks"));
		glDeleteTransformFeedbacks = reinterpret_cast<PFNGLDELETETRANSFORMFEEDBACKSPROC>(this->loadOpenGLProc("glDeleteTransformFeedbacks"));
		glIsTransformFeedback = reinterpret_cast<PFNGLISTRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glIsTransformFeedback"));
		glBindTransformFeedback = reinterpret_cast<PFNGLBINDTRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glBindTransformFeedback"));
		glCreateTransformFeedbacks = reinterpret_cast<PFNGLCREATETRANSFORMFEEDBACKSPROC>(this->loadOpenGLProc("glCreateTransformFeedbacks"));
		glBeginTransformFeedback = reinterpret_cast<PFNGLBEGINTRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glBeginTransformFeedback"));
		glEndTransformFeedback = reinterpret_cast<PFNGLENDTRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glEndTransformFeedback"));
		glPauseTransformFeedback = reinterpret_cast<PFNGLPAUSETRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glPauseTransformFeedback"));
		glResumeTransformFeedback = reinterpret_cast<PFNGLRESUMETRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glResumeTransformFeedback"));
		glTransformFeedbackBufferRange = reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC>(this->loadOpenGLProc("glTransformFeedbackBufferRange"));
		glTransformFeedbackBufferBase = reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC>(this->loadOpenGLProc("glTransformFeedbackBufferBase"));
		glDrawTransformFeedback = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKPROC>(this->loadOpenGLProc("glDrawTransformFeedback"));
		glDrawTransformFeedbackInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>(this->loadOpenGLProc("glDrawTransformFeedbackInstanced"));
		glDrawTransformFeedbackStream = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>(this->loadOpenGLProc("glDrawTransformFeedbackStream"));
		glDrawTransformFeedbackStreamInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>(this->loadOpenGLProc("glDrawTransformFeedbackStreamInstanced"));
		glProvokingVertex = reinterpret_cast<PFNGLPROVOKINGVERTEXPROC>(this->loadOpenGLProc("glProvokingVertex"));
		glClipControl = reinterpret_cast<PFNGLCLIPCONTROLPROC>(this->loadOpenGLProc("glClipControl"));
		glDepthRangeArrayv = reinterpret_cast<PFNGLDEPTHRANGEARRAYVPROC>(this->loadOpenGLProc("glDepthRangeArrayv"));
		glDepthRangeIndexed = reinterpret_cast<PFNGLDEPTHRANGEINDEXEDPROC>(this->loadOpenGLProc("glDepthRangeIndexed"));
		glDepthRange = reinterpret_cast<PFNGLDEPTHRANGEPROC>(this->loadOpenGLProc("glDepthRange"));
		glDepthRangef = reinterpret_cast<PFNGLDEPTHRANGEFPROC>(this->loadOpenGLProc("glDepthRangef"));
		glViewportArrayv = reinterpret_cast<PFNGLVIEWPORTARRAYVPROC>(this->loadOpenGLProc("glViewportArrayv"));
		glViewportIndexedf = reinterpret_cast<PFNGLVIEWPORTINDEXEDFPROC>(this->loadOpenGLProc("glViewportIndexedf"));
		glViewportIndexedfv = reinterpret_cast<PFNGLVIEWPORTINDEXEDFVPROC>(this->loadOpenGLProc("glViewportIndexedfv"));
		glViewport = reinterpret_cast<PFNGLVIEWPORTPROC>(this->loadOpenGLProc("glViewport"));
	}

	void OpenGLExtension::loadRasterizationExtensions()
	{
		glGetMultisamplefv = reinterpret_cast<PFNGLGETMULTISAMPLEFVPROC>(this->loadOpenGLProc("glGetMultisamplefv"));
		glMinSampleShading = reinterpret_cast<PFNGLMINSAMPLESHADINGPROC>(this->loadOpenGLProc("glMinSampleShading"));
		glPointSize = reinterpret_cast<PFNGLPOINTSIZEPROC>(this->loadOpenGLProc("glPointSize"));
		glPointParameteri = reinterpret_cast<PFNGLPOINTPARAMETERIPROC>(this->loadOpenGLProc("glPointParameteri"));
		glPointParameterf = reinterpret_cast<PFNGLPOINTPARAMETERFPROC>(this->loadOpenGLProc("glPointParameterf"));
		glPointParameteriv = reinterpret_cast<PFNGLPOINTPARAMETERIVPROC>(this->loadOpenGLProc("glPointParameteriv"));
		glPointParameterfv = reinterpret_cast<PFNGLPOINTPARAMETERFVPROC>(this->loadOpenGLProc("glPointParameterfv"));
		glLineWidth = reinterpret_cast<PFNGLLINEWIDTHPROC>(this->loadOpenGLProc("glLineWidth"));
		glFrontFace = reinterpret_cast<PFNGLFRONTFACEPROC>(this->loadOpenGLProc("glFrontFace"));
		glCullFace = reinterpret_cast<PFNGLCULLFACEPROC>(this->loadOpenGLProc("glCullFace"));
		glPolygonMode = reinterpret_cast<PFNGLPOLYGONMODEPROC>(this->loadOpenGLProc("glPolygonMode"));
		glPolygonOffsetClamp = reinterpret_cast<PFNGLPOLYGONOFFSETCLAMPPROC>(this->loadOpenGLProc("glPolygonOffsetClamp"));
		glPolygonOffset = reinterpret_cast<PFNGLPOLYGONOFFSETPROC>(this->loadOpenGLProc("glPolygonOffset"));
	}

	void OpenGLExtension::loadFragmentShadersExtensions()
	{
		glBindFragDataLocationIndexed = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONINDEXEDPROC>(this->loadOpenGLProc("glBindFragDataLocationIndexed"));
		glBindFragDataLocation = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONPROC>(this->loadOpenGLProc("glBindFragDataLocation"));
		glGetFragDataLocation = reinterpret_cast<PFNGLGETFRAGDATALOCATIONPROC>(this->loadOpenGLProc("glGetFragDataLocation"));
		glGetFragDataIndex = reinterpret_cast<PFNGLGETFRAGDATAINDEXPROC>(this->loadOpenGLProc("glGetFragDataIndex"));
	}

	void OpenGLExtension::loadComputeShadersExtensions()
	{
		glDispatchCompute = reinterpret_cast<PFNGLDISPATCHCOMPUTEPROC>(this->loadOpenGLProc("glDispatchCompute"));
		glDispatchComputeIndirect = reinterpret_cast<PFNGLDISPATCHCOMPUTEINDIRECTPROC>(this->loadOpenGLProc("glDispatchComputeIndirect"));
	}

	void OpenGLExtension::loadPerFragmentOperationsExtensions()
	{
		glEnablei = reinterpret_cast<PFNGLENABLEIPROC>(this->loadOpenGLProc("glEnablei"));
		glDisablei = reinterpret_cast<PFNGLDISABLEIPROC>(this->loadOpenGLProc("glDisablei"));
		glIsEnabledi = reinterpret_cast<PFNGLISENABLEDIPROC>(this->loadOpenGLProc("glIsEnabledi"));
		glScissorArrayv = reinterpret_cast<PFNGLSCISSORARRAYVPROC>(this->loadOpenGLProc("glScissorArrayv"));
		glScissorIndexed = reinterpret_cast<PFNGLSCISSORINDEXEDPROC>(this->loadOpenGLProc("glScissorIndexed"));
		glScissorIndexedv = reinterpret_cast<PFNGLSCISSORINDEXEDVPROC>(this->loadOpenGLProc("glScissorIndexedv"));
		glScissor = reinterpret_cast<PFNGLSCISSORPROC>(this->loadOpenGLProc("glScissor"));
		glSampleCoverage = reinterpret_cast<PFNGLSAMPLECOVERAGEPROC>(this->loadOpenGLProc("glSampleCoverage"));
		glSampleMaski = reinterpret_cast<PFNGLSAMPLEMASKIPROC>(this->loadOpenGLProc("glSampleMaski"));
		glStencilFunc = reinterpret_cast<PFNGLSTENCILFUNCPROC>(this->loadOpenGLProc("glStencilFunc"));
		glStencilFuncSeparate = reinterpret_cast<PFNGLSTENCILFUNCSEPARATEPROC>(this->loadOpenGLProc("glStencilFuncSeparate"));
		glStencilOp = reinterpret_cast<PFNGLSTENCILOPPROC>(this->loadOpenGLProc("glStencilOp"));
		glStencilOpSeparate = reinterpret_cast<PFNGLSTENCILOPSEPARATEPROC>(this->loadOpenGLProc("glStencilOpSeparate"));
		glDepthFunc = reinterpret_cast<PFNGLDEPTHFUNCPROC>(this->loadOpenGLProc("glDepthFunc"));
		glBlendEquation = reinterpret_cast<PFNGLBLENDEQUATIONPROC>(this->loadOpenGLProc("glBlendEquation"));
		glBlendEquationSeparate = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEPROC>(this->loadOpenGLProc("glBlendEquationSeparate"));
		glBlendEquationi = reinterpret_cast<PFNGLBLENDEQUATIONIPROC>(this->loadOpenGLProc("glBlendEquationi"));
		glBlendEquationSeparatei = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEIPROC>(this->loadOpenGLProc("glBlendEquationSeparatei"));
		glBlendFunc = reinterpret_cast<PFNGLBLENDFUNCPROC>(this->loadOpenGLProc("glBlendFunc"));
		glBlendFuncSeparate = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>(this->loadOpenGLProc("glBlendFuncSeparate"));
		glBlendFunci = reinterpret_cast<PFNGLBLENDFUNCIPROC>(this->loadOpenGLProc("glBlendFunci"));
		glBlendFuncSeparatei = reinterpret_cast<PFNGLBLENDFUNCSEPARATEIPROC>(this->loadOpenGLProc("glBlendFuncSeparatei"));
		glBlendColor = reinterpret_cast<PFNGLBLENDCOLORPROC>(this->loadOpenGLProc("glBlendColor"));
		glLogicOp = reinterpret_cast<PFNGLLOGICOPPROC>(this->loadOpenGLProc("glLogicOp"));
	}

	void OpenGLExtension::loadHintsExtensions()
	{
		glHint = reinterpret_cast<PFNGLHINTPROC>(this->loadOpenGLProc("glHint"));
	}

	void OpenGLExtension::loadWholeFramebufferExtensions()
	{
		glDrawBuffer = reinterpret_cast<PFNGLDRAWBUFFERPROC>(this->loadOpenGLProc("glDrawBuffer"));
		glNamedFramebufferDrawBuffer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>(this->loadOpenGLProc("glNamedFramebufferDrawBuffer"));
		glDrawBuffers = reinterpret_cast<PFNGLDRAWBUFFERSPROC>(this->loadOpenGLProc("glDrawBuffers"));
		glNamedFramebufferDrawBuffers = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>(this->loadOpenGLProc("glNamedFramebufferDrawBuffers"));
		glColorMask = reinterpret_cast<PFNGLCOLORMASKPROC>(this->loadOpenGLProc("glColorMask"));
		glColorMaski = reinterpret_cast<PFNGLCOLORMASKIPROC>(this->loadOpenGLProc("glColorMaski"));
		glDepthMask = reinterpret_cast<PFNGLDEPTHMASKPROC>(this->loadOpenGLProc("glDepthMask"));
		glStencilMask = reinterpret_cast<PFNGLSTENCILMASKPROC>(this->loadOpenGLProc("glStencilMask"));
		glStencilMaskSeparate = reinterpret_cast<PFNGLSTENCILMASKSEPARATEPROC>(this->loadOpenGLProc("glStencilMaskSeparate"));
		glClear = reinterpret_cast<PFNGLCLEARPROC>(this->loadOpenGLProc("glClear"));
		glClearColor = reinterpret_cast<PFNGLCLEARCOLORPROC>(this->loadOpenGLProc("glClearColor"));
		glClearDepth = reinterpret_cast<PFNGLCLEARDEPTHPROC>(this->loadOpenGLProc("glClearDepth"));
		glClearDepthf = reinterpret_cast<PFNGLCLEARDEPTHFPROC>(this->loadOpenGLProc("glClearDepthf"));
		glClearStencil = reinterpret_cast<PFNGLCLEARSTENCILPROC>(this->loadOpenGLProc("glClearStencil"));
		glClearBufferiv = reinterpret_cast<PFNGLCLEARBUFFERIVPROC>(this->loadOpenGLProc("glClearBufferiv"));
		glClearBufferfv = reinterpret_cast<PFNGLCLEARBUFFERFVPROC>(this->loadOpenGLProc("glClearBufferfv"));
		glClearBufferuiv = reinterpret_cast<PFNGLCLEARBUFFERUIVPROC>(this->loadOpenGLProc("glClearBufferuiv"));
		glClearNamedFramebufferiv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERIVPROC>(this->loadOpenGLProc("glClearNamedFramebufferiv"));
		glClearNamedFramebufferfv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFVPROC>(this->loadOpenGLProc("glClearNamedFramebufferfv"));
		glClearNamedFramebufferuiv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC>(this->loadOpenGLProc("glClearNamedFramebufferuiv"));
		glClearBufferfi = reinterpret_cast<PFNGLCLEARBUFFERFIPROC>(this->loadOpenGLProc("glClearBufferfi"));
		glClearNamedFramebufferfi = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFIPROC>(this->loadOpenGLProc("glClearNamedFramebufferfi"));
		glInvalidateSubFramebuffer = reinterpret_cast<PFNGLINVALIDATESUBFRAMEBUFFERPROC>(this->loadOpenGLProc("glInvalidateSubFramebuffer"));
		glInvalidateNamedFramebufferSubData = reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC>(this->loadOpenGLProc("glInvalidateNamedFramebufferSubData"));
		glInvalidateFramebuffer = reinterpret_cast<PFNGLINVALIDATEFRAMEBUFFERPROC>(this->loadOpenGLProc("glInvalidateFramebuffer"));
		glInvalidateNamedFramebufferData = reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC>(this->loadOpenGLProc("glInvalidateNamedFramebufferData"));
	}

	void OpenGLExtension::loadReadingAndCopyingPixelsExtensions()
	{
		glReadBuffer = reinterpret_cast<PFNGLREADBUFFERPROC>(this->loadOpenGLProc("glReadBuffer"));
		glNamedFramebufferReadBuffer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>(this->loadOpenGLProc("glNamedFramebufferReadBuffer"));
		glReadPixels = reinterpret_cast<PFNGLREADPIXELSPROC>(this->loadOpenGLProc("glReadPixels"));
		glReadnPixels = reinterpret_cast<PFNGLREADNPIXELSPROC>(this->loadOpenGLProc("glReadnPixels"));
		glClampColor = reinterpret_cast<PFNGLCLAMPCOLORPROC>(this->loadOpenGLProc("glClampColor"));
		glBlitFramebuffer = reinterpret_cast<PFNGLBLITFRAMEBUFFERPROC>(this->loadOpenGLProc("glBlitFramebuffer"));
		glBlitNamedFramebuffer = reinterpret_cast<PFNGLBLITNAMEDFRAMEBUFFERPROC>(this->loadOpenGLProc("glBlitNamedFramebuffer"));
		glCopyImageSubData = reinterpret_cast<PFNGLCOPYIMAGESUBDATAPROC>(this->loadOpenGLProc("glCopyImageSubData"));
	}

	void OpenGLExtension::loadDebugOutputExtensions()
	{
		glDebugMessageCallback = reinterpret_cast<PFNGLDEBUGMESSAGECALLBACKPROC>(this->loadOpenGLProc("glDebugMessageCallback"));
		glDebugMessageControl = reinterpret_cast<PFNGLDEBUGMESSAGECONTROLPROC>(this->loadOpenGLProc("glDebugMessageControl"));
		glDebugMessageInsert = reinterpret_cast<PFNGLDEBUGMESSAGEINSERTPROC>(this->loadOpenGLProc("glDebugMessageInsert"));
		glPushDebugGroup = reinterpret_cast<PFNGLPUSHDEBUGGROUPPROC>(this->loadOpenGLProc("glPushDebugGroup"));
		glPopDebugGroup = reinterpret_cast<PFNGLPOPDEBUGGROUPPROC>(this->loadOpenGLProc("glPopDebugGroup"));
		glObjectLabel = reinterpret_cast<PFNGLOBJECTLABELPROC>(this->loadOpenGLProc("glObjectLabel"));
		glObjectPtrLabel = reinterpret_cast<PFNGLOBJECTPTRLABELPROC>(this->loadOpenGLProc("glObjectPtrLabel"));
		glGetDebugMessageLog = reinterpret_cast<PFNGLGETDEBUGMESSAGELOGPROC>(this->loadOpenGLProc("glGetDebugMessageLog"));
		glGetObjectLabel = reinterpret_cast<PFNGLGETOBJECTLABELPROC>(this->loadOpenGLProc("glGetObjectLabel"));
		glGetObjectPtrLabel = reinterpret_cast<PFNGLGETOBJECTPTRLABELPROC>(this->loadOpenGLProc("glGetObjectPtrLabel"));
	}

	void OpenGLExtension::loadStateAndStateRequestsExtensions()
	{
		glGetBooleanv = reinterpret_cast<PFNGLGETBOOLEANVPROC>(this->loadOpenGLProc("glGetBooleanv"));
		glGetIntegerv = reinterpret_cast<PFNGLGETINTEGERVPROC>(this->loadOpenGLProc("glGetIntegerv"));
		glGetInteger64v = reinterpret_cast<PFNGLGETINTEGER64VPROC>(this->loadOpenGLProc("glGetInteger64v"));
		glGetFloatv = reinterpret_cast<PFNGLGETFLOATVPROC>(this->loadOpenGLProc("glGetFloatv"));
		glGetDoublev = reinterpret_cast<PFNGLGETDOUBLEVPROC>(this->loadOpenGLProc("glGetDoublev"));
		glGetDoublei_v = reinterpret_cast<PFNGLGETDOUBLEI_VPROC>(this->loadOpenGLProc("glGetDoublei_v"));
		glGetBooleani_v = reinterpret_cast<PFNGLGETBOOLEANI_VPROC>(this->loadOpenGLProc("glGetBooleani_v"));
		glGetIntegeri_v = reinterpret_cast<PFNGLGETINTEGERI_VPROC>(this->loadOpenGLProc("glGetIntegeri_v"));
		glGetFloati_v = reinterpret_cast<PFNGLGETFLOATI_VPROC>(this->loadOpenGLProc("glGetFloati_v"));
		glGetInteger64i_v = reinterpret_cast<PFNGLGETINTEGER64I_VPROC>(this->loadOpenGLProc("glGetInteger64i_v"));
		glGetPointerv = reinterpret_cast<PFNGLGETPOINTERVPROC>(this->loadOpenGLProc("glGetPointerv"));
		glGetString = reinterpret_cast<PFNGLGETSTRINGPROC>(this->loadOpenGLProc("glGetString"));
		glGetStringi = reinterpret_cast<PFNGLGETSTRINGIPROC>(this->loadOpenGLProc("glGetStringi"));
		glGetInternalformativ = reinterpret_cast<PFNGLGETINTERNALFORMATIVPROC>(this->loadOpenGLProc("glGetInternalformativ"));
		glGetInternalformati64v = reinterpret_cast<PFNGLGETINTERNALFORMATI64VPROC>(this->loadOpenGLProc("glGetInternalformati64v"));
		glGetTransformFeedbackiv = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKIVPROC>(this->loadOpenGLProc("glGetTransformFeedbackiv"));
		glGetTransformFeedbacki_v = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI_VPROC>(this->loadOpenGLProc("glGetTransformFeedbacki_v"));
		glGetTransformFeedbacki64_v = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI64_VPROC>(this->loadOpenGLProc("glGetTransformFeedbacki64_v"));
	}
}


// Command Execution
//PFNGLGETERRORPROC glGetError = nullptr;
PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus = nullptr;
PFNGLFLUSHPROC glFlush = nullptr;
PFNGLFINISHPROC glFinish = nullptr;

// Timer Queries
PFNGLQUERYCOUNTERPROC glQueryCounter = nullptr;

// Synchronization
PFNGLDELETESYNCPROC glDeleteSync = nullptr;
PFNGLFENCESYNCPROC glFenceSync = nullptr;
PFNGLCLIENTWAITSYNCPROC glClientWaitSync = nullptr;
PFNGLWAITSYNCPROC glWaitSync = nullptr;
PFNGLGETSYNCIVPROC glGetSynciv = nullptr;
PFNGLISSYNCPROC glIsSync = nullptr;

// Asynchronous Queries
PFNGLGENQUERIESPROC glGenQueries = nullptr;
PFNGLCREATEQUERIESPROC glCreateQueries = nullptr;
PFNGLDELETEQUERIESPROC glDeleteQueries = nullptr;
PFNGLBEGINQUERYPROC glBeginQuery = nullptr;
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed = nullptr;
PFNGLENDQUERYPROC glEndQuery = nullptr;
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed = nullptr;
PFNGLISQUERYPROC glIsQuery = nullptr;
PFNGLGETQUERYIVPROC glGetQueryiv = nullptr;
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv = nullptr;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = nullptr;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = nullptr;
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v = nullptr;
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v = nullptr;

// Buffer Objects
PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
PFNGLCREATEBUFFERSPROC glCreateBuffers = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange = nullptr;
PFNGLBINDBUFFERBASEPROC glBindBufferBase = nullptr;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = nullptr;
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = nullptr;
PFNGLBUFFERSTORAGEPROC glBufferStorage = nullptr;
PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage = nullptr;
PFNGLBUFFERDATAPROC glBufferData = nullptr;
PFNGLNAMEDBUFFERDATAPROC glNamedBufferData = nullptr;
PFNGLBUFFERSUBDATAPROC glBufferSubData = nullptr;
PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData = nullptr;
PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData = nullptr;
PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData = nullptr;
PFNGLCLEARBUFFERDATAPROC glClearBufferData = nullptr;
PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData = nullptr;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange = nullptr;
PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange = nullptr;
PFNGLMAPBUFFERPROC glMapBuffer = nullptr;
PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer = nullptr;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = nullptr;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glFlushMappedNamedBufferRange = nullptr;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = nullptr;
PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer = nullptr;
PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData = nullptr;
PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData = nullptr;
PFNGLISBUFFERPROC glIsBuffer = nullptr;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = nullptr;
PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData = nullptr;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v = nullptr;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = nullptr;
PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv = nullptr;
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = nullptr;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData = nullptr;

// Shaders and Programs
PFNGLCREATESHADERPROC glCreateShader = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler = nullptr;
PFNGLDELETESHADERPROC glDeleteShader = nullptr;
PFNGLISSHADERPROC glIsShader = nullptr;
PFNGLSHADERBINARYPROC glShaderBinary = nullptr;
PFNGLSPECIALIZESHADERPROC glSpecializeShader = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
PFNGLATTACHSHADERPROC glAttachShader = nullptr;
PFNGLDETACHSHADERPROC glDetachShader = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv = nullptr;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
PFNGLISPROGRAMPROC glIsProgram = nullptr;
PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv = nullptr;
PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex = nullptr;
PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName = nullptr;
PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex = nullptr;
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines = nullptr;
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines = nullptr;
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline = nullptr;
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline = nullptr;
PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines = nullptr;
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages = nullptr;
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram = nullptr;
PFNGLGETPROGRAMBINARYPROC glGetProgramBinary = nullptr;
PFNGLPROGRAMBINARYPROC glProgramBinary = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = nullptr;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = nullptr;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = nullptr;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = nullptr;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = nullptr;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = nullptr;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv = nullptr;
PFNGLUNIFORM1IPROC glUniform1i = nullptr;
PFNGLUNIFORM1IVPROC glUniform1iv = nullptr;
PFNGLUNIFORM1FPROC glUniform1f = nullptr;
PFNGLUNIFORM1FVPROC glUniform1fv = nullptr;
PFNGLUNIFORM1DPROC glUniform1d = nullptr;
PFNGLUNIFORM1DVPROC glUniform1dv = nullptr;
PFNGLUNIFORM1UIPROC glUniform1ui = nullptr;
PFNGLUNIFORM1UIVPROC glUniform1uiv = nullptr;
PFNGLUNIFORM2IPROC glUniform2i = nullptr;
PFNGLUNIFORM2IVPROC glUniform2iv = nullptr;
PFNGLUNIFORM2FPROC glUniform2f = nullptr;
PFNGLUNIFORM2FVPROC glUniform2fv = nullptr;
PFNGLUNIFORM2DPROC glUniform2d = nullptr;
PFNGLUNIFORM2DVPROC glUniform2dv = nullptr;
PFNGLUNIFORM2UIPROC glUniform2ui = nullptr;
PFNGLUNIFORM2UIVPROC glUniform2uiv = nullptr;
PFNGLUNIFORM3IPROC glUniform3i = nullptr;
PFNGLUNIFORM3IVPROC glUniform3iv = nullptr;
PFNGLUNIFORM3FPROC glUniform3f = nullptr;
PFNGLUNIFORM3FVPROC glUniform3fv = nullptr;
PFNGLUNIFORM3DPROC glUniform3d = nullptr;
PFNGLUNIFORM3DVPROC glUniform3dv = nullptr;
PFNGLUNIFORM3UIPROC glUniform3ui = nullptr;
PFNGLUNIFORM3UIVPROC glUniform3uiv = nullptr;
PFNGLUNIFORM4IPROC glUniform4i = nullptr;
PFNGLUNIFORM4IVPROC glUniform4iv = nullptr;
PFNGLUNIFORM4FPROC glUniform4f = nullptr;
PFNGLUNIFORM4FVPROC glUniform4fv = nullptr;
PFNGLUNIFORM4DPROC glUniform4d = nullptr;
PFNGLUNIFORM4DVPROC glUniform4dv = nullptr;
PFNGLUNIFORM4UIPROC glUniform4ui = nullptr;
PFNGLUNIFORM4UIVPROC glUniform4uiv = nullptr;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = nullptr;
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv = nullptr;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = nullptr;
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = nullptr;
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv = nullptr;
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv = nullptr;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv = nullptr;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv = nullptr;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv = nullptr;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv = nullptr;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv = nullptr;
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i = nullptr;
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f = nullptr;
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d = nullptr;
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i = nullptr;
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f = nullptr;
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d = nullptr;
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i = nullptr;
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f = nullptr;
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d = nullptr;
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i = nullptr;
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f = nullptr;
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d = nullptr;
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv = nullptr;
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv = nullptr;
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv = nullptr;
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv = nullptr;
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv = nullptr;
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv = nullptr;
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv = nullptr;
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv = nullptr;
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv = nullptr;
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv = nullptr;
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv = nullptr;
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv = nullptr;
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv = nullptr;
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv = nullptr;
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv = nullptr;
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv = nullptr;
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui = nullptr;
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui = nullptr;
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui = nullptr;
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv = nullptr;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = nullptr;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding = nullptr;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation = nullptr;
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex = nullptr;
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName = nullptr;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName = nullptr;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv = nullptr;
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv = nullptr;
PFNGLMEMORYBARRIERPROC glMemoryBarrier = nullptr;
PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv = nullptr;
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv = nullptr;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = nullptr;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog = nullptr;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = nullptr;
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat = nullptr;
PFNGLGETUNIFORMFVPROC glGetUniformfv = nullptr;
PFNGLGETUNIFORMDVPROC glGetUniformdv = nullptr;
PFNGLGETUNIFORMIVPROC glGetUniformiv = nullptr;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv = nullptr;
PFNGLGETNUNIFORMFVPROC glGetnUniformfv = nullptr;
PFNGLGETNUNIFORMDVPROC glGetnUniformdv = nullptr;
PFNGLGETNUNIFORMIVPROC glGetnUniformiv = nullptr;
PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv = nullptr;
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv = nullptr;
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv = nullptr;

// Textures and Samplers
PFNGLACTIVETEXTUREPROC glActiveTexture = nullptr;
PFNGLGENTEXTURESPROC glGenTextures = nullptr;
PFNGLBINDTEXTUREPROC glBindTexture = nullptr;
PFNGLBINDTEXTURESPROC glBindTextures = nullptr;
PFNGLBINDTEXTUREUNITPROC glBindTextureUnit = nullptr;
PFNGLCREATETEXTURESPROC glCreateTextures = nullptr;
PFNGLDELETETEXTURESPROC glDeleteTextures = nullptr;
PFNGLISTEXTUREPROC glIsTexture = nullptr;
PFNGLGENSAMPLERSPROC glGenSamplers = nullptr;
PFNGLCREATESAMPLERSPROC glCreateSamplers = nullptr;
PFNGLBINDSAMPLERPROC glBindSampler = nullptr;
PFNGLBINDSAMPLERSPROC glBindSamplers = nullptr;
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri = nullptr;
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf = nullptr;
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv = nullptr;
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv = nullptr;
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv = nullptr;
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv = nullptr;
PFNGLDELETESAMPLERSPROC glDeleteSamplers = nullptr;
PFNGLISSAMPLERPROC glIsSampler = nullptr;
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv = nullptr;
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv = nullptr;
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv = nullptr;
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv = nullptr;
PFNGLPIXELSTOREIPROC glPixelStorei = nullptr;
PFNGLPIXELSTOREFPROC glPixelStoref = nullptr;
PFNGLTEXIMAGE3DPROC glTexImage3D = nullptr;
PFNGLTEXIMAGE2DPROC glTexImage2D = nullptr;
PFNGLTEXIMAGE1DPROC glTexImage1D = nullptr;
PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D = nullptr;
PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D = nullptr;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = nullptr;
PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D = nullptr;
PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D = nullptr;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;
PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = nullptr;
PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = nullptr;
PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D = nullptr;
PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D = nullptr;
PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D = nullptr;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = nullptr;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = nullptr;
PFNGLTEXBUFFERRANGEPROC glTexBufferRange = nullptr;
PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange = nullptr;
PFNGLTEXBUFFERPROC glTexBuffer = nullptr;
PFNGLTEXTUREBUFFERPROC glTextureBuffer = nullptr;
PFNGLTEXPARAMETERIPROC glTexParameteri = nullptr;
PFNGLTEXPARAMETERFPROC glTexParameterf = nullptr;
PFNGLTEXPARAMETERIVPROC glTexParameteriv = nullptr;
PFNGLTEXPARAMETERFVPROC glTexParameterfv = nullptr;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = nullptr;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = nullptr;
PFNGLTEXTUREPARAMETERIPROC glTextureParameteri = nullptr;
PFNGLTEXTUREPARAMETERFPROC glTextureParameterf = nullptr;
PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv = nullptr;
PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv = nullptr;
PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv = nullptr;
PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv = nullptr;
PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv = nullptr;
PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv = nullptr;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = nullptr;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = nullptr;
PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv = nullptr;
PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv = nullptr;
PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv = nullptr;
PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv = nullptr;
PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv = nullptr;
PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv = nullptr;
PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv = nullptr;
PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv = nullptr;
PFNGLGETTEXIMAGEPROC glGetTexImage = nullptr;
PFNGLGETTEXTUREIMAGEPROC glGetTextureImage = nullptr;
PFNGLGETNTEXIMAGEPROC glGetnTexImage = nullptr;
PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage = nullptr;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = nullptr;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage = nullptr;
PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage = nullptr;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage = nullptr;
PFNGLENABLEPROC glEnable = nullptr;
PFNGLDISABLEPROC glDisable = nullptr;
PFNGLISENABLEDPROC glIsEnabled = nullptr;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = nullptr;
PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap = nullptr;
PFNGLTEXTUREVIEWPROC glTextureView = nullptr;
PFNGLTEXSTORAGE1DPROC glTexStorage1D = nullptr;
PFNGLTEXSTORAGE2DPROC glTexStorage2D = nullptr;
PFNGLTEXSTORAGE3DPROC glTexStorage3D = nullptr;
PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D = nullptr;
PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D = nullptr;
PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D = nullptr;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample = nullptr;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample = nullptr;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample = nullptr;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample = nullptr;
PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage = nullptr;
PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage = nullptr;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = nullptr;
PFNGLCLEARTEXIMAGEPROC glClearTexImage = nullptr;
PFNGLBINDIMAGETEXTUREPROC glBindImageTexture = nullptr;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;

// Framebuffer objects
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = nullptr;
PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers = nullptr;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = nullptr;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = nullptr;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer = nullptr;
PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri = nullptr;
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri = nullptr;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv = nullptr;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv = nullptr;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = nullptr;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv = nullptr;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = nullptr;
PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers = nullptr;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = nullptr;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = nullptr;
PFNGLISRENDERBUFFERPROC glIsRenderbuffer = nullptr;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample = nullptr;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage = nullptr;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = nullptr;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv = nullptr;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer = nullptr;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture = nullptr;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = nullptr;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = nullptr;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = nullptr;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer = nullptr;
PFNGLTEXTUREBARRIERPROC glTextureBarrier = nullptr;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = nullptr;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus = nullptr;

// Vertices
PFNGLPATCHPARAMETERIPROC glPatchParameteri = nullptr;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = nullptr;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = nullptr;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = nullptr;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = nullptr;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = nullptr;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = nullptr;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = nullptr;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = nullptr;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = nullptr;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = nullptr;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = nullptr;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = nullptr;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = nullptr;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = nullptr;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = nullptr;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = nullptr;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = nullptr;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = nullptr;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = nullptr;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = nullptr;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = nullptr;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = nullptr;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = nullptr;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = nullptr;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = nullptr;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = nullptr;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = nullptr;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = nullptr;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = nullptr;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = nullptr;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = nullptr;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = nullptr;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = nullptr;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = nullptr;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = nullptr;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i = nullptr;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui = nullptr;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i = nullptr;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui = nullptr;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i = nullptr;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui = nullptr;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i = nullptr;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui = nullptr;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv = nullptr;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv = nullptr;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv = nullptr;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv = nullptr;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv = nullptr;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv = nullptr;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv = nullptr;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv = nullptr;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv = nullptr;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv = nullptr;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv = nullptr;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv = nullptr;
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d = nullptr;
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d = nullptr;
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d = nullptr;
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d = nullptr;
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv = nullptr;
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv = nullptr;
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv = nullptr;
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv = nullptr;
PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui = nullptr;
PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui = nullptr;
PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui = nullptr;
PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui = nullptr;
PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv = nullptr;
PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv = nullptr;
PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv = nullptr;
PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv = nullptr;

// Vertex Arrays
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays = nullptr;
PFNGLISVERTEXARRAYPROC glIsVertexArray = nullptr;
PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer = nullptr;
PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat = nullptr;
PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat = nullptr;
PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat = nullptr;
PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat = nullptr;
PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat = nullptr;
PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat = nullptr;
PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer = nullptr;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers = nullptr;
PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding = nullptr;
PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = nullptr;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib = nullptr;
PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor = nullptr;
PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor = nullptr;
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = nullptr;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = nullptr;
PFNGLDRAWARRAYSPROC glDrawArrays = nullptr;
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance = nullptr;
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = nullptr;
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect = nullptr;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount = nullptr;
PFNGLDRAWELEMENTSPROC glDrawElements = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance = nullptr;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = nullptr;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = nullptr;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = nullptr;
PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv = nullptr;
PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv = nullptr;
PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv = nullptr;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = nullptr;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = nullptr;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = nullptr;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = nullptr;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = nullptr;
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv = nullptr;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = nullptr;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = nullptr;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = nullptr;

// Vertex Attributes
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = nullptr;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = nullptr;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = nullptr;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = nullptr;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying = nullptr;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = nullptr;
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline = nullptr;
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv = nullptr;

// Vertex Post-Processing
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks = nullptr;
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks = nullptr;
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback = nullptr;
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback = nullptr;
PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks = nullptr;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = nullptr;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = nullptr;
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback = nullptr;
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback = nullptr;
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange = nullptr;
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced = nullptr;
PFNGLPROVOKINGVERTEXPROC glProvokingVertex = nullptr;
PFNGLCLIPCONTROLPROC glClipControl = nullptr;
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv = nullptr;
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed = nullptr;
PFNGLDEPTHRANGEPROC glDepthRange = nullptr;
PFNGLDEPTHRANGEFPROC glDepthRangef = nullptr;
PFNGLVIEWPORTARRAYVPROC glViewportArrayv = nullptr;
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf = nullptr;
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv = nullptr;
PFNGLVIEWPORTPROC glViewport = nullptr;

// Rasterization
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = nullptr;
PFNGLMINSAMPLESHADINGPROC glMinSampleShading = nullptr;
PFNGLPOINTSIZEPROC glPointSize = nullptr;
PFNGLPOINTPARAMETERIPROC glPointParameteri = nullptr;
PFNGLPOINTPARAMETERFPROC glPointParameterf = nullptr;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = nullptr;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = nullptr;
PFNGLLINEWIDTHPROC glLineWidth = nullptr;
PFNGLFRONTFACEPROC glFrontFace = nullptr;
PFNGLCULLFACEPROC glCullFace = nullptr;
PFNGLPOLYGONMODEPROC glPolygonMode = nullptr;
PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp = nullptr;
PFNGLPOLYGONOFFSETPROC glPolygonOffset = nullptr;

// Fragment Shaders
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = nullptr;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = nullptr;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = nullptr;
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex = nullptr;

// Compute Shaders
PFNGLDISPATCHCOMPUTEPROC glDispatchCompute = nullptr;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect = nullptr;

// Per-Fragment Operations
PFNGLENABLEIPROC glEnablei = nullptr;
PFNGLDISABLEIPROC glDisablei = nullptr;
PFNGLISENABLEDIPROC glIsEnabledi = nullptr;
PFNGLSCISSORARRAYVPROC glScissorArrayv = nullptr;
PFNGLSCISSORINDEXEDPROC glScissorIndexed = nullptr;
PFNGLSCISSORINDEXEDVPROC glScissorIndexedv = nullptr;
PFNGLSCISSORPROC glScissor = nullptr;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = nullptr;
PFNGLSAMPLEMASKIPROC glSampleMaski = nullptr;
PFNGLSTENCILFUNCPROC glStencilFunc = nullptr;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = nullptr;
PFNGLSTENCILOPPROC glStencilOp = nullptr;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = nullptr;
PFNGLDEPTHFUNCPROC glDepthFunc = nullptr;
PFNGLBLENDEQUATIONPROC glBlendEquation = nullptr;
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = nullptr;
PFNGLBLENDEQUATIONIPROC glBlendEquationi = nullptr;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = nullptr;
PFNGLBLENDFUNCPROC glBlendFunc = nullptr;
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
PFNGLBLENDFUNCIPROC glBlendFunci = nullptr;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = nullptr;
PFNGLBLENDCOLORPROC glBlendColor = nullptr;
PFNGLLOGICOPPROC glLogicOp = nullptr;

// Hints
PFNGLHINTPROC glHint = nullptr;

// Whole Framebuffer
PFNGLDRAWBUFFERPROC glDrawBuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer = nullptr;
PFNGLDRAWBUFFERSPROC glDrawBuffers = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers = nullptr;
PFNGLCOLORMASKPROC glColorMask = nullptr;
PFNGLCOLORMASKIPROC glColorMaski = nullptr;
PFNGLDEPTHMASKPROC glDepthMask = nullptr;
PFNGLSTENCILMASKPROC glStencilMask = nullptr;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = nullptr;
PFNGLCLEARPROC glClear = nullptr;
PFNGLCLEARCOLORPROC glClearColor = nullptr;
PFNGLCLEARDEPTHPROC glClearDepth = nullptr;
PFNGLCLEARDEPTHFPROC glClearDepthf = nullptr;
PFNGLCLEARSTENCILPROC glClearStencil = nullptr;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = nullptr;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = nullptr;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv = nullptr;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi = nullptr;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer = nullptr;
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData = nullptr;
PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer = nullptr;
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData = nullptr;

// Reading and Copying Pixels
PFNGLREADBUFFERPROC glReadBuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer = nullptr;
PFNGLREADPIXELSPROC glReadPixels = nullptr;
PFNGLREADNPIXELSPROC glReadnPixels = nullptr;
PFNGLCLAMPCOLORPROC glClampColor = nullptr;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = nullptr;
PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer = nullptr;
PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData = nullptr;

// Debug Output
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback = nullptr;
PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl = nullptr;
PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert = nullptr;
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup = nullptr;
PFNGLPOPDEBUGGROUPPROC glPopDebugGroup = nullptr;
PFNGLOBJECTLABELPROC glObjectLabel = nullptr;
PFNGLOBJECTPTRLABELPROC glObjectPtrLabel = nullptr;
PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog = nullptr;
PFNGLGETOBJECTLABELPROC glGetObjectLabel = nullptr;
PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel = nullptr;

// State and State Request
PFNGLGETBOOLEANVPROC glGetBooleanv = nullptr;
PFNGLGETINTEGERVPROC glGetIntegerv = nullptr;
PFNGLGETINTEGER64VPROC glGetInteger64v = nullptr;
PFNGLGETFLOATVPROC glGetFloatv = nullptr;
PFNGLGETDOUBLEVPROC glGetDoublev = nullptr;
PFNGLGETDOUBLEI_VPROC glGetDoublei_v = nullptr;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v = nullptr;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v = nullptr;
PFNGLGETFLOATI_VPROC glGetFloati_v = nullptr;
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = nullptr;
PFNGLGETPOINTERVPROC glGetPointerv = nullptr;
PFNGLGETSTRINGPROC glGetString = nullptr;
PFNGLGETSTRINGIPROC glGetStringi = nullptr;
PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ = nullptr;
PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v = nullptr;
PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv = nullptr;
PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v = nullptr;
PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v = nullptr;