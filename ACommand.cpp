#include "stdafx.h"
#include "ACommand.h"
#include "CM.h"

ACommand::ACommand()
{
}

ACommand::~ACommand()
{
}

void ACommand::execute()
{
	doExecute();
	CM::instance().registry(this->clone());
}


