namespace ece
{
	template <class T>
	inline constexpr EulerAngle<T>::EulerAngle() noexcept: roll(0.0), pitch(0.0), yaw(0.0) {}

	template <class T>
	inline EulerAngle<T>::EulerAngle(const double roll, const double pitch, const double yaw) noexcept: roll(roll), pitch(pitch), yaw(yaw) {}

	template <class T>
	EulerAngle<T>::EulerAngle(const Quaternion<T> & quaternion): roll(0.0), pitch(0.0), yaw(0.0)
	{
		double sinr = 2.0 * (quaternion.getW() * quaternion.getX() + quaternion.getY() * quaternion.getZ());
		double cosr = 1.0 - 2.0 * (quaternion.getX() * quaternion.getX() + quaternion.getY() * quaternion.getY());
		double sinp = 2.0 * (quaternion.getW() * quaternion.getY() - quaternion.getX() * quaternion.getZ());
		double siny = 2.0 * (quaternion.getW() * quaternion.getZ() + quaternion.getX() * quaternion.getY());
		double cosy = 1.0 - 2.0 * (quaternion.getY() * quaternion.getY() + quaternion.getZ() * quaternion.getZ());

		this->roll = std::atan2(sinr, cosr);
		this->pitch = std::fabs(sinp) >= 1.0 ? std::copysign(M_PI / 2, sinp) : std::asin(sinp);
		this->yaw = std::atan2(siny, cosy);
	}

	template <class T>
	Quaternion<T> EulerAngle<T>::toQuaternion() const
	{
		double cy = cos(this->yaw * 0.5);
		double sy = sin(this->yaw * 0.5);
		double cr = cos(this->roll * 0.5);
		double sr = sin(this->roll * 0.5);
		double cp = cos(this->pitch * 0.5);
		double sp = sin(this->pitch * 0.5);

		return Quaternion<T>(cy * cr * cp + sy * sr * sp,
			cy * sr * cp - sy * cr * sp,
			cy * cr * sp + sy * sr * cp,
			sy * cr * cp - cy * sr * sp);
	}

	template <class T>
	Matrix4u<T> EulerAngle<T>::toMatrix() const
	{
	}

	template <class T>
	inline T & EulerAngle<T>::getRoll() noexcept { return this->roll; }

	template <class T>
	inline T & EulerAngle<T>::getPitch() noexcept { return this->pitch; }

	template <class T>
	inline T & EulerAngle<T>::getYaw() noexcept { return this->yaw; }

	template <class T>
	inline T EulerAngle<T>::getRoll() const noexcept { return this->roll; }

	template <class T>
	inline T EulerAngle<T>::getPitch() const noexcept { return this->pitch; }

	template <class T>
	inline T EulerAngle<T>::getYaw() const noexcept { return this->yaw; }
}