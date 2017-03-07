namespace ece
{
	inline Box3D::Box3D(const FastVertex3D & a, FastVertex3D & b): a(a), b(b) {}

	inline const FastVertex3D & Box3D::getCenter() const { return FastVertex3D{(this->a.x + this->b.x) / 2, (this->a.y + this->b.y) / 2 , (this->a.z + this->b.z) / 2 }; }
}