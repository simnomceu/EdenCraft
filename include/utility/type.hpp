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
		BOOLEAN_JSON = 1,
		INTEGER_JSON = 2,
		DOUBLE_JSON = 3,
		STRING_JSON = 4,
		OBJECT_JSON = 5,
		ARRAY_JSON = 6
	};
}

#endif // TYPE_HPP
