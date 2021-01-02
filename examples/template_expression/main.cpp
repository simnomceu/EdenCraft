#include "utility/template_expression.hpp"
#include "utility/mathematics.hpp"

#include <iostream>

int main()
{
	ece::Vector<int, 3> a = { 1, 5, 3 };
	a *= 2;
	ece::Vector<float, 3> b = { 2.1f, 4.5f, 7.2f };
	ece::Vector<int, 3> c = 1;

	ece::Vector<int, 3> d = { 1, -1, 2 };
	d[d > 0 && d < 2] += 1;
	d[{0, 1}] *= 10;

	std::cout << "d: { ";
	for (unsigned int i = 0; i < d.size(); ++i) {
		std::cout << d[i] << " ";
	}
	std::cout << "}" << std::endl;

	auto && result = ece::abs(-(7 + a + 1 + ece::Vector<int, 3>{ 1, 1, 1 }  + b - ece::Vector<int, 3>(1)));
	auto resultBis = +a + c;

	std::cout << "result: { ";
	for (unsigned int i = 0; i < result.size(); ++i) {
		std::cout << result[i] << " ";
	}
	std::cout << "}" << std::endl;

	// ==============================

	ece::Matrix<int, 2, 2> matrix = { 0, 1, 2, 0 };
	ece::Matrix<int, 2, 3> rectMatrix = { 0, 1, 2, 3, 4, 5 };
	std::cout << rectMatrix[0][0] << " | " << rectMatrix[0][1] << " | " << rectMatrix[0][2] << std::endl << "---------" << std::endl << rectMatrix[1][0] << " | " << rectMatrix[1][1] << " | " << rectMatrix[1][2] << std::endl;
	ece::Matrix<float, 2, 2> matrixBis = { 2.1f, 4.5f, 7.2f, 5.7f };
//	matrix[matrix <= 0] += 5;
	auto && resultMat = ece::abs(-(7 + matrix + 1 + ece::Matrix<int, 2, 2>{ 1, 1, 1, 1 }  + matrixBis - ece::Matrix<int, 2, 2>(1)));

	std::cout << "resultMat: { ";
	for (unsigned int i = 0; i < resultMat.size(); ++i) {
		std::cout << resultMat[i] << " ";
	}
	std::cout << "}" << std::endl;

	// =============================
	ece::Matrix<int, 3, 3> first{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto second = ece::Matrix<float, 3, 3>::Identity();
	first *= second;

	std::cout << "identity: { ";
	for (unsigned int i = 0; i < first.size(); ++i) {
		std::cout << first.cell(i) << " ";
	}
	std::cout << "}" << std::endl;

	// =============================
	ece::Vector<float, 3> unit{ 1.0f, 1.0f, 1.0f };
	auto matvec = first * unit;

	std::cout << "identity: { ";
	for (unsigned int i = 0; i < matvec.size(); ++i) {
		std::cout << matvec[i] << " ";
	}
	std::cout << "}" << std::endl;

	// =============================

	const auto pos = ece::Vector<float, 3>{ 4.0f, 5.0f, 6.0f } / 2.0f;
	const auto center = ece::Vector<float, 3>{ 1.0f, 7.0f, 3.0f };
	const auto ratio = 2.0f;
	const auto newPos = ((pos - center) * ratio) + center;
	std::cout << "New position: {" << newPos[0] << " " << newPos[1] << " " << newPos[2] << "}" << std::endl;
	
	const auto secondNewPos = (pos + center) * 3.0f;
	std::cout << "Second New position: {" << secondNewPos[0] << " " << secondNewPos[1] << " " << secondNewPos[2] << "}" << std::endl;

	// =============================

	const auto box = ece::Box3D<float>({2.0f, 5.0f, 3.0f}, {7.0, 18.0f, -11.0f});
	auto centerBox = box.getCenter();
	std::cerr << "Center: " << centerBox[0] << " " << centerBox[1] << " " << centerBox[2] << std::endl;

	return EXIT_SUCCESS;
}