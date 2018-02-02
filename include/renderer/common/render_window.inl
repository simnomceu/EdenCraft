namespace ece
{
	inline void RenderWindow::setContextMinimumVersion(const Version<2> & minVersion) { this->_context->setMinVersion(minVersion); }

	inline void RenderWindow::setContextMaximumVersion(const Version<2> & maxVersion) { this->_context->setMaxVersion(maxVersion); }
}