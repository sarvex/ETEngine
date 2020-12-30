#pragma once

#define NOMINMAX

//#define GRAPHICS_API_DEBUG
//#define GRAPHICS_API_VERBOSE

#pragma region
//C RunTime Header Files
#include <wchar.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#pragma endregion stl

#pragma region
#include <EtCore/stdafx.h>
#include <EtCore/UpdateCycle/PerformanceInfo.h>
#include <EtCore/Hashing/Hash.h>

#include <EtRendering/GraphicsContext/GraphicsContextApi.h>
#include <EtRendering/GraphicsContext/ContextHolder.h>
#include <EtRendering/GraphicsContext/Viewport.h>
#pragma endregion Includes