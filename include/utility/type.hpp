#ifndef TYPE_HPP 
#define TYPE_HPP 

namespace ece
{
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
}

#endif // TYPE_HPP
