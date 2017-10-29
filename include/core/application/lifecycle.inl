namespace ece
{
	inline void Lifecycle::preInit() { this->emit(PRE_INIT); }

	inline void Lifecycle::postInit() { this->emit(POST_INIT); }

	inline void Lifecycle::preProcess() { this->emit(PRE_PROCESS); }

	inline void Lifecycle::preUpdate() { this->emit(PRE_UPDATE); }

	inline void Lifecycle::postUpdate() { this->emit(POST_UPDATE); }

	inline void Lifecycle::postRender() { this->emit(POST_RENDER); }

	inline void Lifecycle::preTerminate() { this->emit(PRE_TERMINATE); }

	inline void Lifecycle::postTerminate() { this->emit(POST_TERMINATE); }

	inline void Lifecycle::onPreInit(const Listener & listener, const unsigned int slot) { this->connect(PRE_INIT, listener, slot); }

	inline void Lifecycle::onPostInit(const Listener & listener, const unsigned int slot) { this->connect(POST_INIT, listener, slot); }

	inline void Lifecycle::onPreProcess(const Listener & listener, const unsigned int slot) { this->connect(PRE_PROCESS, listener, slot); }

	inline void Lifecycle::onPreUpdate(const Listener & listener, const unsigned int slot) { this->connect(PRE_UPDATE, listener, slot); }

	inline void Lifecycle::onPostUpdate(const Listener & listener, const unsigned int slot) { this->connect(POST_UPDATE, listener, slot); }

	inline void Lifecycle::onPostRender(const Listener & listener, const unsigned int slot) { this->connect(POST_RENDER, listener, slot); }

	inline void Lifecycle::onPreTerminate(const Listener & listener, const unsigned int slot) { this->connect(PRE_TERMINATE, listener, slot); }

	inline void Lifecycle::onPostTerminate(const Listener & listener, const unsigned int slot) { this->connect(POST_TERMINATE, listener, slot); }

}