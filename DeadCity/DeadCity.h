#pragma once
#include "Game.h"
#include "GameField.h"
#include "Canvas.h"
#include "Figure.h"

class DeadCity : public Game
{
public:
	DeadCity();

	void OnKeyPressed(int btnCode) override;
	void Update(double dt) override;
	bool End() override;

private:
	GameField m_GameField;
	Canvas m_Canvas;
	Figure m_Figure;
	bool m_End = false;
};