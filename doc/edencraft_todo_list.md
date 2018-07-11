# ToDo List EdenCraft Engine

## Versions system
The version system works as follows: \[dev/alpha/beta/rc/release\]-Major.Minor.Fix
The prefix tag gives the distribution stage, whereas the major version indicates the progress stage. Minor version indicates the number of modifications done on a major version, and the fix is the number of fix patches applied on the same major version.

### Dev
Dev version won't be used at all for now. Eventually, it will be used for nightly build in the future.

### Alpha
Alpha is the first stage of distribution of the software. It is a version to test functionalities without any guarantee it works. Some of the alpha releases might be public, but most of them shall be private.

### Beta
Beta is the second stage of distribution and concerns a working but incomplete software. It means that it is supposed to works, but not all the features of the release have been implemented yet. Beta versions can be public, as well as private.

### Release Candidate (aka. RC)
A release candidate is a proposal for releasing a version of the software. Then, no new features will be added to. The only possible modifications are bug fixes. The version is delivered and considered as near-stability.

### Release
Release is the final stage  of the software. A release is stable and completed. There is no new features and theoretically, no new patches in this version. It does not mean, there will be no new versions of the software. It means, that, this version is achieved.

[1 https://en.wikipedia.org/wiki/Software_release_life_cycle](https://en.wikipedia.org/wiki/Software_release_life_cycle)

## Alpha guideline
For an alpha version, all code needs to be commented obviously. However, it is not mandatory to have all unit tests. It is only supposed to compile and run.

### alpha-0.1.0 (aka. Basics update)
+ [ ] Continuous integration pipeline. (Git / GitFlow / etc...).
+ [ ] AppVeyor profile for Windows (x86 and x64).
+ [ ] Travis CI profile for Linux (x86 and x64) and MacOSX (x64).
+ [ ] Coveralls profile.
+ [ ] Scripts automation for project generation (Premake5).
+ [x] Doxygen profile.
+ [x] Licensing.
+ [x] Static & Shared library usages.
##### Utility
 + [x] Basic exception specialization.
 + [x] Enumeration used like C-like flags.
 + [ ] Reflective enumeration traits.
 + [ ] Reading and writing files and binary files.
 + [ ] Parsing BMP images.
 + [ ] Parsing OBJ and MTL Wavefront formats.
 + [ ] Parsing JSON formats.
 + [ ] Dealing with paths (relative and absolute).
 + [ ] Indexing multi-dimensional arrays.
 + [ ] Version handling.
 + [ ] Unique ID generator.
 + [ ] Localization handling.
 + [ ] Console/file logger.
 + [ ] Geometric operations.
 + [ ] Matrix and vector handling, with expression templates.
 + [ ] 3D rotation using quaternions, matrix, and Euler angles.
 + [ ] Pimpl design pattern implementation.
 + [ ] Listener/listenable design pattern.
 + [ ] Service-consumer pattern implementation.
 + [ ] Timer, and UPS/FPS counter.
 + [ ] C++11, C++14, C++17 versions compatibility.
##### Core
 + [ ] General application management.
 + [ ] Application lifecycle.
 + [ ] CLI parser.
 + [ ] Basic Entity-Component-System pattern.
 + [ ] Signal/Slot mechanism (Qt-like).
 + [ ] Pluggable module for application (extending application capabilities).
 + [ ] Basic resources manager without any strategy (like, unloading the resource proportionally to the elapsed time since the last use).
##### Window
+ [ ] Common interface to handle window.
+ [ ] Enqueuing window events.
+ [ ] Dealing with screen ratio/resolution.
+ [ ] Handling video mode.
+ [ ] Win32 implementation of window.
+ [ ] X11 implementation of window (Xlib and XCB).
+ [ ] Cocoa implementation of window.
+ [ ] Managing input devices events (Mouse, keyboard).
##### Renderer
+ [ ] Common interface for OpenGL context.
+ [ ] OpenGL extensions loader with lazy-loading.
+ [ ] OpenGL support from OpenGL 3.2 to OpenGL 4.6.
+ [ ] WGL implementation for Win32.
+ [ ] GLX implementation for X11.
+ [ ] CGL implementation (AGL ?) for OSX.
+ [ ] Basic 2D and 3D renderer.
+ [ ] Basic shaders.
+ [ ] Basic 2D and 3D textures.
+ [ ] Enhanced shaders, with hot reloading, and some other features.
+ [ ] Particle renderer.
+ [ ] MSAA with OpenGL implementation.
+ [ ] Phong ligthing model.
##### Graphic
+ [ ] Particle generator.
+ [ ] 3D scene with 3D objects.
+ [ ] Static camera.
+ [ ] 3D primitive objects (Cube, sphere, rectangle, square, triangle, circle, torus, cylinder, pyramid, tetrahedron, etc ...)

### alpha-0.2.0 (aka. Graphic update)
##### Utility
+ [ ] Fractal algorithms.
##### Core
+ [ ] Allowing strategy for the resource manager.
+ [ ] Caping memory allocated throw resource manager.
##### Window
+ [ ] Wayland implementation.
+ [ ] Mir implementation.
##### Renderer
+ [ ] Basic 2D text renderer.
+ [ ] Basic GUI renderer.
+ [ ] PBR lighting model.
+ [ ] IBL implementation.
+ [ ] Light emitter (spot, directional, point).
+ [ ] Toon shading
+ [ ] Reflection and Refraction.
+ [ ] Shader AST.
+ [ ] BatchRenderer (to merge several draw calls of 2D objects in a single one).
##### Graphic
+ [ ] Scene graph.
+ [ ] Procedural texture generation (2D and 3D, eg. terrains).
+ [ ] Skeleton for game animation.
+ [ ] Keyframes.
+ [ ] Cinematic camera (movements, travelling, etc...).
+ [ ] glTF Parser.
+ [ ] External module to use FBX SDK from Autodesk.

### alpha-0.3.0 (aka. Audio update)
##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio
+ [ ] Audio buffers.
+ [ ] OGG parser.
+ [ ] MP3 parser (if it is under public domain).
+ [ ] MIDI parser.
+ [ ] 3D sound emitter.
+ [ ] Spatialization.
+ [ ] Dealing with sound devices (input and output).
+ [ ] Playlisting.
+ [ ] Transitioning.

### alpha-0.4.0 (aka. Optimisation update)
##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio

### alpha-0.5.0 (aka. Network update)
##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio
##### Network
+ [ ] TCP implementation.
+ [ ] UDP implementation.
+ [ ] Packets serialization.
+ [ ] IRC implementation.
+ [ ] XMPP implementation.

### alpha-0.6.0 (aka. Physic update)
##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio
##### Network
##### Physic
+ [ ] Mass-spring.
+ [ ] Gravity.
+ [ ] Fluid mechanics.
+ [ ] Collisions.
+ [ ] Acceleration.

### alpha-0.7.0 (aka. Intelligent update)
##### Utility
##### Core
+ [ ] Lua binding.
+ [ ] Python binding.
##### Window
##### Renderer
##### Graphic
##### Audio
##### Network
##### Physic
##### IA
+ [ ] Single layer perceptron (Feedforward).
+ [ ] Multi layer perceptron (Feedforward).
+ [ ] Back propagation.

## Beta guideline

### beta-1.0.0
+ [ ] Unit testing everywhere.
##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio
##### Network
##### Physic
