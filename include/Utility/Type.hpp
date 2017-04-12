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

	enum TypeNodeJSON : unsigned short int
	{
		NULL_JSON = 0,
		BOOLEAN = 1,
		INTEGER = 2,
		DOUBLE = 3,
		STRING = 4,
		OBJECT = 5,
		ARRAY = 6
	};

	static const double RATIO_4_3 = 4.0 / 3.0;
	static const double RATIO_5_4 = 5.0 / 4.0;
	static const double RATIO_16_9 = 16.0 / 9.0;
	static const double RATIO_16_10 = 16.0 / 10.0;
}

#endif // TYPE_HPP