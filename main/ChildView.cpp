#include "pch.h"
#include "framework.h"
#include "datbom.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView

CChildView::CChildView()
{
    dc = new CDC();
    image = new Image(dc);
    cellSize = 50; // Set the cell size as needed
}

CChildView::~CChildView()
{
    delete image;
    delete dc;
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
    ON_WM_PAINT()
    ON_WM_KEYDOWN()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CWnd::PreCreateWindow(cs))
        return FALSE;

    cs.dwExStyle |= WS_EX_CLIENTEDGE;
    cs.style &= ~WS_BORDER;
    cs.style &= ~WS_THICKFRAME;
    cs.style |= CS_SAVEBITS;
    cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
        ::LoadCursor(nullptr, IDC_ARROW),
        reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

    return TRUE;
}

void CChildView::OnPaint()
{
    CPaintDC dc(this);

    CRect rect(10, 10, cellSize, cellSize);
    image->DrawCell(rect, 0); // Example usage
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // Lưu lại vị trí cũ của nhân vật
    CRect oldCell(player.getX() * cellSize, player.getY() * cellSize,
        (player.getX() + 1) * cellSize, (player.getY() + 1) * cellSize);

    switch (nChar)
    {
    case 'W':
        if (player.getY() > 0 && maze.GetCell(player.getY() - 1, player.getX()) != 1) // Kiểm tra tường
            player.setY(player.getY() - 1);
        break;
    case 'A':
        if (player.getX() > 0 && maze.GetCell(player.getY(), player.getX() - 1) != 1) // Kiểm tra tường
            player.setX(player.getX() - 1);
        break;
    case 'S':
        if (player.getY() < maze.GetRows() - 1 && maze.GetCell(player.getY() + 1, player.getX()) != 1) // Kiểm tra tường
            player.setY(player.getY() + 1);
        break;
    case 'D':
        if (player.getX() < maze.GetCols() - 1 && maze.GetCell(player.getY(), player.getX() + 1) != 1) // Kiểm tra tường
            player.setX(player.getX() + 1);
        break;
    }

    // Tạo ô mới của nhân vật
    CRect newCell(player.getX() * cellSize, player.getY() * cellSize,
        (player.getX() + 1) * cellSize, (player.getY() + 1) * cellSize);

    InvalidateRect(oldCell);
    InvalidateRect(newCell);
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
    Invalidate();
    CWnd::OnTimer(nIDEvent);
}
