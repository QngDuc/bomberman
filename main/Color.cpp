#include "pch.h"
#include "Color.h"

Color::Color(CDC* dc) 
    : dc(dc) ,
    wallBrush(RGB(100, 100, 100)),
    pathBrush(RGB(255, 255, 255)), 
    obstacleBrush(RGB(255, 0, 0)), 
    playerBrush(RGB(40,40,40))
{ 
}

void Color::DrawCell(const CRect& rect, int colorType)
{
    SetColor(colorType); 
    dc->FillRect(&rect, GetColor(colorType));  
    dc->Rectangle(&rect);
}

void Color::SetColor(int colorType)
{
    dc->SelectObject(GetColor(colorType));
}

CBrush* Color::GetColor(int colorType)
{
    switch (colorType)
    {
    case 0: 
        return &pathBrush;
    case 1: 
        return &wallBrush;
    case 2: 
        return &obstacleBrush;
    default: 
        return &pathBrush;  
    }
}

CBrush* Color::playerColor(int colorType)
{
    return &playerBrush;
}
