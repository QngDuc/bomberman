#pragma once

class Maze
{
public:
    int rows ;        
    int cols ; 
    int width= rows * cellSize;      
    int height = cols * cellSize;
	int cellSize;
	int maze[20][20];

    int GetCell(int y, int x);
    int GetRows();
    int GetCols();

    Maze();

    void draw(CPaintDC* dc);
	void draw(CClientDC* dc);
};

