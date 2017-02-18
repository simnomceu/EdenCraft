namespace ece
{
	inline Object::~Object() { delete this->program; }
}