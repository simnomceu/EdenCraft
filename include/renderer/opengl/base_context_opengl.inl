#ifdef _MSC_VER
#	undef min
#	undef max
#endif

namespace ece
{
	inline BaseContextOpenGL::BaseContextOpenGL() : _minVersion{ 2, 0 }, _maxVersion{ 4, 6 } {}

	inline BaseContextOpenGL::~BaseContextOpenGL() {}

	inline void BaseContextOpenGL::setMinVersion(const Version<2> & minVersion) { this->_minVersion = min(max(minVersion, Version<2>{ 2, 0 }), Version<2>{ 4, 6 }); }
	inline void BaseContextOpenGL::setMaxVersion(const Version<2> & maxVersion) { this->_maxVersion = min(max(maxVersion, Version<2>{ 2, 0 }), Version<2>{ 4, 6 }); }
}