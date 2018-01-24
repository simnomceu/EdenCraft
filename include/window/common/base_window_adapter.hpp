#ifndef BASE_WINDOW_ADAPTER_HPP
#define BASE_WINDOW_ADAPTER_HPP

#include <memory>
#include <string>

#include "window/window_event/input_event.hpp"
#include "window/common/event_queue.hpp"
#include "utility/pattern/pimpl.hpp"

namespace ece
{
	struct DataWindowAdapter;
	struct WindowMessage;

	class BaseWindowAdapter
	{
	public:
		BaseWindowAdapter();
		BaseWindowAdapter(const BaseWindowAdapter & copy) = default;
		BaseWindowAdapter(BaseWindowAdapter && move) = default;

		virtual ~BaseWindowAdapter() = 0;

		BaseWindowAdapter & operator=(const BaseWindowAdapter & copy) = default;
		BaseWindowAdapter & operator=(BaseWindowAdapter && move) = default;

		virtual void createWindow() = 0;
		virtual void deleteWindow() = 0;
		virtual bool isWindowCreated() const = 0;

		virtual void setTitle(const std::string & title) = 0;
		virtual std::string getTitle() const = 0;

		virtual void setPosition(const IntVector2u & position) = 0;
		virtual IntVector2u getPosition() const = 0;

		virtual void minimize() = 0;
		virtual void maximize() = 0;

		void enableKeyRepeat(const bool enabled);

		virtual void processEvent(const bool blocking) = 0;
		bool hasEvents() const;
		InputEvent popEvent();

		virtual Pimpl<DataWindowAdapter> & getImpl() = 0;

	protected:
		void pushEvent(const InputEvent & nextEvent);
		InputEvent & lastEvent();

		bool _keyRepeat;

	private:
		EventQueue _eventQueue;
	};
}

#endif // BASE_WINDOW_ADAPTER_HPP
