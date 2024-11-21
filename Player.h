#pragma once
class Player
{
public:
	int x, y;
	int bomb;
	Player();
	void draw(CPaintDC* dc);
	void draw(CClientDC* dc);
};

