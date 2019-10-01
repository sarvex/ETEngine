#pragma once

#include <gtkmm/treestore.h>
#include <gtkmm/treemodelcolumn.h>
#include <glibmm/refptr.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treeselection.h>

#include <EtEditor/SceneSelection.h>


namespace Gtk {
	class TreeView;
	class TreeViewColumn;
}

//--------------------
// Outliner
//
// visual representation of the scene hierachy and selection
//
class Outliner final : public I_SceneSelectionListener
{
public:
	// definitions
	//--------------------
	class ModelColumns : public Gtk::TreeModelColumnRecord
	{
	public:

		ModelColumns()
		{
			add(m_Name);
			add(m_Id);
			add(m_Entity);
		}

		Gtk::TreeModelColumn<Glib::ustring> m_Name;
		Gtk::TreeModelColumn<T_Hash> m_Id;
		Gtk::TreeModelColumn<Entity*> m_Entity;
	};

	// construct destruct
	//--------------------
	Outliner(SceneSelection* sceneSelection, Gtk::TreeView* treeView);
	~Outliner();

	// scene selection listener interface
	//--------------------------------------
protected:
	void OnSceneEvent(SceneEventData const* const eventData);

	// Functionality
	//-------------------
private:
	void OnTreeViewRowActivated(Gtk::TreeModel::Path const& path, Gtk::TreeViewColumn* const column);
	void OnSelectionChanged();

	void RefillTreeView();

	// Data
	///////

	Gtk::TreeView* m_TreeView;

	ModelColumns m_Columns;
	Glib::RefPtr<Gtk::TreeStore> m_TreeModel;
	Glib::RefPtr<Gtk::TreeSelection> m_TreeSelection;

	SceneSelection* m_SceneSelection;
};
