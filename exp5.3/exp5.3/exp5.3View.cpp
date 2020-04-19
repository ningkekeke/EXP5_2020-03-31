
// exp5.3View.cpp : Cexp53View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp5.3.h"
#endif

#include "exp5.3Doc.h"
#include "exp5.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp53View

IMPLEMENT_DYNCREATE(Cexp53View, CView)

BEGIN_MESSAGE_MAP(Cexp53View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp53View 构造/析构

Cexp53View::Cexp53View()
{
	// TODO: 在此处添加构造代码
	ptCharacter.x = 105;
	ptCharacter.y = 205;
	A = CRect(100, 200, 800, 230);

}

Cexp53View::~Cexp53View()
{
}

BOOL Cexp53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp53View 绘制

void Cexp53View::OnDraw(CDC* pDC)
{
	Cexp53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(A);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp53View 打印

BOOL Cexp53View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp53View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp53View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp53View 诊断

#ifdef _DEBUG
void Cexp53View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp53Doc* Cexp53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp53Doc)));
	return (Cexp53Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp53View 消息处理程序


void Cexp53View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	dc.TextOut(ptCharacter.x, ptCharacter.y, (LPCTSTR)&nChar);
	CSize textsize;
	textsize = dc.GetTextExtent((LPCTSTR)&nChar);
	ptCharacter.x = ptCharacter.x + textsize.cx;
	UpdateWindow();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
