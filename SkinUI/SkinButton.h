#ifndef BUTTON_HEAD_FILE
#define BUTTON_HEAD_FILE

#pragma once

#include "SkinUI.h"
#include "ISkinControl.h"

//�������
enum UI_BUTTON_TYPE
{
	en_PushButton,
	en_CheckButton,
	en_RadioButton,
	en_IconButton,
	en_MenuButton
};

// CButtonEx

class SKINUI_CLASS CSkinButton : public CButton,public ISkinControl
{
	DECLARE_DYNAMIC(CSkinButton)

	//��Դ����
public:
	CImageEx * m_pBackImgN, * m_pBackImgH, * m_pBackImgD, * m_pBackImgF;
	CImageEx * m_pCheckImgN, * m_pCheckImgH, * m_pCheckImgTickN, *m_pCheckImgTickH;
	CImageEx * m_pArrowImg, * m_pIconImg;

	CImageEx * m_pUnEnableImg;
	//��������
protected:
	BOOL m_bFocus, m_bPress, m_bHover, m_bMouseTracking;

	UI_BUTTON_TYPE				m_nBtnType;

	HMENU						m_hMenu;
	HDC							m_hBackDC;
	bool						m_bPushed;

	LPCTSTR						m_lpszUrl;
	int							nFontIndex;
	//��������
public:
	//���캯��
	CSkinButton();
	//��������
	virtual ~CSkinButton();

	//���غ���
protected:
	//��Ϣѭ��
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//��������
	virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
	//�����ؼ�
	virtual BOOL CreateControl(CWnd* pParentWnd);

	//���ú���
public:
	//��������
	void SetButtonType(UI_BUTTON_TYPE type);
	//����λ��
	void SetSize(int nWidth,int nHeight);
	//���ò˵�
	void SetMenu(HMENU hMenu);
	//���ò˵�
	void SetPushed(bool bPush);
	//����״̬
	void SetUpDown(bool bDown);

	//��Դ����
public:
	//������Դ
	BOOL SetBackImage(LPCTSTR lpNormal, LPCTSTR lpHoven, LPCTSTR lpDown, LPCTSTR lpFocus,CONST LPRECT lprcNinePart=NULL);
	//������Դ
	BOOL SetCheckImage(LPCTSTR lpNormal, LPCTSTR lpHoven, LPCTSTR lpTickNormal, LPCTSTR lpTickHoven);
	//������Դ
	BOOL SetIconImage(LPCTSTR lpszFileName);
	//������Դ
	BOOL SetMenuImage(LPCTSTR lpszFileName);

	//�滭����
public:
	//PUSH��ť
	void DrawPushButton(CDC* pDC,RECT &rcClient);
	//Check��ť
	void DrawCheckButton(CDC* pDC,RECT &rcClient);
	//Check��ť
	void DrawIConButton(CDC* pDC,RECT &rcClient);
	//Check��ť
	void DrawMenuButton(CDC* pDC,RECT &rcClient);


	//��Ϣ����
protected:
	//����ƶ�
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//����뿪
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	//�ػ汳��
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//������Ϣ
	afx_msg void OnDestroy();
	//�������
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//���̧��
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//���ý���
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//���㶪ʧ
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//������Ϣ
	afx_msg void OnPaint();
	//���˫��
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

protected:
	DECLARE_MESSAGE_MAP()
};


#endif