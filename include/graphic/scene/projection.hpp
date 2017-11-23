#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include "window/window/ratio.hpp"
//#include "glm\glm.hpp"
#include "utility/mathematics/matrix4u.hpp"

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

		//inline const glm::mat4 & getProjection() const;
		inline const FloatMatrix4u & getProjection() const;

	private:
		//glm::mat4 projection;
		FloatMatrix4u projection;
	};
}

#include "graphic/scene/projection.inl"

#endif // PROJECTION_HPP