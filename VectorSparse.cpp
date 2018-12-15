#include "stdafx.h"
#include "VectorSparse.h"


VectorSparse::VectorSparse(int size)
{
	length = size;
}

VectorSparse::~VectorSparse()
{
}

int VectorSparse::getSize() {
	return length;
}

double VectorSparse::get(int pos) {
	if (pos > getSize() || pos < 0)
		return values.at(pos);
	auto it = values.find(pos);
	if (it != values.end())
		return values[pos];
	else return 0;
}

void VectorSparse::set(int pos, double value) {
	if (value == 0) return;
	if (pos >= 0 && pos < length)
		values[pos] = value;
	else
		values.at(pos);
}

void VectorSparse::iterate(std::function<void(int)>iterator) {
	for (auto it = values.begin(); it != values.end(); ++it)
		iterator(it->first);
}