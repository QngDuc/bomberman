#include "pch.h"
#include "Color.h"
#include "Maze.h"



Maze::Maze() : rows(13), cols(15), cellSize(30)
{
    int tempMaze[13][15] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1},
        {1, 0, 0, 2, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    for (int i = 0; i < rows ; ++i)
        for (int j = 0; j < cols ; ++j)
            maze[i][j] = tempMaze[i][j];    //nạp giá trị vào maze
}

void Maze::draw(CDC* dc) const
{
    Color colorDrawer(dc);  
    for (int i = 0; i < rows ; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            
            CRect cell(j * cellSize, i * cellSize, (j + 1) * cellSize, (i + 1) * cellSize);

            if (maze[i][j] == 1) // Tường
            {
                colorDrawer.DrawCell(cell, 1); 
            }
            else if (maze[i][j] == 0) // Đường
            {
                colorDrawer.DrawCell(cell, 0);  
            }
            else if (maze[i][j] == 2) // Chướng ngại vật
            {
                colorDrawer.DrawCell(cell, 2);  
            }
        }
    }
}



