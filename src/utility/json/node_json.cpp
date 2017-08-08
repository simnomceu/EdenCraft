#include "json\node_json.hpp"

namespace ece
{
	NodeJSON::NodeJSON(const std::weak_ptr<NodeJSON>& parent): std::enable_shared_from_this<NodeJSON>(), parent(parent)
	{
	}

	NodeJSON::NodeJSON(const NodeJSON & copy): std::enable_shared_from_this<NodeJSON>(copy), parent(copy.parent)
	{
	}

	NodeJSON::NodeJSON(NodeJSON && move): std::enable_shared_from_this<NodeJSON>(move), parent(std::move(move.parent))
	{
	}

	NodeJSON::~NodeJSON()
	{
		this->parent.reset();
	}

	NodeJSON & NodeJSON::operator=(const NodeJSON & copy)
	{
		this->parent = copy.parent;
		return *this;
	}

	NodeJSON & NodeJSON::operator=(NodeJSON && move)
	{
		this->parent = std::move(move.parent);
		return *this;
	}

	std::shared_ptr<NodeJSON> NodeJSON::getParent()
	{
		return this->parent.lock();
	}

	const bool NodeJSON::hasParent() const
	{
		return !this->parent.expired();
	}
}