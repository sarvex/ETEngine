#pragma once
#include <EtRendering/GraphicsContext/ViewportEvents.h>


// fwd
namespace Rml {
	class Context;
}


namespace et {
namespace gui {


//---------------------------------
// Context
//
// Context for RML UI documents
//  - for now all contexts are screen space and the same size as the viewport
//
class Context
{
public:
	// construct destruct
	//--------------------
	Context() = default;
	~Context();

	void Init(std::string const& name, ivec2 const dimensions);

	// functionality
	//---------------
	void SetActive(bool const isActive) { m_Active = isActive; }
	void SetDimensions(ivec2 const dimensions);

	void LoadDocument(core::HashString const documentId);
	void UnloadDocument();

	// accessors
	//-----------
	bool IsActive() const { return m_Active; }
	bool IsDocumentLoaded() const { return !m_Document.IsEmpty(); }

	// Data
	///////

private:
	Ptr<Rml::Context> m_Context;
	bool m_Active = true;
	core::HashString m_Document; // # temp
};


} // namespace gui
} // namespace et

