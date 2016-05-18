#pragma once

#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

namespace geo
{
	template <unsigned int N>
	class MYLIBRARY_EXPORT Vertex
	{
	public:
		Vertex();
		Vertex(unsigned int positionsIn[N]);

		const int getPositionInAxe(const unsigned int dimensionIn) const;
		const int[N] getPositions() const;
		const int getDimension() const;

		void move(const Transformation<N> transformationIn);

	private:
		unsigned int positions[N];
	};

	template <unsigned int N>
	Vertex::Vertex() : positions({ 0 })
	{
	}

	template <unsigned int N>
	Vertex::Vertex(unsigned int positionsIn[N]) : positions(positionsIn)
	{
	}

	template <unsigned int N>
	const int Vertex::getPositionInAxe(const unsigned int dimensionIn) const
	{
		return this->positions[dimensionIn];
	}

	template <unsigned int N>
	const int[N] Vertex::getPositions() const
	{
		return this->positions;
	}

	template <unsigned int N>
	const int Vertex::getDimension() const
	{
		return N;
	}

	template <unsigned int N>
	void Vertex::move(const Transformation<N> transformationIn)
	{

	}
}