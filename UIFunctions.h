#pragma once
// Common UI functions for MFC MAPI

#include <oleacc.h>

enum uiColor
{
	cBackground,
	cBackgroundReadOnly,
	cGlow,
	cGlowBackground,
	cGlowText,
	cFrameSelected,
	cFrameUnselected,
	cSelectedBackground,
	cArrow,
	cText,
	cTextDisabled,
	cTextReadOnly,
	cBitmapTransBack,
	cBitmapTransFore,
	cStatus,
	cStatusText,
	cPaneHeaderBackground,
	cPaneHeaderText,
	cUIEnd
};

enum uiPen
{
	cSolidPen,
	cSolidGreyPen,
	cDashedPen,
	cPenEnd
};

enum uiBitmap
{
	cNotify,
	cClose,
	cMinimize,
	cMaximize,
	cRestore,
	cBitmapEnd
};

enum uiButtonStyle
{
	bsUnstyled,
	bsUpArrow,
	bsDownArrow
};

enum uiLabelStyle
{
	lsUnstyled,
	lsPaneHeaderLabel,
	lsPaneHeaderText,
};

void InitializeGDI();
void UninitializeGDI();

void UpdateMenuString(_In_ HWND hWnd, UINT uiMenuTag, UINT uidNewString);

void DisplayContextMenu(UINT uiClassMenu, UINT uiControlMenu, _In_ HWND hWnd, int x, int y);

HMENU LocateSubmenu(_In_ HMENU hMenu, UINT uid);

_Check_return_ int GetEditHeight(_In_ HWND hwndEdit);
_Check_return_ int GetTextHeight(_In_ HWND hwndEdit);
SIZE GetTextExtentPoint32(HDC hdc, const wstring& szText);

HFONT GetSegoeFont();
HFONT GetSegoeFontBold();

_Check_return_ HBRUSH GetSysBrush(uiColor uc);
_Check_return_ COLORREF MyGetSysColor(uiColor uc);

_Check_return_ HPEN GetPen(uiPen up);

HBITMAP GetBitmap(uiBitmap ub);

void ClearEditFormatting(_In_ HWND hWnd, bool bReadOnly);

// Application-specific owner-drawn menu info struct. Owner-drawn data 
// is a pointer to one of these. MSAAMENUINFO must be the first 
// member. 
struct MenuEntry
{
	MSAAMENUINFO m_MSAA; // MSAA info - must be first element.
	wstring m_pName; // Menu text for display. Empty for separator item.
	BOOL m_bOnMenuBar;
	ULONG_PTR m_AddInData;
};
typedef MenuEntry* LPMENUENTRY;

_Check_return_ LPMENUENTRY CreateMenuEntry(_In_ const wstring& szMenu);
void ConvertMenuOwnerDraw(_In_ HMENU hMenu, bool bRoot);
void DeleteMenuEntries(_In_ HMENU hMenu);

// Edit box
LRESULT CALLBACK DrawEditProc(
	_In_ HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam,
	UINT_PTR uIdSubclass,
	DWORD_PTR /*dwRefData*/);
void SubclassEdit(_In_ HWND hWnd, _In_ HWND hWndParent, bool bReadOnly);

// List
void CustomDrawList(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult, int iItemCur);
void DrawListItemGlow(_In_ HWND hWnd, UINT itemID);

// Tree
void CustomDrawTree(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult, bool bHover, _In_ HTREEITEM hItemCurHover);
void DrawTreeItemGlow(_In_ HWND hWnd, _In_ HTREEITEM hItem);
void DrawExpandTriangle(_In_ HWND hWnd, _In_ HDC hdc, _In_ HTREEITEM hItem, bool bGlow, bool bHover);

// Header
void DrawTriangle(_In_ HWND hWnd, _In_ HDC hdc, _In_ const RECT& lprc, bool bButton, bool bUp);
void CustomDrawHeader(_In_ NMHDR* pNMHDR, _In_ LRESULT* pResult);
void DrawTrackingBar(_In_ HWND hWndHeader, _In_ HWND hWndList, int x, int iHeaderHeight, bool bRedraw);

// Menu and Combo box
void MeasureItem(_In_ LPMEASUREITEMSTRUCT lpMeasureItemStruct);
void DrawItem(_In_ LPDRAWITEMSTRUCT lpDrawItemStruct);
wstring GetLBText(HWND hwnd, int nIndex);

// Status Bar
void DrawStatus(
	HWND hwnd,
	int iStatusHeight,
	const wstring& szStatusData1,
	int iStatusData1,
	const wstring& szStatusData2,
	int iStatusData2,
	const wstring& szStatusInfo);

void GetCaptionRects(HWND hWnd,
	RECT* lprcFullCaption,
	RECT* lprcIcon,
	RECT* lprcCloseIcon,
	RECT* lprcMaxIcon,
	RECT* lprcMinIcon,
	RECT* lprcCaptionText);
void DrawSystemButtons(_In_ HWND hWnd, _In_opt_ HDC hdc, LONG_PTR iHitTest, bool bHover);
void DrawWindowFrame(_In_ HWND hWnd, bool bActive, int iStatusHeight);

// Winproc handler for custom controls
_Check_return_ bool HandleControlUI(UINT message, WPARAM wParam, LPARAM lParam, _Out_ LRESULT* lpResult);

// Help Text
void DrawHelpText(_In_ HWND hWnd, _In_ UINT uIDText);

// Text labels
void SubclassLabel(_In_ HWND hWnd);
void StyleLabel(_In_ HWND hWnd, uiLabelStyle lsStyle);

void StyleButton(_In_ HWND hWnd, uiButtonStyle bsStyle);