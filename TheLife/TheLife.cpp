#include "stdafx.h"
#include "TheLife.h"


int TheLife::Run()
{
	m_map.resize(m_mapWidth * m_mapHeight, state_none);
	m_turn = 0;
	GenerateStartingPopulation();

	while (true)
	{
		++m_turn;
		DrawMap();

		char key = (char)_getch();

		if (key == 'q')
			break;

		MakeTurn();
	}

	return 0;
}


void TheLife::GenerateStartingPopulation()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 150; ++i)
	{
		int x = rand() % m_mapWidth / 2 + m_mapWidth / 4;
		int y = rand() % m_mapHeight / 2 + m_mapHeight / 4;
		m_map[x + y * m_mapWidth] = state_new;
	}
}


void TheLife::MakeTurn()
{
	for (auto & cell : m_map)
	{
		if (cell == state_dead)
			cell = state_none;
		else if (cell == state_new)
			cell = state_stable;
	}

	int neighs;
	for (int y = 0; y < m_mapHeight; ++y)
	{
		for (int x = 0; x < m_mapWidth; ++x)
		{
			neighs = 0;
			neighs += IsLifeInt(x - 1, y - 1);
			neighs += IsLifeInt(x + 0, y - 1);
			neighs += IsLifeInt(x + 1, y - 1);

			neighs += IsLifeInt(x - 1, y + 0);
			neighs += IsLifeInt(x + 1, y + 0);

			neighs += IsLifeInt(x - 1, y + 1);
			neighs += IsLifeInt(x + 0, y + 1);
			neighs += IsLifeInt(x + 1, y + 1);

			if ((m_map[x + y * m_mapWidth] == state_stable) && (neighs < 2 || neighs > 3))
				m_map[x + y * m_mapWidth] = state_dead;
			else if ((m_map[x + y * m_mapWidth] == state_none) && (neighs == 3))
				m_map[x + y * m_mapWidth] = state_new;
		}
	}
}

void TheLife::DrawMap()
{
	// Header

	std::string str = "+- TURN: " + std::to_string(m_turn) + " ";
	str.resize(m_mapWidth + 1, '-');
	str += ("+");
	std::cout << str << std::endl;

	// Body

	for (int y = 0; y < m_mapHeight; ++y)
	{
		str = "|";
		for (int x = 0; x < m_mapWidth; ++x)
			str += g_renderChars[m_map[x + y * m_mapWidth]];
		str += "|";
		std::cout << str << std::endl;
	}

	// Footer

	str = "+";
	str.resize(m_mapWidth + 1, '-');
	str += ("+");
	std::cout << str << std::endl;
}


bool TheLife::IsLife(int x, int y)
{
	if (x < 0 || x >= m_mapWidth || y < 0 || y >= m_mapHeight)
		return false;
	
	return ((m_map[x + y * m_mapWidth] == state_stable) || (m_map[x + y * m_mapWidth] == state_dead));
}

int TheLife::IsLifeInt(int x, int y)
{
	return IsLife(x, y) ? 1 : 0;
}
