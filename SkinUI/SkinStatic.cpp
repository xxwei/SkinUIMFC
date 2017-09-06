#include "stdafx.h"
#include "SkinStatic.h"

// CSkinStatic

IMPLEMENT_DYNAMIC(CSkinStatic, CStatic)

CSkinStatic::CSkinStatic()
{
	nFontIndex = -1;
}


CSkinStatic::~CSkinStatic()
{
}

BEGIN_MESSAGE_MAP(CSkinStatic, CStatic)
    ON_WM_ERASEBKGND()
    ON_WM_DESTROY()  
    ON_WM_PAINT()
END_MESSAGE_MAP()


//消息循环
LRESULT CSkinStatic::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
    return __super::DefWindowProc(message, wParam, lParam);
}

//创建控件
BOOL CSkinStatic::CreateControl(CWnd* pParentWnd)
{
    if (!Create(NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), pParentWnd, 0))
        return FALSE;

    m_pOwnWnd = this;

    return TRUE;
}

//void CSkinStatic::SetWindowText(LPCTSTR txt)
//{
//    SetRedraw(false);
//    __super::SetWindowText(txt);
//    SetRedraw(false);
//}
//设置属性

void CSkinStatic::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
{
	if (_tcscmp(pstrName, _T("font")) == 0)
	{
		nFontIndex = _ttoi(pstrValue);
	}
    ISkinControl::SetAttribute(pstrName, pstrValue);
}

//重画消息
BOOL CSkinStatic::OnEraseBkgnd(CDC* pDC)
{
    return TRUE;
}
//销毁消息
void CSkinStatic::OnDestroy()
{
    __super::OnDestroy();
}
// 绘制消息
void CSkinStatic::OnPaint()
{
    CPaintDC dc(this);

    CRect rcClient;
    GetClientRect(&rcClient);

    CMemoryDC MemDC(&dc, rcClient);

    //绘制背景
    DrawParentWndBg(GetSafeHwnd(), MemDC->GetSafeHdc());

    CString strText;
    GetWindowText(strText);

    BOOL bHasText = FALSE;
    if (strText.GetLength() > 0)
        bHasText = TRUE;
    UINT nFormat = m_dwTextAlign ? m_dwTextAlign : DT_CENTER | DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS;

 

    int nMode = MemDC.SetBkMode(TRANSPARENT);
	if (nFontIndex < 0)
	{
		MemDC.SelectObject(GetCtrlFont());
	}
	else
	{
		MemDC.SelectObject(RenderEngine->GetFont(nFontIndex-1));
	}

    MemDC.SetTextColor(m_colNormalText);
    MemDC.DrawText(strText, &rcClient, nFormat);
    MemDC.SetBkMode(nMode);
}