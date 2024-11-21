#include "pch.h"
#include "Color.h"

Color::Color(CDC* dc) : dc(dc) , blackBrush(RGB(192, 192, 192)) , whiteBrush(RGB(255, 255, 255)) , redBrush(RGB(255, 0, 0)), playerBrush(RGB(40,40,40))
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
        return &whiteBrush;
    case 1: 
        return &blackBrush;
    case 2: 
        return &redBrush;
    default: 
        return &whiteBrush;  
    }
}

CBrush* Color::playerColor(int colorType)
{
    return &playerBrush;
}
