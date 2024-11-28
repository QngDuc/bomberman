
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Maze.h"
#include "Player.h"
#include "Image.h"


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();
	
public:
	Maze maze;
	Player player;
	int cellSize = 30;
// Operations
public:

// Overrides
protected:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	CChildView();
	virtual ~CChildView();

protected:
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

private:
	CDC* dc;
	Image* image;
	int cellSize;
};