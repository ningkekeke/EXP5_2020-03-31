
// exp5.3View.h : Cexp53View ��Ľӿ�
//

#pragma once


class Cexp53View : public CView
{
protected: // �������л�����
	Cexp53View();
	DECLARE_DYNCREATE(Cexp53View)

// ����
public:
	Cexp53Doc* GetDocument() const;
	CRect A;
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
	virtual ~Cexp53View();
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

#ifndef _DEBUG  // exp5.3View.cpp �еĵ��԰汾
inline Cexp53Doc* Cexp53View::GetDocument() const
   { return reinterpret_cast<Cexp53Doc*>(m_pDocument); }
#endif

