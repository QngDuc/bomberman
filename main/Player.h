class Player
{
private:
    int player_x;  // Tọa độ X của nhân vật (cột)
    int player_y;  // Tọa độ Y của nhân vật (hàng)
    int prev_x;    // Tọa độ X trước khi di chuyển
    int prev_y;    // Tọa độ Y trước khi di chuyển

public:
    Player(); // Hàm khởi tạo

    // Getter và Setter cho tọa độ nhân vật
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    int GetCell(int row, int col) const;
    // Lưu vị trí cũ của nhân vật
    void SavePreviousPosition();

    // Vẽ nhân vật trên màn hình
    void Draw(CDC* pDC);
};