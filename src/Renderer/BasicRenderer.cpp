#include "BasicRenderer.hpp"

#include "Scene\Camera.hpp"
#include "Scene\Projection.hpp"
#include "Renderable\Renderable.hpp"

#include <iostream>

namespace ece
{
	void BasicRenderer::render(const Camera & cam, const Projection & projection, std::vector<Renderable *> & objects)
	{
		for (auto & object : objects) {
			auto vertices = object->getVertices();
			auto uniforms = object->getUniforms();
			auto shaders = object->getShaderSources();

			// create the object here

			// Set the mesh here

			// bind the uniforms here

			// load the shaders here
		}
	}
}