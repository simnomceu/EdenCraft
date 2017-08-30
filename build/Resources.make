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
  TARGET = $(TARGETDIR)/Resources.exe
  OBJDIR = obj/Win32/Debug/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win32/Debug/Utility.lib bin/Win32/Debug/Core.lib
  LDDEPS += bin/Win32/Debug/Utility.lib bin/Win32/Debug/Core.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/msvc/x86 -m32 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources.exe
  OBJDIR = obj/Win64/Debug/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win64/Debug/Utility.lib bin/Win64/Debug/Core.lib
  LDDEPS += bin/Win64/Debug/Utility.lib bin/Win64/Debug/Core.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/msvc/x64 -m64 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources
  OBJDIR = obj/Unix32/Debug/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix32/Debug/libUtility.a bin/Unix32/Debug/libCore.a
  LDDEPS += bin/Unix32/Debug/libUtility.a bin/Unix32/Debug/libCore.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/gmake/x32 -m32 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources
  OBJDIR = obj/Unix64/Debug/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix64/Debug/libUtility.a bin/Unix64/Debug/libCore.a
  LDDEPS += bin/Unix64/Debug/libUtility.a bin/Unix64/Debug/libCore.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/gmake/x64 -m64 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources
  OBJDIR = obj/OSX/Debug/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/OSX/Debug/libUtility.a bin/OSX/Debug/libCore.a
  LDDEPS += bin/OSX/Debug/libUtility.a bin/OSX/Debug/libCore.a
  ALL_LDFLAGS += $(LDFLAGS) -L../extlibs/lib/gmake/x64 -m64
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources.exe
  OBJDIR = obj/Win32/Release/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win32/Release/Utility.lib bin/Win32/Release/Core.lib
  LDDEPS += bin/Win32/Release/Utility.lib bin/Win32/Release/Core.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/msvc/x86 -m32 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources.exe
  OBJDIR = obj/Win64/Release/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Win64/Release/Utility.lib bin/Win64/Release/Core.lib
  LDDEPS += bin/Win64/Release/Utility.lib bin/Win64/Release/Core.lib
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/msvc/x64 -m64 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources
  OBJDIR = obj/Unix32/Release/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m32 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix32/Release/libUtility.a bin/Unix32/Release/libCore.a
  LDDEPS += bin/Unix32/Release/libUtility.a bin/Unix32/Release/libCore.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib32 -L../extlibs/lib/gmake/x32 -m32 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources
  OBJDIR = obj/Unix64/Release/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/Unix64/Release/libUtility.a bin/Unix64/Release/libCore.a
  LDDEPS += bin/Unix64/Release/libUtility.a bin/Unix64/Release/libCore.a
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -L../extlibs/lib/gmake/x64 -m64 -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
  TARGET = $(TARGETDIR)/Resources
  OBJDIR = obj/OSX/Release/Resources
  DEFINES +=
  INCLUDES += -I../extlibs/include -I../include/utility -I../include/core -I../examples/resources
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/OSX/Release/libUtility.a bin/OSX/Release/libCore.a
  LDDEPS += bin/OSX/Release/libUtility.a bin/OSX/Release/libCore.a
  ALL_LDFLAGS += $(LDFLAGS) -L../extlibs/lib/gmake/x64 -m64
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
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
	$(OBJDIR)/main.o \

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
	@echo Linking Resources
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
	@echo Cleaning Resources
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

$(OBJDIR)/main.o: ../examples/resources/main.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(OBJDIR)/$(notdir $(PCH)).d
endif