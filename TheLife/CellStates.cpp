#include "stdafx.h"
#include "CellStates.h"


std::unordered_map<CellState, std::string> g_renderChars =
{
	{ state_none, " " },
	{ state_new, " " },
	{ state_stable, "o" },
	{ state_dead, "o" },
};
