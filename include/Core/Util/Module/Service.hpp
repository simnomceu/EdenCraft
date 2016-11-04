#ifndef SERVICE_HPP
#define SERVICE_HPP

namespace ece
{
	enum class Mode
	{
		NOT_INIT,
		NONE,
		DEFAULT,
		CONSOLE
	};

	class Service
	{
	public:
		Service();

		virtual void init(Mode mode = Mode::NONE) = 0;

		bool isInitialized() const;

		virtual void setMode(Mode mode) = 0;

	protected:
		bool initialized;
		Mode modeInitialized;
	};
}

#endif // SERVICE_HPP