#pragma once

class Maze
{
public:
    Maze();
    int rows ;        
    int cols ; 
	int cellSize;
	int maze[13][15];
	int GetRows() const;
	int GetCols() const;
	int GetCell(int row, int col) const;
	void draw(CDC* dc) const;
	/*void draw(CClientDC* dc);*/
};

