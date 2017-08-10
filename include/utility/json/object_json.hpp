#ifndef OBJECT_JSON_HPP
#define OBJECT_JSON_HPP

#include "json/node_json.hpp"
#include "json/atomic_json.hpp"

namespace ece
{
	class ArrayJSON;

	using IteratorObjectJSON = std::map<std::string, std::shared_ptr<NodeJSON>>::iterator;

	class ObjectJSON: public NodeJSON
	{
	public:
		ObjectJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());
		ObjectJSON(const ObjectJSON & copy) = default;
		ObjectJSON(ObjectJSON && move) = default;

		~ObjectJSON() = default;

		ObjectJSON & operator=(const ObjectJSON & copy) = default;
		ObjectJSON & operator=(ObjectJSON && move) = default;

		std::shared_ptr<NodeJSON> addNull(const std::string & key);
		std::shared_ptr<NodeJSON> addBoolean(const std::string & key, const bool value);
		std::shared_ptr<NodeJSON> addInteger(const std::string & key, const int value);
		std::shared_ptr<NodeJSON> addDouble(const std::string & key, const double value);
		std::shared_ptr<NodeJSON> addString(const std::string & key, const std::string & value);
		std::shared_ptr<NodeJSON> addObject(const std::string & key);
		std::shared_ptr<NodeJSON> addArray(const std::string & key);

		void remove(const std::string & key);

		virtual bool isAtomic() const override;
		virtual TypeNodeJSON getType() const override;

		IteratorObjectJSON begin();
		IteratorObjectJSON end();
		std::shared_ptr<NodeJSON> operator[](const std::string & key);
		void clear();

	private:
		std::map<std::string, std::shared_ptr<NodeJSON>> children;
	};
}

#endif // OBJECT_JSON_HPP