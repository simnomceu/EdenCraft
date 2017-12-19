#ifndef WINDOW_ADAPTER_HPP
#define WINDOW_ADAPTER_HPP

#include "window/common/base_window_adapter.hpp"

namespace ece
{
	class WindowAdapter: public BaseWindowAdapter
	{
	public:
		WindowAdapter();
		WindowAdapter(const WindowAdapter & copy) = default;
		WindowAdapter(WindowAdapter && move) = default;

		~WindowAdapter() = default;

		WindowAdapter & operator=(const WindowAdapter & copy) = default;
		WindowAdapter & operator=(WindowAdapter && move) = default;

		virtual void createWindow() override;
		virtual void deleteWindow() override;
		virtual bool isWindowCreated() const override;

		virtual void setTitle(const std::string & title) override;
		virtual std::string getTitle() const override;

		virtual void setPosition(const IntVertex2u & position) override;
		virtual IntVertex2u getPosition() const override;

		virtual void minimize() override;
		virtual void maximize() override;

		virtual void processEvent(const bool blocking) override;

		virtual inline Pimpl<DataWindowAdapter> & getImpl() override { return this->data; }

		void processMessage(const WindowMessage & message);

	private:
		Pimpl<DataWindowAdapter> data;
	};
}

#endif // WINDOW_ADAPTER_HPP
