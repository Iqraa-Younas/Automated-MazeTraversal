
// Homework5View.cpp : implementation of the CHomework5View class
//

#include "pch.h"
#include "framework.h"
#include <cstdlib> 
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Homework5.h"
#endif

#include "Homework5Doc.h"
#include "Homework5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHomework5View

IMPLEMENT_DYNCREATE(CHomework5View, CView)

BEGIN_MESSAGE_MAP(CHomework5View, CView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CHomework5View construction/destruction

CHomework5View::CHomework5View() noexcept
{
	// TODO: add construction code here

}

CHomework5View::~CHomework5View()
{
}

BOOL CHomework5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHomework5View drawing

void CHomework5View::OnDraw(CDC* pDC)
{
	
	CHomework5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: add draw code for native data here

	
	int size = pDoc->Mazeptr.getSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (pDoc->Mazeptr.getCellValueAt(i, j) == '.') {
			
				//pDC->FillSolidRect(j* pDoc->Mazeptr.getCellWidthPx(), i* pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB/*(100,100,0)*//*(30,0,9)*/(12,12,12));
				
				CImage* pacmanimage = new CImage();
				pacmanimage->Load(L"images\\pacmandot.png"); //images folder is placed in working directory 

				pacmanimage->Draw(pDC->m_hDC, j * pDoc->Mazeptr.getCellWidthPx(), i * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
				pacmanimage->Destroy();
				
			}
			else if (pDoc->Mazeptr.getCellValueAt(i, j) == '#') {
				
				/*pDC->FillSolidRect(x, y, pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB(253, 94, 83));*/
				CImage* wallimage = new CImage();
				wallimage->Load(L"images\\wall2.png"); //images folder is placed in working directory 
				
				wallimage->Draw(pDC->m_hDC, j * pDoc->Mazeptr.getCellWidthPx(), i * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
				wallimage->Destroy();
				
			}
		}
	}
	
	cheeryFormation();
	ImageFormation();
	
	//AUTOMATION
	SetTimer(1, 600, NULL);
	calltimer();
	
	
	

	//CImage* ghostimage = new CImage();
	//ghostimage->Load(L"images\\lol.png"); //images folder is placed in working directory 
	//ghostimage->Draw(pDC->m_hDC, pDoc->Mazeptr.getStartCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getStartRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
	
	
	
}


// CHomework5View diagnostics

#ifdef _DEBUG
void CHomework5View::AssertValid() const
{
	CView::AssertValid();
}

void CHomework5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHomework5Doc* CHomework5View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomework5Doc)));
	return (CHomework5Doc*)m_pDocument;
}
#endif //_DEBUG


// CHomework5View message handlers


void CHomework5View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
     
	CHomework5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size as 100x100
	rcWindow.right = rcWindow.left + (pDoc->Mazeptr.getCellWidthPx()*pDoc->Mazeptr.getSize()) + nWidthDiff;
	rcWindow.bottom = rcWindow.top + (pDoc->Mazeptr.getCellHeightPx() * pDoc->Mazeptr.getSize()) + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);

	// TODO: Add your specialized code here and/or call the base class
}
void CHomework5View::ImageFormation() {
	CDC* pDC = GetDC();
	CHomework5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CImage* ghostimage = new CImage();
	//right
	if (pDoc->Mazeptr.getDir() == 'R') {
		ghostimage->Load(L"images\\pacmanright.png"); //images folder is placed in working directory 
		ghostimage->Draw(pDC->m_hDC, pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
	}
	//left
	else if (pDoc->Mazeptr.getDir() == 'L') {
		ghostimage->Load(L"images\\pacmanleft.png"); //images folder is placed in working directory 
		ghostimage->Draw(pDC->m_hDC, pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
	}
	//down
	else if (pDoc->Mazeptr.getDir() == 'D') {
		
		ghostimage->Load(L"images\\pacmandown.png"); //images folder is placed in working directory 
		ghostimage->Draw(pDC->m_hDC, pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
		
	}
	//up
	else if (pDoc->Mazeptr.getDir() == 'U') {
		ghostimage->Load(L"images\\pacmanup.png"); //images folder is placed in working directory 
		ghostimage->Draw(pDC->m_hDC, pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
	}
	
	
	
	
	ghostimage->Destroy();
	
	

         
	
	
	
	
}
void CHomework5View::cheeryFormation() {

	CDC* pDC = GetDC();
	CHomework5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	 
	for (int i = 0; i < pDoc->Mazeptr.getSize(); i++) {

		int j = pDoc->Mazeptr.getSize() - 1;
		if (pDoc->Mazeptr.getCellValueAt(i, j) == '.') {
			CImage* cheeryimage = new CImage();
			cheeryimage->Load(L"images\\cheery.png"); //images folder is placed in working directory 

			cheeryimage->Draw(pDC->m_hDC, j * pDoc->Mazeptr.getCellWidthPx(), i * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
			cheeryimage->Destroy();
		}
		else if (pDoc->Mazeptr.noend() == true) {
			CImage* cheeryimage = new CImage();
			cheeryimage->Load(L"images\\cheery.png"); //images folder is placed in working directory 

			cheeryimage->Draw(pDC->m_hDC, pDoc->Mazeptr.getStartCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getStartRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx());
			cheeryimage->Destroy();
		}
		




	}
}
void CHomework5View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){

	// TODO: Add your message handler code here and/or call default

	CDC* pDC = GetDC();
	CHomework5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	if (nChar == 'R') {
		
		
		pDC->FillSolidRect(pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB(0, 0, 0));
		pDoc->Mazeptr.moveRight();
		cheeryFormation();
		ImageFormation();
	}
	else if (nChar == 'L') {
		pDC->FillSolidRect(pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB(0, 0, 0));
		pDoc->Mazeptr.moveLeft();
		cheeryFormation();
		ImageFormation();
	}
	else if (nChar == 'U') {
		pDC->FillSolidRect(pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB(0, 0, 0));
		pDoc->Mazeptr.moveUp();
		cheeryFormation();
		ImageFormation();
	}
	else if (nChar == 'D') {
		pDC->FillSolidRect(pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB(0, 0, 0));
		pDoc->Mazeptr.moveDown();
		cheeryFormation();
		ImageFormation();
		
	}
	if (pDoc->Mazeptr.DestinationReached() == true) {
		displaymessage();
	}

		
			
			
	

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CHomework5View::OnTimer(UINT_PTR nIDEvent)
{
	
	// TODO: Add your message handler code here and/or call default
	
	if (nIDEvent == 1) {
		CDC* pDC = GetDC();
		CHomework5Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		
		
			pDC->FillSolidRect(pDoc->Mazeptr.getCurrCol() * pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCurrRow() * pDoc->Mazeptr.getCellHeightPx(), pDoc->Mazeptr.getCellWidthPx(), pDoc->Mazeptr.getCellHeightPx(), RGB(0, 0, 0));
			
			pDoc->Mazeptr.moveToNextCell();
			
			cheeryFormation();
			ImageFormation();

			
			if (pDoc->Mazeptr.DestinationReached() == true) {
				KillTimer(1);
				displaymessage();


			}
			
			
		
	}
	
	

	CView::OnTimer(nIDEvent);
}
void CHomework5View::displaymessage() {
	AfxMessageBox(_T("DESTINATION REACHED SUCCESSFULLY!"));
	exit(0);
}
void CHomework5View::calltimer() {
	CHomework5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	OnTimer(1);
}
