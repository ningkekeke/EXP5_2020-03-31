
// exp5.1View.h : Cexp51View ��Ľӿ�
//

#pragma once


class Cexp51View : public CView
{
protected: // �������л�����
	Cexp51View();
	DECLARE_DYNCREATE(Cexp51View)

// ����
public:
	Cexp51Doc* GetDocument() const;
	CRect A;
	int flag = 230;
	CString s;
// ����
public:
	CPoint ptCharacter;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cexp51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // exp5.1View.cpp �еĵ��԰汾
inline Cexp51Doc* Cexp51View::GetDocument() const
   { return reinterpret_cast<Cexp51Doc*>(m_pDocument); }
#endif

