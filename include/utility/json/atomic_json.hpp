#ifndef ATOMIC_JSON_HPP
#define ATOMIC_JSON_HPP

#include "json/node_json.hpp"

namespace ece
{
	template <class T>
	class AtomicJSON: public NodeJSON
	{
	public:
		AtomicJSON() = delete;
		AtomicJSON(const std::string & key, const T & value, const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());
		AtomicJSON(const AtomicJSON & copy) = default;
		AtomicJSON(AtomicJSON && move) = default;

		~AtomicJSON() = default;

		AtomicJSON & operator=(const AtomicJSON & copy) = default;
		AtomicJSON & operator=(AtomicJSON && move) = default;

		virtual bool isAtomic() const override;
		virtual TypeNodeJSON getType() const override;

		const T & getValue() const;
		void setValue(const T & value);
		const std::string & getKey() const;

	private:
		std::string key;
		T value;
	};

	typedef AtomicJSON<void *> NullJSON;
	typedef AtomicJSON<bool> BooleanJSON;
	typedef AtomicJSON<int> IntegerJSON;
	typedef AtomicJSON<double> DoubleJSON;
	typedef AtomicJSON<std::string> StringJSON;
}

#include "json/atomic_json.inl"

#endif // ATOMIC_JSON_HPP