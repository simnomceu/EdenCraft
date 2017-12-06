namespace ece
{
	inline constexpr ParserJSON::ParserJSON() : pathname(), contentJSON() {}

	inline std::shared_ptr<ObjectJSON> ParserJSON::getObject() const { return this->contentJSON; }
}