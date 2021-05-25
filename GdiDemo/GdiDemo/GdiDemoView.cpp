
// GdiDemoView.cpp: CGdiDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GdiDemo.h"
#endif

#include "GdiDemoDoc.h"
#include "GdiDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiDemoView

IMPLEMENT_DYNCREATE(CGdiDemoView, CView)

BEGIN_MESSAGE_MAP(CGdiDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiDemoView 생성/소멸

CGdiDemoView::CGdiDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiDemoView::~CGdiDemoView()
{
}

BOOL CGdiDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiDemoView 그리기

void CGdiDemoView::OnDraw(CDC* /*pDC*/)
{
	CGdiDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiDemoView 인쇄

BOOL CGdiDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiDemoView 진단

#ifdef _DEBUG
void CGdiDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiDemoDoc* CGdiDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiDemoDoc)));
	return (CGdiDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiDemoView 메시지 처리기


void CGdiDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC* pDC = GetDC();

	pDC->Rectangle(100, 100, 300, 300);


	ReleaseDC(pDC);

	CView::OnLButtonDown(nFlags, point);
}


void CGdiDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	/*CPen myPen(PS_DOT, 1, RGB(255, 0, 0));
	CPen* pOldPen = dc.SelectObject(&myPen);

	dc.Rectangle(200, 200, 500, 500);
	dc.Ellipse(200, 200, 500, 500);
	dc.MoveTo(200, 200); dc.LineTo(500, 500);
	dc.MoveTo(200, 500); dc.LineTo(500, 200);

	dc.SelectObject(pOldPen);*/

	//dc.Rectangle(200, 200, 500, 500);

	//CBrush myBr(RGB(255, 0, 0)); // solidbrush
	//CBrush myBr(HS_CROSS, RGB(255, 0, 0)); // hash brush
	
	/*CBitmap bmpFlower;
	bmpFlower.LoadBitmap(IDB_Flower);
	CBrush myBr(&bmpFlower); // pattern brush

	CBrush* pOldBr = dc.SelectObject(&myBr);

	CRect rectView;
	GetClientRect(&rectView);
	dc.Ellipse(&rectView);

	//dc.Rectangle(200, 200, 500, 500);

	dc.SelectObject(pOldBr);*/

	LOGFONT lf = { 0, };
	lf.lfHeight = 50;
	lf.lfWidth = 30;
	lf.lfItalic = 1;
	lf.lfUnderline = 1;
	wsprintf(lf.lfFaceName, _T("%s"), _T("궁서체"));

	CFont myFont;
	myFont.CreateFontIndirect(&lf);
	CFont* pOldFont = dc.SelectObject(&myFont);

	dc.TextOut(10, 10, _T("안녕하세요 반가워요"));

	dc.SelectObject(myFont);

	
}
