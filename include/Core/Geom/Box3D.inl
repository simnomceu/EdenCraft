namespace ece
{
	inline Box3D::Box3D(const FloatVertex3D & a, FloatVertex3D & b): a(a), b(b) {}

	inline FloatVertex3D Box3D::getCenter() const { return FloatVertex3D{(this->a.x + this->b.x) / 2, (this->a.y + this->b.y) / 2 , (this->a.z + this->b.z) / 2 }; }
}