#pragma once

class Maze
{
public:
    Maze();
    int rows ;        
    int cols ; 
	int cellSize;
	int maze[20][20];


    

    void draw(CPaintDC* dc) const;
	/*void draw(CClientDC* dc);*/
};

