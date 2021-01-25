#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "Battleship.h"

void ShowExampleBoard()
{
	std::cout << "Zaidimo lentos pavyzdys:" << std::endl;
	std::cout << '\n';
	std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i;
		for (int j = 0; j < 10; j++)
		{
			std::cout << " " << "-";
			if (j == 9)
			{
				std::cout << std::endl;
			}
		}
	}
	std::cout << '\n';
}

int main()
{
	srand(unsigned int(time(NULL)));

	std::cout << "Battleships game by Povilas Lajus" << std::endl;
	std::cout << '\n';
	std::cout << "Taisykles: Jus turite 5 laivus - Carrier (uzima 5 lang.), Battleship (4 lang.), Cruiser (3 lang.), Submarine (3 lang.), Destroyer(2 lang.)" << std::endl;
	std::cout << '\n';
	std::cout << "Laivai yra deliojami ivedant pradzios koordinates ir galo koordinates. Pozicija gali buti horizontali arba vertikali (istrizai deti negalima). Laivai negali buti uzdeti vienas ant kito." << std::endl;
	std::cout << "Atakuojama ivedus norimo sprogdinti langelio koordinates. Pataikius i prieso laiva, galima eiti dar karta. Laimi zaidejas, kuris pirmas sunaikina visus priesininko laivus." << std::endl;
	std::cout << '\n';

	ShowExampleBoard();

	Player playerplay;
	playerplay.SetPlayerShips();
	Bot botplay;
	botplay.SetBotShips();

	Gameplay gameplayob(playerplay, botplay);
	gameplayob.LetsPlay();
}