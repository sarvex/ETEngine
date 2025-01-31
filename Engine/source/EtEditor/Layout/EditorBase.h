#pragma once
#include "EditorNodeHierachy.h"
#include "EditorNode.h"
#include "EditorTool.h"

#include <gdk/gdk.h>


namespace et {
namespace edit {


class EditorToolNode;


//---------------------------------
// EditorBase
//
// Abstract editor that could manipulate some sort of resource. The init function should attach the editors UI to the parent frame 
//
class EditorBase
{
public:
	virtual ~EditorBase() = default;

	// interface
	//------------
protected:
	virtual void InitInternal() = 0;
public:
	virtual std::string const& GetName() const = 0;
	virtual std::string const& GetLayoutName() const = 0;
	virtual std::vector<E_EditorTool> const& GetSupportedTools() const = 0;

	virtual bool OnKeyEvent(bool const pressed, GdkEventKey* const evnt);

	// accessors
	//-----------
	Gtk::Frame* GetRoot();
	EditorNodeHierachy& GetHierachy() { return m_NodeHierachy; }

	// functionality
	//------------------
	void Init(Gtk::Frame* const parent);
	void SaveLayout();

	void QueueNodeForSplit(WeakPtr<EditorToolNode> const& node);
	void QueueNodeForCollapse(WeakPtr<EditorToolNode> const& node);

	// utility
	//---------
	void OnAllocationAvailable();
private:
	void ProcessLayoutChanges();

	// Data
	///////

protected:
	EditorNodeHierachy m_NodeHierachy;

private:
	std::vector<WeakPtr<EditorToolNode>> m_QueuedSplits;
	std::vector<WeakPtr<EditorToolNode>> m_QueuedCollapse;

	bool m_HasInitialSize = false;
};


} // namespace edit
} // namespace et
