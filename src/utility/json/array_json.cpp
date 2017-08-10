#include "json/array_json.hpp"

#include "json/object_json.hpp"

namespace ece
{
	ArrayJSON::ArrayJSON(const std::weak_ptr<NodeJSON>& parent): NodeJSON(parent), children()
	{
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addNull()
	{
		this->children.push_back(std::make_shared<NullJSON>(std::to_string(this->children.size()), nullptr, this->shared_from_this()));
		return this->children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addBoolean(const bool value)
	{
		this->children.push_back(std::make_shared<BooleanJSON>(std::to_string(this->children.size()), value, this->shared_from_this()));
		return this->children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addInteger(const int value)
	{
		this->children.push_back(std::make_shared<IntegerJSON>(std::to_string(this->children.size()), value, this->shared_from_this()));
		return this->children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addDouble(const double value)
	{
		this->children.push_back(std::make_shared<DoubleJSON>(std::to_string(this->children.size()), value, this->shared_from_this()));
		return this->children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addString(const std::string & value)
	{
		this->children.push_back(std::make_shared<StringJSON>(std::to_string(this->children.size()), value, this->shared_from_this()));
		return this->children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addObject()
	{
		this->children.push_back(std::make_shared<ObjectJSON>(this->shared_from_this()));
		return this->children.back();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::addArray()
	{
		this->children.push_back(std::make_shared<ArrayJSON>(this->shared_from_this()));
		return this->children.back();
	}

	void ArrayJSON::remove(const std::shared_ptr<NodeJSON>& child)
	{
		auto it = std::find(this->begin(), this->end(), child);
		if (it != this->end()) {
			this->children.erase(it);
		}
	}

	bool ArrayJSON::isAtomic() const
	{
		return false;
	}

	TypeNodeJSON ArrayJSON::getType() const
	{
		return TypeNodeJSON::ARRAY;
	}
	
	IteratorArrayJSON ArrayJSON::begin()
	{
		return this->children.begin();
	}

	IteratorArrayJSON ArrayJSON::end()
	{
		return this->children.end();
	}

	std::shared_ptr<NodeJSON> ArrayJSON::operator[](const int key)
	{
		return this->children[key];
	}

	void ArrayJSON::clear()
	{
		this->children.clear();
	}
}