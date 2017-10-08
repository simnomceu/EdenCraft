namespace ece
{
	inline Index3u::Index3u() : i(0), j(0), k(0) {}

	inline Index3u::Index3u(const int i, const int j, const int k) : i(i), j(j), k(k) {}

	inline int Index3u::get(const int maxI, const int maxJ) { return this->k * maxI * maxJ + this->j * maxI + this->i; }

	inline void Index3u::set(const int maxI, const int maxJ, const int index)
	{
		this->k = index / (maxI * maxJ);
		this->j = (index - this->k * (maxI * maxJ)) / maxI;
		this->i = index - (this->j * maxI) - (this->k * maxI * maxJ);
	}
}