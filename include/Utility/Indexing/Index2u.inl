namespace ece
{
	inline Index2u::Index2u(): i(0), j(0) {}

	inline Index2u::Index2u(const int i, const int j) : i(i), j(j) {}

	inline int Index2u::get(const int maxI) { return this->j * maxI + this->i; }
	
	inline void Index2u::set(const int maxI, const int index)
	{
		this->j = index / maxI;
		this->i = index - (this->j * maxI); 
	}
}