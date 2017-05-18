namespace ece
{
	template<class T>
	inline Component<T>::Component() : BaseComponent(), value() {}

	template<class T>
	inline Component<T>::~Component() {}

	template<class T>
	inline const T & Component<T>::get() { return this->value; }

	template<class T>
	inline void Component<T>::set(const T & value) { this->value = value; }
}
