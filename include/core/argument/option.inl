namespace ece
{
	inline Option::Option(const std::string & name, const std::shared_ptr<OptionValue> & value, const std::function<void(const std::string &)> & command) :
		_name(name), _value(value), _command(command)
	{
	}
}