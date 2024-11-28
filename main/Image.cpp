#include "pch.h"
#include "Image.h"

Image::Image(CDC* dc)
    : dc(dc),
    wallImage(L"wall.png"),
    pathImage(L"road.png"),
    obstacleImage(L"block.png"),
    playerImage(L"player.png")
{
}

void Image::DrawCell(const CRect& rect, int imageType)
{
    SetImage(imageType);
    dc->DrawImage(&rect, GetImage(imageType));
    dc->Rectangle(&rect);
}

void Image::SetImage(int imageType)
{
    dc->SelectObject(GetImage(imageType));
}

CImage* Image::GetImage(int imageType)
{
    switch (imageType)
    {
    case 0:
        return &pathImage;
    case 1:
        return &wallImage;
    case 2:
        return &obstacleImage;
    default:
        return &pathImage;
    }
}

CImage* Image::playerImage(int imageType)
{
    return &playerImage;
}