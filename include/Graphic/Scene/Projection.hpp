#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include "Window\Ratio.hpp"
#include "glm\glm.hpp"

namespace ece
{
	class Projection
	{
	public:
		inline Projection();
		Projection(const Projection & copy) = default;
		Projection(Projection && move) = default;

		~Projection() = default;

		Projection & operator=(const Projection & copy) = default;
		Projection & operator=(Projection && move) = default;

		inline void setProjection(const double FOV, const Ratio ratio, const double nearClipping, const double farClipping);

		inline const glm::mat4 & getProjection() const;

	private:
		glm::mat4 projection;
	};
}

#include "Scene\Projection.inl"

#endif // PROJECTION_HPP