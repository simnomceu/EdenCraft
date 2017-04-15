#include "JSON\ObjectJSON.hpp"

#include "JSON\ArrayJSON.hpp"

#include <utility>

namespace ece
{
	ObjectJSON::ObjectJSON(const std::weak_ptr<NodeJSON>& parent): NodeJSON(parent), children()
	{
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addNull(const std::string & key)
	{
		this->children[key] = std::make_shared<NullJSON>(key, nullptr, this->shared_from_this());
		return this->children[key];
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addBoolean(const std::string & key, const bool value)
	{
		this->children[key] = std::make_shared<BooleanJSON>(key, value, this->shared_from_this());
		return this->children[key];
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addInteger(const std::string & key, const int value)
	{
		this->children[key] = std::make_shared<IntegerJSON>(key, value, this->shared_from_this());
		return this->children[key];
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addDouble(const std::string & key, const double value)
	{
		this->children[key] = std::make_shared<DoubleJSON>(key, value, this->shared_from_this());
		return this->children[key];
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addString(const std::string & key, const std::string & value)
	{
		this->children[key] = std::make_shared<StringJSON>(key, value, this->shared_from_this());
		return this->children[key];
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addObject(const std::string & key)
	{
		this->children[key] = std::make_shared<ObjectJSON>(this->shared_from_this());
		return this->children[key];
	}

	std::shared_ptr<NodeJSON> ObjectJSON::addArray(const std::string & key)
	{
		this->children[key] = std::make_shared<ArrayJSON>(this->shared_from_this());
		return this->children[key];
	}

	void ObjectJSON::remove(const std::string & key)
	{
		this->children.erase(key);
	}

	bool ObjectJSON::isAtomic() const
	{
		return false;
	}

	TypeNodeJSON ObjectJSON::getType() const
	{
		return TypeNodeJSON::OBJECT;
	}

	IteratorObjectJSON ObjectJSON::begin()
	{
		return this->children.begin();
	}

	IteratorObjectJSON ObjectJSON::end()
	{
		return this->children.end();
	}

	std::shared_ptr<NodeJSON> ObjectJSON::operator[](const std::string & key)
	{
		return this->children[key];
	}

	void ObjectJSON::clear()
	{
		this->children.clear();
	}
}