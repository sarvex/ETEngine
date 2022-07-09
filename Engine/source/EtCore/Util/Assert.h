#pragma once
#include <EtCore/Util/Logger.h>

#include "CommonMacros.h"
#include "StringUtil.h"


// when is it enabled
//====================

#ifdef ET_SHIPPING
#	define ET_ASSERT_ENABLED false
#else
#	define ET_ASSERT_ENABLED true
#endif // ET_SHIPPING



// implementation
//=================


#if ET_ASSERT_ENABLED

namespace et { namespace detail {
	bool ProcessAssert(bool const condition, std::string const& caller, std::string const& msg);
} } 


#	define ET_ASSERT_HANDLER_DEFAULT() ET_BREAK();


#	ifdef ET_PLATFORM_WIN
#		define ET_PROCESS_ASSERT_IMPL(condition, ...) et::detail::ProcessAssert(condition, __FUNCSIG__, FS(__VA_ARGS__))
#	else
#		define ET_PROCESS_ASSERT_IMPL(condition, ...) et::detail::ProcessAssert(condition, __PRETTY_FUNCTION__, FS(__VA_ARGS__))
#	endif // ET_PLATFORM_WIN														


#	define ET_ASSERT_IMPL(condition, ...)\
	__pragma(warning(push))\
	__pragma(warning(disable: 4127))\
	do\
	{\
		if (ET_PROCESS_ASSERT_IMPL(condition, __VA_ARGS__)) ET_ASSERT_HANDLER_DEFAULT();\
	}\
	while (false)\
	__pragma(warning(pop))

#endif // ET_ASSERT_ENABLED



// assert macros
//=================


#if ET_ASSERT_ENABLED
#	define ET_ASSERT(condition, ...) ET_ASSERT_IMPL(condition, __VA_ARGS__)
#else
#	define ET_ASSERT(condition, ...)
#endif // ET_ASSERT_ENABLED

// for performance critical code
#define ET_PARANOID_ASSERTS_ENABLED false

#if ET_PARANOID_ASSERTS_ENABLED
#	define ET_ASSERT_PARANOID(condition, ...) ET_ASSERT(condition, __VA_ARGS__)
#else
#	define ET_ASSERT_PARANOID(condition, ...)
#endif

