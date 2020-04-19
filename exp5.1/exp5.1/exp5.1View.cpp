
// exp5.1View.cpp : Cexp51View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp5.1.h"
#endif

#include "exp5.1Doc.h"
#include "exp5.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp51View

IMPLEMENT_DYNCREATE(Cexp51View, CView)

BEGIN_MESSAGE_MAP(Cexp51View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp51View ����/����

Cexp51View::Cexp51View()
{
	// TODO: �ڴ˴���ӹ������
	ptCharacter.x = 105;
	ptCharacter.y = 205;
	A = CRect(100, 200, 500, flag);
}

Cexp51View::~Cexp51View()
{
}

BOOL Cexp51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp51View ����

void Cexp51View::OnDraw(CDC* pDC)
{
	Cexp51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->Rectangle(A);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp51View ��ӡ

BOOL Cexp51View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp51View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp51View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp51View ���

#ifdef _DEBUG
void Cexp51View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp51Doc* Cexp51View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp51Doc)));
	return (Cexp51Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp51View ��Ϣ�������


void Cexp51View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (nChar == 13|| ptCharacter.x>=490)
	{
		ptCharacter.x = 110;
		ptCharacter.y = ptCharacter.y + 25;
		flag += 25;
		A = CRect(100, 200, 500, flag);
		dc.Rectangle(A);
	}
	else
	{
		dc.TextOut(ptCharacter.x, ptCharacter.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		ptCharacter.x = ptCharacter.x + textsize.cx;
	}
	UpdateWindow();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
