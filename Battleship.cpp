#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "Battleship.h"

void Player::SetPlayerShips()
{
	std::cout << "Ivedimo tvarka: 1 laivas = Carrier (5 ilgio), 2 = Battleship (4 ilgio), 3 = Cruiser (3 ilgio), 4 = Submarine (3 ilgio), 5 = Destroyer (2 ilgio)" << std::endl;
	int k = 0;
	while (k < 5)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		std::cout << "Iveskite pradzios koordinates (pvz.: 1 3): ";
		std::cin >> x1 >> y1;
		if (x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9)
		{
			std::cout << "Klaida! Iseinate is lentos ribu." << std::endl;
			continue;
		}
		std::cout << "Iveskite pabaigos koordinates (pvz.: 1 6) : ";
		std::cin >> x2 >> y2;
		if (x2 < 0 || x2 > 9 || y2 < 0 || y2 > 9)
		{
			std::cout << "Klaida! Iseinate is lentos ribu." << std::endl;
			continue;
		}
		if (x1 != x2 && y1 != y2)
		{
			std::cout << "Klaida! Negalimos koordinates." << std::endl;
			continue;
		}
		if (k == 0)
		{	//Patikrinimas 5 langeliu ilgio
			if (x1 == x2 && abs(y2 - y1) != 4)
			{
				std::cout << "Klaida! Laivas turi uzimti 5 langelius." << std::endl;
				continue;
			}
			if (abs(x2 - x1) != 4 && y1 == y2)
			{
				std::cout << "Klaida! Laivas turi uzimti 5 langelius." << std::endl;
				continue;
			}
			SetShipLocation(x1, y1, x2, y2, k);
			Ships[k].length = 5;
			std::cout << "1 laivo koordinates issaugotos" << std::endl;
		}
		if (k == 1)
		{
			if (x1 == x2 && abs(y2 - y1) != 3)
			{
				std::cout << "Klaida! Laivas turi uzimti 4 langelius." << std::endl;
				continue;
			}
			if (abs(x2 - x1) != 3 && y1 == y2)
			{
				std::cout << "Klaida! Laivas turi uzimti 4 langelius." << std::endl;
				continue;
			}
			CalculateFullCoords(x1, y1, x2, y2);
			if (IsLocationFree(k))
			{
				SetShipLocation(x1, y1, x2, y2, k);
				Ships[k].length = 4;
				std::cout << "2 laivo koordinates issaugotos" << std::endl;
			}
			else
			{
				std::cout << "Koordinates jau uzimtos." << std::endl;
				continue;
			}
		}
		if (k == 2 || k == 3)
		{
			if (x1 == x2 && abs(y2 - y1) != 2)
			{
				std::cout << "Klaida! Laivas turi uzimti 3 langelius." << std::endl;
				continue;
			}
			if (abs(x2 - x1) != 2 && y1 == y2)
			{
				std::cout << "Klaida! Laivas turi uzimti 3 langelius." << std::endl;
				continue;
			}
			CalculateFullCoords(x1, y1, x2, y2);
			if (IsLocationFree(k))
			{
				SetShipLocation(x1, y1, x2, y2, k);
				Ships[k].length = 3;
				if (k == 2) std::cout << "3 laivo koordinates issaugotos" << std::endl;
				else   std::cout << "4 laivo koordinates issaugotos" << std::endl;
			}
			else
			{
				std::cout << "Koordinates jau uzimtos." << std::endl;
				continue;
			}
		}
		if (k == 4)
		{
			if (x1 == x2 && abs(y2 - y1) != 1)
			{
				std::cout << "Klaida! Laivas turi uzimti 2 langelius." << std::endl;
				continue;
			}
			if (abs(x2 - x1) != 1 && y1 == y2)
			{
				std::cout << "Klaida! Laivas turi uzimti 2 langelius." << std::endl;
				continue;
			}
			CalculateFullCoords(x1, y1, x2, y2);
			if (IsLocationFree(k))
			{
				SetShipLocation(x1, y1, x2, y2, k);
				Ships[k].length = 2;
				std::cout << "5 laivo koordinates issaugotos" << std::endl;
			}
			else
			{
				std::cout << "Koordinates jau uzimtos." << std::endl;
				continue;
			}
		}
		k++;
	}
}

void Base_User::SetShipLocation(int x1, int y1, int x2, int y2, int k)
{
	if (x1 == x2) //laivas horizontalus
	{
		if (y2 > y1)
		{
			while (y2 >= y1)
			{
				if (k == 0)
					matrix[x1][y2] = 1;
				if (k == 1)
					matrix[x1][y2] = 2;
				if (k == 2)
					matrix[x1][y2] = 3;
				if (k == 3)
					matrix[x1][y2] = 4;
				if (k == 4)
					matrix[x1][y2] = 5;
				Ships[k].FullCoord.push_back(std::make_pair(x1, y2));
				--y2;
			}
		}
		else if (y2 < y1)
		{
			while (y1 >= y2)
			{
				if (k == 0)
					matrix[x1][y1] = 1;
				if (k == 1)
					matrix[x1][y1] = 2;
				if (k == 2)
					matrix[x1][y1] = 3;
				if (k == 3)
					matrix[x1][y1] = 4;
				if (k == 4)
					matrix[x1][y1] = 5;
				Ships[k].FullCoord.push_back(std::make_pair(x1, y1));
				--y1;
			}
		}
	}
	else if (y1 == y2) //laivas vertikalus
	{
		if (x2 > x1)
		{
			while (x2 >= x1)
			{
				if (k == 0)
					matrix[x2][y1] = 1;
				if (k == 1)
					matrix[x2][y1] = 2;
				if (k == 2)
					matrix[x2][y1] = 3;
				if (k == 3)
					matrix[x2][y1] = 4;
				if (k == 4)
					matrix[x2][y1] = 5;
				Ships[k].FullCoord.push_back(std::make_pair(x2, y1));
				--x2;
			}
		}
		else if (x2 < x1)
		{
			while (x1 >= x2)
			{
				if (k == 0)
					matrix[x1][y1] = 1;
				if (k == 1)
					matrix[x1][y1] = 2;
				if (k == 2)
					matrix[x1][y1] = 3;
				if (k == 3)
					matrix[x1][y1] = 4;
				if (k == 4)
					matrix[x1][y1] = 5;
				Ships[k].FullCoord.push_back(std::make_pair(x1, y1));
				--x1;
			}
		}
	}
}

void Base_User::CalculateFullCoords(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)  //laivas horizontalus
	{
		if (y2 > y1)
		{
			while (y2 >= y1)
			{
				TempCoords.push_back(std::make_pair(x1, y2));
				--y2;
			}
		}
		else if (y2 < y1)
		{
			while (y1 >= y2)
			{
				TempCoords.push_back(std::make_pair(x1, y1));
				--y1;
			}
		}
	}
	else if (y1 == y2)  //laivas vertikalus
	{
		if (x2 > x1)
		{
			while (x2 >= x1)
			{
				TempCoords.push_back(std::make_pair(x2, y1));
				--x2;
			}
		}
		else if (x2 < x1)
		{
			while (x1 >= x2)
			{
				TempCoords.push_back(std::make_pair(x1, y1));
				--x1;
			}
		}
	}
}

bool Base_User::IsLocationFree(int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < Ships[i].FullCoord.size(); j++)
		{
			for (int h = 0; h < TempCoords.size(); h++)
			{
				if (Ships[i].FullCoord[j].first == TempCoords[h].first && Ships[i].FullCoord[j].second == TempCoords[h].second)
				{
					TempCoords.clear();
					return false;
				}
			}
		}
	}
	TempCoords.clear();
	return true;
}

void Bot::SetBotShips()
{
	int k = 0;
	int laivoilgis = 4;
	while (k < 5)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		x1 = rand() % 10;
		y1 = rand() % 10;
		int x1ory1[2] = { x1,y1 }; // random pasirinkimas kuri koordinate islieka, tai nulemia ar laivas bus padetas vertikaliai ar horizontaliai
		int oneortwo = rand() % (2);
		if (x1ory1[oneortwo] == x1) // laivas padetas horizontaliai
		{
			x2 = x1;
			if (y1 + laivoilgis <= 9 && y1 - laivoilgis >= 0)  // tikrinimai ar pozicija pakankamai plati, kad galetume rinktis is 2 galines koordinates variantu
			{
				int biggersmaller[2] = { y1 + laivoilgis, y1 - laivoilgis };
				oneortwo = rand() % (2);
				y2 = biggersmaller[oneortwo];
			}
			else if (y1 - laivoilgis < 0)
			{
				y2 = y1 + laivoilgis;
			}
			else if (y1 + laivoilgis > 9)
			{
				y2 = y1 - laivoilgis;
			}
		}
		else if (x1ory1[oneortwo] == y1) // laivas padetas vertikaliai
		{
			y2 = y1;
			if (x1 + laivoilgis <= 9 && x1 - laivoilgis >= 0)
			{
				int biggersmaller[2] = { x1 + laivoilgis, x1 - laivoilgis };
				oneortwo = rand() % (2);
				x2 = biggersmaller[oneortwo];
			}
			else if (x1 - laivoilgis < 0)
			{
				x2 = x1 + laivoilgis;
			}
			else if (x1 + laivoilgis > 9)
			{
				x2 = x1 - laivoilgis;
			}
		}
		if (k == 0)
		{
			SetShipLocation(x1, y1, x2, y2, k);
			Ships[k].length = 5;
		}
		else
		{
			CalculateFullCoords(x1, y1, x2, y2);
			if (IsLocationFree(k))
			{
				SetShipLocation(x1, y1, x2, y2, k);
				Ships[k].length = laivoilgis + 1;
			}
			else continue;
		}
		k++;
		if (k != 3)
			--laivoilgis;
	}
}

void Gameplay::PlayerMove()
{
	int attackx = 0, attacky = 0;

	std::cout << "Iveskite koordinates, kurias norite sprogdinti: " << std::endl;
	std::cin >> attackx >> attacky;
	if (attackx < 0 || attackx > 9 || attacky < 0 || attacky > 9)
	{
		std::cout << "Negalimos koordinates!" << std::endl;
		PlayerMove();
	}
	if (botob.matrix[attackx][attacky] == 8 || botob.matrix[attackx][attacky] == 9)
	{
		std::cout << "I sia vieta jau sovete." << std::endl;
		PlayerMove();
	}
	if (DidPlayerHit(attackx, attacky))
	{
		std::cout << "Hit!" << std::endl;

		if (botob.matrix[attackx][attacky] == 1)
		{
			++botob.Ships[0].hit;
			if (botob.Ships[0].hit == botob.Ships[0].length)
			{
				std::cout << "Sunaikinote prieso Carrier!" << std::endl;
				++botdestroyed;
			}
		}
		if (botob.matrix[attackx][attacky] == 2)
		{
			++botob.Ships[1].hit;
			if (botob.Ships[1].hit == botob.Ships[1].length)
			{
				std::cout << "Sunaikinote prieso Battleship!" << std::endl;
				++botdestroyed;
			}
		}
		if (botob.matrix[attackx][attacky] == 3)
		{
			++botob.Ships[2].hit;
			if (botob.Ships[2].hit == botob.Ships[2].length)
			{
				std::cout << "Sunaikinote prieso Cruiser!" << std::endl;
				++botdestroyed;
			}
		}
		if (botob.matrix[attackx][attacky] == 4)
		{
			++botob.Ships[3].hit;
			if (botob.Ships[3].hit == botob.Ships[3].length)
			{
				std::cout << "Sunaikinote prieso Submarine!" << std::endl;
				++botdestroyed;
			}
		}
		if (botob.matrix[attackx][attacky] == 5)
		{
			++botob.Ships[4].hit;
			if (botob.Ships[4].hit == botob.Ships[4].length)
			{
				std::cout << "Sunaikinote prieso Destroyer!" << std::endl;
				++botdestroyed;
			}
		}
		botob.matrix[attackx][attacky] = 8;
		visablebotmatrix[attackx][attacky] = 8;

		std::cout << '\n';
		ShowBotBoard();

		PlayerMove();
	}
	else if (!DidPlayerHit(attackx, attacky))
	{
		std::cout << "Miss!" << std::endl;
		botob.matrix[attackx][attacky] = 9;
		visablebotmatrix[attackx][attacky] = 9;

		std::cout << '\n';
		ShowBotBoard();
	}

}

void Gameplay::BotMove()
{
	if (hits == 0)	//nera pataikymo arba laivas buvo sunaikintats
	{
		do
		{
			attackx = rand() % 10;
			attacky = rand() % 10;
		} while (playerob.matrix[attackx][attacky] == 8 || playerob.matrix[attackx][attacky] == 9);
	}
	else	//yra pataikymas
	{
		attackx = LastHitCoords.first;
		attacky = LastHitCoords.second;

		if (attacky == 9)
		{
			desinyskrastas = true;
		}

		if (attacky == 0)
		{
			kairyskrastas = true;
		}

		if (attackx == 0)
		{
			stogas = true;
		}

		if (attackx == 9)
		{
			grindys = true;
		}

		if (misses == 0 && !desinyskrastas)		//ejimas i desine
		{
			attacky++;
		}
		else if ((misses == 1 && !kairyskrastas) || (desinyskrastas && misses == 0))	//ejimas i kaire
		{
			while (playerob.matrix[attackx][attacky] == 8)
			{
				attacky--;
			}
		}
		else if ((misses == 2 || (misses == 1 && (desinyskrastas || kairyskrastas))) && !grindys)	//ejimas i apacia
		{
			while (playerob.matrix[attackx][attacky] == 8)
			{
				attackx++;
			}
		}
		else	//ejimas i virsu
		{
			while (playerob.matrix[attackx][attacky] == 8)
			{
				attackx--;
			}
		}

	}

	if (DidBotHit(attackx, attacky))
	{
		LastHitCoords.first = attackx;
		LastHitCoords.second = attacky;
		hits++;

		if (playerob.matrix[attackx][attacky] == 1)
		{
			++playerob.Ships[0].hit;
			if (playerob.Ships[0].hit == playerob.Ships[0].length)
			{
				++playerdestroyed;
				hits = 0;
				misses = 0;
				desinyskrastas = false;
				kairyskrastas = false;
				stogas = false;
				grindys = false;
			}
		}
		if (playerob.matrix[attackx][attacky] == 2)
		{
			++playerob.Ships[1].hit;
			if (playerob.Ships[1].hit == playerob.Ships[1].length)
			{
				++playerdestroyed;
				hits = 0;
				misses = 0;
				desinyskrastas = false;
				kairyskrastas = false;
				stogas = false;
				grindys = false;
			}
		}
		if (playerob.matrix[attackx][attacky] == 3)
		{
			++playerob.Ships[2].hit;
			if (playerob.Ships[2].hit == playerob.Ships[2].length)
			{
				++playerdestroyed;
				hits = 0;
				misses = 0;
				desinyskrastas = false;
				kairyskrastas = false;
				stogas = false;
				grindys = false;
			}
		}
		if (playerob.matrix[attackx][attacky] == 4)
		{
			++playerob.Ships[3].hit;
			if (playerob.Ships[3].hit == playerob.Ships[3].length)
			{
				++playerdestroyed;
				hits = 0;
				misses = 0;
				desinyskrastas = false;
				kairyskrastas = false;
				stogas = false;
				grindys = false;
			}
		}
		if (playerob.matrix[attackx][attacky] == 5)
		{
			++playerob.Ships[4].hit;
			if (playerob.Ships[4].hit == playerob.Ships[4].length)
			{
				++playerdestroyed;
				hits = 0;
				misses = 0;
				desinyskrastas = false;
				kairyskrastas = false;
				stogas = false;
				grindys = false;
			}
		}
		playerob.matrix[attackx][attacky] = 8;

		std::cout << '\n';
		ShowPlayerBoard();

		BotMove();
	}
	else if (!DidBotHit(attackx, attacky))
	{
		if (playerob.matrix[attackx][attacky] == 9)
		{
			misses++;
			BotMove();
		}

		if (playerob.matrix[attackx][attacky] == 0)
		{
			playerob.matrix[attackx][attacky] = 9;

			if (hits != 0)
			{
				misses++;
			}
		}

		std::cout << '\n';
		ShowPlayerBoard();
	}

}

bool Gameplay::DidPlayerHit(int attackx, int attacky)
{
	if (botob.matrix[attackx][attacky] != 0 && botob.matrix[attackx][attacky] != 8 && botob.matrix[attackx][attacky] != 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gameplay::DidBotHit(int attackx, int attacky)
{
	if (playerob.matrix[attackx][attacky] != 0 && playerob.matrix[attackx][attacky] != 8 && playerob.matrix[attackx][attacky] != 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Gameplay::ShowBotBoard()
{
	std::cout << "Priesininko lenta:" << std::endl;
	std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i;
		for (int j = 0; j < 10; j++)
		{
			if (botob.matrix[i][j] == 8)
			{
				std::cout << " " << "#";
			}
			else if (botob.matrix[i][j] == 9)
			{
				std::cout << " " << "x";
			}
			else
			{
				std::cout << " " << "-";
			}
			if (j == 9)
			{
				std::cout << std::endl;
			}
		}
	}
}

void Gameplay::ShowPlayerBoard()
{
	std::cout << "Jusu lenta:" << std::endl;
	std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i;
		for (int j = 0; j < 10; j++)
		{
			if (playerob.matrix[i][j] == 0)
			{
				std::cout << " " << "-";
			}
			else if (playerob.matrix[i][j] == 8) 
			{
				std::cout << " " << "#";
			}
			else if (playerob.matrix[i][j] == 9)
			{
				std::cout << " " << "x";
			}
			else
			{
				std::cout << " " << playerob.matrix[i][j];
			}
			if (j == 9)
			{
				std::cout << std::endl;
			}
		}
	}
}

void Gameplay::LetsPlay()
{
	int prades;
	prades = rand() % (2);

	while (playerdestroyed != 5 && botdestroyed != 5)
	{
		switch (prades)
		{
		case 0:
			PlayerMove();
			BotMove();
			break;
		case 1:
			BotMove();
			PlayerMove();
			break;
		}
	}
	if (botdestroyed == 5)
		std::cout << "Jus laimejote!!" << std::endl;
	else std::cout << "Kompiuteris laimejo. Better luck next time!" << std::endl;
}