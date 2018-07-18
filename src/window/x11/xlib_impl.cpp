/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooo   oooooo     oooo  o8o                    .o8
															 `888.    `888.     .8'   `"'                   "888
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'


				This file is part of EdenCraft Engine - Window module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "window/x11/xlib_impl.hpp"

#include "utility/log/service_logger.hpp"

namespace ece
{
	namespace window
	{
		namespace x11
		{
			using utility::log::ServiceLoggerLocator;

			XlibImpl::XlibImpl() noexcept: _windowId(0), _connection(nullptr), _screen(0)
			{
			}

			Window XlibImpl::getWindowHandle() const
			{
				return this->_windowId;
			}

			Display * XlibImpl::getDevice() const
			{
				return this->_connection;
			}

			void XlibImpl::createWindow()
			{
				this->_connection = XOpenDisplay(nullptr);
				if (!this->_connection) {
					ServiceLoggerLocator::getService().logError("No X server available.");
				}
				this->logInfos();

				this->_screen = DefaultScreen(this->_connection);

				XSetWindowAttributes attributes;
				attributes.colormap = XCreateColormap(this->_connection,
					RootWindow(this->_connection, this->_screen),
					DefaultVisual(this->_connection, this->_screen),
					AllocNone);
				attributes.border_pixel = 0;
				attributes.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask
					| ButtonReleaseMask | EnterWindowMask | LeaveWindowMask
					| PointerMotionMask /*| PointerMotionHintMask <= PointerMotionHintMask specifies that the server should
					send only one MotionNotify event when the pointer moves, until a key or button state changes, the pointer leaves
					the window, or the client calls XQueryPointer() or XGetMotionEvents().*/
					| Button1MotionMask | Button2MotionMask | Button3MotionMask
					| Button4MotionMask | Button5MotionMask | ButtonMotionMask
					| KeymapStateMask | ExposureMask | VisibilityChangeMask
					| StructureNotifyMask | ResizeRedirectMask
					| SubstructureNotifyMask | SubstructureRedirectMask
					| FocusChangeMask | PropertyChangeMask | ColormapChangeMask
					| OwnerGrabButtonMask;

				this->_windowId = XCreateWindow(this->_connection,
					RootWindow(this->_connection, this->_screen),
					0, 0, 320, 320,
					0,
					DefaultDepth(this->_connection, this->_screen),
					InputOutput,
					DefaultVisual(this->_connection, this->_screen),
					CWBorderPixel | CWColormap | CWEventMask,
					&attributes);
				XMapWindow(this->_connection, this->_windowId);
			}

			void XlibImpl::deleteWindow()
			{
				XDestroyWindow(this->_connection, this->_windowId);
				XCloseDisplay(this->_connection);

				this->_windowId = 0;
				this->_connection = nullptr;
			}

			bool XlibImpl::isWindowCreated() const
			{
				return this->_windowId != 0;
			}

			void XlibImpl::setTitle(const std::string & title)
			{
				XStoreName(this->_connection, this->_windowId, title.data());
			}

			std::string XlibImpl::getTitle() const
			{
				char * name;
				XFetchName(this->_connection, this->_windowId, &name);
				return std::string(name);
			}

			void XlibImpl::setPosition(const IntVector2u & position)
			{
				XMoveWindow(this->_connection, this->_windowId, position[0], position[1]);
			}

			IntVector2u XlibImpl::getPosition() const
			{
				int x = 0, y = 0;
				unsigned int w = 0, h = 0, border = 0, depth = 0;
				Window dummy;
				XGetGeometry(this->_connection, this->_windowId, &dummy, &x, &y, &w, &h, &border, &depth);
		//        XTranslateCoordinates(this->_connection, XRootWindow(this->_connection, 0), this->_windowId, 0, 0, &result[0], &result[1], &dummy);

				return IntVector2u{ x, y };
			}

			IntVector2u XlibImpl::getSize() const
			{
				int x = 0, y = 0;
				unsigned int w = 0, h = 0, border = 0, depth = 0;
				Window dummy;
				XGetGeometry(this->_connection, this->_windowId, &dummy, &x, &y, &w, &h, &border, &depth);

				return IntVector2u{ static_cast<int>(w), static_cast<int>(h) };
			}

			void XlibImpl::minimize()
			{
				ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to minimize the window.");
			}

			void XlibImpl::maximize()
			{
				XEvent event;
				event.type = ClientMessage;
				event.xclient.window = this->_windowId;
				event.xclient.format = 32;
				event.xclient.message_type = XInternAtom(this->_connection, "_NET_WM_STATE", false);
				event.xclient.data.l[0] = XInternAtom(this->_connection, "_NET_WM_STATE_ADD", false);
				event.xclient.data.l[1] = XInternAtom(this->_connection, "_NET_WM_STATE_MAXIMIZED_VERT", false);
				event.xclient.data.l[2] = XInternAtom(this->_connection, "_NET_WM_STATE_MAXIMIZED_HORZ", false);
				event.xclient.data.l[3] = 1;
				event.xclient.data.l[4] = 0;

				XSendEvent(this->_connection, XRootWindow(this->_connection, 0), false, SubstructureNotifyMask | SubstructureRedirectMask, &event);
			}

			std::vector<InputEvent> XlibImpl::processEvent(const bool blocking)
			{
				std::vector<InputEvent> events;
				XMapWindow(this->_connection, this->_windowId);
				if (blocking) {
					while (XPending(this->_connection)) { //while (XPending(this->_connection)) <= blocking || XEventsQueued() <= non blocking
						auto message = this->getNextMessage();
						events.push_back(std::move(this->processMessage(message)));
					}
				}
				else {
					int n = XEventsQueued(this->_connection, QueuedAlready);
					for (int i = 0; i < n; ++i) {
						auto message = this->getNextMessage();
						events.push_back(std::move(this->processMessage(message)));
					}
				}
				XFlush(this->_connection);
				return std::move(events);
			}

			void XlibImpl::logInfos()
			{
				std::string owner(XServerVendor(this->_connection));
				auto version = std::to_string(XVendorRelease(this->_connection));
				ServiceLoggerLocator::getService().logInfo("Xserver from: " + owner + " - version " + version + ".");
				auto major = std::to_string(XProtocolVersion(this->_connection));
				auto minor = std::to_string(XProtocolRevision(this->_connection));
				ServiceLoggerLocator::getService().logInfo("Protocol X version " + major + "." + minor + " used.");
			}

			WindowMessage XlibImpl::getNextMessage()
			{
				XEvent e;
				//        XPeekEvent(this->_connection, &e);
				//        if(e.xany.window == this->_windowId) {
				XNextEvent(this->_connection, &e);
				return std::move(WindowMessage{ e });
				//        }
				//        return std::move(WindowMessage{XEvent()});
			}

			InputEvent XlibImpl::processMessage(const WindowMessage & message)
			{
				InputEvent newEvent;
				if (message._impl.xany.window == this->_windowId) {
					switch (message._impl.type) {
					case KeyPress: {
						break;
					}
					case KeyRelease: {
						break;
					}
					case ButtonPress: {
						break;
					}
					case ButtonRelease: {
						break;
					}
					case MotionNotify: {
						newEvent._type = InputEvent::Type::ECE_MOUSE_MOVED;
						newEvent._mousePosition[0] = message._impl.xmotion.x;
						newEvent._mousePosition[1] = message._impl.xmotion.y;
						Mouse::setPosition(this->getPosition() + newEvent._mousePosition);
						break;
					}
					case EnterNotify: {
						break;
					}
					case LeaveNotify: {
						break;
					}
					case FocusIn: {
						break;
					}
					case FocusOut: {
						break;
					}
					case KeymapNotify: {
						break;
					}
					case Expose: {
						break;
					}
					case GraphicsExpose: {
						break;
					}
					case NoExpose: {
						break;
					}
					case VisibilityNotify: {
						break;
					}
					case CreateNotify: {
						break;
					}
					case DestroyNotify: {
//						std::cout << std::endl << std::endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>> DESTROY <<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
						break;
					}
					case UnmapNotify: {
//						std::cout << std::endl << std::endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>> UNMAP <<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
						break;
					}
					case MapNotify: {
						break;
					}
					case MapRequest: {
						break;
					}
					case ReparentNotify: {
						break;
					}
					case ConfigureNotify: {
						break;
					}
					case ConfigureRequest: {
						break;
					}
					case GravityNotify: {
						break;
					}
					case ResizeRequest: {
						break;
					}
					case CirculateNotify: {
						break;
					}
					case CirculateRequest: {
						break;
					}
					case PropertyNotify: {
						break;
					}
					case SelectionClear: {
						break;
					}
					case SelectionRequest: {
						break;
					}
					case SelectionNotify: {
						break;
					}
					case ColormapNotify: {
						break;
					}
					case ClientMessage: {
						break;
					}
					case MappingNotify: {
						break;
					}
					case GenericEvent: {
						break;
					}
					default: {
						break;
					}
					}
				}
				return std::move(newEvent);
			}
		} // namespace x11
	} // namespace window
} // namespace ece
