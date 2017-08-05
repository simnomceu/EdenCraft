namespace ece
{
	inline Box3D::Box3D(const FloatVertex3u & a, FloatVertex3u & b): a(a), b(b) {}

	inline FloatVertex3u Box3D::getCenter() const { return (this->a + this->b ) / 2.0f; }
}