#pragma once
#include <functional>
class IVector {
public:
	virtual ~IVector() {};
	virtual int getSize() = 0;
	virtual double get(int pos) = 0;
	virtual void set(int pos, double value) = 0;
	virtual void iterate(std::function<void(int)>iterator) = 0;
};