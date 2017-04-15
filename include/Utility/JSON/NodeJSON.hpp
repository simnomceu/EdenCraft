#ifndef NODEJSON_HPP
#define NODEJSON_HPP

#include <memory>
#include <map>
#include <string>

#include "Type.hpp"

namespace ece
{
	class NodeJSON: public std::enable_shared_from_this<NodeJSON>
	{
	public:
		NodeJSON() = delete;
		NodeJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());
		NodeJSON(const NodeJSON & copy);
		NodeJSON(NodeJSON && move);

		~NodeJSON();

		NodeJSON & operator=(const NodeJSON & copy);
		NodeJSON & operator=(NodeJSON && move);

		std::shared_ptr<NodeJSON> getParent();
		const bool hasParent() const;

		virtual bool isAtomic() const = 0;
		virtual TypeNodeJSON getType() const = 0;

	private:
		std::weak_ptr<NodeJSON> parent;
	};
}

#endif // NODEJSON_HPP