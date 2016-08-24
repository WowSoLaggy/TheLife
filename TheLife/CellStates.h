#pragma once

#ifndef CELLSTATES_H
#define CELLSTATES_H


enum CellState
{
	state_none = 0,
	state_new,
	state_stable,
	state_dead,

	state_end
};


extern std::unordered_map<CellState, std::string> g_renderChars;


#endif // CELLSTATES_H
