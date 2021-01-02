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
+ [x] Scripts automation for project generation (Premake5).
+ [x] Doxygen profile.
+ [x] Licensing.
+ [x] Static & Shared library usages.
##### Utility
 + [x] Basic exception specialization.
 + [x] Enumeration used like C-like flags.
 * [x] Reflective enumeration traits.
 * [x] Reading and writing files and binary files.
 * [x] Parsing BMP images.
 * [x] Parsing OBJ and MTL Wavefront formats.
 * [x] Parsing JSON formats.
 * [x] Version handling.
 * [x] Unique ID generator.
 * [x] Localization handling.
 * [x] Console/file logger.
 * [x] Geometric operations.
 * [x] Matrix and vector handling, with expression templates.
 * [x] 3D rotation using quaternions, matrix, and Euler angles.
 + [x] Pimpl design pattern implementation.
 * [x] Listener/listenable design pattern.
 * [x] Service-consumer pattern implementation.
 * [x] Timer, and UPS/FPS counter.
##### Core
 * [x] General application management.
 * [x] CLI parser.
 * [x] Entity-Component-System pattern.
 * [x] Signal/Slot mechanism (Qt-like).
 * [x] Basic resources manager without any strategy (like, unloading the resource proportionally to the elapsed time since the last use).
##### Window
* [x] Windowed application.
* [x] Common interface to handle window.
+ [ ] Enqueuing window events.
+ [ ] Dealing with screen ratio/resolution.
+ [ ] Handling video mode.
* [x] Win32 implementation of window.
* [x] X11 implementation of window (Xlib and XCB).
+ [ ] Managing input devices events (Mouse, keyboard).
##### Renderer
* [x] Common interface for OpenGL context.
* [x] OpenGL extensions loader with lazy-loading.
* [x] OpenGL support from OpenGL 3.3 to OpenGL 4.6.
* [x] WGL implementation for Win32.
* [x] GLX implementation for X11.
* [x] Basic 2D and 3D renderer.
* [x] Basic shaders.
* [x] Basic 2D textures.
* [x] MSAA with OpenGL implementation.
* [x] Phong ligthing model.
* [x] Render state used for draw calls.
* [x] Light emitter (spot, directional, point).
##### Graphic
* [x] Basic particle generator.
* [x] 3D scene with 3D objects.
* [x] Static camera.
* [x] 3D primitive objects (Cube, sphere, rectangle, square, triangle, circle, torus, cylinder, pyramid, tetrahedron, etc ...)

### alpha-0.2.0 (aka. Graphic update)
##### Utility
+ [ ] Fractal algorithms.
##### Core
+ [ ] Allowing strategy for the resource manager.
+ [ ] Caping memory allocated throw resource manager.
+ [ ] MVC design integrating the ECS.
##### Window
+ [ ] Wayland implementation.
+ [ ] Mir implementation.
+ [ ] Cocoa implementation of window.
##### Renderer
+ [ ] CGL implementation (AGL ?) for OSX.
* [ ] Basic 3D textures.
+ [ ] Basic 2D text renderer.
+ [ ] Basic GUI renderer.
+ [ ] PBR lighting model.
+ [ ] IBL implementation.
+ [ ] Toon shading
+ [ ] Reflection and Refraction.
+ [ ] Particle renderer.
+ [ ] Shader AST.
+ [ ] BatchRenderer (to merge several draw calls of 2D objects in a single one).
+ [ ] CubeMap
+ [ ] Enhanced shaders, with hot reloading, and some other features.

##### Graphic
+ [ ] Scene graph.
+ [ ] Procedural texture generation (2D and 3D, eg. terrains).
+ [ ] Skeleton for game animation.
+ [ ] Keyframes.
+ [ ] Cinematic camera (movements, travelling, etc...).
+ [ ] glTF Parser.
+ [ ] External module to use FBX SDK from Autodesk.
+ [ ] Customizable particles generator.
+ [ ] Skybox and Skydome

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
- [ ] Threads
- [ ] Reflection on all the Core module at least, to allow serialization and nodalization.
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
+ [ ] Sockets

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
* [ ] Pluggable module for application (extending application capabilities).
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

### alpha-0.8.0 (aka. Game update)
##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio
##### Network
##### Physic
##### IA
##### Game

## Beta guideline

### beta-1.0.0
+ [ ] Unit testing everywhere.
* [ ] Continuous integration pipeline. (Git / GitFlow / etc...).
+ [ ] AppVeyor profile for Windows (x86 and x64).
+ [ ] Travis CI profile for Linux (x86 and x64) and MacOSX (x64).
+ [ ] Coveralls profile.

##### Utility
##### Core
##### Window
##### Renderer
##### Graphic
##### Audio
##### Network
##### Physic
##### IA
##### Game
