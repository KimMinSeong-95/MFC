
// ProjectTest1View.cpp: CProjectTest1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ProjectTest1.h"
#endif

#include "ProjectTest1Doc.h"
#include "ProjectTest1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjectTest1View

IMPLEMENT_DYNCREATE(CProjectTest1View, CView)

BEGIN_MESSAGE_MAP(CProjectTest1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_LINE_DRAW, &CProjectTest1View::OnLineDraw)
	ON_COMMAND(ID_RECTANGLE_DRAW, &CProjectTest1View::OnRectangleDraw)
	ON_COMMAND(ID_ELLIPSE_DRAW, &CProjectTest1View::OnEllipseDraw)
	ON_COMMAND(ID_FILL_DRAW, &CProjectTest1View::OnFillDraw)
	ON_UPDATE_COMMAND_UI(ID_FILL_DRAW, &CProjectTest1View::OnUpdateFillDraw)
	ON_UPDATE_COMMAND_UI(ID_LINE_DRAW, &CProjectTest1View::OnUpdateLineDraw)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE_DRAW, &CProjectTest1View::OnUpdateRectangleDraw)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE_DRAW, &CProjectTest1View::OnUpdateEllipseDraw)
END_MESSAGE_MAP()

// CProjectTest1View 생성/소멸

CProjectTest1View::CProjectTest1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	//m_ptStart = { 0, };
	//m_ptEnd = { 0, };
	m_ptStart.x = 0;
	m_ptStart.y = 0;
	m_ptEnd.x = 0;
	m_ptEnd.y = 0;
	m_bDrag = FALSE;

	m_nShape = 0;
	m_bFill = FALSE;
}

CProjectTest1View::~CProjectTest1View()
{
}

BOOL CProjectTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CProjectTest1View 그리기

void CProjectTest1View::OnDraw(CDC* /*pDC*/)
{
	CProjectTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CProjectTest1View 인쇄

BOOL CProjectTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CProjectTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CProjectTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CProjectTest1View 진단

#ifdef _DEBUG
void CProjectTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CProjectTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectTest1Doc* CProjectTest1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectTest1Doc)));
	return (CProjectTest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CProjectTest1View 메시지 처리기


void CProjectTest1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = TRUE;
	m_ptStart = point;

	CView::OnLButtonDown(nFlags, point);
}

void CProjectTest1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_bDrag)
	{
		m_ptEnd = point;
		RedrawWindow();
	}
	CView::OnLButtonDown(nFlags, point);

}

void CProjectTest1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_bDrag)
	{
		m_bDrag = FALSE;

		m_ptEnd = point;
		RedrawWindow();
	}
	CView::OnLButtonUp(nFlags, point);
}


void CProjectTest1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	CBrush Redbr = RGB(255, 0, 0);
	CBrush* pOldbr = NULL;

	if (m_bFill)
	{
		pOldbr = dc.SelectObject(&Redbr);
	}
	//////////////////////////////////////////////////////////////
	if (m_nShape == 0)
	{
		dc.MoveTo(m_ptStart.x, m_ptStart.y);
		dc.LineTo(m_ptEnd.x, m_ptEnd.y);
	}
	else if (m_nShape == 1)
	{
		dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
	}
	else if (m_nShape == 2)
	{
		dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
	}
	//////////////////////////////////////////////////////////////

	if (m_bFill)
	{
		dc.SelectObject(pOldbr);
	}
}


void CProjectTest1View::OnLineDraw()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nShape = 0;
}


void CProjectTest1View::OnRectangleDraw()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nShape = 1;
}


void CProjectTest1View::OnEllipseDraw()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nShape = 2;
}


void CProjectTest1View::OnFillDraw()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_bFill)
	{
		m_bFill = FALSE;
	}
	else
	{
		m_bFill = TRUE;
	}
}


void CProjectTest1View::OnUpdateLineDraw(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_nShape == 0)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}


void CProjectTest1View::OnUpdateRectangleDraw(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_nShape == 1)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}


void CProjectTest1View::OnUpdateEllipseDraw(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_nShape == 2)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}

void CProjectTest1View::OnUpdateFillDraw(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_bFill)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}