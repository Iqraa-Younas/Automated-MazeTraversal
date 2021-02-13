
// Homework5Doc.h : interface of the CHomework5Doc class
//


#pragma once
#include"MazeTraversal.h"


class CHomework5Doc : public CDocument
{
protected: // create from serialization only
	CHomework5Doc() noexcept;
	DECLARE_DYNCREATE(CHomework5Doc)

// Attributes
public:

// Operations
public:
	MazeTraversal Mazeptr;
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CHomework5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
