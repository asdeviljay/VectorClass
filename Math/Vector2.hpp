#pragma once

#include <iostream>

const float PI = 3.1415927f;
const float RADIUS = 180.0f / PI;

namespace cw {
	template <class T> 
	class Vector2
	{
	public:
		T x;
		T y;

		static Vector2 zero() {
			return Vector2(0, 0);
		}
		static Vector2 one() {
			return Vector2(1, 1);
		}
		static Vector2 up() {
			return Vector2(0, 1);
		}
		static Vector2 right() {
			return Vector2(1, 0);
		}

		Vector2() {}
		Vector2(T t_x, T t_y) :
			x(t_x), 
			y(t_y) {}
		Vector2(const Vector2& T) :
			x(T.x),
			y(T.y) {}
		~Vector2() {}

		Vector2& operator= (const Vector2& T) {
			x = T.x;
			y = T.y;
		}

		Vector2 sum(const Vector2& t_v) {
			return Vector2(x + t_v.x, y + t_v.y);
		}
		Vector2 operator+ (const Vector2& t_v) {
			return Vector2(x + t_v.x, y + t_v.y);
		}
		void operator+= (const Vector2& t_v) {
			x += t_v.x;
			y += t_v.y;
		}

		Vector2 minus(const Vector2& t_v) {
			return Vector2(x - t_v.x, y - t_v.y);
		}
		Vector2 operator- (const Vector2& t_v) {
			return Vector2(x - t_v.x, y - t_v.y);
		}
		void operator-= (const Vector2& t_v) {
			x -= t_v.x;
			y -= t_v.y;
		}

		Vector2 mul(const T& t_s) {
			return Vector2(x * t_s, y * t_s);
		}
		Vector2 operator* (const T& t_s) {
			return Vector2(x * t_s, y * t_s);
		}
		void operator*= (const T& t_s) {
			x *= t_s;
			y *= t_s;
		}

		Vector2 div(const T& t_s) {
			return Vector2(x / t_s, y / t_s);
		}
		Vector2 operator/ (const T& t_s) {
			return Vector2(x / t_s, y / t_s);
		}
		void operator/= (const T& t_s) {
			x /= t_s;
			y /= t_s;
		}

		T cross(const Vector2& t_v) {
			return x * t_v.y - y * t_v.x;
		}

		T dot(const Vector2& t_v) {
			return x * t_v.x + y * t_v.y;
		}

		float sqrMagnitude() {
			return static_cast<float>(x) * static_cast<float>(x) + static_cast<float>(y) * static_cast<float>(y);
		}

		float magnitude() {
			return std::sqrtf(sqrMagnitude());
		}

		Vector2<float> normalize() {
			float mag = magnitude();
			return Vector2<float>(x / mag, y / mag);
		}

		float angle() {
			return std::atanf(static_cast<float>(y) / static_cast<float>(x)) * RADIUS;
		}

		float btwAngle(const Vector2& t_v) {
			float dotProd = static_cast<float>(this->dot(t_v));
			float magV1 = this->sqrMagnitude();
			float magV2 = static_cast<float>(t_v.x) * static_cast<float>(t_v.x) + static_cast<float>(t_v.y) * static_cast<float>(t_v.y);
			return std::acosf(dotProd / std::sqrtf(magV1 * magV2)) * RADIUS;
		}

		bool operator== (const Vector2& t_v) {
			return x == t_v.x && y == t_v.y;
		}
		bool operator!= (const Vector2& t_v) {
			return x != t_v.x || y != t_v.y;
		}

		std::string toString() {
			return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
		}
	};

	template <class T> Vector2<T> operator* (const T& t_s, const Vector2<T>& t_v) {
		return Vector2<T>(t_s * t_v.x, t_s * t_v.y);
	}

	template <class T> std::ostream& operator<< (std::ostream& os, const Vector2<T>& t_v) {
		os << "(" << t_v.x << ", " << t_v.y << ")";
		return os;
	}

	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
}