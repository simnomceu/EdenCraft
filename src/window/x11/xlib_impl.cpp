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
    XlibImpl::XlibImpl() noexcept: _windowId(0), _connection(nullptr), _screen(0)
    {
    }

	void XlibImpl::createWindow()
    {
		this->_connection = XOpenDisplay(nullptr);
		if(!this->_connection) {
			ServiceLoggerLocator::getService().logError("No X server available.");
		}

		this->_screen = DefaultScreen(this->_connection);
		this->_windowId = XCreateSimpleWindow(this->_connection,
													RootWindow(this->_connection, this->_screen),
													0, 0, 320, 320,
													1,
													BlackPixel(this->_connection, this->_screen),
													WhitePixel(this->_connection, this->_screen));
		XSelectInput(this->_connection, this->_windowId, ExposureMask | KeyPressMask);
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
        IntVector2u result;
        Window dummy;
        XTranslateCoordinates(this->_connection, XRootWindow(this->_connection, 0), this->_windowId, 0, 0, &result[0], &result[1], &dummy);

        return result;
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

	void XlibImpl::processEvent(const bool blocking)
    {
        if (blocking) {
    		while (XPending(this->_connection)) { //while (XPending(this->_connection)) <= blocking || XEventsQueued() <= non blocking
            	XEvent e;
                XNextEvent(this->_connection, &e);
    	      	if (e.type == Expose) {
    	        	XFillRectangle(this->_connection, this->_windowId, DefaultGC(this->_connection, this->_screen), 20, 20, 10, 10);
    	      	}
    	      	if (e.type == KeyPress)
    	        	break;
    	   	}
        }
        else {
            int n = XEventsQueued(this->_connection, QueuedAlready);
            for(int i = 0; i < n; ++i) {
                XEvent e;
                XNextEvent(this->_connection, &e);
    	      	if (e.type == Expose) {
    	        	XFillRectangle(this->_connection, this->_windowId, DefaultGC(this->_connection, this->_screen), 20, 20, 10, 10);
    	      	}
    	      	if (e.type == KeyPress)
    	        	break;
            }
        }
    }
}
