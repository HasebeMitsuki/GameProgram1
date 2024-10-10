#include "Stage.h"

const int WIDTH = 12;
const int HEIGHT = 8;
const int CHIP_SIZE = 40;
int map[HEIGHT][WIDTH] = {
	{1,1,1,1,1,0,0,1,1,0,0,1},
	{1,1,1,1,1,0,0,1,1,0,0,1},
	{1,2,0,0,0,0,0,1,1,0,0,1},
	{1,0,0,0,0,0,0,1,1,0,0,1},
	{1,0,0,1,1,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,1,1,1,0,0,1},
	{1,0,0,0,0,0,1,1,1,0,0,1},
	{1,1,1,1,0,0,1,1,1,0,0,1},
};

Stage::Stage()
{
	hImage = LoadGraph("data/image/parts.png");
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
