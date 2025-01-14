#include "stdafx.h"
#include "GtkUtil.h"

#include <gdk/gdkkeysyms.h>
#include <gdk/gdk.h>


namespace et {
namespace edit {


//===========
// GTK Util
//===========


//---------------------------------
// GtkUtil::GetButtonFromGtk
//
// Convert GTK mouse button codes to the input managers buttons
//
E_MouseButton GtkUtil::GetButtonFromGtk(uint32 const buttonCode)
{
	switch (buttonCode)
	{
	case 1: return E_MouseButton::Left;
	case 2: return E_MouseButton::Center;
	case 3: return E_MouseButton::Right;

	default: return E_MouseButton::COUNT; // invalid button code
	}
}

//---------------------------------
// GtkUtil::GetButtonFromGtk
//
// Convert GTK key codes to the input managers keys
//
E_KbdKey GtkUtil::GetKeyFromGtk(uint32 const keyCode)
{
	switch (keyCode)
	{
	case GDK_KEY_space: return E_KbdKey::Space;
	case GDK_KEY_quoteright: return E_KbdKey::Apostrophe;
	case GDK_KEY_comma: return E_KbdKey::Comma;
	case GDK_KEY_minus: return E_KbdKey::Minus;
	case GDK_KEY_period: return E_KbdKey::Period;
	case GDK_KEY_slash: return E_KbdKey::Slash;

	case GDK_KEY_0: return E_KbdKey::Num_0;
	case GDK_KEY_1: return E_KbdKey::Num_1;
	case GDK_KEY_2: return E_KbdKey::Num_2;
	case GDK_KEY_3: return E_KbdKey::Num_3;
	case GDK_KEY_4: return E_KbdKey::Num_4;
	case GDK_KEY_5: return E_KbdKey::Num_5;
	case GDK_KEY_6: return E_KbdKey::Num_6;
	case GDK_KEY_7: return E_KbdKey::Num_7;
	case GDK_KEY_8: return E_KbdKey::Num_8;
	case GDK_KEY_9: return E_KbdKey::Num_9;

	case GDK_KEY_semicolon: return E_KbdKey::Semicolon;
	case GDK_KEY_equal: return E_KbdKey::Equal;

	case GDK_KEY_a: case GDK_KEY_A: return E_KbdKey::A;
	case GDK_KEY_b: case GDK_KEY_B: return E_KbdKey::B;
	case GDK_KEY_c: case GDK_KEY_C: return E_KbdKey::C;
	case GDK_KEY_d: case GDK_KEY_D: return E_KbdKey::D;
	case GDK_KEY_e: case GDK_KEY_E: return E_KbdKey::E;
	case GDK_KEY_f: case GDK_KEY_F: return E_KbdKey::F;
	case GDK_KEY_g: case GDK_KEY_G: return E_KbdKey::G;
	case GDK_KEY_h: case GDK_KEY_H: return E_KbdKey::H;
	case GDK_KEY_i: case GDK_KEY_I: return E_KbdKey::I;
	case GDK_KEY_j: case GDK_KEY_J: return E_KbdKey::J;
	case GDK_KEY_k: case GDK_KEY_K: return E_KbdKey::K;
	case GDK_KEY_l: case GDK_KEY_L: return E_KbdKey::L;
	case GDK_KEY_m: case GDK_KEY_M: return E_KbdKey::M;
	case GDK_KEY_n: case GDK_KEY_N: return E_KbdKey::N;
	case GDK_KEY_o: case GDK_KEY_O: return E_KbdKey::O;
	case GDK_KEY_p: case GDK_KEY_P: return E_KbdKey::P;
	case GDK_KEY_q: case GDK_KEY_Q: return E_KbdKey::Q;
	case GDK_KEY_r: case GDK_KEY_R: return E_KbdKey::R;
	case GDK_KEY_s: case GDK_KEY_S: return E_KbdKey::S;
	case GDK_KEY_t: case GDK_KEY_T: return E_KbdKey::T;
	case GDK_KEY_u: case GDK_KEY_U: return E_KbdKey::U;
	case GDK_KEY_v: case GDK_KEY_V: return E_KbdKey::V;
	case GDK_KEY_w: case GDK_KEY_W: return E_KbdKey::W;
	case GDK_KEY_x: case GDK_KEY_X: return E_KbdKey::X;
	case GDK_KEY_y: case GDK_KEY_Y: return E_KbdKey::Y;
	case GDK_KEY_z: case GDK_KEY_Z: return E_KbdKey::Z;

	case GDK_KEY_bracketleft: return E_KbdKey::LeftBracket;
	case GDK_KEY_backslash: return E_KbdKey::Backslash;
	case GDK_KEY_bracketright: return E_KbdKey::RightBracket;
	case GDK_KEY_quoteleft: return E_KbdKey::GraveAccent;
	case GDK_KEY_exclamdown: return E_KbdKey::World_1;
	case GDK_KEY_cent: return E_KbdKey::World_2;

	case GDK_KEY_Escape: return E_KbdKey::Escape;
	case GDK_KEY_Return: return E_KbdKey::Return;
	case GDK_KEY_Tab: return E_KbdKey::Tab;
	case GDK_KEY_BackSpace: return E_KbdKey::Backspace;
	case GDK_KEY_Insert: return E_KbdKey::Insert;
	case GDK_KEY_Delete: return E_KbdKey::Delete;
	case GDK_KEY_Right: return E_KbdKey::Right;
	case GDK_KEY_Left: return E_KbdKey::Left;
	case GDK_KEY_Down: return E_KbdKey::Down;
	case GDK_KEY_Up: return E_KbdKey::Up;
	case GDK_KEY_Page_Up: return E_KbdKey::PageUp;
	case GDK_KEY_Page_Down: return E_KbdKey::PageDown;
	case GDK_KEY_Home: return E_KbdKey::Home;
	case GDK_KEY_End: return E_KbdKey::End;
	case GDK_KEY_Caps_Lock: return E_KbdKey::CapsLock;
	case GDK_KEY_Scroll_Lock: return E_KbdKey::ScrollLock;
	case GDK_KEY_Num_Lock: return E_KbdKey::NumLock;
	case GDK_KEY_Print: return E_KbdKey::PrintScreen;
	case GDK_KEY_Pause: return E_KbdKey::Pause;

	case GDK_KEY_F1: return E_KbdKey::F1;
	case GDK_KEY_F2: return E_KbdKey::F2;
	case GDK_KEY_F3: return E_KbdKey::F3;
	case GDK_KEY_F4: return E_KbdKey::F4;
	case GDK_KEY_F5: return E_KbdKey::F5;
	case GDK_KEY_F6: return E_KbdKey::F6;
	case GDK_KEY_F7: return E_KbdKey::F7;
	case GDK_KEY_F8: return E_KbdKey::F8;
	case GDK_KEY_F9: return E_KbdKey::F9;
	case GDK_KEY_F10: return E_KbdKey::F10;
	case GDK_KEY_F11: return E_KbdKey::F11;
	case GDK_KEY_F12: return E_KbdKey::F12;
	case GDK_KEY_F13: return E_KbdKey::F13;
	case GDK_KEY_F14: return E_KbdKey::F14;
	case GDK_KEY_F15: return E_KbdKey::F15;
	case GDK_KEY_F16: return E_KbdKey::F16;
	case GDK_KEY_F17: return E_KbdKey::F17;
	case GDK_KEY_F18: return E_KbdKey::F18;
	case GDK_KEY_F19: return E_KbdKey::F19;
	case GDK_KEY_F20: return E_KbdKey::F20;
	case GDK_KEY_F21: return E_KbdKey::F21;
	case GDK_KEY_F22: return E_KbdKey::F22;
	case GDK_KEY_F23: return E_KbdKey::F23;
	case GDK_KEY_F24: return E_KbdKey::F24;
	case GDK_KEY_F25: return E_KbdKey::F25;

	case GDK_KEY_KP_0: return E_KbdKey::KP_0;
	case GDK_KEY_KP_1: return E_KbdKey::KP_1;
	case GDK_KEY_KP_2: return E_KbdKey::KP_2;
	case GDK_KEY_KP_3: return E_KbdKey::KP_3;
	case GDK_KEY_KP_4: return E_KbdKey::KP_4;
	case GDK_KEY_KP_5: return E_KbdKey::KP_5;
	case GDK_KEY_KP_6: return E_KbdKey::KP_6;
	case GDK_KEY_KP_7: return E_KbdKey::KP_7;
	case GDK_KEY_KP_8: return E_KbdKey::KP_8;
	case GDK_KEY_KP_9: return E_KbdKey::KP_9;

	case GDK_KEY_KP_Decimal: return E_KbdKey::KP_Decimal;
	case GDK_KEY_KP_Divide: return E_KbdKey::KP_Divide;
	case GDK_KEY_KP_Multiply: return E_KbdKey::KP_Mult;
	case GDK_KEY_KP_Subtract: return E_KbdKey::KP_Minus;
	case GDK_KEY_KP_Add: return E_KbdKey::KP_Plus;
	case GDK_KEY_KP_Enter: return E_KbdKey::KP_Enter;
	case GDK_KEY_KP_Equal: return E_KbdKey::KP_Equal;

	case GDK_KEY_Shift_L: return E_KbdKey::LeftShift;
	case GDK_KEY_Control_L: return E_KbdKey::LeftControl;
	case GDK_KEY_Alt_L: return E_KbdKey::LeftAlt;
	case GDK_KEY_Super_L: return E_KbdKey::LeftSuper;
	case GDK_KEY_Shift_R: return E_KbdKey::RightShift;
	case GDK_KEY_Control_R: return E_KbdKey::RightControl;
	case GDK_KEY_Alt_R: return E_KbdKey::RightAlt;
	case GDK_KEY_Super_R: return E_KbdKey::RightSuper;
	case GDK_KEY_Menu: return E_KbdKey::Menu;

	default: return E_KbdKey::Invalid;
	}
}

//---------------------------------
// GtkUtil::GetModifiersFromGtk
//
// Convert GTK modifier bitmask to the corresponding input manager version
//
core::T_KeyModifierFlags GtkUtil::GetModifiersFromGtk(uint32 const modifierState)
{
	core::T_KeyModifierFlags ret = 0u;

	if (modifierState & GdkModifierType::GDK_SHIFT_MASK)
	{
		ret |= core::E_KeyModifier::KM_Shift;
	}

	if (modifierState & GdkModifierType::GDK_CONTROL_MASK)
	{
		ret |= core::E_KeyModifier::KM_Control;
	}

	if (modifierState & GdkModifierType::GDK_MOD1_MASK)
	{
		ret |= core::E_KeyModifier::KM_Alt;
	}

	if (modifierState & GdkModifierType::GDK_SUPER_MASK)
	{
		ret |= core::E_KeyModifier::KM_Super;
	}

	if (modifierState & GdkModifierType::GDK_LOCK_MASK)
	{
		ret |= core::E_KeyModifier::KM_CapsLock;
	}

	// no clearly defined mask for Num Lock
	//if (modifierState & GdkModifierType)
	//{
	//	ret |= core::E_KeyModifier::KM_NumLock;
	//}

	return ret;
}


} // namespace edit
} // namespace et
