#ifndef STATIC_HEAD_FILE
#define STATIC_HEAD_FILE

#pragma once

#include "SkinUI.h"
#include "ISkinControl.h"
class CSkinStatic : public CStatic, public ISkinControl
{
    DECLARE_DYNAMIC(CSkinStatic)
    //函数定义
public:
    //构造函数
    CSkinStatic();
    //析构函数
    ~CSkinStatic();
    //重载函数
protected:
    //消息循环
    virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
    //设置属性
    virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
    //创建控件
    virtual BOOL CreateControl(CWnd* pParentWnd);
public:
    ////设置文字
    //void SetWindowText(LPCTSTR txt);
    
    //消息函数
protected:
    //重绘背景
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    //销毁消息
    afx_msg void OnDestroy();
    //绘制消息
    afx_msg void OnPaint();
protected:
    DECLARE_MESSAGE_MAP()
private:
	int		nFontIndex;
};

#endif

