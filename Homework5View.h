
// Homework5View.h : interface of the CHomework5View class
//

#pragma once


class CHomework5View : public CView
{
protected: // create from serialization only
	CHomework5View() noexcept;
	DECLARE_DYNCREATE(CHomework5View)

// Attributes
public:
	CHomework5Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CHomework5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void ImageFormation();
	void cheeryFormation();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void displaymessage();
	void calltimer();
};

#ifndef _DEBUG  // debug version in Homework5View.cpp
inline CHomework5Doc* CHomework5View::GetDocument() const
   { return reinterpret_cast<CHomework5Doc*>(m_pDocument); }
#endif

