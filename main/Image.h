#pragma once
#include <afxwin.h>
#include <atlimage.h>

class Image
{
public:
    Image(CDC* dc);
    void DrawCell(const CRect& rect, int imageType);
    void SetImage(int imageType);
    CImage* GetImage(int imageType);
    CImage* playerImage(int imageType);

private:
    CDC* dc;
    CImage wallImage;
    CImage pathImage;
    CImage obstacleImage;
    CImage playerImage;
};