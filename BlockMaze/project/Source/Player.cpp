#include "Player.h"
#include "config.h"
#include "Stage.h"

Player::Player()
{
	hImage = LoadGraph("data/image/chara.png");
	position.x = 0;
	position.y = 0;
	speed.x = 0.0;
	speed.y = 0.0f;
}

Player::~Player()
{
}

void Player::Update()
{
	Stage* s = FindGameObject<Stage>();

	if (CheckHitKey(KEY_INPUT_D)) {
		speed.x += 0.1f;
		if (speed.x > 2.0f) {
			speed.x = 2.0f;
		}
		int push = s->IsWallRight(position + VECTOR2(39, 0));
		position.x -= push;
		 push = s->IsWallRight(position + VECTOR2(39, 39));
		position.x -= push;
	}
	else if (CheckHitKey(KEY_INPUT_A)) {
		speed.x -= 0.1f;
		if (speed.x < -2.0f) {
			speed.x = -2.0f;
		}
		int push = s->IsWallLeft(position + VECTOR2(0, 0));
		position.x -= push;
		push = s->IsWallLeft(position + VECTOR2(0, 39));
		position.x += push;
	}
	else {
		if (speed.x >= 0.1f) {
			speed.x -= 0.1f;
		}
		else if (speed.x <= -0.1f) {
			speed.x += 0.1f;
		}
		else {
			speed.x = 0.0f;
		}
	}
	position.x += speed.x;
	if (position.x < 0) {
		position.x = 0;
	}
	if (position.x > SCREEN_WIDTH - 64) {
		position.x = SCREEN_WIDTH - 64;
	}

	if (CheckHitKey(KEY_INPUT_W)) {
		speed.y -= 0.1f;
		if (speed.y < -2.0f) {
			speed.y = -2.0f;
		}
		int push = s->IsWallUp(position + VECTOR2(0, 0));
		position.y += push;
		push = s->IsWallUp(position + VECTOR2(39, 0));
		position.y += push;
	}
	else if (CheckHitKey(KEY_INPUT_S)) {
		speed.y += 0.1f;
		if (speed.y > 2.0f) {
			speed.y = 2.0f;
		}
		int push = s->IsWallDown(position + VECTOR2(39, 0));
		position.y -= push;
		 push = s->IsWallDown(position + VECTOR2(39, 39));
		position.y -= push;
	}
	else {
		if (speed.y >= 0.1f) {
			speed.y -= 0.1f;
		}
		else if (speed.y <= -0.1f) {
			speed.y += 0.1f;
		}
		else {
			speed.y = 0.0f;
		}
	}
	position.y += speed.y;
	if (position.y < 0) {
		position.y = 0;
	}	
}

void Player::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 40, 40, hImage, TRUE);
}
