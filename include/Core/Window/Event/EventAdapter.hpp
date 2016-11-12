#ifndef EVENTADAPTER_HPP
#define EVENTADAPTER_HPP

namespace ece
{
	class EventAdapter
	{
	public:	
		EventAdapter(const short int windowID);

	private:
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}

#endif // EVENTADAPTER_HPP
