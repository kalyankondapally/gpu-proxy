#include "basic_test.h"
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

static void
test_basic_egl (void)
{
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetError"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetDisplay"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglInitialize"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglTerminate"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglQueryString"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetConfigs"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglChooseConfig"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetConfigAttrib"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreateWindowSurface"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreatePbufferSurface"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreatePixmapSurface"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglDestroySurface"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglQuerySurface"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglBindAPI"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglQueryAPI"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglWaitClient"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglReleaseThread"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreatePbufferFromClientBuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglSurfaceAttrib"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglBindTexImage"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglReleaseTexImage"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglSwapInterval"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreateContext"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglDestroyContext"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglMakeCurrent"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetCurrentContext"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetCurrentSurface"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetCurrentDisplay"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglQueryContext"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglWaitGL"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglWaitNative"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglSwapBuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCopyBuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetProcAddress"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglLockSurfaceKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglUnlockSurfaceKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreateImageKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglDestroyImageKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreateSyncKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglDestroySyncKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglClientWaitSyncKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglSignalSyncKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetSyncAttribKHR"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreateFenceSyncNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglDestroySyncNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglFenceNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglClientWaitSyncNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglSignalSyncNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetSyncAttribNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreatePixmapSurfaceHI"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglCreateDRMImageMESA"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglExportDRMImageMESA"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglPostSubBufferNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglQuerySurfacePointerANGLE"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglMapImageSEC"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglUnmapImageSEC"));
    GPUPROCESS_ASSERT (dlsym (NULL, "eglGetImageAttribSEC"));
}

static void
test_basic_gles (void)
{
    GPUPROCESS_ASSERT (dlsym (NULL, "glActiveTexture"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glAttachShader"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBindAttribLocation"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBindBuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBindFramebuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBindRenderbuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBindTexture"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBlendColor"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBlendEquation"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBlendEquationSeparate"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBlendFunc"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBlendFuncSeparate"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBufferData"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glBufferSubData"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCheckFramebufferStatus"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glClear"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glClearColor"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glClearDepthf"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glClearStencil"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glColorMask"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCompileShader"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCompressedTexImage2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCompressedTexSubImage2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCopyTexImage2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCopyTexSubImage2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCreateProgram"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCreateShader"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glCullFace"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDeleteBuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDeleteFramebuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDeleteProgram"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDeleteRenderbuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDeleteShader"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDeleteTextures"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDepthFunc"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDepthMask"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDepthRangef"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDetachShader"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDisable"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDisableVertexAttribArray"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDrawArrays"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glDrawElements"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glEnable"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glEnableVertexAttribArray"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glFinish"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glFlush"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glFramebufferRenderbuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glFramebufferTexture2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glFrontFace"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGenBuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGenerateMipmap"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGenFramebuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGenRenderbuffers"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGenTextures"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetActiveAttrib"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetActiveUniform"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetAttachedShaders"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetAttribLocation"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetBooleanv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetBufferParameteriv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetError"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetFloatv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetFramebufferAttachmentParameteriv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetIntegerv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetProgramiv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetProgramInfoLog"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetRenderbufferParameteriv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetShaderiv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetShaderInfoLog"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetShaderPrecisionFormat"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetShaderSource"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetString"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetTexParameterfv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetTexParameteriv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetUniformfv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetUniformiv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetUniformLocation"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetVertexAttribfv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetVertexAttribiv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glGetVertexAttribPointerv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glHint"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsBuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsEnabled"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsFramebuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsProgram"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsRenderbuffer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsShader"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glIsTexture"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glLineWidth"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glLinkProgram"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glPixelStorei"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glPolygonOffset"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glReadPixels"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glReleaseShaderCompiler"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glRenderbufferStorage"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glSampleCoverage"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glScissor"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glShaderBinary"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glShaderSource"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glStencilFunc"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glStencilFuncSeparate"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glStencilMask"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glStencilMaskSeparate"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glStencilOp"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glStencilOpSeparate"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glTexImage2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glTexParameteri"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glTexParameteriv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glTexParameterf"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glTexParameterfv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glTexSubImage2D"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform1f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform1fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform1i"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform1iv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform2f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform2fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform2i"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform2iv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform3f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform3fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform3i"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform3iv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform4f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform4fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform4i"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniform4iv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniformMatrix2fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniformMatrix3fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUniformMatrix4fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glUseProgram"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glValidateProgram"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib1f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib1fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib2f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib2fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib3f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib3fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib4f"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttrib4fv"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glVertexAttribPointer"));
    GPUPROCESS_ASSERT (dlsym (NULL, "glViewport"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glBlitFramebufferEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glRenderbufferStorageMultisampleEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glFramebufferTexture2DMultisampleEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glTexStorage2DEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGenQueriesEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glDeleteQueriesEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glIsQueryEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glBeginQueryEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glEndQueryEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetQueryivEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetQueryObjectuivEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glInsertEventMarkerEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glPushGroupMarkerEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glEGLImageTargetTexture2DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glEGLImageTargetRenderbufferStorageOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetProgramBinaryOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glProgramBinaryOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glMapBufferOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glUnmapBufferOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetBufferPointervOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glTexImage3DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glTexSubImage3DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glCopyTexSubImage3DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glCompressedTexImage3DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glCompressedTexSubImage3DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glFramebufferTexture3DOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glBindVertexArrayOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glDeleteVertexArraysOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGenVertexArraysOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glIsVertexArrayOES"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetPerfMonitorGroupsAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetPerfMonitorCountersAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetPerfMonitorGroupStringAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetPerfMonitorCounterStringAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetPerfMonitorCounterInfoAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGenPerfMonitorsAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glDeletePerfMonitorsAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glSelectPerfMonitorCountersAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glBeginPerfMonitorAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glEndPerfMonitorAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetPerfMonitorCounterDataAMD"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glDiscardFramebufferEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glMultiDrawArraysEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glMultiDrawElementsEXT"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glRenderbufferStorageMultisampleIMG"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glFramebufferTexture2DMultisampleIMG"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glDeleteFencesNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGenFencesNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glIsFenceNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glTestFenceNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetFenceivNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glFinishFenceNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glSetFenceNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glCoverageMaskNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glCoverageOperationNV"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetDriverControlsQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glGetDriverControlStringQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glEnableDriverControlQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glDisableDriverControlQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetTexturesQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetBuffersQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetRenderbuffersQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetFramebuffersQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetTexLevelParameterivQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtTexObjectStateOverrideiQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetTexSubImageQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetBufferPointervQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetShadersQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetProgramsQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtIsProgramBinaryQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glExtGetProgramBinarySourceQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glStartTilingQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glEndTilingQCOM"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glBlitFramebufferANGLE"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glRenderbufferStorageMultisampleANGLE"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glRenderbufferStorageMultisampleAPPLE"));
    GPUPROCESS_ASSERT (dlsym (NULL, "__hidden_gpuproxy_glResolveMultisampleFramebufferAPPLE"));
}

void
add_basic_testcases (gpuprocess_suite_t *suite)
{
    gpuprocess_testcase_t *basic = gpuprocess_testcase_create ("basic");
    gpuprocess_testcase_add_test (basic, test_basic_egl);
    gpuprocess_testcase_add_test (basic, test_basic_gles);
    gpuprocess_suite_add_testcase (suite, basic);
}
