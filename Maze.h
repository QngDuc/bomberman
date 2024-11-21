#pragma once

class Maze
{
public:
    Maze();
    int rows ;        
    int cols ; 
	int cellSize;
	int maze[13][15];

	void draw(CDC* dc) const;
	/*void draw(CClientDC* dc);*/
};

