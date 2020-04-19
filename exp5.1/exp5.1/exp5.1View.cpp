
// exp5.1View.cpp : Cexp51View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp51View 构造/析构

Cexp51View::Cexp51View()
{
	// TODO: 在此处添加构造代码
	ptCharacter.x = 105;
	ptCharacter.y = 205;
	A = CRect(100, 200, 500, flag);
}

Cexp51View::~Cexp51View()
{
}

BOOL Cexp51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp51View 绘制

void Cexp51View::OnDraw(CDC* pDC)
{
	Cexp51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->Rectangle(A);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp51View 打印

BOOL Cexp51View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp51View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp51View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp51View 诊断

#ifdef _DEBUG
void Cexp51View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp51Doc* Cexp51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp51Doc)));
	return (Cexp51Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp51View 消息处理程序


void Cexp51View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
