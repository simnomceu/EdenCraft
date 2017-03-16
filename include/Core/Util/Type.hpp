#ifndef TYPE_HPP 
#define TYPE_HPP 

namespace ece
{
	using uint8 = unsigned __int8;
	using uint16 = unsigned __int16;
	using uint32 = unsigned __int32;
	using uint64 = unsigned __int64;

	using int8 = __int8;
	using int16 = __int16;
	using int32 = __int32;
	using int64 = __int64;

	struct FastVertex3D
	{
		float x;
		float y;
		float z;
	};

	enum FileCodeError : unsigned short int
	{
		BAD_PATH = 0,
		PARSE_ERROR = 1
	};

	enum ResourceType : unsigned short int
	{
		SHADER = 0,
		PROGRAM = 1,
		MESH = 2,
		TEXTURE = 3,
		ANIMATION = 4
	};
}

#endif // TYPE_HPP