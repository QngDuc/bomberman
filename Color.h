#pragma once

class Color
{
public:
    // Constructor
    Color(CDC* dc);

    // Các phương thức để vẽ các thành phần với màu sắc
    void DrawCell(const CRect& rect, int colorType);
    void SetColor(int colorType);

private:
    CDC* dc;  // CDC dùng để vẽ
    CBrush wallBrush;    // Màu đen
    CBrush pathBrush;    // Màu trắng
    CBrush obstacleBrush;      // Màu đỏ
    CBrush playerBrush;

    // Helper method để thiết lập brush theo loại màu
    CBrush* GetColor(int colorType);
    CBrush* playerColor(int colorType);
};

