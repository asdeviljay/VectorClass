#pragma once

#include <iostream>

const float PI = 3.1415927f;
const float RADIUS = 180.0f / PI;

namespace cw {
	template <class T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;

		static Vector3 zero() {
			return Vector3(0, 0, 0);
		}
		static Vector3 one() {
			return Vector3(1, 1, 1);
		}
		static Vector3 up() {
			return Vector3(0, 1, 0);
		}
		static Vector3 right() {
			return Vector3(1, 0, 0);
		}
		static Vector3 forward() {
			return Vector3(0, 0, 1);
		}

		Vector3() {}
		Vector3(T t_x, T t_y, T t_z) :
			x(t_x),
			y(t_y),
			z(t_z) {}
		Vector3(const Vector3& T) :
			x(T.x),
			y(T.y),
			z(T.z) {}
		~Vector3() {}

		Vector3& operator= (const Vector3& T) {
			x = T.x;
			y = T.y;
			z = T.z;
		}

		Vector3 sum(const Vector3& t_v) {
			return Vector3(x + t_v.x, y + t_v.y, z + t_v.z);
		}
		Vector3 operator+ (const Vector3& t_v) {
			return Vector3(x + t_v.x, y + t_v.y, z + t_v.z);
		}
		void operator+= (const Vector3& t_v) {
			x += t_v.x;
			y += t_v.y;
			z += t_v.z;
		}

		Vector3 minus(const Vector3& t_v) {
			return Vector3(x - t_v.x, y - t_v.y, z - t_v.z);
		}
		Vector3 operator- (const Vector3& t_v) {
			return Vector3(x - t_v.x, y - t_v.y, z - t_v.z);
		}
		void operator-= (const Vector3& t_v) {
			x -= t_v.x;
			y -= t_v.y;
			z -= t_v.z;
		}

		Vector3 mul(const T& t_s) {
			return Vector3(x * t_s, y * t_s, z * t_s);
		}
		Vector3 operator* (const T& t_s) {
			return Vector3(x * t_s, y * t_s, z * t_s);
		}
		void operator*= (const T& t_s) {
			x *= t_s;
			y *= t_s;
			z *= t_s;
		}

		Vector3 div(const T& t_s) {
			return Vector3(x / t_s, y / t_s, z / t_s);
		}
		Vector3 operator/ (const T& t_s) {
			return Vector3(x / t_s, y / t_s, z / t_s);
		}
		void operator/= (const T& t_s) {
			x /= t_s;
			y /= t_s;
			z /= t_s;
		}

		Vector3 cross(const Vector3& t_v) {
			return Vector3(y * t_v.z - z * t_v.y,
				z * t_v.x - x * t_v.z,
				x * t_v.y - y * t_v.x);
		}

		T dot(const Vector3& t_v) {
			return x * t_v.x + y * t_v.y + z * t_v.z;
		}

		float sqrMagnitude() {
			return static_cast<float>(x) * static_cast<float>(x) + static_cast<float>(y) * static_cast<float>(y) + static_cast<float>(z) * static_cast<float>(z);
		}

		float magnitude() {
			return std::sqrtf(sqrMagnitude());
		}

		Vector3<float> normalize() {
			float mag = magnitude();
			return Vector3<float>(x / mag, y / mag, z / mag);
		}

		/*float angle() {		//Not sure this formula is right or wrong
			return std::asinf(static_cast<float>(x) / magnitude()) * RADIUS;	//Angle from X-axis
			return std::asinf(static_cast<float>(y) / magnitude()) * RADIUS;	//Angle from Y-axis
			return std::asinf(static_cast<float>(z) / magnitude()) * RADIUS;	//Angle from Z-axis
		}*/

		float btwAngle(const Vector3& t_v) {
			float dotProd = static_cast<float>(this->dot(t_v));
			float magV1 = this->sqrMagnitude();
			float magV2 = static_cast<float>(t_v.x) * static_cast<float>(t_v.x) + static_cast<float>(t_v.y) * static_cast<float>(t_v.y) + static_cast<float>(t_v.z) * static_cast<float>(t_v.z);
			return std::acosf(dotProd / std::sqrtf(magV1 * magV2)) * RADIUS;
		}

		bool operator== (const Vector3& t_v) {
			return x == t_v.x && y == t_v.y && z == t_v.z;
		}
		bool operator!= (const Vector3& t_v) {
			return x != t_v.x || y != t_v.y || z != t_v.z;
		}

		std::string toString() {
			return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
		}
	};

	template <class T> Vector3<T> operator* (const T& t_s, const Vector3<T>& t_v) {
		return Vector3<T>(t_s * t_v.x, t_s * t_v.y, t_s * t_v.z);
	}

	template <class T> std::ostream& operator<< (std::ostream& os, const Vector3<T>& t_v) {
		os << "(" << t_v.x << ", " << t_v.y << ", " << t_v.z << ")";
		return os;
	}

	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;
}