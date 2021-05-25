
// ProjectTest1View.h: CProjectTest1View 클래스의 인터페이스
//

#pragma once


class CProjectTest1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CProjectTest1View() noexcept;
	DECLARE_DYNCREATE(CProjectTest1View)

// 특성입니다.
public:
	CProjectTest1Doc* GetDocument() const;

// 작업입니다.
public:
	CPoint m_ptStart;
	CPoint m_ptEnd;
	BOOL m_bDrag;

	int m_nShape;
	BOOL m_bFill;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CProjectTest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnLineDraw();
	afx_msg void OnRectangleDraw();
	afx_msg void OnEllipseDraw();
	afx_msg void OnFillDraw();
	afx_msg void OnUpdateFillDraw(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLineDraw(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRectangleDraw(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllipseDraw(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // ProjectTest1View.cpp의 디버그 버전
inline CProjectTest1Doc* CProjectTest1View::GetDocument() const
   { return reinterpret_cast<CProjectTest1Doc*>(m_pDocument); }
#endif

