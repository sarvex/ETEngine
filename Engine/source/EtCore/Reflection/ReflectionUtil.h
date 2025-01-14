#pragma once


namespace et {
namespace core {


//---------------------------------
// reflection
//
// utility functions using the reflection system
//
namespace reflection
{


template<typename TEnum>
std::string EnumString(TEnum const value);

template<typename TEnum>
TEnum EnumFromString(std::string const& value);

template<typename TEnum>
bool EnumFromStringSafe(std::string const& value, TEnum& outEnum);


enum class E_MetaData
{
	VectorType,
	AssetType
};


}


} // namespace core
} // namespace et


#include "ReflectionUtil.inl"
