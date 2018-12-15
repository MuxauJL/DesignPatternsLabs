#include "stdafx.h"
#include "CM.h"
#include "Init.h"

CM::CM():commands(std::vector<ACommand*>()) {
	lock = false;
}

CM::~CM() {
	for (ACommand* cmd : commands)
		delete cmd;
}

void CM::registry(ACommand* c) {
	if (lock)
		return;
	else {
		commands.push_back(c);
	}
}

void CM::undo() {
	if (commands.size() > 1) {
		commands.pop_back();
		lock = true;
		for (ACommand* cmd : commands)
			cmd->execute();
		lock = false;
	}
}
