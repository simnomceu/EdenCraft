# GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug_win32
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild prelink

ifeq ($(config),debug_win32)
  RESCOMP = windres
  TARGETDIR = bin/Win32/Debug
  TARGET = $(TARGETDIR)/Renderer.lib
  OBJDIR = obj/Win32/Debug/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win32/Debug/Utility.lib bin/Win32/Debug/Core.lib bin/Win32/Debug/Window.lib bin/Win32/Debug/Graphic.lib
  LDDEPS += bin/Win32/Debug/Utility.lib bin/Win32/Debug/Core.lib bin/Win32/Debug/Window.lib bin/Win32/Debug/Graphic.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/msvc/x86 -m32 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),debug_win64)
  RESCOMP = windres
  TARGETDIR = bin/Win64/Debug
  TARGET = $(TARGETDIR)/Renderer.lib
  OBJDIR = obj/Win64/Debug/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win64/Debug/Utility.lib bin/Win64/Debug/Core.lib bin/Win64/Debug/Window.lib bin/Win64/Debug/Graphic.lib
  LDDEPS += bin/Win64/Debug/Utility.lib bin/Win64/Debug/Core.lib bin/Win64/Debug/Window.lib bin/Win64/Debug/Graphic.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/msvc/x64 -m64 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),debug_unix32)
  RESCOMP = windres
  TARGETDIR = bin/Unix32/Debug
  TARGET = $(TARGETDIR)/libRenderer.a
  OBJDIR = obj/Unix32/Debug/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix32/Debug/libUtility.a bin/Unix32/Debug/libCore.a bin/Unix32/Debug/libWindow.a bin/Unix32/Debug/libGraphic.a
  LDDEPS += bin/Unix32/Debug/libUtility.a bin/Unix32/Debug/libCore.a bin/Unix32/Debug/libWindow.a bin/Unix32/Debug/libGraphic.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/gmake/x32 -m32 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),debug_unix64)
  RESCOMP = windres
  TARGETDIR = bin/Unix64/Debug
  TARGET = $(TARGETDIR)/libRenderer.a
  OBJDIR = obj/Unix64/Debug/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix64/Debug/libUtility.a bin/Unix64/Debug/libCore.a bin/Unix64/Debug/libWindow.a bin/Unix64/Debug/libGraphic.a
  LDDEPS += bin/Unix64/Debug/libUtility.a bin/Unix64/Debug/libCore.a bin/Unix64/Debug/libWindow.a bin/Unix64/Debug/libGraphic.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/gmake/x64 -m64 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),debug_osx)
  ifeq ($(origin CC), default)
    CC = clang
  endif
  ifeq ($(origin CXX), default)
    CXX = clang++
  endif
  ifeq ($(origin AR), default)
    AR = ar
  endif
  TARGETDIR = bin/OSX/Debug
  TARGET = $(TARGETDIR)/libRenderer.a
  OBJDIR = obj/OSX/Debug/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/OSX/Debug/libUtility.a bin/OSX/Debug/libCore.a bin/OSX/Debug/libWindow.a bin/OSX/Debug/libGraphic.a
  LDDEPS += bin/OSX/Debug/libUtility.a bin/OSX/Debug/libCore.a bin/OSX/Debug/libWindow.a bin/OSX/Debug/libGraphic.a
  ALL_LDFLAGS += $(LDFLAGS) -L../extlibs/lib/gmake/x64 -m64
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release_win32)
  RESCOMP = windres
  TARGETDIR = bin/Win32/Release
  TARGET = $(TARGETDIR)/Renderer.lib
  OBJDIR = obj/Win32/Release/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win32/Release/Utility.lib bin/Win32/Release/Core.lib bin/Win32/Release/Window.lib bin/Win32/Release/Graphic.lib
  LDDEPS += bin/Win32/Release/Utility.lib bin/Win32/Release/Core.lib bin/Win32/Release/Window.lib bin/Win32/Release/Graphic.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/msvc/x86 -m32 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release_win64)
  RESCOMP = windres
  TARGETDIR = bin/Win64/Release
  TARGET = $(TARGETDIR)/Renderer.lib
  OBJDIR = obj/Win64/Release/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win64/Release/Utility.lib bin/Win64/Release/Core.lib bin/Win64/Release/Window.lib bin/Win64/Release/Graphic.lib
  LDDEPS += bin/Win64/Release/Utility.lib bin/Win64/Release/Core.lib bin/Win64/Release/Window.lib bin/Win64/Release/Graphic.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/msvc/x64 -m64 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release_unix32)
  RESCOMP = windres
  TARGETDIR = bin/Unix32/Release
  TARGET = $(TARGETDIR)/libRenderer.a
  OBJDIR = obj/Unix32/Release/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix32/Release/libUtility.a bin/Unix32/Release/libCore.a bin/Unix32/Release/libWindow.a bin/Unix32/Release/libGraphic.a
  LDDEPS += bin/Unix32/Release/libUtility.a bin/Unix32/Release/libCore.a bin/Unix32/Release/libWindow.a bin/Unix32/Release/libGraphic.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/gmake/x32 -m32 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release_unix64)
  RESCOMP = windres
  TARGETDIR = bin/Unix64/Release
  TARGET = $(TARGETDIR)/libRenderer.a
  OBJDIR = obj/Unix64/Release/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix64/Release/libUtility.a bin/Unix64/Release/libCore.a bin/Unix64/Release/libWindow.a bin/Unix64/Release/libGraphic.a
  LDDEPS += bin/Unix64/Release/libUtility.a bin/Unix64/Release/libCore.a bin/Unix64/Release/libWindow.a bin/Unix64/Release/libGraphic.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/gmake/x64 -m64 -s
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release_osx)
  ifeq ($(origin CC), default)
    CC = clang
  endif
  ifeq ($(origin CXX), default)
    CXX = clang++
  endif
  ifeq ($(origin AR), default)
    AR = ar
  endif
  TARGETDIR = bin/OSX/Release
  TARGET = $(TARGETDIR)/libRenderer.a
  OBJDIR = obj/OSX/Release/Renderer
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../include/window -I../include/graphic -I../include/renderer
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/OSX/Release/libUtility.a bin/OSX/Release/libCore.a bin/OSX/Release/libWindow.a bin/OSX/Release/libGraphic.a
  LDDEPS += bin/OSX/Release/libUtility.a bin/OSX/Release/libCore.a bin/OSX/Release/libWindow.a bin/OSX/Release/libGraphic.a
  ALL_LDFLAGS += $(LDFLAGS) -L../extlibs/lib/gmake/x64 -m64
  LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

OBJECTS := \
	$(OBJDIR)/basic_renderer.o \
	$(OBJDIR)/open_gl_util.o \
	$(OBJDIR)/program.o \
	$(OBJDIR)/render_queue.o \
	$(OBJDIR)/render_window.o \
	$(OBJDIR)/renderer_gl.o \
	$(OBJDIR)/shader_gl.o \

RESOURCES := \

CUSTOMFILES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

$(TARGET): $(GCH) ${CUSTOMFILES} $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking Renderer
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning Renderer
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) $(PCH)
$(GCH): $(PCH)
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
endif

$(OBJDIR)/basic_renderer.o: ../src/renderer/basic_renderer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/open_gl_util.o: ../src/renderer/opengl/open_gl_util.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/program.o: ../src/renderer/program.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/render_queue.o: ../src/renderer/render_queue.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/render_window.o: ../src/renderer/render_window.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/renderer_gl.o: ../src/renderer/renderer_gl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/shader_gl.o: ../src/renderer/shader_gl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(OBJDIR)/$(notdir $(PCH)).d
endif