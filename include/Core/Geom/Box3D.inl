namespace ece
{
	inline Box3D::Box3D(const FloatVertex3D & a, FloatVertex3D & b): a(a), b(b) {}

	inline FloatVertex3D Box3D::getCenter() const { return (this->a + this->b ) / 2.0f; }
}