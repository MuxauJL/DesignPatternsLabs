#include "stdafx.h"
#include "VectorNormal.h"


VectorNormal::VectorNormal(int size)
{
	values = std::vector<double>(size);
}

VectorNormal::~VectorNormal()
{
}

int VectorNormal::getSize() {
	return values.size();
}

double VectorNormal::get(int pos) {
	return values.at(pos);
}

void VectorNormal::set(int pos, double value) {
	values.at(pos) = value;
}

void VectorNormal::iterate(std::function<void(int)>iterator) {
	for (int j = 0; j < getSize(); ++j)
		iterator(j);
}