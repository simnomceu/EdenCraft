#ifndef GLEW_HPP
#define GLEW_HPP

namespace ece
{
	class GLEW
	{
	public:
		GLEW();
		~GLEW() = default;

		void init();
		bool isInit() const;

	private:
		bool initialized;
	};
}

#endif // GLEW_HPP
