#include "Indexer.hpp"

using namespace core::cmp;

Indexer::Indexer()
{
}

Indexer::~Indexer()
{
}

bool Indexer::contains(const int keyIn) const
{
	return this->index.find(keyIn) != this->index.end();
}

std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> Indexer::get(const int keyIn)
{
	return this->index.equal_range(keyIn);
}

void Indexer::add(const int keyIn, const int valueIn)
{
	this->index.insert(std::pair<int, int>(keyIn, valueIn));
}

void Indexer::remove(const int keyIn)
{
	while (this->index.find(keyIn) != this->index.end()) {
		this->index.erase(keyIn);
	}
}

int Indexer::intersect(const std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator>& rightOperand, const int keyIn)
{
	auto resultRight = this->get(keyIn);
	auto itLeft = rightOperand.first;
	int result = -1;
	while ( itLeft != rightOperand.second && result == -1) {
		auto itRight = resultRight.first;
		while (itRight != rightOperand.second && result == -1) {
			if (itRight->second == itLeft->second) {
				result = itLeft->second;
			}
			++itRight;
		}
		++itLeft;
	}
	return result;
}
