#pragma once


namespace et {
namespace fw {


//====================
// Component Registry
//====================


//-----------------------------
// ComponentRegistry::Register
//
// Register a component type and return its type index
//
template<typename TComponentType>
T_CompTypeIdx ComponentRegistry::Register()
{
	// create type info from the template data
	ComponentTypeInfo ti(rttr::type::get<TComponentType>(), sizeof(TComponentType));

	ti.copyAssign = [](void const* const source, void* const target) -> void
	{
		new (static_cast<TComponentType*>(target)) TComponentType(*static_cast<TComponentType const*>(source));
	};

	ti.destructor = [](void const* const lhs) -> void
	{
		static_cast<TComponentType const*>(lhs)->~TComponentType();
	};

	ti.fullDestructor = [](void const* const lhs) -> void
	{
		delete static_cast<TComponentType const*>(lhs);
	};

	// ensure we only register components once
	ET_ASSERT(GetTypeIdx(ti.type) == s_InvalidTypeIdx, "Component '%s' was already registered!", ti.type.get_name().data());

	// next free index
	T_CompTypeIdx const idx = static_cast<T_CompTypeIdx>(m_ComponentTypes.size()); 

	m_ComponentTypes.emplace_back(ti);

	return idx;
}


//=====================
// Component Type List
//=====================


namespace detail {

	//-----------------------------
	// CompTypeListAdder
	//
	// implements a recursive variadic template
	//
	template <typename... Args>
	struct CompTypeListAdder;

	template<typename TComponentType>
	struct CompTypeListAdder<TComponentType>
	{
		static void Call(T_CompTypeList& list)
		{
			list.emplace_back(TComponentType::GetTypeIndex());
		}
	};

	template<typename TComponentType, typename... Args>
	struct CompTypeListAdder<TComponentType, Args...>
	{
		static void Call(T_CompTypeList& list)
		{
			list.emplace_back(TComponentType::GetTypeIndex());
			CompTypeListAdder<Args...>::Call(list);
		}
	};

} // namespace detail

//-----------------------------
// GenCompTypeList
//
// Generate a list of components from their types
//
template<typename... Args>
T_CompTypeList GenCompTypeList()
{
	T_CompTypeList ret;
	detail::CompTypeListAdder<Args...>::Call(ret);
	return ret;
}


} // namespace fw
} // namespace et
