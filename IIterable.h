#pragma once
#include <functional>

class IIterable {
public:
	virtual void iterate(std::function<void(int, int, double)>) = 0;
};