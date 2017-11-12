#ifndef ARRAY_JSON_HPP
#define ARRAY_JSON_HPP

#include "utility/json/node_json.hpp"
#include "utility/json/atomic_json.hpp"

#include <vector>

namespace ece
{
	class ObjectJSON;

	using IteratorArrayJSON = std::vector<std::shared_ptr<NodeJSON>>::iterator;

	class ArrayJSON : public NodeJSON
	{
	public:
		ArrayJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());
		ArrayJSON(const ArrayJSON & copy) = default;
		ArrayJSON(ArrayJSON && move) = default;

		~ArrayJSON() = default;

		ArrayJSON & operator=(const ArrayJSON & copy) = default;
		ArrayJSON & operator=(ArrayJSON && move) = default;

		std::shared_ptr<NodeJSON> addNull();
		std::shared_ptr<NodeJSON> addBoolean(const bool value);
		std::shared_ptr<NodeJSON> addInteger(const int value);
		std::shared_ptr<NodeJSON> addDouble(const double value);
		std::shared_ptr<NodeJSON> addString(const std::string & value);
		std::shared_ptr<NodeJSON> addObject();
		std::shared_ptr<NodeJSON> addArray();

		void remove(const std::shared_ptr<NodeJSON> & child);

		virtual bool isAtomic() const override;
		virtual TypeNodeJSON getType() const override;

		IteratorArrayJSON begin();
		IteratorArrayJSON end();
		std::shared_ptr<NodeJSON> operator[](const int key);
		void clear();

	private:
		std::vector<std::shared_ptr<NodeJSON>> children;
	};
}

#endif // ARRAY_JSON_HPP