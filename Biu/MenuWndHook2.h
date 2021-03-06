#pragma once

namespace SOUI
{

	extern void DrawItem1(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);

/*########################################################################
              ------------------------------------------------
                             CMenuWndHook 类
              ------------------------------------------------
  ########################################################################*/
class  CMenuWndHook2
{
// 建构 ---------------------------------------------------------
public:
    CMenuWndHook2(HWND hWnd);
    ~CMenuWndHook2();
    static void InstallHook(HINSTANCE hInst,LPCWSTR pszSkinName=NULL);
    static void UnInstallHook();

// 消息 ----------------------------------------------------------
public:
    static LRESULT CALLBACK CoolMenuProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowHook (int code, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK CoolMenuParentProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    void OnNcCalcsize(BOOL bValidCalc,NCCALCSIZE_PARAMS* lpncsp);
    void OnNcDestroy();
    void OnPrint(HDC dc);
    void OnNcPaint();
    void OnWindowPosChanging(WINDOWPOS* pWindowPos);
    void OnWindowPosChanged();
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
// 操作 ----------------------------------------------------------
public:
    static CMenuWndHook2* AddWndHook(HWND hwnd);
    static CMenuWndHook2* GetWndHook(HWND hwnd);

// 数据 -----------------------------------------------------------
protected:
    HWND m_hWnd;

    static SMap<HWND, CMenuWndHook2*> m_WndMenuMap;
    static HHOOK m_hMenuHook;
    static SStringW    m_strSkinName;
};

}//namespace SOUI

namespace COOL {

	void BiuBiut();
}