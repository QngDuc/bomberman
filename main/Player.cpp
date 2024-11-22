#include "pch.h"
#include "Player.h"
#include "Maze.h"

Player::Player() : player_x(1), player_y(1), prev_x(1), prev_y(1)
{
    // Khởi tạo nhân vật tại vị trí ban đầu (ô hàng 1, cột 1)
}

// Lấy tọa độ X của nhân vật
int Player::getX() const
{
    return player_x;
}

// Lấy tọa độ Y của nhân vật
int Player::getY() const
{
    return player_y;
}

// Đặt tọa độ X mới cho nhân vật
void Player::setX(int x)
{
    player_x = x;
}

// Đặt tọa độ Y mới cho nhân vật
void Player::setY(int y)
{
    player_y = y;
}


// Lưu vị trí hiện tại của nhân vật trước khi di chuyển
void Player::SavePreviousPosition()
{
    prev_x = player_x;
    prev_y = player_y;
}

// Vẽ nhân vật trên màn hình
void Player::Draw(CDC* pDC)
{
    // Xóa nhân vật ở vị trí cũ (nếu có)
    CBrush eraseBrush(RGB(255, 255, 255)); // Màu nền (trắng)
    CBrush* pOldBrush = pDC->SelectObject(&eraseBrush);
    pDC->Rectangle(prev_x * 30, prev_y * 30, prev_x * 30 + 30, prev_y * 30 + 30);

    // Vẽ nhân vật ở vị trí mới
    CBrush brush(RGB(0, 255, 0)); // Màu xanh lá
    pDC->SelectObject(&brush);
    pDC->Rectangle(player_x * 30, player_y * 30, player_x * 30 + 30, player_y * 30 + 30);

    // Khôi phục bút cọ cũ
    pDC->SelectObject(pOldBrush);
}