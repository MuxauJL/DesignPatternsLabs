#pragma once
#include <functional>
class IIterator {
public:
	virtual std::function<void(int, int, double)> getIterator() = 0;
};