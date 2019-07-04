// VectorClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Math/Vector2.hpp"

#define CATCH_CONFIG_MAIN
#include "Thirdparty/catch2/catch.hpp"

using namespace cw;

TEST_CASE("It must passed", "[vector]") {
	REQUIRE(true);
}

TEST_CASE("It should initialize correctly", "[vector]") {
	Vector2i vi(1, 1);
	REQUIRE(vi.x == 1);
	REQUIRE(vi.y == 1);
	Vector2f vf(1.1f, 1.1f);
	REQUIRE(vf.x == 1.1f);
	REQUIRE(vf.y == 1.1f);
	Vector2d vd(1.2, 1.2);
	REQUIRE(vd.x == 1.2);
	REQUIRE(vd.y == 1.2);
}

TEST_CASE("It can sum with a vector correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	auto result = v1.sum(v2);
	REQUIRE(result.x == 3);
	REQUIRE(result.y == 3);
}

TEST_CASE("It can sum with a vector with + correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	auto result = v1 + v2;
	REQUIRE(result.x == 3);
	REQUIRE(result.y == 3);
}

TEST_CASE("It can sum with a vector with += correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	v1 += v2;
	REQUIRE(v1.x == 3);
	REQUIRE(v1.y == 3);
}

TEST_CASE("It can minus with a vector correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	auto result = v1.minus(v2);
	REQUIRE(result.x == -1);
	REQUIRE(result.y == -1);
}

TEST_CASE("It can minus with a vector with - correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	auto result = v1 - v2;
	REQUIRE(result.x == -1);
	REQUIRE(result.y == -1);
}

TEST_CASE("It can minus with a vector with -= correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	v1 -= v2;
	REQUIRE(v1.x == -1);
	REQUIRE(v1.y == -1);
}

TEST_CASE("It can multiply with a scalar correctly", "[vector]") {
	Vector2i v(1, 1);
	auto result = v.mul(3);
	REQUIRE(result.x == 3);
	REQUIRE(result.y == 3);
}

TEST_CASE("It can multiply with a scalar with * correctly", "[vector]") {
	Vector2i v(1, 1);
	auto result = v * 3;
	REQUIRE(result.x == 3);
	REQUIRE(result.y == 3);
}

TEST_CASE("It can multiply with a scalar with *= correctly", "[vector]") {
	Vector2i v(1, 1);
	v *= 3;
	REQUIRE(v.x == 3);
	REQUIRE(v.y == 3);
}

TEST_CASE("It can multiply with a scalar with * before vector correctly", "[vector]") {
	Vector2i v(1, 1);
	auto result = 5 * v;
	REQUIRE(result.x == 5);
	REQUIRE(result.y == 5);
}

TEST_CASE("It can divide with a scalar correctly", "[vector]") {
	Vector2i v(2, 2);
	auto result = v.div(2);
	REQUIRE(result.x == 1);
	REQUIRE(result.y == 1);
}

TEST_CASE("It can divide with a scalar with / correctly", "[vector]") {
	Vector2i v(2, 2);
	auto result = v / 2;
	REQUIRE(result.x == 1);
	REQUIRE(result.y == 1);
}

TEST_CASE("It can divide with a scalar with /= correctly", "[vector]") {
	Vector2i v(2, 2);
	v /= 2;
	REQUIRE(v.x == 1);
	REQUIRE(v.y == 1);
}

TEST_CASE("It can cross product with a vector correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	auto result = v1.cross(v2);
	REQUIRE(result == 0);
}

TEST_CASE("It can dot product with a vector correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	auto result = v1.dot(v2);
	REQUIRE(result == 4);
}

TEST_CASE("It can call vector one, zero and up correctly", "[vector]") {
	REQUIRE(Vector2<int>::one().x == 1);
	REQUIRE(Vector2<int>::one().y == 1);
	REQUIRE(Vector2<int>::zero().x == 0);
	REQUIRE(Vector2<int>::zero().y == 0);
	REQUIRE(Vector2<int>::up().x == 0);
	REQUIRE(Vector2<int>::up().y == 1);
}

TEST_CASE("It can return degree of vector correctly", "[vector]") {
	Vector2i v(1, 1);
	REQUIRE(v.angle() == 45.0f);
}

TEST_CASE("It can return magnitude and square magnitude of vector correctly", "[vector]") {
	Vector2i v(1, 1);
	REQUIRE(v.magnitude() == std::sqrtf(2.0f));
	REQUIRE(v.sqrMagnitude() == 2.0f);
}

TEST_CASE("It can normalizing vector correctly", "[vector]") {
	Vector2i v(1, 1);
	auto result = v.normalize();
	REQUIRE(result.x == 1.0f / std::sqrtf(2.0f));
	REQUIRE(result.y == 1.0f / std::sqrtf(2.0f));
}

TEST_CASE("It can return angle between two-vectors correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	float result = v1.btwAngle(v2);
	REQUIRE(result == 0.0f);
}

TEST_CASE("It can compare between two-vectors correctly", "[vector]") {
	Vector2i v1(1, 1);
	Vector2i v2(2, 2);
	REQUIRE((v1 == v2) == false);
	REQUIRE((v1 != v2) == true);
}

TEST_CASE("It can print out vector correctly", "[vector]") {
	Vector2i v(1, 1);
	REQUIRE(v.toString() == "(1, 1)");
	std::stringstream ss;
	ss << v;
	REQUIRE(ss.str() == "(1, 1)");
}

/*int main()
{
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
