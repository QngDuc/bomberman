#pragma once

class Color
{
public:
    Color(CDC* dc);
    
    void DrawCell(const CRect& rect, int colorType);
    void SetColor(int colorType);

    CDC* dc;  
    CBrush wallBrush;    
    CBrush pathBrush;    
    CBrush obstacleBrush;      
    CBrush playerBrush;

    
    CBrush* GetColor(int colorType);
    CBrush* playerColor(int colorType);
};

