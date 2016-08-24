#pragma once

#ifndef THELIFE_H
#define THELIFE_H


#include "CellStates.h"


class TheLife
{
public:

	int Run();

private:

	const int m_mapWidth = 117;
	const int m_mapHeight = 27;
	std::vector<CellState> m_map;

	int m_turn;

	void GenerateStartingPopulation();

	void MakeTurn();
	void DrawMap();

	bool IsLife(int x, int y);
	int IsLifeInt(int x, int y);

};


#endif // THELIFE_H
