#pragma once
#include "ACommand.h"
#include <vector>

class CM
{
private:
	bool lock;
	std::vector<ACommand*> commands;
public:
	static CM& instance() {
		static CM cm;
		return cm;
	};
	void registry(ACommand* c);
	void undo();
private:
	CM();
	~CM();
	CM(const CM&) = default;
	CM& operator=(const CM&) = default;
};

