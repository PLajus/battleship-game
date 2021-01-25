#ifndef __BATTLESHIP_H__
#define __BATTLESHIP_H__

#include <vector>

struct Ship
{
	std::vector<std::pair<int, int>> FullCoord; // pirmas sk - x koordinate, antras sk - y koordinate
	int length;
	int hit;
	Ship() : length(0), hit(0) {}
};

class Base_User
{
public:
	std::vector<Ship> Ships;
	int matrix[10][10];
	std::vector<std::pair<int, int>> TempCoords;

	Base_User() : matrix{ 0 }, Ships(5, (Ship())) {};

	void SetShipLocation(int x1, int y1, int x2, int y2, int k);

	void CalculateFullCoords(int x1, int y1, int x2, int y2); //is koordinaciu paziuret kokius langelius uzims laivas, naudosiu laisvos vietos patikrai

	bool IsLocationFree(int k); //patikrinu ar langeliai yra laisvi
};

class Player : public Base_User
{
public:
	void SetPlayerShips();
};

class Bot : public Base_User
{
public:
	void SetBotShips();
};

class Gameplay
{
private:
	int visablebotmatrix[10][10], playerdestroyed, botdestroyed, attackx, attacky, hits, misses;
	Player playerob;
	Bot botob;
	std::pair<int, int> LastHitCoords; //first = x, second = y

public:
	bool desinyskrastas = false;
	bool kairyskrastas = false;
	bool stogas = false;
	bool grindys = false;

	Gameplay(Player& obp, Bot& obb) : visablebotmatrix{ 0 }, playerdestroyed(0), botdestroyed(0), playerob(obp), botob(obb), attackx(0), attacky(0), hits(0), misses(0), LastHitCoords(-1, -1) {}

	void PlayerMove();

	void BotMove();

	bool DidPlayerHit(int attackx, int attacky);

	bool DidBotHit(int attackx, int attacky);

	void ShowBotBoard();

	void ShowPlayerBoard();

	void LetsPlay();
};

#endif