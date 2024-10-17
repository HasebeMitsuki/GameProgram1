#include "Stage.h"
#include "Player.h"

const int WIDTH = 12;
const int HEIGHT = 8;
const int CHIP_SIZE = 40;
int map[HEIGHT][WIDTH] = {
	{1,1,1,1,1,0,0,1,1,0,0,1},
	{1,1,1,1,1,0,0,1,1,0,0,1},
	{1,2,0,0,0,0,0,1,1,0,0,1},
	{1,0,0,0,0,0,9,0,1,0,0,1},
	{1,0,0,1,1,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,1,1,1,0,0,1},
	{1,0,0,0,0,0,1,1,1,0,0,1},
	{1,1,1,1,0,0,1,1,1,0,0,1},
};

Stage::Stage()
{
	hImage = LoadGraph("data/image/parts.png");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (map[i][j] == 9) {
				Player* p = Instantiate<Player>();
				p->position.x = j * CHIP_SIZE + 100;
				p->position.y = i * CHIP_SIZE + 100;
			}

		}
	}
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	for (int i = 0; i < HEIGHT; i++){
		int y = i * CHIP_SIZE + 100;
		for (int j = 0; j < WIDTH; j++) {
			int x = j * CHIP_SIZE + 100;
			if (map[i][j] == 1) {
				DrawRectGraph(x, y, 0, 40, 40, 40, hImage, TRUE);
			}
			if (map[i][j] == 2) {
				DrawRectGraph(x, y, 120, 0, 40, 40, hImage, TRUE);
			}
		}
	}
}

int Stage::IsWallRight(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = ((int)pos.x - 100) % 40 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallDown(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = ((int)pos.y - 100) % 40 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallLeft(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = 40 - ((int)pos.x - 100) % 40;
		return push;
	}
	return 0;
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1) {
		int push = 40 - ((int)pos.y - 100) % 40;
		return push;
	}
	return 0;
}

