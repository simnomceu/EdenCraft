/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooo   oooooo     oooo  o8o                    .o8
															 `888.    `888.     .8'   `"'                   "888
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'


				This file is part of EdenCraft Engine - Window module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "window/pch.hpp"
#include "window/event/keyboard.hpp"

#include <X11/keysym.h>

namespace ece
{
	namespace window
	{
		namespace event
		{
			auto Keyboard::getKey(const unsigned int keycode) -> Keyboard::Key
			{
				auto key = Keyboard::Key::NONE;
				switch (keycode) {
			#ifdef XK_MISCELLANY
				case XK_BackSpace: key = Keyboard::Key::BACKSPACE; break;  /* Back space, back char */
				case XK_Tab: key = Keyboard::Key::TAB; break;
				case XK_Linefeed            : break;  /* Linefeed, LF */
				case XK_Clear               : break;
				case XK_Return: key = Keyboard::Key::RETURN; break;  /* Return, enter */
				case XK_Pause: key = Keyboard::Key::PAUSE; break;  /* Pause, hold */
				case XK_Scroll_Lock         : break;
				case XK_Sys_Req             : break;
				case XK_Escape: key = Keyboard::Key::ESCAPE; break;
				case XK_Delete: key = Keyboard::Key::DEL; break;  /* Delete, rubout */
				case XK_Multi_key           : break;  /* Multi-key character compose */
				case XK_Codeinput           : break;
				case XK_SingleCandidate     : break;
				case XK_MultipleCandidate   : break;
				case XK_PreviousCandidate   : break;
				case XK_Kanji               : break;  /* Kanji, Kanji convert */
				case XK_Muhenkan            : break;  /* Cancel Conversion */
//				case XK_Henkan_Mode         : break;  /* Start/Stop Conversion */
				case XK_Henkan              : break;  /* Alias for Henkan_Mode */
				case XK_Romaji              : break;  /* to Romaji */
				case XK_Hiragana            : break;  /* to Hiragana */
				case XK_Katakana            : break;  /* to Katakana */
				case XK_Hiragana_Katakana   : break;  /* Hiragana/Katakana toggle */
				case XK_Zenkaku             : break;  /* to Zenkaku */
				case XK_Hankaku             : break;  /* to Hankaku */
				case XK_Zenkaku_Hankaku     : break;  /* Zenkaku/Hankaku toggle */
				case XK_Touroku             : break;  /* Add to Dictionary */
				case XK_Massyo              : break;  /* Delete from Dictionary */
				case XK_Kana_Lock           : break;  /* Kana Lock */
				case XK_Kana_Shift          : break;  /* Kana Shift */
				case XK_Eisu_Shift          : break;  /* Alphanumeric Shift */
				case XK_Eisu_toggle         : break;  /* Alphanumeric toggle */
//				case XK_Kanji_Bangou        : break;  /* Codeinput */
//				case XK_Zen_Koho            : break;  /* Multiple/All Candidate(s) */
//				case XK_Mae_Koho            : break;  /* Previous Candidate */
				case XK_Home: key = Keyboard::Key::HOME; break;
				case XK_Left: key = Keyboard::Key::LEFT; break;  /* Move left, left arrow */
				case XK_Up: key = Keyboard::Key::UP; break;  /* Move up, up arrow */
				case XK_Right: key = Keyboard::Key::RIGHT; break;  /* Move right, right arrow */
				case XK_Down: key = Keyboard::Key::DOWN; break;  /* Move down, down arrow */
//				case XK_Prior               : break;  /* Prior, previous */
				case XK_Page_Up: key = Keyboard::Key::PAGE_UP; break;
//				case XK_Next                : break;  /* Next */
				case XK_Page_Down: key = Keyboard::Key::PAGE_DOWN; break;
				case XK_End: key = Keyboard::Key::END; break;  /* EOL */
				case XK_Begin               : break;  /* BOL */
				case XK_Select              : break;  /* Select, mark */
				case XK_Print               : break;
				case XK_Execute             : break;  /* Execute, run, do */
				case XK_Insert: key = Keyboard::Key::INS; break;  /* Insert, insert here */
				case XK_Undo                : break;
				case XK_Redo                : break;  /* Redo, again */
				case XK_Menu                : break;
				case XK_Find                : break;  /* Find, search */
				case XK_Cancel              : break;  /* Cancel, stop, abort, exit */
				case XK_Help: key = Keyboard::Key::HELP; break;  /* Help */
				case XK_Break               : break;
				case XK_Mode_switch         : break;  /* Character set switch */
//				case XK_script_switch       : break;  /* Alias for mode_switch */
				case XK_Num_Lock: key = Keyboard::Key::NUMLOCK; break;
				case XK_KP_Space: key = Keyboard::Key::BACKSPACE; break;  /* Space */
				case XK_KP_Tab: key = Keyboard::Key::TAB; break;
				case XK_KP_Enter: key = Keyboard::Key::RETURN; break;  /* Enter */
				case XK_KP_F1: key = Keyboard::Key::F1; break;  /* PF1, KP_A, ... */
				case XK_KP_F2: key = Keyboard::Key::F2; break;
				case XK_KP_F3: key = Keyboard::Key::F3; break;
				case XK_KP_F4: key = Keyboard::Key::F4; break;
				case XK_KP_Home: key = Keyboard::Key::HOME; break;
				case XK_KP_Left: key = Keyboard::Key::LEFT; break;
				case XK_KP_Up: key = Keyboard::Key::UP; break;
				case XK_KP_Right: key = Keyboard::Key::RIGHT; break;
				case XK_KP_Down: key = Keyboard::Key::DOWN; break;
//				case XK_KP_Prior            : break;
				case XK_KP_Page_Up: key = Keyboard::Key::PAGE_UP; break;
//				case XK_KP_Next             : break;
				case XK_KP_Page_Down: key = Keyboard::Key::PAGE_DOWN; break;
				case XK_KP_End: key = Keyboard::Key::END; break;
				case XK_KP_Begin            : break;
				case XK_KP_Insert: key = Keyboard::Key::INS; break;
				case XK_KP_Delete: key = Keyboard::Key::DEL; break;
				case XK_KP_Equal            : break;  /* Equals */
				case XK_KP_Multiply: key = Keyboard::Key::MULTIPLY; break;
				case XK_KP_Add: key = Keyboard::Key::ADD; break;
				case XK_KP_Separator        : break;  /* Separator, often comma */
				case XK_KP_Subtract: key = Keyboard::Key::SUBSTRACT; break;
				case XK_KP_Decimal          : break;
				case XK_KP_Divide: key = Keyboard::Key::DIVIDE; break;
				case XK_KP_0: key = Keyboard::Key::NUMPAD_0; break;
				case XK_KP_1: key = Keyboard::Key::NUMPAD_1; break;
				case XK_KP_2: key = Keyboard::Key::NUMPAD_2; break;
				case XK_KP_3: key = Keyboard::Key::NUMPAD_3; break;
				case XK_KP_4: key = Keyboard::Key::NUMPAD_4; break;
				case XK_KP_5: key = Keyboard::Key::NUMPAD_5; break;
				case XK_KP_6: key = Keyboard::Key::NUMPAD_6; break;
				case XK_KP_7: key = Keyboard::Key::NUMPAD_7; break;
				case XK_KP_8: key = Keyboard::Key::NUMPAD_8; break;
				case XK_KP_9: key = Keyboard::Key::NUMPAD_9; break;
				case XK_F1: key = Keyboard::Key::F1; break;
				case XK_F2: key = Keyboard::Key::F2; break;
				case XK_F3: key = Keyboard::Key::F3; break;
				case XK_F4: key = Keyboard::Key::F4; break;
				case XK_F5: key = Keyboard::Key::F5; break;
				case XK_F6: key = Keyboard::Key::F6; break;
				case XK_F7: key = Keyboard::Key::F7; break;
				case XK_F8: key = Keyboard::Key::F8; break;
				case XK_F9: key = Keyboard::Key::F9; break;
				case XK_F10: key = Keyboard::Key::F10; break;
				case XK_F11: key = Keyboard::Key::F11; break;
//				case XK_L1                  : break;
				case XK_F12: key = Keyboard::Key::F12; break;
//				case XK_L2                  : break;
				case XK_F13: key = Keyboard::Key::F13; break;
//				case XK_L3                  : break;
				case XK_F14: key = Keyboard::Key::F14; break;
//				case XK_L4                  : break;
				case XK_F15: key = Keyboard::Key::F15; break;
//				case XK_L5                  : break;
				case XK_F16: key = Keyboard::Key::F16; break;
//				case XK_L6                  : break;
				case XK_F17: key = Keyboard::Key::F17; break;
//				case XK_L7                  : break;
				case XK_F18: key = Keyboard::Key::F18; break;
//				case XK_L8                  : break;
				case XK_F19: key = Keyboard::Key::F19; break;
//				case XK_L9                  : break;
				case XK_F20: key = Keyboard::Key::F20; break;
//				case XK_L10                 : break;
				case XK_F21: key = Keyboard::Key::F21; break;
//				case XK_R1                  : break;
				case XK_F22: key = Keyboard::Key::F22; break;
//				case XK_R2                  : break;
				case XK_F23: key = Keyboard::Key::F23; break;
//				case XK_R3                  : break;
				case XK_F24: key = Keyboard::Key::F24; break;
//				case XK_R4                  : break;
				case XK_F25: break;
//				case XK_R5                  : break;
				case XK_F26: break;
//				case XK_R6                  : break;
				case XK_F27: break;
//				case XK_R7                  : break;
				case XK_F28: break;
//				case XK_R8                  : break;
				case XK_F29: break;
//				case XK_R9                  : break;
				case XK_F30: break;
//				case XK_R10                 : break;
				case XK_F31: break;
//				case XK_R11                 : break;
				case XK_F32: break;
//				case XK_R12                 : break;
				case XK_F33: break;
//				case XK_R13                 : break;
				case XK_F34: break;
//				case XK_R14                 : break;
				case XK_F35: break;
//				case XK_R15                 : break;
				case XK_Shift_L             : break;  /* Left shift */
				case XK_Shift_R             : break;  /* Right shift */
				case XK_Control_L           : break;  /* Left control */
				case XK_Control_R           : break;  /* Right control */
				case XK_Caps_Lock: key = Keyboard::Key::CAPS_LOCK; break;  /* Caps lock */
				case XK_Shift_Lock          : break;  /* Shift lock */
				case XK_Meta_L              : break;  /* Left meta */
				case XK_Meta_R              : break;  /* Right meta */
				case XK_Alt_L               : break;  /* Left alt */
				case XK_Alt_R               : break;  /* Right alt */
				case XK_Super_L             : break;  /* Left super */
				case XK_Super_R             : break;  /* Right super */
				case XK_Hyper_L             : break;  /* Left hyper */
				case XK_Hyper_R             : break;  /* Right hyper */
			#endif /* XK_MISCELLANY */
			#ifdef XK_XKB_KEYS
				case XK_ISO_Lock                   : break;
				case XK_ISO_Level2_Latch           : break;
				case XK_ISO_Level3_Shift           : break;
				case XK_ISO_Level3_Latch           : break;
				case XK_ISO_Level3_Lock            : break;
			#ifndef XK_MISCELLANY
				case XK_ISO_Group_Shift            : break;  /* Alias for mode_switch */
			#endif
				case XK_ISO_Group_Latch            : break;
				case XK_ISO_Group_Lock             : break;
				case XK_ISO_Next_Group             : break;
				case XK_ISO_Next_Group_Lock        : break;
				case XK_ISO_Prev_Group             : break;
				case XK_ISO_Prev_Group_Lock        : break;
				case XK_ISO_First_Group            : break;
				case XK_ISO_First_Group_Lock       : break;
				case XK_ISO_Last_Group             : break;
				case XK_ISO_Last_Group_Lock        : break;
				case XK_ISO_Left_Tab               : break;
				case XK_ISO_Move_Line_Up           : break;
				case XK_ISO_Move_Line_Down         : break;
				case XK_ISO_Partial_Line_Up        : break;
				case XK_ISO_Partial_Line_Down      : break;
				case XK_ISO_Partial_Space_Left     : break;
				case XK_ISO_Partial_Space_Right    : break;
				case XK_ISO_Set_Margin_Left        : break;
				case XK_ISO_Set_Margin_Right       : break;
				case XK_ISO_Release_Margin_Left    : break;
				case XK_ISO_Release_Margin_Right   : break;
				case XK_ISO_Release_Both_Margins   : break;
				case XK_ISO_Fast_Cursor_Left       : break;
				case XK_ISO_Fast_Cursor_Right      : break;
				case XK_ISO_Fast_Cursor_Up         : break;
				case XK_ISO_Fast_Cursor_Down       : break;
				case XK_ISO_Continuous_Underline   : break;
				case XK_ISO_Discontinuous_Underline: break;
				case XK_ISO_Emphasize              : break;
				case XK_ISO_Center_Object          : break;
				case XK_ISO_Enter                  : break;
				case XK_dead_grave                 : break;
				case XK_dead_acute                 : break;
				case XK_dead_circumflex            : break;
				case XK_dead_tilde                 : break;
				case XK_dead_macron                : break;
				case XK_dead_breve                 : break;
				case XK_dead_abovedot              : break;
				case XK_dead_diaeresis             : break;
				case XK_dead_abovering             : break;
				case XK_dead_doubleacute           : break;
				case XK_dead_caron                 : break;
				case XK_dead_cedilla               : break;
				case XK_dead_ogonek                : break;
				case XK_dead_iota                  : break;
				case XK_dead_voiced_sound          : break;
				case XK_dead_semivoiced_sound      : break;
				case XK_dead_belowdot              : break;
				case XK_dead_hook                  : break;
				case XK_dead_horn                  : break;
				case XK_First_Virtual_Screen       : break;
				case XK_Prev_Virtual_Screen        : break;
				case XK_Next_Virtual_Screen        : break;
				case XK_Last_Virtual_Screen        : break;
				case XK_Terminate_Server           : break;
				case XK_AccessX_Enable             : break;
				case XK_AccessX_Feedback_Enable    : break;
				case XK_RepeatKeys_Enable          : break;
				case XK_SlowKeys_Enable            : break;
				case XK_BounceKeys_Enable          : break;
				case XK_StickyKeys_Enable          : break;
				case XK_MouseKeys_Enable           : break;
				case XK_MouseKeys_Accel_Enable     : break;
				case XK_Overlay1_Enable            : break;
				case XK_Overlay2_Enable            : break;
				case XK_AudibleBell_Enable         : break;
				case XK_Pointer_Left               : break;
				case XK_Pointer_Right              : break;
				case XK_Pointer_Up                 : break;
				case XK_Pointer_Down               : break;
				case XK_Pointer_UpLeft             : break;
				case XK_Pointer_UpRight            : break;
				case XK_Pointer_DownLeft           : break;
				case XK_Pointer_DownRight          : break;
				case XK_Pointer_Button_Dflt        : break;
				case XK_Pointer_Button1            : break;
				case XK_Pointer_Button2            : break;
				case XK_Pointer_Button3            : break;
				case XK_Pointer_Button4            : break;
				case XK_Pointer_Button5            : break;
				case XK_Pointer_DblClick_Dflt      : break;
				case XK_Pointer_DblClick1          : break;
				case XK_Pointer_DblClick2          : break;
				case XK_Pointer_DblClick3          : break;
				case XK_Pointer_DblClick4          : break;
				case XK_Pointer_DblClick5          : break;
				case XK_Pointer_Drag_Dflt          : break;
				case XK_Pointer_Drag1              : break;
				case XK_Pointer_Drag2              : break;
				case XK_Pointer_Drag3              : break;
				case XK_Pointer_Drag4              : break;
				case XK_Pointer_Drag5              : break;
				case XK_Pointer_EnableKeys         : break;
				case XK_Pointer_Accelerate         : break;
				case XK_Pointer_DfltBtnNext        : break;
				case XK_Pointer_DfltBtnPrev        : break;
			#endif /* XK_XKB_KEYS */
			#ifdef XK_3270
				case XK_3270_Duplicate        : break;
				case XK_3270_FieldMark        : break;
				case XK_3270_Right2           : break;
				case XK_3270_Left2            : break;
				case XK_3270_BackTab          : break;
				case XK_3270_EraseEOF         : break;
				case XK_3270_EraseInput       : break;
				case XK_3270_Reset            : break;
				case XK_3270_Quit             : break;
				case XK_3270_PA1              : break;
				case XK_3270_PA2              : break;
				case XK_3270_PA3              : break;
				case XK_3270_Test             : break;
				case XK_3270_Attn             : break;
				case XK_3270_CursorBlink      : break;
				case XK_3270_AltCursor        : break;
				case XK_3270_KeyClick         : break;
				case XK_3270_Jump             : break;
				case XK_3270_Ident            : break;
				case XK_3270_Rule             : break;
				case XK_3270_Copy             : break;
				case XK_3270_Play             : break;
				case XK_3270_Setup            : break;
				case XK_3270_Record           : break;
				case XK_3270_ChangeScreen     : break;
				case XK_3270_DeleteWord       : break;
				case XK_3270_ExSelect         : break;
				case XK_3270_CursorSelect     : break;
				case XK_3270_PrintScreen      : break;
				case XK_3270_Enter            : break;
			#endif /* XK_3270 */
			#ifdef XK_LATIN1
				case XK_space: key = Keyboard::Key::SPACEBAR; break;/* U+0020 SPACE */
				case XK_exclam                  : break;/* U+0021 EXCLAMATION MARK */
				case XK_quotedbl                : break;/* U+0022 QUOTATION MARK */
				case XK_numbersign              : break;/* U+0023 NUMBER SIGN */
				case XK_dollar                  : break;/* U+0024 DOLLAR SIGN */
				case XK_percent                 : break;/* U+0025 PERCENT SIGN */
				case XK_ampersand               : break;/* U+0026 AMPERSAND */
				case XK_apostrophe              : break;/* U+0027 APOSTROPHE */
				case XK_parenleft               : break;/* U+0028 LEFT PARENTHESIS */
				case XK_parenright              : break;/* U+0029 RIGHT PARENTHESIS */
				case XK_asterisk                : break;/* U+002A ASTERISK */
				case XK_plus                    : break;/* U+002B PLUS SIGN */
				case XK_comma                   : break;/* U+002C COMMA */
				case XK_minus                   : break;/* U+002D HYPHEN-MINUS */
				case XK_period                  : break;/* U+002E FULL STOP */
				case XK_slash                   : break;/* U+002F SOLIDUS */
				case XK_0                       : break;/* U+0030 DIGIT ZERO */
				case XK_1                       : break;/* U+0031 DIGIT ONE */
				case XK_2                       : break;/* U+0032 DIGIT TWO */
				case XK_3                       : break;/* U+0033 DIGIT THREE */
				case XK_4                       : break;/* U+0034 DIGIT FOUR */
				case XK_5                       : break;/* U+0035 DIGIT FIVE */
				case XK_6                       : break;/* U+0036 DIGIT SIX */
				case XK_7                       : break;/* U+0037 DIGIT SEVEN */
				case XK_8                       : break;/* U+0038 DIGIT EIGHT */
				case XK_9                       : break;/* U+0039 DIGIT NINE */
				case XK_colon                   : break;/* U+003A COLON */
				case XK_semicolon               : break;/* U+003B SEMICOLON */
				case XK_less                    : break;/* U+003C LESS-THAN SIGN */
				case XK_equal                   : break;/* U+003D EQUALS SIGN */
				case XK_greater                 : break;/* U+003E GREATER-THAN SIGN */
				case XK_question                : break;/* U+003F QUESTION MARK */
				case XK_at                      : break;/* U+0040 COMMERCIAL AT */
				case XK_A: key = Keyboard::Key::A; break;/* U+0041 LATIN CAPITAL LETTER A */
				case XK_B: key = Keyboard::Key::B; break;/* U+0042 LATIN CAPITAL LETTER B */
				case XK_C: key = Keyboard::Key::C; break;/* U+0043 LATIN CAPITAL LETTER C */
				case XK_D: key = Keyboard::Key::D; break;/* U+0044 LATIN CAPITAL LETTER D */
				case XK_E: key = Keyboard::Key::E; break;/* U+0045 LATIN CAPITAL LETTER E */
				case XK_F: key = Keyboard::Key::F; break;/* U+0046 LATIN CAPITAL LETTER F */
				case XK_G: key = Keyboard::Key::G; break;/* U+0047 LATIN CAPITAL LETTER G */
				case XK_H: key = Keyboard::Key::H; break;/* U+0048 LATIN CAPITAL LETTER H */
				case XK_I: key = Keyboard::Key::I; break;/* U+0049 LATIN CAPITAL LETTER I */
				case XK_J: key = Keyboard::Key::J; break;/* U+004A LATIN CAPITAL LETTER J */
				case XK_K: key = Keyboard::Key::K; break;/* U+004B LATIN CAPITAL LETTER K */
				case XK_L: key = Keyboard::Key::L; break;/* U+004C LATIN CAPITAL LETTER L */
				case XK_M: key = Keyboard::Key::M; break;/* U+004D LATIN CAPITAL LETTER M */
				case XK_N: key = Keyboard::Key::N; break;/* U+004E LATIN CAPITAL LETTER N */
				case XK_O: key = Keyboard::Key::O; break;/* U+004F LATIN CAPITAL LETTER O */
				case XK_P: key = Keyboard::Key::P; break;/* U+0050 LATIN CAPITAL LETTER P */
				case XK_Q: key = Keyboard::Key::Q; break;/* U+0051 LATIN CAPITAL LETTER Q */
				case XK_R: key = Keyboard::Key::R; break;/* U+0052 LATIN CAPITAL LETTER R */
				case XK_S: key = Keyboard::Key::S; break;/* U+0053 LATIN CAPITAL LETTER S */
				case XK_T: key = Keyboard::Key::T; break;/* U+0054 LATIN CAPITAL LETTER T */
				case XK_U: key = Keyboard::Key::U; break;/* U+0055 LATIN CAPITAL LETTER U */
				case XK_V: key = Keyboard::Key::V; break;/* U+0056 LATIN CAPITAL LETTER V */
				case XK_W: key = Keyboard::Key::W; break;/* U+0057 LATIN CAPITAL LETTER W */
				case XK_X: key = Keyboard::Key::X; break;/* U+0058 LATIN CAPITAL LETTER X */
				case XK_Y: key = Keyboard::Key::Y; break;/* U+0059 LATIN CAPITAL LETTER Y */
				case XK_Z: key = Keyboard::Key::Z; break;/* U+005A LATIN CAPITAL LETTER Z */
				case XK_bracketleft             : break;/* U+005B LEFT SQUARE BRACKET */
				case XK_backslash               : break;/* U+005C REVERSE SOLIDUS */
				case XK_bracketright            : break;/* U+005D RIGHT SQUARE BRACKET */
				case XK_asciicircum             : break;/* U+005E CIRCUMFLEX ACCENT */
				case XK_underscore              : break;/* U+005F LOW LINE */
				case XK_grave                   : break;/* U+0060 GRAVE ACCENT */
				case XK_a: key = Keyboard::Key::A; break;/* U+0061 LATIN SMALL LETTER A */
				case XK_b: key = Keyboard::Key::B; break;/* U+0062 LATIN SMALL LETTER B */
				case XK_c: key = Keyboard::Key::C; break;/* U+0063 LATIN SMALL LETTER C */
				case XK_d: key = Keyboard::Key::D; break;/* U+0064 LATIN SMALL LETTER D */
				case XK_e: key = Keyboard::Key::E; break;/* U+0065 LATIN SMALL LETTER E */
				case XK_f: key = Keyboard::Key::F; break;/* U+0066 LATIN SMALL LETTER F */
				case XK_g: key = Keyboard::Key::G; break;/* U+0067 LATIN SMALL LETTER G */
				case XK_h: key = Keyboard::Key::H; break;/* U+0068 LATIN SMALL LETTER H */
				case XK_i: key = Keyboard::Key::I; break;/* U+0069 LATIN SMALL LETTER I */
				case XK_j: key = Keyboard::Key::J; break;/* U+006A LATIN SMALL LETTER J */
				case XK_k: key = Keyboard::Key::K; break;/* U+006B LATIN SMALL LETTER K */
				case XK_l: key = Keyboard::Key::L; break;/* U+006C LATIN SMALL LETTER L */
				case XK_m: key = Keyboard::Key::M; break;/* U+006D LATIN SMALL LETTER M */
				case XK_n: key = Keyboard::Key::N; break;/* U+006E LATIN SMALL LETTER N */
				case XK_o: key = Keyboard::Key::O; break;/* U+006F LATIN SMALL LETTER O */
				case XK_p: key = Keyboard::Key::P; break;/* U+0070 LATIN SMALL LETTER P */
				case XK_q: key = Keyboard::Key::Q; break;/* U+0071 LATIN SMALL LETTER Q */
				case XK_r: key = Keyboard::Key::R; break;/* U+0072 LATIN SMALL LETTER R */
				case XK_s: key = Keyboard::Key::S; break;/* U+0073 LATIN SMALL LETTER S */
				case XK_t: key = Keyboard::Key::T; break;/* U+0074 LATIN SMALL LETTER T */
				case XK_u: key = Keyboard::Key::U; break;/* U+0075 LATIN SMALL LETTER U */
				case XK_v: key = Keyboard::Key::V; break;/* U+0076 LATIN SMALL LETTER V */
				case XK_w: key = Keyboard::Key::W; break;/* U+0077 LATIN SMALL LETTER W */
				case XK_x: key = Keyboard::Key::X; break;/* U+0078 LATIN SMALL LETTER X */
				case XK_y: key = Keyboard::Key::Y; break;/* U+0079 LATIN SMALL LETTER Y */
				case XK_z: key = Keyboard::Key::Z; break;/* U+007A LATIN SMALL LETTER Z */
				case XK_braceleft               : break;/* U+007B LEFT CURLY BRACKET */
				case XK_bar                     : break;/* U+007C VERTICAL LINE */
				case XK_braceright              : break;/* U+007D RIGHT CURLY BRACKET */
				case XK_asciitilde              : break;/* U+007E TILDE */
				case XK_nobreakspace            : break;/* U+00A0 NO-BREAK SPACE */
				case XK_exclamdown              : break;/* U+00A1 INVERTED EXCLAMATION MARK */
				case XK_cent                    : break;/* U+00A2 CENT SIGN */
				case XK_sterling                : break;/* U+00A3 POUND SIGN */
				case XK_currency                : break;/* U+00A4 CURRENCY SIGN */
				case XK_yen                     : break;/* U+00A5 YEN SIGN */
				case XK_brokenbar               : break;/* U+00A6 BROKEN BAR */
				case XK_section                 : break;/* U+00A7 SECTION SIGN */
				case XK_diaeresis               : break;/* U+00A8 DIAERESIS */
				case XK_copyright               : break;/* U+00A9 COPYRIGHT SIGN */
				case XK_ordfeminine             : break;/* U+00AA FEMININE ORDINAL INDICATOR */
				case XK_guillemotleft           : break;/* U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
				case XK_notsign                 : break;/* U+00AC NOT SIGN */
				case XK_hyphen                  : break;/* U+00AD SOFT HYPHEN */
				case XK_registered              : break;/* U+00AE REGISTERED SIGN */
				case XK_macron                  : break;/* U+00AF MACRON */
				case XK_degree                  : break;/* U+00B0 DEGREE SIGN */
				case XK_plusminus               : break;/* U+00B1 PLUS-MINUS SIGN */
				case XK_twosuperior             : break;/* U+00B2 SUPERSCRIPT TWO */
				case XK_threesuperior           : break;/* U+00B3 SUPERSCRIPT THREE */
				case XK_acute                   : break;/* U+00B4 ACUTE ACCENT */
				case XK_mu                      : break;/* U+00B5 MICRO SIGN */
				case XK_paragraph               : break;/* U+00B6 PILCROW SIGN */
				case XK_periodcentered          : break;/* U+00B7 MIDDLE DOT */
				case XK_cedilla                 : break;/* U+00B8 CEDILLA */
				case XK_onesuperior             : break;/* U+00B9 SUPERSCRIPT ONE */
				case XK_masculine               : break;/* U+00BA MASCULINE ORDINAL INDICATOR */
				case XK_guillemotright          : break;/* U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
				case XK_onequarter              : break;/* U+00BC VULGAR FRACTION ONE QUARTER */
				case XK_onehalf                 : break;/* U+00BD VULGAR FRACTION ONE HALF */
				case XK_threequarters           : break;/* U+00BE VULGAR FRACTION THREE QUARTERS */
				case XK_questiondown            : break;/* U+00BF INVERTED QUESTION MARK */
				case XK_Agrave                  : break;/* U+00C0 LATIN CAPITAL LETTER A WITH GRAVE */
				case XK_Aacute                  : break;/* U+00C1 LATIN CAPITAL LETTER A WITH ACUTE */
				case XK_Acircumflex             : break;/* U+00C2 LATIN CAPITAL LETTER A WITH CIRCUMFLEX */
				case XK_Atilde                  : break;/* U+00C3 LATIN CAPITAL LETTER A WITH TILDE */
				case XK_Adiaeresis              : break;/* U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS */
				case XK_Aring                   : break;/* U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE */
				case XK_AE                      : break;/* U+00C6 LATIN CAPITAL LETTER AE */
				case XK_Ccedilla                : break;/* U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA */
				case XK_Egrave                  : break;/* U+00C8 LATIN CAPITAL LETTER E WITH GRAVE */
				case XK_Eacute                  : break;/* U+00C9 LATIN CAPITAL LETTER E WITH ACUTE */
				case XK_Ecircumflex             : break;/* U+00CA LATIN CAPITAL LETTER E WITH CIRCUMFLEX */
				case XK_Ediaeresis              : break;/* U+00CB LATIN CAPITAL LETTER E WITH DIAERESIS */
				case XK_Igrave                  : break;/* U+00CC LATIN CAPITAL LETTER I WITH GRAVE */
				case XK_Iacute                  : break;/* U+00CD LATIN CAPITAL LETTER I WITH ACUTE */
				case XK_Icircumflex             : break;/* U+00CE LATIN CAPITAL LETTER I WITH CIRCUMFLEX */
				case XK_Idiaeresis              : break;/* U+00CF LATIN CAPITAL LETTER I WITH DIAERESIS */
				case XK_ETH                     : break;/* U+00D0 LATIN CAPITAL LETTER ETH */
				case XK_Ntilde                  : break;/* U+00D1 LATIN CAPITAL LETTER N WITH TILDE */
				case XK_Ograve                  : break;/* U+00D2 LATIN CAPITAL LETTER O WITH GRAVE */
				case XK_Oacute                  : break;/* U+00D3 LATIN CAPITAL LETTER O WITH ACUTE */
				case XK_Ocircumflex             : break;/* U+00D4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX */
				case XK_Otilde                  : break;/* U+00D5 LATIN CAPITAL LETTER O WITH TILDE */
				case XK_Odiaeresis              : break;/* U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS */
				case XK_multiply                : break;/* U+00D7 MULTIPLICATION SIGN */
				case XK_Oslash                  : break;/* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
//				case XK_Ooblique                : break;/* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
				case XK_Ugrave                  : break;/* U+00D9 LATIN CAPITAL LETTER U WITH GRAVE */
				case XK_Uacute                  : break;/* U+00DA LATIN CAPITAL LETTER U WITH ACUTE */
				case XK_Ucircumflex             : break;/* U+00DB LATIN CAPITAL LETTER U WITH CIRCUMFLEX */
				case XK_Udiaeresis              : break;/* U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS */
				case XK_Yacute                  : break;/* U+00DD LATIN CAPITAL LETTER Y WITH ACUTE */
				case XK_THORN                   : break;/* U+00DE LATIN CAPITAL LETTER THORN */
				case XK_ssharp                  : break;/* U+00DF LATIN SMALL LETTER SHARP S */
				case XK_agrave                  : break;/* U+00E0 LATIN SMALL LETTER A WITH GRAVE */
				case XK_aacute                  : break;/* U+00E1 LATIN SMALL LETTER A WITH ACUTE */
				case XK_acircumflex             : break;/* U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX */
				case XK_atilde                  : break;/* U+00E3 LATIN SMALL LETTER A WITH TILDE */
				case XK_adiaeresis              : break;/* U+00E4 LATIN SMALL LETTER A WITH DIAERESIS */
				case XK_aring                   : break;/* U+00E5 LATIN SMALL LETTER A WITH RING ABOVE */
				case XK_ae                      : break;/* U+00E6 LATIN SMALL LETTER AE */
				case XK_ccedilla                : break;/* U+00E7 LATIN SMALL LETTER C WITH CEDILLA */
				case XK_egrave                  : break;/* U+00E8 LATIN SMALL LETTER E WITH GRAVE */
				case XK_eacute                  : break;/* U+00E9 LATIN SMALL LETTER E WITH ACUTE */
				case XK_ecircumflex             : break;/* U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX */
				case XK_ediaeresis              : break;/* U+00EB LATIN SMALL LETTER E WITH DIAERESIS */
				case XK_igrave                  : break;/* U+00EC LATIN SMALL LETTER I WITH GRAVE */
				case XK_iacute                  : break;/* U+00ED LATIN SMALL LETTER I WITH ACUTE */
				case XK_icircumflex             : break;/* U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX */
				case XK_idiaeresis              : break;/* U+00EF LATIN SMALL LETTER I WITH DIAERESIS */
				case XK_eth                     : break;/* U+00F0 LATIN SMALL LETTER ETH */
				case XK_ntilde                  : break;/* U+00F1 LATIN SMALL LETTER N WITH TILDE */
				case XK_ograve                  : break;/* U+00F2 LATIN SMALL LETTER O WITH GRAVE */
				case XK_oacute                  : break;/* U+00F3 LATIN SMALL LETTER O WITH ACUTE */
				case XK_ocircumflex             : break;/* U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX */
				case XK_otilde                  : break;/* U+00F5 LATIN SMALL LETTER O WITH TILDE */
				case XK_odiaeresis              : break;/* U+00F6 LATIN SMALL LETTER O WITH DIAERESIS */
				case XK_division                : break;/* U+00F7 DIVISION SIGN */
				case XK_oslash                  : break;/* U+00F8 LATIN SMALL LETTER O WITH STROKE */
//				case XK_ooblique                : break;/* U+00F8 LATIN SMALL LETTER O WITH STROKE */
				case XK_ugrave                  : break;/* U+00F9 LATIN SMALL LETTER U WITH GRAVE */
				case XK_uacute                  : break;/* U+00FA LATIN SMALL LETTER U WITH ACUTE */
				case XK_ucircumflex             : break;/* U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX */
				case XK_udiaeresis              : break;/* U+00FC LATIN SMALL LETTER U WITH DIAERESIS */
				case XK_yacute                  : break;/* U+00FD LATIN SMALL LETTER Y WITH ACUTE */
				case XK_thorn                   : break;/* U+00FE LATIN SMALL LETTER THORN */
				case XK_ydiaeresis              : break;/* U+00FF LATIN SMALL LETTER Y WITH DIAERESIS */
			#endif /* XK_LATIN1 */
			#ifdef XK_LATIN2
				case XK_Aogonek              : break;/* U+0104 LATIN CAPITAL LETTER A WITH OGONEK */
				case XK_breve                : break;/* U+02D8 BREVE */
				case XK_Lstroke              : break;/* U+0141 LATIN CAPITAL LETTER L WITH STROKE */
				case XK_Lcaron               : break;/* U+013D LATIN CAPITAL LETTER L WITH CARON */
				case XK_Sacute               : break;/* U+015A LATIN CAPITAL LETTER S WITH ACUTE */
				case XK_Scaron               : break;/* U+0160 LATIN CAPITAL LETTER S WITH CARON */
				case XK_Scedilla             : break;/* U+015E LATIN CAPITAL LETTER S WITH CEDILLA */
				case XK_Tcaron               : break;/* U+0164 LATIN CAPITAL LETTER T WITH CARON */
				case XK_Zacute               : break;/* U+0179 LATIN CAPITAL LETTER Z WITH ACUTE */
				case XK_Zcaron               : break;/* U+017D LATIN CAPITAL LETTER Z WITH CARON */
				case XK_Zabovedot            : break;/* U+017B LATIN CAPITAL LETTER Z WITH DOT ABOVE */
				case XK_aogonek              : break;/* U+0105 LATIN SMALL LETTER A WITH OGONEK */
				case XK_ogonek               : break;/* U+02DB OGONEK */
				case XK_lstroke              : break;/* U+0142 LATIN SMALL LETTER L WITH STROKE */
				case XK_lcaron               : break;/* U+013E LATIN SMALL LETTER L WITH CARON */
				case XK_sacute               : break;/* U+015B LATIN SMALL LETTER S WITH ACUTE */
				case XK_caron                : break;/* U+02C7 CARON */
				case XK_scaron               : break;/* U+0161 LATIN SMALL LETTER S WITH CARON */
				case XK_scedilla             : break;/* U+015F LATIN SMALL LETTER S WITH CEDILLA */
				case XK_tcaron               : break;/* U+0165 LATIN SMALL LETTER T WITH CARON */
				case XK_zacute               : break;/* U+017A LATIN SMALL LETTER Z WITH ACUTE */
				case XK_doubleacute          : break;/* U+02DD DOUBLE ACUTE ACCENT */
				case XK_zcaron               : break;/* U+017E LATIN SMALL LETTER Z WITH CARON */
				case XK_zabovedot            : break;/* U+017C LATIN SMALL LETTER Z WITH DOT ABOVE */
				case XK_Racute               : break;/* U+0154 LATIN CAPITAL LETTER R WITH ACUTE */
				case XK_Abreve               : break;/* U+0102 LATIN CAPITAL LETTER A WITH BREVE */
				case XK_Lacute               : break;/* U+0139 LATIN CAPITAL LETTER L WITH ACUTE */
				case XK_Cacute               : break;/* U+0106 LATIN CAPITAL LETTER C WITH ACUTE */
				case XK_Ccaron               : break;/* U+010C LATIN CAPITAL LETTER C WITH CARON */
				case XK_Eogonek              : break;/* U+0118 LATIN CAPITAL LETTER E WITH OGONEK */
				case XK_Ecaron               : break;/* U+011A LATIN CAPITAL LETTER E WITH CARON */
				case XK_Dcaron               : break;/* U+010E LATIN CAPITAL LETTER D WITH CARON */
				case XK_Dstroke              : break;/* U+0110 LATIN CAPITAL LETTER D WITH STROKE */
				case XK_Nacute               : break;/* U+0143 LATIN CAPITAL LETTER N WITH ACUTE */
				case XK_Ncaron               : break;/* U+0147 LATIN CAPITAL LETTER N WITH CARON */
				case XK_Odoubleacute         : break;/* U+0150 LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
				case XK_Rcaron               : break;/* U+0158 LATIN CAPITAL LETTER R WITH CARON */
				case XK_Uring                : break;/* U+016E LATIN CAPITAL LETTER U WITH RING ABOVE */
				case XK_Udoubleacute         : break;/* U+0170 LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
				case XK_Tcedilla             : break;/* U+0162 LATIN CAPITAL LETTER T WITH CEDILLA */
				case XK_racute               : break;/* U+0155 LATIN SMALL LETTER R WITH ACUTE */
				case XK_abreve               : break;/* U+0103 LATIN SMALL LETTER A WITH BREVE */
				case XK_lacute               : break;/* U+013A LATIN SMALL LETTER L WITH ACUTE */
				case XK_cacute               : break;/* U+0107 LATIN SMALL LETTER C WITH ACUTE */
				case XK_ccaron               : break;/* U+010D LATIN SMALL LETTER C WITH CARON */
				case XK_eogonek              : break;/* U+0119 LATIN SMALL LETTER E WITH OGONEK */
				case XK_ecaron               : break;/* U+011B LATIN SMALL LETTER E WITH CARON */
				case XK_dcaron               : break;/* U+010F LATIN SMALL LETTER D WITH CARON */
				case XK_dstroke              : break;/* U+0111 LATIN SMALL LETTER D WITH STROKE */
				case XK_nacute               : break;/* U+0144 LATIN SMALL LETTER N WITH ACUTE */
				case XK_ncaron               : break;/* U+0148 LATIN SMALL LETTER N WITH CARON */
				case XK_odoubleacute         : break;/* U+0151 LATIN SMALL LETTER O WITH DOUBLE ACUTE */
				case XK_udoubleacute         : break;/* U+0171 LATIN SMALL LETTER U WITH DOUBLE ACUTE */
				case XK_rcaron               : break;/* U+0159 LATIN SMALL LETTER R WITH CARON */
				case XK_uring                : break;/* U+016F LATIN SMALL LETTER U WITH RING ABOVE */
				case XK_tcedilla             : break;/* U+0163 LATIN SMALL LETTER T WITH CEDILLA */
				case XK_abovedot             : break;/* U+02D9 DOT ABOVE */
			#endif /* XK_LATIN2 */
			#ifdef XK_LATIN3
				case XK_Hstroke              : break;/* U+0126 LATIN CAPITAL LETTER H WITH STROKE */
				case XK_Hcircumflex          : break;/* U+0124 LATIN CAPITAL LETTER H WITH CIRCUMFLEX */
				case XK_Iabovedot            : break;/* U+0130 LATIN CAPITAL LETTER I WITH DOT ABOVE */
				case XK_Gbreve               : break;/* U+011E LATIN CAPITAL LETTER G WITH BREVE */
				case XK_Jcircumflex          : break;/* U+0134 LATIN CAPITAL LETTER J WITH CIRCUMFLEX */
				case XK_hstroke              : break;/* U+0127 LATIN SMALL LETTER H WITH STROKE */
				case XK_hcircumflex          : break;/* U+0125 LATIN SMALL LETTER H WITH CIRCUMFLEX */
				case XK_idotless             : break;/* U+0131 LATIN SMALL LETTER DOTLESS I */
				case XK_gbreve               : break;/* U+011F LATIN SMALL LETTER G WITH BREVE */
				case XK_jcircumflex          : break;/* U+0135 LATIN SMALL LETTER J WITH CIRCUMFLEX */
				case XK_Cabovedot            : break;/* U+010A LATIN CAPITAL LETTER C WITH DOT ABOVE */
				case XK_Ccircumflex          : break;/* U+0108 LATIN CAPITAL LETTER C WITH CIRCUMFLEX */
				case XK_Gabovedot            : break;/* U+0120 LATIN CAPITAL LETTER G WITH DOT ABOVE */
				case XK_Gcircumflex          : break;/* U+011C LATIN CAPITAL LETTER G WITH CIRCUMFLEX */
				case XK_Ubreve               : break;/* U+016C LATIN CAPITAL LETTER U WITH BREVE */
				case XK_Scircumflex          : break;/* U+015C LATIN CAPITAL LETTER S WITH CIRCUMFLEX */
				case XK_cabovedot            : break;/* U+010B LATIN SMALL LETTER C WITH DOT ABOVE */
				case XK_ccircumflex          : break;/* U+0109 LATIN SMALL LETTER C WITH CIRCUMFLEX */
				case XK_gabovedot            : break;/* U+0121 LATIN SMALL LETTER G WITH DOT ABOVE */
				case XK_gcircumflex          : break;/* U+011D LATIN SMALL LETTER G WITH CIRCUMFLEX */
				case XK_ubreve               : break;/* U+016D LATIN SMALL LETTER U WITH BREVE */
				case XK_scircumflex          : break;/* U+015D LATIN SMALL LETTER S WITH CIRCUMFLEX */
			#endif /* XK_LATIN3 */
			#ifdef XK_LATIN4
				case XK_kra               : break;/* U+0138 LATIN SMALL LETTER KRA */
				case XK_Rcedilla          : break;/* U+0156 LATIN CAPITAL LETTER R WITH CEDILLA */
				case XK_Itilde            : break;/* U+0128 LATIN CAPITAL LETTER I WITH TILDE */
				case XK_Lcedilla          : break;/* U+013B LATIN CAPITAL LETTER L WITH CEDILLA */
				case XK_Emacron           : break;/* U+0112 LATIN CAPITAL LETTER E WITH MACRON */
				case XK_Gcedilla          : break;/* U+0122 LATIN CAPITAL LETTER G WITH CEDILLA */
				case XK_Tslash            : break;/* U+0166 LATIN CAPITAL LETTER T WITH STROKE */
				case XK_rcedilla          : break;/* U+0157 LATIN SMALL LETTER R WITH CEDILLA */
				case XK_itilde            : break;/* U+0129 LATIN SMALL LETTER I WITH TILDE */
				case XK_lcedilla          : break;/* U+013C LATIN SMALL LETTER L WITH CEDILLA */
				case XK_emacron           : break;/* U+0113 LATIN SMALL LETTER E WITH MACRON */
				case XK_gcedilla          : break;/* U+0123 LATIN SMALL LETTER G WITH CEDILLA */
				case XK_tslash            : break;/* U+0167 LATIN SMALL LETTER T WITH STROKE */
				case XK_ENG               : break;/* U+014A LATIN CAPITAL LETTER ENG */
				case XK_eng               : break;/* U+014B LATIN SMALL LETTER ENG */
				case XK_Amacron           : break;/* U+0100 LATIN CAPITAL LETTER A WITH MACRON */
				case XK_Iogonek           : break;/* U+012E LATIN CAPITAL LETTER I WITH OGONEK */
				case XK_Eabovedot         : break;/* U+0116 LATIN CAPITAL LETTER E WITH DOT ABOVE */
				case XK_Imacron           : break;/* U+012A LATIN CAPITAL LETTER I WITH MACRON */
				case XK_Ncedilla          : break;/* U+0145 LATIN CAPITAL LETTER N WITH CEDILLA */
				case XK_Omacron           : break;/* U+014C LATIN CAPITAL LETTER O WITH MACRON */
				case XK_Kcedilla          : break;/* U+0136 LATIN CAPITAL LETTER K WITH CEDILLA */
				case XK_Uogonek           : break;/* U+0172 LATIN CAPITAL LETTER U WITH OGONEK */
				case XK_Utilde            : break;/* U+0168 LATIN CAPITAL LETTER U WITH TILDE */
				case XK_Umacron           : break;/* U+016A LATIN CAPITAL LETTER U WITH MACRON */
				case XK_amacron           : break;/* U+0101 LATIN SMALL LETTER A WITH MACRON */
				case XK_iogonek           : break;/* U+012F LATIN SMALL LETTER I WITH OGONEK */
				case XK_eabovedot         : break;/* U+0117 LATIN SMALL LETTER E WITH DOT ABOVE */
				case XK_imacron           : break;/* U+012B LATIN SMALL LETTER I WITH MACRON */
				case XK_ncedilla          : break;/* U+0146 LATIN SMALL LETTER N WITH CEDILLA */
				case XK_omacron           : break;/* U+014D LATIN SMALL LETTER O WITH MACRON */
				case XK_kcedilla          : break;/* U+0137 LATIN SMALL LETTER K WITH CEDILLA */
				case XK_uogonek           : break;/* U+0173 LATIN SMALL LETTER U WITH OGONEK */
				case XK_utilde            : break;/* U+0169 LATIN SMALL LETTER U WITH TILDE */
				case XK_umacron           : break;/* U+016B LATIN SMALL LETTER U WITH MACRON */
			#endif /* XK_LATIN4 */
			#ifdef XK_LATIN8
				case XK_Babovedot         : break;/* U+1E02 LATIN CAPITAL LETTER B WITH DOT ABOVE */
				case XK_babovedot         : break;/* U+1E03 LATIN SMALL LETTER B WITH DOT ABOVE */
				case XK_Dabovedot         : break;/* U+1E0A LATIN CAPITAL LETTER D WITH DOT ABOVE */
				case XK_Wgrave            : break;/* U+1E80 LATIN CAPITAL LETTER W WITH GRAVE */
				case XK_Wacute            : break;/* U+1E82 LATIN CAPITAL LETTER W WITH ACUTE */
				case XK_dabovedot         : break;/* U+1E0B LATIN SMALL LETTER D WITH DOT ABOVE */
				case XK_Ygrave            : break;/* U+1EF2 LATIN CAPITAL LETTER Y WITH GRAVE */
				case XK_Fabovedot         : break;/* U+1E1E LATIN CAPITAL LETTER F WITH DOT ABOVE */
				case XK_fabovedot         : break;/* U+1E1F LATIN SMALL LETTER F WITH DOT ABOVE */
				case XK_Mabovedot         : break;/* U+1E40 LATIN CAPITAL LETTER M WITH DOT ABOVE */
				case XK_mabovedot         : break;/* U+1E41 LATIN SMALL LETTER M WITH DOT ABOVE */
				case XK_Pabovedot         : break;/* U+1E56 LATIN CAPITAL LETTER P WITH DOT ABOVE */
				case XK_wgrave            : break;/* U+1E81 LATIN SMALL LETTER W WITH GRAVE */
				case XK_pabovedot         : break;/* U+1E57 LATIN SMALL LETTER P WITH DOT ABOVE */
				case XK_wacute            : break;/* U+1E83 LATIN SMALL LETTER W WITH ACUTE */
				case XK_Sabovedot         : break;/* U+1E60 LATIN CAPITAL LETTER S WITH DOT ABOVE */
				case XK_ygrave            : break;/* U+1EF3 LATIN SMALL LETTER Y WITH GRAVE */
				case XK_Wdiaeresis        : break;/* U+1E84 LATIN CAPITAL LETTER W WITH DIAERESIS */
				case XK_wdiaeresis        : break;/* U+1E85 LATIN SMALL LETTER W WITH DIAERESIS */
				case XK_sabovedot         : break;/* U+1E61 LATIN SMALL LETTER S WITH DOT ABOVE */
				case XK_Wcircumflex       : break;/* U+0174 LATIN CAPITAL LETTER W WITH CIRCUMFLEX */
				case XK_Tabovedot         : break;/* U+1E6A LATIN CAPITAL LETTER T WITH DOT ABOVE */
				case XK_Ycircumflex       : break;/* U+0176 LATIN CAPITAL LETTER Y WITH CIRCUMFLEX */
				case XK_wcircumflex       : break;/* U+0175 LATIN SMALL LETTER W WITH CIRCUMFLEX */
				case XK_tabovedot         : break;/* U+1E6B LATIN SMALL LETTER T WITH DOT ABOVE */
				case XK_ycircumflex       : break;/* U+0177 LATIN SMALL LETTER Y WITH CIRCUMFLEX */
			#endif /* XK_LATIN8 */
			#ifdef XK_LATIN9
				case XK_OE                  : break; /* U+0152 LATIN CAPITAL LIGATURE OE */
				case XK_oe                  : break; /* U+0153 LATIN SMALL LIGATURE OE */
				case XK_Ydiaeresis          : break; /* U+0178 LATIN CAPITAL LETTER Y WITH DIAERESIS */
			#endif /* XK_LATIN9 */
			#ifdef XK_KATAKANA
				case XK_overline             : break; /* U+203E OVERLINE */
				case XK_kana_fullstop        : break; /* U+3002 IDEOGRAPHIC FULL STOP */
				case XK_kana_openingbracket  : break; /* U+300C LEFT CORNER BRACKET */
				case XK_kana_closingbracket  : break; /* U+300D RIGHT CORNER BRACKET */
				case XK_kana_comma           : break; /* U+3001 IDEOGRAPHIC COMMA */
				case XK_kana_conjunctive     : break; /* U+30FB KATAKANA MIDDLE DOT */
				case XK_kana_WO              : break; /* U+30F2 KATAKANA LETTER WO */
				case XK_kana_a               : break; /* U+30A1 KATAKANA LETTER SMALL A */
				case XK_kana_i               : break; /* U+30A3 KATAKANA LETTER SMALL I */
				case XK_kana_u               : break; /* U+30A5 KATAKANA LETTER SMALL U */
				case XK_kana_e               : break; /* U+30A7 KATAKANA LETTER SMALL E */
				case XK_kana_o               : break; /* U+30A9 KATAKANA LETTER SMALL O */
				case XK_kana_ya              : break; /* U+30E3 KATAKANA LETTER SMALL YA */
				case XK_kana_yu              : break; /* U+30E5 KATAKANA LETTER SMALL YU */
				case XK_kana_yo              : break; /* U+30E7 KATAKANA LETTER SMALL YO */
				case XK_kana_tsu             : break; /* U+30C3 KATAKANA LETTER SMALL TU */
				case XK_prolongedsound       : break; /* U+30FC KATAKANA-HIRAGANA PROLONGED SOUND MARK */
				case XK_kana_A               : break; /* U+30A2 KATAKANA LETTER A */
				case XK_kana_I               : break; /* U+30A4 KATAKANA LETTER I */
				case XK_kana_U               : break; /* U+30A6 KATAKANA LETTER U */
				case XK_kana_E               : break; /* U+30A8 KATAKANA LETTER E */
				case XK_kana_O               : break; /* U+30AA KATAKANA LETTER O */
				case XK_kana_KA              : break; /* U+30AB KATAKANA LETTER KA */
				case XK_kana_KI              : break; /* U+30AD KATAKANA LETTER KI */
				case XK_kana_KU              : break; /* U+30AF KATAKANA LETTER KU */
				case XK_kana_KE              : break; /* U+30B1 KATAKANA LETTER KE */
				case XK_kana_KO              : break; /* U+30B3 KATAKANA LETTER KO */
				case XK_kana_SA              : break; /* U+30B5 KATAKANA LETTER SA */
				case XK_kana_SHI             : break; /* U+30B7 KATAKANA LETTER SI */
				case XK_kana_SU              : break; /* U+30B9 KATAKANA LETTER SU */
				case XK_kana_SE              : break; /* U+30BB KATAKANA LETTER SE */
				case XK_kana_SO              : break; /* U+30BD KATAKANA LETTER SO */
				case XK_kana_TA              : break; /* U+30BF KATAKANA LETTER TA */
				case XK_kana_CHI             : break; /* U+30C1 KATAKANA LETTER TI */
				case XK_kana_TSU             : break; /* U+30C4 KATAKANA LETTER TU */
				case XK_kana_TE              : break; /* U+30C6 KATAKANA LETTER TE */
				case XK_kana_TO              : break; /* U+30C8 KATAKANA LETTER TO */
				case XK_kana_NA              : break; /* U+30CA KATAKANA LETTER NA */
				case XK_kana_NI              : break; /* U+30CB KATAKANA LETTER NI */
				case XK_kana_NU              : break; /* U+30CC KATAKANA LETTER NU */
				case XK_kana_NE              : break; /* U+30CD KATAKANA LETTER NE */
				case XK_kana_NO              : break; /* U+30CE KATAKANA LETTER NO */
				case XK_kana_HA              : break; /* U+30CF KATAKANA LETTER HA */
				case XK_kana_HI              : break; /* U+30D2 KATAKANA LETTER HI */
				case XK_kana_FU              : break; /* U+30D5 KATAKANA LETTER HU */
				case XK_kana_HE              : break; /* U+30D8 KATAKANA LETTER HE */
				case XK_kana_HO              : break; /* U+30DB KATAKANA LETTER HO */
				case XK_kana_MA              : break; /* U+30DE KATAKANA LETTER MA */
				case XK_kana_MI              : break; /* U+30DF KATAKANA LETTER MI */
				case XK_kana_MU              : break; /* U+30E0 KATAKANA LETTER MU */
				case XK_kana_ME              : break; /* U+30E1 KATAKANA LETTER ME */
				case XK_kana_MO              : break; /* U+30E2 KATAKANA LETTER MO */
				case XK_kana_YA              : break; /* U+30E4 KATAKANA LETTER YA */
				case XK_kana_YU              : break; /* U+30E6 KATAKANA LETTER YU */
				case XK_kana_YO              : break; /* U+30E8 KATAKANA LETTER YO */
				case XK_kana_RA              : break; /* U+30E9 KATAKANA LETTER RA */
				case XK_kana_RI              : break; /* U+30EA KATAKANA LETTER RI */
				case XK_kana_RU              : break; /* U+30EB KATAKANA LETTER RU */
				case XK_kana_RE              : break; /* U+30EC KATAKANA LETTER RE */
				case XK_kana_RO              : break; /* U+30ED KATAKANA LETTER RO */
				case XK_kana_WA              : break; /* U+30EF KATAKANA LETTER WA */
				case XK_kana_N               : break; /* U+30F3 KATAKANA LETTER N */
				case XK_voicedsound          : break; /* U+309B KATAKANA-HIRAGANA VOICED SOUND MARK */
				case XK_semivoicedsound      : break; /* U+309C KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK */
			#ifndef XK_MISCELLANY
				case XK_kana_switch          : break; /* Alias for mode_switch */
			#endif
			#endif /* XK_KATAKANA */
			#ifdef XK_ARABIC
				case XK_Farsi_0                 : break; /* U+06F0 EXTENDED ARABIC-INDIC DIGIT ZERO */
				case XK_Farsi_1                 : break; /* U+06F1 EXTENDED ARABIC-INDIC DIGIT ONE */
				case XK_Farsi_2                 : break; /* U+06F2 EXTENDED ARABIC-INDIC DIGIT TWO */
				case XK_Farsi_3                 : break; /* U+06F3 EXTENDED ARABIC-INDIC DIGIT THREE */
				case XK_Farsi_4                 : break; /* U+06F4 EXTENDED ARABIC-INDIC DIGIT FOUR */
				case XK_Farsi_5                 : break; /* U+06F5 EXTENDED ARABIC-INDIC DIGIT FIVE */
				case XK_Farsi_6                 : break; /* U+06F6 EXTENDED ARABIC-INDIC DIGIT SIX */
				case XK_Farsi_7                 : break; /* U+06F7 EXTENDED ARABIC-INDIC DIGIT SEVEN */
				case XK_Farsi_8                 : break; /* U+06F8 EXTENDED ARABIC-INDIC DIGIT EIGHT */
				case XK_Farsi_9                 : break; /* U+06F9 EXTENDED ARABIC-INDIC DIGIT NINE */
				case XK_Arabic_percent          : break; /* U+066A ARABIC PERCENT SIGN */
				case XK_Arabic_superscript_alef : break; /* U+0670 ARABIC LETTER SUPERSCRIPT ALEF */
				case XK_Arabic_tteh             : break; /* U+0679 ARABIC LETTER TTEH */
				case XK_Arabic_peh              : break; /* U+067E ARABIC LETTER PEH */
				case XK_Arabic_tcheh            : break; /* U+0686 ARABIC LETTER TCHEH */
				case XK_Arabic_ddal             : break; /* U+0688 ARABIC LETTER DDAL */
				case XK_Arabic_rreh             : break; /* U+0691 ARABIC LETTER RREH */
				case XK_Arabic_comma            : break; /* U+060C ARABIC COMMA */
				case XK_Arabic_fullstop         : break; /* U+06D4 ARABIC FULL STOP */
				case XK_Arabic_0                : break; /* U+0660 ARABIC-INDIC DIGIT ZERO */
				case XK_Arabic_1                : break; /* U+0661 ARABIC-INDIC DIGIT ONE */
				case XK_Arabic_2                : break; /* U+0662 ARABIC-INDIC DIGIT TWO */
				case XK_Arabic_3                : break; /* U+0663 ARABIC-INDIC DIGIT THREE */
				case XK_Arabic_4                : break; /* U+0664 ARABIC-INDIC DIGIT FOUR */
				case XK_Arabic_5                : break; /* U+0665 ARABIC-INDIC DIGIT FIVE */
				case XK_Arabic_6                : break; /* U+0666 ARABIC-INDIC DIGIT SIX */
				case XK_Arabic_7                : break; /* U+0667 ARABIC-INDIC DIGIT SEVEN */
				case XK_Arabic_8                : break; /* U+0668 ARABIC-INDIC DIGIT EIGHT */
				case XK_Arabic_9                : break; /* U+0669 ARABIC-INDIC DIGIT NINE */
				case XK_Arabic_semicolon        : break; /* U+061B ARABIC SEMICOLON */
				case XK_Arabic_question_mark    : break; /* U+061F ARABIC QUESTION MARK */
				case XK_Arabic_hamza            : break; /* U+0621 ARABIC LETTER HAMZA */
				case XK_Arabic_maddaonalef      : break; /* U+0622 ARABIC LETTER ALEF WITH MADDA ABOVE */
				case XK_Arabic_hamzaonalef      : break; /* U+0623 ARABIC LETTER ALEF WITH HAMZA ABOVE */
				case XK_Arabic_hamzaonwaw       : break; /* U+0624 ARABIC LETTER WAW WITH HAMZA ABOVE */
				case XK_Arabic_hamzaunderalef   : break; /* U+0625 ARABIC LETTER ALEF WITH HAMZA BELOW */
				case XK_Arabic_hamzaonyeh       : break; /* U+0626 ARABIC LETTER YEH WITH HAMZA ABOVE */
				case XK_Arabic_alef             : break; /* U+0627 ARABIC LETTER ALEF */
				case XK_Arabic_beh              : break; /* U+0628 ARABIC LETTER BEH */
				case XK_Arabic_tehmarbuta       : break; /* U+0629 ARABIC LETTER TEH MARBUTA */
				case XK_Arabic_teh              : break; /* U+062A ARABIC LETTER TEH */
				case XK_Arabic_theh             : break; /* U+062B ARABIC LETTER THEH */
				case XK_Arabic_jeem             : break; /* U+062C ARABIC LETTER JEEM */
				case XK_Arabic_hah              : break; /* U+062D ARABIC LETTER HAH */
				case XK_Arabic_khah             : break; /* U+062E ARABIC LETTER KHAH */
				case XK_Arabic_dal              : break; /* U+062F ARABIC LETTER DAL */
				case XK_Arabic_thal             : break; /* U+0630 ARABIC LETTER THAL */
				case XK_Arabic_ra               : break; /* U+0631 ARABIC LETTER REH */
				case XK_Arabic_zain             : break; /* U+0632 ARABIC LETTER ZAIN */
				case XK_Arabic_seen             : break; /* U+0633 ARABIC LETTER SEEN */
				case XK_Arabic_sheen            : break; /* U+0634 ARABIC LETTER SHEEN */
				case XK_Arabic_sad              : break; /* U+0635 ARABIC LETTER SAD */
				case XK_Arabic_dad              : break; /* U+0636 ARABIC LETTER DAD */
				case XK_Arabic_tah              : break; /* U+0637 ARABIC LETTER TAH */
				case XK_Arabic_zah              : break; /* U+0638 ARABIC LETTER ZAH */
				case XK_Arabic_ain              : break; /* U+0639 ARABIC LETTER AIN */
				case XK_Arabic_ghain            : break; /* U+063A ARABIC LETTER GHAIN */
				case XK_Arabic_tatweel          : break; /* U+0640 ARABIC TATWEEL */
				case XK_Arabic_feh              : break; /* U+0641 ARABIC LETTER FEH */
				case XK_Arabic_qaf              : break; /* U+0642 ARABIC LETTER QAF */
				case XK_Arabic_kaf              : break; /* U+0643 ARABIC LETTER KAF */
				case XK_Arabic_lam              : break; /* U+0644 ARABIC LETTER LAM */
				case XK_Arabic_meem             : break; /* U+0645 ARABIC LETTER MEEM */
				case XK_Arabic_noon             : break; /* U+0646 ARABIC LETTER NOON */
				case XK_Arabic_ha               : break; /* U+0647 ARABIC LETTER HEH */
				case XK_Arabic_waw              : break; /* U+0648 ARABIC LETTER WAW */
				case XK_Arabic_alefmaksura      : break; /* U+0649 ARABIC LETTER ALEF MAKSURA */
				case XK_Arabic_yeh              : break; /* U+064A ARABIC LETTER YEH */
				case XK_Arabic_fathatan         : break; /* U+064B ARABIC FATHATAN */
				case XK_Arabic_dammatan         : break; /* U+064C ARABIC DAMMATAN */
				case XK_Arabic_kasratan         : break; /* U+064D ARABIC KASRATAN */
				case XK_Arabic_fatha            : break; /* U+064E ARABIC FATHA */
				case XK_Arabic_damma            : break; /* U+064F ARABIC DAMMA */
				case XK_Arabic_kasra            : break; /* U+0650 ARABIC KASRA */
				case XK_Arabic_shadda           : break; /* U+0651 ARABIC SHADDA */
				case XK_Arabic_sukun            : break; /* U+0652 ARABIC SUKUN */
				case XK_Arabic_madda_above      : break; /* U+0653 ARABIC MADDAH ABOVE */
				case XK_Arabic_hamza_above      : break; /* U+0654 ARABIC HAMZA ABOVE */
				case XK_Arabic_hamza_below      : break; /* U+0655 ARABIC HAMZA BELOW */
				case XK_Arabic_jeh              : break; /* U+0698 ARABIC LETTER JEH */
				case XK_Arabic_veh              : break; /* U+06A4 ARABIC LETTER VEH */
				case XK_Arabic_keheh            : break; /* U+06A9 ARABIC LETTER KEHEH */
				case XK_Arabic_gaf              : break; /* U+06AF ARABIC LETTER GAF */
				case XK_Arabic_noon_ghunna      : break; /* U+06BA ARABIC LETTER NOON GHUNNA */
				case XK_Arabic_heh_doachashmee  : break; /* U+06BE ARABIC LETTER HEH DOACHASHMEE */
				case XK_Farsi_yeh               : break; /* U+06CC ARABIC LETTER FARSI YEH */
//				case XK_Arabic_farsi_yeh        : break; /* U+06CC ARABIC LETTER FARSI YEH */
				case XK_Arabic_yeh_baree        : break; /* U+06D2 ARABIC LETTER YEH BARREE */
				case XK_Arabic_heh_goal         : break; /* U+06C1 ARABIC LETTER HEH GOAL */
			#ifndef XK_MISCELLANY
				case XK_Arabic_switch           : break; /* Alias for mode_switch */
			#endif
			#endif /* XK_ARABIC */
			#ifdef XK_CYRILLIC
				case XK_Cyrillic_GHE_bar			: break;	/* U+0492 CYRILLIC CAPITAL LETTER GHE WITH STROKE */
				case XK_Cyrillic_ghe_bar			: break;	/* U+0493 CYRILLIC SMALL LETTER GHE WITH STROKE */
				case XK_Cyrillic_ZHE_descender		: break;/* U+0496 CYRILLIC CAPITAL LETTER ZHE WITH DESCENDER */
				case XK_Cyrillic_zhe_descender		: break;/* U+0497 CYRILLIC SMALL LETTER ZHE WITH DESCENDER */
				case XK_Cyrillic_KA_descender		: break;/* U+049A CYRILLIC CAPITAL LETTER KA WITH DESCENDER */
				case XK_Cyrillic_ka_descender		: break;/* U+049B CYRILLIC SMALL LETTER KA WITH DESCENDER */
				case XK_Cyrillic_KA_vertstroke		: break;/* U+049C CYRILLIC CAPITAL LETTER KA WITH VERTICAL STROKE */
				case XK_Cyrillic_ka_vertstroke		: break;/* U+049D CYRILLIC SMALL LETTER KA WITH VERTICAL STROKE */
				case XK_Cyrillic_EN_descender		: break;/* U+04A2 CYRILLIC CAPITAL LETTER EN WITH DESCENDER */
				case XK_Cyrillic_en_descender		: break;/* U+04A3 CYRILLIC SMALL LETTER EN WITH DESCENDER */
				case XK_Cyrillic_U_straight			: break;/* U+04AE CYRILLIC CAPITAL LETTER STRAIGHT U */
				case XK_Cyrillic_u_straight			: break;/* U+04AF CYRILLIC SMALL LETTER STRAIGHT U */
				case XK_Cyrillic_U_straight_bar		: break;/* U+04B0 CYRILLIC CAPITAL LETTER STRAIGHT U WITH STROKE */
				case XK_Cyrillic_u_straight_bar		: break;/* U+04B1 CYRILLIC SMALL LETTER STRAIGHT U WITH STROKE */
				case XK_Cyrillic_HA_descender		: break;/* U+04B2 CYRILLIC CAPITAL LETTER HA WITH DESCENDER */
				case XK_Cyrillic_ha_descender		: break;/* U+04B3 CYRILLIC SMALL LETTER HA WITH DESCENDER */
				case XK_Cyrillic_CHE_descender		: break;/* U+04B6 CYRILLIC CAPITAL LETTER CHE WITH DESCENDER */
				case XK_Cyrillic_che_descender		: break;/* U+04B7 CYRILLIC SMALL LETTER CHE WITH DESCENDER */
				case XK_Cyrillic_CHE_vertstroke		: break;/* U+04B8 CYRILLIC CAPITAL LETTER CHE WITH VERTICAL STROKE */
				case XK_Cyrillic_che_vertstroke		: break;/* U+04B9 CYRILLIC SMALL LETTER CHE WITH VERTICAL STROKE */
				case XK_Cyrillic_SHHA				: break;/* U+04BA CYRILLIC CAPITAL LETTER SHHA */
				case XK_Cyrillic_shha				: break;/* U+04BB CYRILLIC SMALL LETTER SHHA */
				case XK_Cyrillic_SCHWA				: break;/* U+04D8 CYRILLIC CAPITAL LETTER SCHWA */
				case XK_Cyrillic_schwa				: break;/* U+04D9 CYRILLIC SMALL LETTER SCHWA */
				case XK_Cyrillic_I_macron			: break;/* U+04E2 CYRILLIC CAPITAL LETTER I WITH MACRON */
				case XK_Cyrillic_i_macron			: break;/* U+04E3 CYRILLIC SMALL LETTER I WITH MACRON */
				case XK_Cyrillic_O_bar				: break;/* U+04E8 CYRILLIC CAPITAL LETTER BARRED O */
				case XK_Cyrillic_o_bar				: break;/* U+04E9 CYRILLIC SMALL LETTER BARRED O */
				case XK_Cyrillic_U_macron			: break;/* U+04EE CYRILLIC CAPITAL LETTER U WITH MACRON */
				case XK_Cyrillic_u_macron			: break;/* U+04EF CYRILLIC SMALL LETTER U WITH MACRON */
				case XK_Serbian_dje					: break;/* U+0452 CYRILLIC SMALL LETTER DJE */
				case XK_Macedonia_gje				: break;/* U+0453 CYRILLIC SMALL LETTER GJE */
				case XK_Cyrillic_io					: break;/* U+0451 CYRILLIC SMALL LETTER IO */
				case XK_Ukrainian_ie				: break;	/* U+0454 CYRILLIC SMALL LETTER UKRAINIAN IE */
				case XK_Macedonia_dse				: break;/* U+0455 CYRILLIC SMALL LETTER DZE */
				case XK_Ukrainian_i					: break;/* U+0456 CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I */
				case XK_Ukrainian_yi				: break;	/* U+0457 CYRILLIC SMALL LETTER YI */
				case XK_Cyrillic_je					: break;/* U+0458 CYRILLIC SMALL LETTER JE */
				case XK_Cyrillic_lje				: break;	/* U+0459 CYRILLIC SMALL LETTER LJE */
				case XK_Cyrillic_nje				: break;	/* U+045A CYRILLIC SMALL LETTER NJE */
				case XK_Serbian_tshe				: break;	/* U+045B CYRILLIC SMALL LETTER TSHE */
				case XK_Macedonia_kje				: break;/* U+045C CYRILLIC SMALL LETTER KJE */
				case XK_Ukrainian_ghe_with_upturn	: break;/* U+0491 CYRILLIC SMALL LETTER GHE WITH UPTURN */
				case XK_Byelorussian_shortu			: break;/* U+045E CYRILLIC SMALL LETTER SHORT U */
				case XK_Cyrillic_dzhe				: break;/* U+045F CYRILLIC SMALL LETTER DZHE */
				case XK_numerosign					: break;/* U+2116 NUMERO SIGN */
				case XK_Serbian_DJE					: break;/* U+0402 CYRILLIC CAPITAL LETTER DJE */
				case XK_Macedonia_GJE				: break;/* U+0403 CYRILLIC CAPITAL LETTER GJE */
				case XK_Cyrillic_IO					: break;/* U+0401 CYRILLIC CAPITAL LETTER IO */
				case XK_Ukrainian_IE				: break;	/* U+0404 CYRILLIC CAPITAL LETTER UKRAINIAN IE */
				case XK_Macedonia_DSE				: break;/* U+0405 CYRILLIC CAPITAL LETTER DZE */
				case XK_Ukrainian_I					: break;/* U+0406 CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I */
				case XK_Ukrainian_YI				: break;	/* U+0407 CYRILLIC CAPITAL LETTER YI */
				case XK_Cyrillic_JE					: break;/* U+0408 CYRILLIC CAPITAL LETTER JE */
				case XK_Cyrillic_LJE				: break;	/* U+0409 CYRILLIC CAPITAL LETTER LJE */
				case XK_Cyrillic_NJE				: break;	/* U+040A CYRILLIC CAPITAL LETTER NJE */
				case XK_Serbian_TSHE				: break;	/* U+040B CYRILLIC CAPITAL LETTER TSHE */
				case XK_Macedonia_KJE				: break;/* U+040C CYRILLIC CAPITAL LETTER KJE */
				case XK_Ukrainian_GHE_WITH_UPTURN	: break;/* U+0490 CYRILLIC CAPITAL LETTER GHE WITH UPTURN */
				case XK_Byelorussian_SHORTU			: break;/* U+040E CYRILLIC CAPITAL LETTER SHORT U */
				case XK_Cyrillic_DZHE				: break;/* U+040F CYRILLIC CAPITAL LETTER DZHE */
				case XK_Cyrillic_yu					: break;/* U+044E CYRILLIC SMALL LETTER YU */
				case XK_Cyrillic_a					: break;/* U+0430 CYRILLIC SMALL LETTER A */
				case XK_Cyrillic_be					: break;/* U+0431 CYRILLIC SMALL LETTER BE */
				case XK_Cyrillic_tse				: break;	/* U+0446 CYRILLIC SMALL LETTER TSE */
				case XK_Cyrillic_de					: break;/* U+0434 CYRILLIC SMALL LETTER DE */
				case XK_Cyrillic_ie					: break;/* U+0435 CYRILLIC SMALL LETTER IE */
				case XK_Cyrillic_ef					: break;/* U+0444 CYRILLIC SMALL LETTER EF */
				case XK_Cyrillic_ghe				: break;	/* U+0433 CYRILLIC SMALL LETTER GHE */
				case XK_Cyrillic_ha					: break;/* U+0445 CYRILLIC SMALL LETTER HA */
				case XK_Cyrillic_i					: break;/* U+0438 CYRILLIC SMALL LETTER I */
				case XK_Cyrillic_shorti				: break;/* U+0439 CYRILLIC SMALL LETTER SHORT I */
				case XK_Cyrillic_ka					: break;/* U+043A CYRILLIC SMALL LETTER KA */
				case XK_Cyrillic_el					: break;/* U+043B CYRILLIC SMALL LETTER EL */
				case XK_Cyrillic_em					: break;/* U+043C CYRILLIC SMALL LETTER EM */
				case XK_Cyrillic_en					: break;/* U+043D CYRILLIC SMALL LETTER EN */
				case XK_Cyrillic_o					: break;/* U+043E CYRILLIC SMALL LETTER O */
				case XK_Cyrillic_pe					: break;/* U+043F CYRILLIC SMALL LETTER PE */
				case XK_Cyrillic_ya					: break;/* U+044F CYRILLIC SMALL LETTER YA */
				case XK_Cyrillic_er					: break;/* U+0440 CYRILLIC SMALL LETTER ER */
				case XK_Cyrillic_es					: break;/* U+0441 CYRILLIC SMALL LETTER ES */
				case XK_Cyrillic_te					: break;/* U+0442 CYRILLIC SMALL LETTER TE */
				case XK_Cyrillic_u					: break;/* U+0443 CYRILLIC SMALL LETTER U */
				case XK_Cyrillic_zhe				: break;	/* U+0436 CYRILLIC SMALL LETTER ZHE */
				case XK_Cyrillic_ve					: break;/* U+0432 CYRILLIC SMALL LETTER VE */
				case XK_Cyrillic_softsign			: break;/* U+044C CYRILLIC SMALL LETTER SOFT SIGN */
				case XK_Cyrillic_yeru				: break;/* U+044B CYRILLIC SMALL LETTER YERU */
				case XK_Cyrillic_ze					: break;/* U+0437 CYRILLIC SMALL LETTER ZE */
				case XK_Cyrillic_sha				: break;	/* U+0448 CYRILLIC SMALL LETTER SHA */
				case XK_Cyrillic_e					: break;/* U+044D CYRILLIC SMALL LETTER E */
				case XK_Cyrillic_shcha				: break;/* U+0449 CYRILLIC SMALL LETTER SHCHA */
				case XK_Cyrillic_che				: break;	/* U+0447 CYRILLIC SMALL LETTER CHE */
				case XK_Cyrillic_hardsign			: break;/* U+044A CYRILLIC SMALL LETTER HARD SIGN */
				case XK_Cyrillic_YU					: break;/* U+042E CYRILLIC CAPITAL LETTER YU */
				case XK_Cyrillic_A					: break;/* U+0410 CYRILLIC CAPITAL LETTER A */
				case XK_Cyrillic_BE					: break;/* U+0411 CYRILLIC CAPITAL LETTER BE */
				case XK_Cyrillic_TSE				: break;	/* U+0426 CYRILLIC CAPITAL LETTER TSE */
				case XK_Cyrillic_DE					: break;/* U+0414 CYRILLIC CAPITAL LETTER DE */
				case XK_Cyrillic_IE					: break;/* U+0415 CYRILLIC CAPITAL LETTER IE */
				case XK_Cyrillic_EF					: break;/* U+0424 CYRILLIC CAPITAL LETTER EF */
				case XK_Cyrillic_GHE				: break;	/* U+0413 CYRILLIC CAPITAL LETTER GHE */
				case XK_Cyrillic_HA					: break;/* U+0425 CYRILLIC CAPITAL LETTER HA */
				case XK_Cyrillic_I					: break;/* U+0418 CYRILLIC CAPITAL LETTER I */
				case XK_Cyrillic_SHORTI				: break;/* U+0419 CYRILLIC CAPITAL LETTER SHORT I */
				case XK_Cyrillic_KA					: break;/* U+041A CYRILLIC CAPITAL LETTER KA */
				case XK_Cyrillic_EL					: break;/* U+041B CYRILLIC CAPITAL LETTER EL */
				case XK_Cyrillic_EM					: break;/* U+041C CYRILLIC CAPITAL LETTER EM */
				case XK_Cyrillic_EN					: break;/* U+041D CYRILLIC CAPITAL LETTER EN */
				case XK_Cyrillic_O					: break;/* U+041E CYRILLIC CAPITAL LETTER O */
				case XK_Cyrillic_PE					: break;/* U+041F CYRILLIC CAPITAL LETTER PE */
				case XK_Cyrillic_YA					: break;/* U+042F CYRILLIC CAPITAL LETTER YA */
				case XK_Cyrillic_ER					: break;/* U+0420 CYRILLIC CAPITAL LETTER ER */
				case XK_Cyrillic_ES					: break;/* U+0421 CYRILLIC CAPITAL LETTER ES */
				case XK_Cyrillic_TE					: break;/* U+0422 CYRILLIC CAPITAL LETTER TE */
				case XK_Cyrillic_U					: break;/* U+0423 CYRILLIC CAPITAL LETTER U */
				case XK_Cyrillic_ZHE				: break;	/* U+0416 CYRILLIC CAPITAL LETTER ZHE */
				case XK_Cyrillic_VE					: break;/* U+0412 CYRILLIC CAPITAL LETTER VE */
				case XK_Cyrillic_SOFTSIGN			: break;/* U+042C CYRILLIC CAPITAL LETTER SOFT SIGN */
				case XK_Cyrillic_YERU				: break;/* U+042B CYRILLIC CAPITAL LETTER YERU */
				case XK_Cyrillic_ZE					: break;/* U+0417 CYRILLIC CAPITAL LETTER ZE */
				case XK_Cyrillic_SHA				: break;	/* U+0428 CYRILLIC CAPITAL LETTER SHA */
				case XK_Cyrillic_E					: break;/* U+042D CYRILLIC CAPITAL LETTER E */
				case XK_Cyrillic_SHCHA				: break;/* U+0429 CYRILLIC CAPITAL LETTER SHCHA */
				case XK_Cyrillic_CHE				: break;	/* U+0427 CYRILLIC CAPITAL LETTER CHE */
				case XK_Cyrillic_HARDSIGN			: break;/* U+042A CYRILLIC CAPITAL LETTER HARD SIGN */
			#endif /* XK_CYRILLIC */
			#ifdef XK_GREEK
				case XK_Greek_ALPHAaccent           : break; /* U+0386 GREEK CAPITAL LETTER ALPHA WITH TONOS */
				case XK_Greek_EPSILONaccent         : break; /* U+0388 GREEK CAPITAL LETTER EPSILON WITH TONOS */
				case XK_Greek_ETAaccent             : break; /* U+0389 GREEK CAPITAL LETTER ETA WITH TONOS */
				case XK_Greek_IOTAaccent            : break; /* U+038A GREEK CAPITAL LETTER IOTA WITH TONOS */
				case XK_Greek_IOTAdieresis          : break; /* U+03AA GREEK CAPITAL LETTER IOTA WITH DIALYTIKA */
//				case XK_Greek_IOTAdiaeresis         : break; /* old typo */
				case XK_Greek_OMICRONaccent         : break; /* U+038C GREEK CAPITAL LETTER OMICRON WITH TONOS */
				case XK_Greek_UPSILONaccent         : break; /* U+038E GREEK CAPITAL LETTER UPSILON WITH TONOS */
				case XK_Greek_UPSILONdieresis       : break; /* U+03AB GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA */
				case XK_Greek_OMEGAaccent           : break; /* U+038F GREEK CAPITAL LETTER OMEGA WITH TONOS */
				case XK_Greek_accentdieresis        : break; /* U+0385 GREEK DIALYTIKA TONOS */
				case XK_Greek_horizbar              : break; /* U+2015 HORIZONTAL BAR */
				case XK_Greek_alphaaccent           : break; /* U+03AC GREEK SMALL LETTER ALPHA WITH TONOS */
				case XK_Greek_epsilonaccent         : break; /* U+03AD GREEK SMALL LETTER EPSILON WITH TONOS */
				case XK_Greek_etaaccent             : break; /* U+03AE GREEK SMALL LETTER ETA WITH TONOS */
				case XK_Greek_iotaaccent            : break; /* U+03AF GREEK SMALL LETTER IOTA WITH TONOS */
				case XK_Greek_iotadieresis          : break; /* U+03CA GREEK SMALL LETTER IOTA WITH DIALYTIKA */
				case XK_Greek_iotaaccentdieresis    : break; /* U+0390 GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS */
				case XK_Greek_omicronaccent         : break; /* U+03CC GREEK SMALL LETTER OMICRON WITH TONOS */
				case XK_Greek_upsilonaccent         : break; /* U+03CD GREEK SMALL LETTER UPSILON WITH TONOS */
				case XK_Greek_upsilondieresis       : break; /* U+03CB GREEK SMALL LETTER UPSILON WITH DIALYTIKA */
				case XK_Greek_upsilonaccentdieresis : break; /* U+03B0 GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS */
				case XK_Greek_omegaaccent           : break; /* U+03CE GREEK SMALL LETTER OMEGA WITH TONOS */
				case XK_Greek_ALPHA                 : break; /* U+0391 GREEK CAPITAL LETTER ALPHA */
				case XK_Greek_BETA                  : break; /* U+0392 GREEK CAPITAL LETTER BETA */
				case XK_Greek_GAMMA                 : break; /* U+0393 GREEK CAPITAL LETTER GAMMA */
				case XK_Greek_DELTA                 : break; /* U+0394 GREEK CAPITAL LETTER DELTA */
				case XK_Greek_EPSILON               : break; /* U+0395 GREEK CAPITAL LETTER EPSILON */
				case XK_Greek_ZETA                  : break; /* U+0396 GREEK CAPITAL LETTER ZETA */
				case XK_Greek_ETA                   : break; /* U+0397 GREEK CAPITAL LETTER ETA */
				case XK_Greek_THETA                 : break; /* U+0398 GREEK CAPITAL LETTER THETA */
				case XK_Greek_IOTA                  : break; /* U+0399 GREEK CAPITAL LETTER IOTA */
				case XK_Greek_KAPPA                 : break; /* U+039A GREEK CAPITAL LETTER KAPPA */
//				case XK_Greek_LAMDA                 : break; /* U+039B GREEK CAPITAL LETTER LAMDA */
				case XK_Greek_LAMBDA                : break; /* U+039B GREEK CAPITAL LETTER LAMDA */
				case XK_Greek_MU                    : break; /* U+039C GREEK CAPITAL LETTER MU */
				case XK_Greek_NU                    : break; /* U+039D GREEK CAPITAL LETTER NU */
				case XK_Greek_XI                    : break; /* U+039E GREEK CAPITAL LETTER XI */
				case XK_Greek_OMICRON               : break; /* U+039F GREEK CAPITAL LETTER OMICRON */
				case XK_Greek_PI                    : break; /* U+03A0 GREEK CAPITAL LETTER PI */
				case XK_Greek_RHO                   : break; /* U+03A1 GREEK CAPITAL LETTER RHO */
				case XK_Greek_SIGMA                 : break; /* U+03A3 GREEK CAPITAL LETTER SIGMA */
				case XK_Greek_TAU                   : break; /* U+03A4 GREEK CAPITAL LETTER TAU */
				case XK_Greek_UPSILON               : break; /* U+03A5 GREEK CAPITAL LETTER UPSILON */
				case XK_Greek_PHI                   : break; /* U+03A6 GREEK CAPITAL LETTER PHI */
				case XK_Greek_CHI                   : break; /* U+03A7 GREEK CAPITAL LETTER CHI */
				case XK_Greek_PSI                   : break; /* U+03A8 GREEK CAPITAL LETTER PSI */
				case XK_Greek_OMEGA                 : break; /* U+03A9 GREEK CAPITAL LETTER OMEGA */
				case XK_Greek_alpha                 : break; /* U+03B1 GREEK SMALL LETTER ALPHA */
				case XK_Greek_beta                  : break; /* U+03B2 GREEK SMALL LETTER BETA */
				case XK_Greek_gamma                 : break; /* U+03B3 GREEK SMALL LETTER GAMMA */
				case XK_Greek_delta                 : break; /* U+03B4 GREEK SMALL LETTER DELTA */
				case XK_Greek_epsilon               : break; /* U+03B5 GREEK SMALL LETTER EPSILON */
				case XK_Greek_zeta                  : break; /* U+03B6 GREEK SMALL LETTER ZETA */
				case XK_Greek_eta                   : break; /* U+03B7 GREEK SMALL LETTER ETA */
				case XK_Greek_theta                 : break; /* U+03B8 GREEK SMALL LETTER THETA */
				case XK_Greek_iota                  : break; /* U+03B9 GREEK SMALL LETTER IOTA */
				case XK_Greek_kappa                 : break; /* U+03BA GREEK SMALL LETTER KAPPA */
//				case XK_Greek_lamda                 : break; /* U+03BB GREEK SMALL LETTER LAMDA */
				case XK_Greek_lambda                : break; /* U+03BB GREEK SMALL LETTER LAMDA */
				case XK_Greek_mu                    : break; /* U+03BC GREEK SMALL LETTER MU */
				case XK_Greek_nu                    : break; /* U+03BD GREEK SMALL LETTER NU */
				case XK_Greek_xi                    : break; /* U+03BE GREEK SMALL LETTER XI */
				case XK_Greek_omicron               : break; /* U+03BF GREEK SMALL LETTER OMICRON */
				case XK_Greek_pi                    : break; /* U+03C0 GREEK SMALL LETTER PI */
				case XK_Greek_rho                   : break; /* U+03C1 GREEK SMALL LETTER RHO */
				case XK_Greek_sigma                 : break; /* U+03C3 GREEK SMALL LETTER SIGMA */
				case XK_Greek_finalsmallsigma       : break; /* U+03C2 GREEK SMALL LETTER FINAL SIGMA */
				case XK_Greek_tau                   : break; /* U+03C4 GREEK SMALL LETTER TAU */
				case XK_Greek_upsilon               : break; /* U+03C5 GREEK SMALL LETTER UPSILON */
				case XK_Greek_phi                   : break; /* U+03C6 GREEK SMALL LETTER PHI */
				case XK_Greek_chi                   : break; /* U+03C7 GREEK SMALL LETTER CHI */
				case XK_Greek_psi                   : break; /* U+03C8 GREEK SMALL LETTER PSI */
				case XK_Greek_omega                 : break; /* U+03C9 GREEK SMALL LETTER OMEGA */
			#ifndef XK_MISCELLANY
				case XK_Greek_switch                : break; /* Alias for mode_switch */
			#endif
			#endif /* XK_GREEK */
			#ifdef XK_TECHNICAL
				case XK_leftradical               : break; /* U+23B7 RADICAL SYMBOL BOTTOM */
				case XK_topleftradical            : break; /*(U+250C BOX DRAWINGS LIGHT DOWN AND RIGHT)*/
				case XK_horizconnector            : break; /*(U+2500 BOX DRAWINGS LIGHT HORIZONTAL)*/
				case XK_topintegral               : break; /* U+2320 TOP HALF INTEGRAL */
				case XK_botintegral               : break; /* U+2321 BOTTOM HALF INTEGRAL */
				case XK_vertconnector             : break; /*(U+2502 BOX DRAWINGS LIGHT VERTICAL)*/
				case XK_topleftsqbracket          : break; /* U+23A1 LEFT SQUARE BRACKET UPPER CORNER */
				case XK_botleftsqbracket          : break; /* U+23A3 LEFT SQUARE BRACKET LOWER CORNER */
				case XK_toprightsqbracket         : break; /* U+23A4 RIGHT SQUARE BRACKET UPPER CORNER */
				case XK_botrightsqbracket         : break; /* U+23A6 RIGHT SQUARE BRACKET LOWER CORNER */
				case XK_topleftparens             : break; /* U+239B LEFT PARENTHESIS UPPER HOOK */
				case XK_botleftparens             : break; /* U+239D LEFT PARENTHESIS LOWER HOOK */
				case XK_toprightparens            : break; /* U+239E RIGHT PARENTHESIS UPPER HOOK */
				case XK_botrightparens            : break; /* U+23A0 RIGHT PARENTHESIS LOWER HOOK */
				case XK_leftmiddlecurlybrace      : break; /* U+23A8 LEFT CURLY BRACKET MIDDLE PIECE */
				case XK_rightmiddlecurlybrace     : break; /* U+23AC RIGHT CURLY BRACKET MIDDLE PIECE */
				case XK_topleftsummation          : break;
				case XK_botleftsummation          : break;
				case XK_topvertsummationconnector : break;
				case XK_botvertsummationconnector : break;
				case XK_toprightsummation         : break;
				case XK_botrightsummation         : break;
				case XK_rightmiddlesummation      : break;
				case XK_lessthanequal             : break; /* U+2264 LESS-THAN OR EQUAL TO */
				case XK_notequal                  : break; /* U+2260 NOT EQUAL TO */
				case XK_greaterthanequal          : break; /* U+2265 GREATER-THAN OR EQUAL TO */
				case XK_integral                  : break; /* U+222B INTEGRAL */
				case XK_therefore                 : break; /* U+2234 THEREFORE */
				case XK_variation                 : break; /* U+221D PROPORTIONAL TO */
				case XK_infinity                  : break; /* U+221E INFINITY */
				case XK_nabla                     : break; /* U+2207 NABLA */
				case XK_approximate               : break; /* U+223C TILDE OPERATOR */
				case XK_similarequal              : break; /* U+2243 ASYMPTOTICALLY EQUAL TO */
				case XK_ifonlyif                  : break; /* U+21D4 LEFT RIGHT DOUBLE ARROW */
				case XK_implies                   : break; /* U+21D2 RIGHTWARDS DOUBLE ARROW */
				case XK_identical                 : break; /* U+2261 IDENTICAL TO */
				case XK_radical                   : break; /* U+221A SQUARE ROOT */
				case XK_includedin                : break; /* U+2282 SUBSET OF */
				case XK_includes                  : break; /* U+2283 SUPERSET OF */
				case XK_intersection              : break; /* U+2229 INTERSECTION */
				case XK_union                     : break; /* U+222A UNION */
				case XK_logicaland                : break; /* U+2227 LOGICAL AND */
				case XK_logicalor                 : break; /* U+2228 LOGICAL OR */
				case XK_partialderivative         : break; /* U+2202 PARTIAL DIFFERENTIAL */
				case XK_function                  : break; /* U+0192 LATIN SMALL LETTER F WITH HOOK */
				case XK_leftarrow                 : break; /* U+2190 LEFTWARDS ARROW */
				case XK_uparrow                   : break; /* U+2191 UPWARDS ARROW */
				case XK_rightarrow                : break; /* U+2192 RIGHTWARDS ARROW */
				case XK_downarrow                 : break; /* U+2193 DOWNWARDS ARROW */
			#endif /* XK_TECHNICAL */
			#ifdef XK_SPECIAL
				case XK_blank             : break;
				case XK_soliddiamond      : break;  /* U+25C6 BLACK DIAMOND */
				case XK_checkerboard      : break;  /* U+2592 MEDIUM SHADE */
				case XK_ht                : break;  /* U+2409 SYMBOL FOR HORIZONTAL TABULATION */
				case XK_ff                : break;  /* U+240C SYMBOL FOR FORM FEED */
				case XK_cr                : break;  /* U+240D SYMBOL FOR CARRIAGE RETURN */
				case XK_lf                : break;  /* U+240A SYMBOL FOR LINE FEED */
				case XK_nl                : break;  /* U+2424 SYMBOL FOR NEWLINE */
				case XK_vt                : break;  /* U+240B SYMBOL FOR VERTICAL TABULATION */
				case XK_lowrightcorner    : break;  /* U+2518 BOX DRAWINGS LIGHT UP AND LEFT */
				case XK_uprightcorner     : break;  /* U+2510 BOX DRAWINGS LIGHT DOWN AND LEFT */
				case XK_upleftcorner      : break;  /* U+250C BOX DRAWINGS LIGHT DOWN AND RIGHT */
				case XK_lowleftcorner     : break;  /* U+2514 BOX DRAWINGS LIGHT UP AND RIGHT */
				case XK_crossinglines     : break;  /* U+253C BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
				case XK_horizlinescan1    : break;  /* U+23BA HORIZONTAL SCAN LINE-1 */
				case XK_horizlinescan3    : break;  /* U+23BB HORIZONTAL SCAN LINE-3 */
				case XK_horizlinescan5    : break;  /* U+2500 BOX DRAWINGS LIGHT HORIZONTAL */
				case XK_horizlinescan7    : break;  /* U+23BC HORIZONTAL SCAN LINE-7 */
				case XK_horizlinescan9    : break;  /* U+23BD HORIZONTAL SCAN LINE-9 */
				case XK_leftt             : break;  /* U+251C BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
				case XK_rightt            : break;  /* U+2524 BOX DRAWINGS LIGHT VERTICAL AND LEFT */
				case XK_bott              : break;  /* U+2534 BOX DRAWINGS LIGHT UP AND HORIZONTAL */
				case XK_topt              : break;  /* U+252C BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
				case XK_vertbar           : break;  /* U+2502 BOX DRAWINGS LIGHT VERTICAL */
			#endif /* XK_SPECIAL */
			#ifdef XK_PUBLISHING
				case XK_emspace                 : break; /* U+2003 EM SPACE */
				case XK_enspace                 : break; /* U+2002 EN SPACE */
				case XK_em3space                : break; /* U+2004 THREE-PER-EM SPACE */
				case XK_em4space                : break; /* U+2005 FOUR-PER-EM SPACE */
				case XK_digitspace              : break; /* U+2007 FIGURE SPACE */
				case XK_punctspace              : break; /* U+2008 PUNCTUATION SPACE */
				case XK_thinspace               : break; /* U+2009 THIN SPACE */
				case XK_hairspace               : break; /* U+200A HAIR SPACE */
				case XK_emdash                  : break; /* U+2014 EM DASH */
				case XK_endash                  : break; /* U+2013 EN DASH */
				case XK_signifblank             : break; /*(U+2423 OPEN BOX)*/
				case XK_ellipsis                : break; /* U+2026 HORIZONTAL ELLIPSIS */
				case XK_doubbaselinedot         : break; /* U+2025 TWO DOT LEADER */
				case XK_onethird                : break; /* U+2153 VULGAR FRACTION ONE THIRD */
				case XK_twothirds               : break; /* U+2154 VULGAR FRACTION TWO THIRDS */
				case XK_onefifth                : break; /* U+2155 VULGAR FRACTION ONE FIFTH */
				case XK_twofifths               : break; /* U+2156 VULGAR FRACTION TWO FIFTHS */
				case XK_threefifths             : break; /* U+2157 VULGAR FRACTION THREE FIFTHS */
				case XK_fourfifths              : break; /* U+2158 VULGAR FRACTION FOUR FIFTHS */
				case XK_onesixth                : break; /* U+2159 VULGAR FRACTION ONE SIXTH */
				case XK_fivesixths              : break; /* U+215A VULGAR FRACTION FIVE SIXTHS */
				case XK_careof                  : break; /* U+2105 CARE OF */
				case XK_figdash                 : break; /* U+2012 FIGURE DASH */
				case XK_leftanglebracket        : break; /*(U+27E8 MATHEMATICAL LEFT ANGLE BRACKET)*/
				case XK_decimalpoint            : break; /*(U+002E FULL STOP)*/
				case XK_rightanglebracket       : break; /*(U+27E9 MATHEMATICAL RIGHT ANGLE BRACKET)*/
				case XK_marker                  : break;
				case XK_oneeighth               : break; /* U+215B VULGAR FRACTION ONE EIGHTH */
				case XK_threeeighths            : break; /* U+215C VULGAR FRACTION THREE EIGHTHS */
				case XK_fiveeighths             : break; /* U+215D VULGAR FRACTION FIVE EIGHTHS */
				case XK_seveneighths            : break; /* U+215E VULGAR FRACTION SEVEN EIGHTHS */
				case XK_trademark               : break; /* U+2122 TRADE MARK SIGN */
				case XK_signaturemark           : break; /*(U+2613 SALTIRE)*/
				case XK_trademarkincircle       : break;
				case XK_leftopentriangle        : break; /*(U+25C1 WHITE LEFT-POINTING TRIANGLE)*/
				case XK_rightopentriangle       : break; /*(U+25B7 WHITE RIGHT-POINTING TRIANGLE)*/
				case XK_emopencircle            : break; /*(U+25CB WHITE CIRCLE)*/
				case XK_emopenrectangle         : break; /*(U+25AF WHITE VERTICAL RECTANGLE)*/
				case XK_leftsinglequotemark     : break; /* U+2018 LEFT SINGLE QUOTATION MARK */
				case XK_rightsinglequotemark    : break; /* U+2019 RIGHT SINGLE QUOTATION MARK */
				case XK_leftdoublequotemark     : break; /* U+201C LEFT DOUBLE QUOTATION MARK */
				case XK_rightdoublequotemark    : break; /* U+201D RIGHT DOUBLE QUOTATION MARK */
				case XK_prescription            : break; /* U+211E PRESCRIPTION TAKE */
				case XK_minutes                 : break; /* U+2032 PRIME */
				case XK_seconds                 : break; /* U+2033 DOUBLE PRIME */
				case XK_latincross              : break; /* U+271D LATIN CROSS */
				case XK_hexagram                : break;
				case XK_filledrectbullet        : break; /*(U+25AC BLACK RECTANGLE)*/
				case XK_filledlefttribullet     : break; /*(U+25C0 BLACK LEFT-POINTING TRIANGLE)*/
				case XK_filledrighttribullet    : break; /*(U+25B6 BLACK RIGHT-POINTING TRIANGLE)*/
				case XK_emfilledcircle          : break; /*(U+25CF BLACK CIRCLE)*/
				case XK_emfilledrect            : break; /*(U+25AE BLACK VERTICAL RECTANGLE)*/
				case XK_enopencircbullet        : break; /*(U+25E6 WHITE BULLET)*/
				case XK_enopensquarebullet      : break; /*(U+25AB WHITE SMALL SQUARE)*/
				case XK_openrectbullet          : break; /*(U+25AD WHITE RECTANGLE)*/
				case XK_opentribulletup         : break; /*(U+25B3 WHITE UP-POINTING TRIANGLE)*/
				case XK_opentribulletdown       : break; /*(U+25BD WHITE DOWN-POINTING TRIANGLE)*/
				case XK_openstar                : break; /*(U+2606 WHITE STAR)*/
				case XK_enfilledcircbullet      : break; /*(U+2022 BULLET)*/
				case XK_enfilledsqbullet        : break; /*(U+25AA BLACK SMALL SQUARE)*/
				case XK_filledtribulletup       : break; /*(U+25B2 BLACK UP-POINTING TRIANGLE)*/
				case XK_filledtribulletdown     : break; /*(U+25BC BLACK DOWN-POINTING TRIANGLE)*/
				case XK_leftpointer             : break; /*(U+261C WHITE LEFT POINTING INDEX)*/
				case XK_rightpointer            : break; /*(U+261E WHITE RIGHT POINTING INDEX)*/
				case XK_club                    : break; /* U+2663 BLACK CLUB SUIT */
				case XK_diamond                 : break; /* U+2666 BLACK DIAMOND SUIT */
				case XK_heart                   : break; /* U+2665 BLACK HEART SUIT */
				case XK_maltesecross            : break; /* U+2720 MALTESE CROSS */
				case XK_dagger                  : break; /* U+2020 DAGGER */
				case XK_doubledagger            : break; /* U+2021 DOUBLE DAGGER */
				case XK_checkmark               : break; /* U+2713 CHECK MARK */
				case XK_ballotcross             : break; /* U+2717 BALLOT X */
				case XK_musicalsharp            : break; /* U+266F MUSIC SHARP SIGN */
				case XK_musicalflat             : break; /* U+266D MUSIC FLAT SIGN */
				case XK_malesymbol              : break; /* U+2642 MALE SIGN */
				case XK_femalesymbol            : break; /* U+2640 FEMALE SIGN */
				case XK_telephone               : break; /* U+260E BLACK TELEPHONE */
				case XK_telephonerecorder       : break; /* U+2315 TELEPHONE RECORDER */
				case XK_phonographcopyright     : break; /* U+2117 SOUND RECORDING COPYRIGHT */
				case XK_caret                   : break; /* U+2038 CARET */
				case XK_singlelowquotemark      : break; /* U+201A SINGLE LOW-9 QUOTATION MARK */
				case XK_doublelowquotemark      : break; /* U+201E DOUBLE LOW-9 QUOTATION MARK */
				case XK_cursor                  : break;
			#endif /* XK_PUBLISHING */
			#ifdef XK_APL
				case XK_leftcaret               :break; /*(U+003C LESS-THAN SIGN)*/
				case XK_rightcaret              :break; /*(U+003E GREATER-THAN SIGN)*/
				case XK_downcaret               :break; /*(U+2228 LOGICAL OR)*/
				case XK_upcaret                 :break; /*(U+2227 LOGICAL AND)*/
				case XK_overbar                 :break; /*(U+00AF MACRON)*/
				case XK_downtack                :break; /* U+22A5 UP TACK */
				case XK_upshoe                  :break; /*(U+2229 INTERSECTION)*/
				case XK_downstile               :break; /* U+230A LEFT FLOOR */
				case XK_underbar                :break; /*(U+005F LOW LINE)*/
				case XK_jot                     :break; /* U+2218 RING OPERATOR */
				case XK_quad                    :break; /* U+2395 APL FUNCTIONAL SYMBOL QUAD */
				case XK_uptack                  :break; /* U+22A4 DOWN TACK */
				case XK_circle                  :break; /* U+25CB WHITE CIRCLE */
				case XK_upstile                 :break; /* U+2308 LEFT CEILING */
				case XK_downshoe                :break; /*(U+222A UNION)*/
				case XK_rightshoe               :break; /*(U+2283 SUPERSET OF)*/
				case XK_leftshoe                :break; /*(U+2282 SUBSET OF)*/
				case XK_lefttack                :break; /* U+22A2 RIGHT TACK */
				case XK_righttack               :break; /* U+22A3 LEFT TACK */
			#endif /* XK_APL */
			#ifdef XK_HEBREW
				case XK_hebrew_doublelowline      : break; /* U+2017 DOUBLE LOW LINE */
				case XK_hebrew_aleph              : break; /* U+05D0 HEBREW LETTER ALEF */
				case XK_hebrew_bet                : break; /* U+05D1 HEBREW LETTER BET */
				case XK_hebrew_gimel              : break; /* U+05D2 HEBREW LETTER GIMEL */
				case XK_hebrew_dalet              : break; /* U+05D3 HEBREW LETTER DALET */
				case XK_hebrew_he                 : break; /* U+05D4 HEBREW LETTER HE */
				case XK_hebrew_waw                : break; /* U+05D5 HEBREW LETTER VAV */
				case XK_hebrew_zain               : break; /* U+05D6 HEBREW LETTER ZAYIN */
				case XK_hebrew_chet               : break; /* U+05D7 HEBREW LETTER HET */
				case XK_hebrew_tet                : break; /* U+05D8 HEBREW LETTER TET */
				case XK_hebrew_yod                : break; /* U+05D9 HEBREW LETTER YOD */
				case XK_hebrew_finalkaph          : break; /* U+05DA HEBREW LETTER FINAL KAF */
				case XK_hebrew_kaph               : break; /* U+05DB HEBREW LETTER KAF */
				case XK_hebrew_lamed              : break; /* U+05DC HEBREW LETTER LAMED */
				case XK_hebrew_finalmem           : break; /* U+05DD HEBREW LETTER FINAL MEM */
				case XK_hebrew_mem                : break; /* U+05DE HEBREW LETTER MEM */
				case XK_hebrew_finalnun           : break; /* U+05DF HEBREW LETTER FINAL NUN */
				case XK_hebrew_nun                : break; /* U+05E0 HEBREW LETTER NUN */
				case XK_hebrew_samech             : break; /* U+05E1 HEBREW LETTER SAMEKH */
				case XK_hebrew_ayin               : break; /* U+05E2 HEBREW LETTER AYIN */
				case XK_hebrew_finalpe            : break; /* U+05E3 HEBREW LETTER FINAL PE */
				case XK_hebrew_pe                 : break; /* U+05E4 HEBREW LETTER PE */
				case XK_hebrew_finalzade          : break; /* U+05E5 HEBREW LETTER FINAL TSADI */
				case XK_hebrew_zade               : break; /* U+05E6 HEBREW LETTER TSADI */
				case XK_hebrew_qoph               : break; /* U+05E7 HEBREW LETTER QOF */
				case XK_hebrew_resh               : break; /* U+05E8 HEBREW LETTER RESH */
				case XK_hebrew_shin               : break; /* U+05E9 HEBREW LETTER SHIN */
				case XK_hebrew_taw                : break; /* U+05EA HEBREW LETTER TAV */
			#ifndef XK_MISCELLANY
				case XK_Hebrew_switch             : break; /* Alias for mode_switch */
			#endif
			#endif /* XK_HEBREW */
			#ifdef XK_THAI
				case XK_Thai_kokai             : break; /* U+0E01 THAI CHARACTER KO KAI */
				case XK_Thai_khokhai           : break; /* U+0E02 THAI CHARACTER KHO KHAI */
				case XK_Thai_khokhuat          : break; /* U+0E03 THAI CHARACTER KHO KHUAT */
				case XK_Thai_khokhwai          : break; /* U+0E04 THAI CHARACTER KHO KHWAI */
				case XK_Thai_khokhon           : break; /* U+0E05 THAI CHARACTER KHO KHON */
				case XK_Thai_khorakhang        : break; /* U+0E06 THAI CHARACTER KHO RAKHANG */
				case XK_Thai_ngongu            : break; /* U+0E07 THAI CHARACTER NGO NGU */
				case XK_Thai_chochan           : break; /* U+0E08 THAI CHARACTER CHO CHAN */
				case XK_Thai_choching          : break; /* U+0E09 THAI CHARACTER CHO CHING */
				case XK_Thai_chochang          : break; /* U+0E0A THAI CHARACTER CHO CHANG */
				case XK_Thai_soso              : break; /* U+0E0B THAI CHARACTER SO SO */
				case XK_Thai_chochoe           : break; /* U+0E0C THAI CHARACTER CHO CHOE */
				case XK_Thai_yoying            : break; /* U+0E0D THAI CHARACTER YO YING */
				case XK_Thai_dochada           : break; /* U+0E0E THAI CHARACTER DO CHADA */
				case XK_Thai_topatak           : break; /* U+0E0F THAI CHARACTER TO PATAK */
				case XK_Thai_thothan           : break; /* U+0E10 THAI CHARACTER THO THAN */
				case XK_Thai_thonangmontho     : break; /* U+0E11 THAI CHARACTER THO NANGMONTHO */
				case XK_Thai_thophuthao        : break; /* U+0E12 THAI CHARACTER THO PHUTHAO */
				case XK_Thai_nonen             : break; /* U+0E13 THAI CHARACTER NO NEN */
				case XK_Thai_dodek             : break; /* U+0E14 THAI CHARACTER DO DEK */
				case XK_Thai_totao             : break; /* U+0E15 THAI CHARACTER TO TAO */
				case XK_Thai_thothung          : break; /* U+0E16 THAI CHARACTER THO THUNG */
				case XK_Thai_thothahan         : break; /* U+0E17 THAI CHARACTER THO THAHAN */
				case XK_Thai_thothong          : break; /* U+0E18 THAI CHARACTER THO THONG */
				case XK_Thai_nonu              : break; /* U+0E19 THAI CHARACTER NO NU */
				case XK_Thai_bobaimai          : break; /* U+0E1A THAI CHARACTER BO BAIMAI */
				case XK_Thai_popla             : break; /* U+0E1B THAI CHARACTER PO PLA */
				case XK_Thai_phophung          : break; /* U+0E1C THAI CHARACTER PHO PHUNG */
				case XK_Thai_fofa              : break; /* U+0E1D THAI CHARACTER FO FA */
				case XK_Thai_phophan           : break; /* U+0E1E THAI CHARACTER PHO PHAN */
				case XK_Thai_fofan             : break; /* U+0E1F THAI CHARACTER FO FAN */
				case XK_Thai_phosamphao        : break; /* U+0E20 THAI CHARACTER PHO SAMPHAO */
				case XK_Thai_moma              : break; /* U+0E21 THAI CHARACTER MO MA */
				case XK_Thai_yoyak             : break; /* U+0E22 THAI CHARACTER YO YAK */
				case XK_Thai_rorua             : break; /* U+0E23 THAI CHARACTER RO RUA */
				case XK_Thai_ru                : break; /* U+0E24 THAI CHARACTER RU */
				case XK_Thai_loling            : break; /* U+0E25 THAI CHARACTER LO LING */
				case XK_Thai_lu                : break; /* U+0E26 THAI CHARACTER LU */
				case XK_Thai_wowaen            : break; /* U+0E27 THAI CHARACTER WO WAEN */
				case XK_Thai_sosala            : break; /* U+0E28 THAI CHARACTER SO SALA */
				case XK_Thai_sorusi            : break; /* U+0E29 THAI CHARACTER SO RUSI */
				case XK_Thai_sosua             : break; /* U+0E2A THAI CHARACTER SO SUA */
				case XK_Thai_hohip             : break; /* U+0E2B THAI CHARACTER HO HIP */
				case XK_Thai_lochula           : break; /* U+0E2C THAI CHARACTER LO CHULA */
				case XK_Thai_oang              : break; /* U+0E2D THAI CHARACTER O ANG */
				case XK_Thai_honokhuk          : break; /* U+0E2E THAI CHARACTER HO NOKHUK */
				case XK_Thai_paiyannoi         : break; /* U+0E2F THAI CHARACTER PAIYANNOI */
				case XK_Thai_saraa             : break; /* U+0E30 THAI CHARACTER SARA A */
				case XK_Thai_maihanakat        : break; /* U+0E31 THAI CHARACTER MAI HAN-AKAT */
				case XK_Thai_saraaa            : break; /* U+0E32 THAI CHARACTER SARA AA */
				case XK_Thai_saraam            : break; /* U+0E33 THAI CHARACTER SARA AM */
				case XK_Thai_sarai             : break; /* U+0E34 THAI CHARACTER SARA I */
				case XK_Thai_saraii            : break; /* U+0E35 THAI CHARACTER SARA II */
				case XK_Thai_saraue            : break; /* U+0E36 THAI CHARACTER SARA UE */
				case XK_Thai_sarauee           : break; /* U+0E37 THAI CHARACTER SARA UEE */
				case XK_Thai_sarau             : break; /* U+0E38 THAI CHARACTER SARA U */
				case XK_Thai_sarauu            : break; /* U+0E39 THAI CHARACTER SARA UU */
				case XK_Thai_phinthu           : break; /* U+0E3A THAI CHARACTER PHINTHU */
				case XK_Thai_maihanakat_maitho : break;
				case XK_Thai_baht              : break; /* U+0E3F THAI CURRENCY SYMBOL BAHT */
				case XK_Thai_sarae             : break; /* U+0E40 THAI CHARACTER SARA E */
				case XK_Thai_saraae            : break; /* U+0E41 THAI CHARACTER SARA AE */
				case XK_Thai_sarao             : break; /* U+0E42 THAI CHARACTER SARA O */
				case XK_Thai_saraaimaimuan     : break; /* U+0E43 THAI CHARACTER SARA AI MAIMUAN */
				case XK_Thai_saraaimaimalai    : break; /* U+0E44 THAI CHARACTER SARA AI MAIMALAI */
				case XK_Thai_lakkhangyao       : break; /* U+0E45 THAI CHARACTER LAKKHANGYAO */
				case XK_Thai_maiyamok          : break; /* U+0E46 THAI CHARACTER MAIYAMOK */
				case XK_Thai_maitaikhu         : break; /* U+0E47 THAI CHARACTER MAITAIKHU */
				case XK_Thai_maiek             : break; /* U+0E48 THAI CHARACTER MAI EK */
				case XK_Thai_maitho            : break; /* U+0E49 THAI CHARACTER MAI THO */
				case XK_Thai_maitri            : break; /* U+0E4A THAI CHARACTER MAI TRI */
				case XK_Thai_maichattawa       : break; /* U+0E4B THAI CHARACTER MAI CHATTAWA */
				case XK_Thai_thanthakhat       : break; /* U+0E4C THAI CHARACTER THANTHAKHAT */
				case XK_Thai_nikhahit          : break; /* U+0E4D THAI CHARACTER NIKHAHIT */
				case XK_Thai_leksun            : break; /* U+0E50 THAI DIGIT ZERO */
				case XK_Thai_leknung           : break; /* U+0E51 THAI DIGIT ONE */
				case XK_Thai_leksong           : break; /* U+0E52 THAI DIGIT TWO */
				case XK_Thai_leksam            : break; /* U+0E53 THAI DIGIT THREE */
				case XK_Thai_leksi             : break; /* U+0E54 THAI DIGIT FOUR */
				case XK_Thai_lekha             : break; /* U+0E55 THAI DIGIT FIVE */
				case XK_Thai_lekhok            : break; /* U+0E56 THAI DIGIT SIX */
				case XK_Thai_lekchet           : break; /* U+0E57 THAI DIGIT SEVEN */
				case XK_Thai_lekpaet           : break; /* U+0E58 THAI DIGIT EIGHT */
				case XK_Thai_lekkao            : break; /* U+0E59 THAI DIGIT NINE */
			#endif /* XK_THAI */
			#ifdef XK_KOREAN
				case  XK_Hangul                      : break;/* Hangul start/stop(toggle) */
				case  XK_Hangul_Start                : break;/* Hangul start */
				case  XK_Hangul_End                  : break;/* Hangul end, English start */
				case  XK_Hangul_Hanja                : break;/* Start Hangul->Hanja Conversion */
				case  XK_Hangul_Jamo                 : break;/* Hangul Jamo mode */
				case  XK_Hangul_Romaja               : break;/* Hangul Romaja mode */
			#ifndef XK_MISCELLANY
				case  XK_Hangul_Codeinput            : break;/* Hangul code input mode */
			#endif
				case  XK_Hangul_Jeonja               : break;/* Jeonja mode */
				case  XK_Hangul_Banja                : break;/* Banja mode */
				case  XK_Hangul_PreHanja             : break;/* Pre Hanja conversion */
				case  XK_Hangul_PostHanja            : break;/* Post Hanja conversion */
			#ifndef XK_MISCELLANY
				case  XK_Hangul_SingleCandidate      : break;/* Single candidate */
				case  XK_Hangul_MultipleCandidate    : break;/* Multiple candidate */
				case  XK_Hangul_PreviousCandidate    : break;/* Previous candidate */
			#endif
				case  XK_Hangul_Special              : break;/* Special symbols */
			#ifndef XK_MISCELLANY
				case  XK_Hangul_switch               : break;/* Alias for mode_switch */
			#endif
				case  XK_Hangul_Kiyeog               : break;
				case  XK_Hangul_SsangKiyeog          : break;
				case  XK_Hangul_KiyeogSios           : break;
				case  XK_Hangul_Nieun                : break;
				case  XK_Hangul_NieunJieuj           : break;
				case  XK_Hangul_NieunHieuh           : break;
				case  XK_Hangul_Dikeud               : break;
				case  XK_Hangul_SsangDikeud          : break;
				case  XK_Hangul_Rieul                : break;
				case  XK_Hangul_RieulKiyeog          : break;
				case  XK_Hangul_RieulMieum           : break;
				case  XK_Hangul_RieulPieub           : break;
				case  XK_Hangul_RieulSios            : break;
				case  XK_Hangul_RieulTieut           : break;
				case  XK_Hangul_RieulPhieuf          : break;
				case  XK_Hangul_RieulHieuh           : break;
				case  XK_Hangul_Mieum                : break;
				case  XK_Hangul_Pieub                : break;
				case  XK_Hangul_SsangPieub           : break;
				case  XK_Hangul_PieubSios            : break;
				case  XK_Hangul_Sios                 : break;
				case  XK_Hangul_SsangSios            : break;
				case  XK_Hangul_Ieung                : break;
				case  XK_Hangul_Jieuj                : break;
				case  XK_Hangul_SsangJieuj           : break;
				case  XK_Hangul_Cieuc                : break;
				case  XK_Hangul_Khieuq               : break;
				case  XK_Hangul_Tieut                : break;
				case  XK_Hangul_Phieuf               : break;
				case  XK_Hangul_Hieuh                : break;
				case  XK_Hangul_A                    : break;
				case  XK_Hangul_AE                   : break;
				case  XK_Hangul_YA                   : break;
				case  XK_Hangul_YAE                  : break;
				case  XK_Hangul_EO                   : break;
				case  XK_Hangul_E                    : break;
				case  XK_Hangul_YEO                  : break;
				case  XK_Hangul_YE                   : break;
				case  XK_Hangul_O                    : break;
				case  XK_Hangul_WA                   : break;
				case  XK_Hangul_WAE                  : break;
				case  XK_Hangul_OE                   : break;
				case  XK_Hangul_YO                   : break;
				case  XK_Hangul_U                    : break;
				case  XK_Hangul_WEO                  : break;
				case  XK_Hangul_WE                   : break;
				case  XK_Hangul_WI                   : break;
				case  XK_Hangul_YU                   : break;
				case  XK_Hangul_EU                   : break;
				case  XK_Hangul_YI                   : break;
				case  XK_Hangul_I                    : break;
				case  XK_Hangul_J_Kiyeog             : break;
				case  XK_Hangul_J_SsangKiyeog        : break;
				case  XK_Hangul_J_KiyeogSios         : break;
				case  XK_Hangul_J_Nieun              : break;
				case  XK_Hangul_J_NieunJieuj         : break;
				case  XK_Hangul_J_NieunHieuh         : break;
				case  XK_Hangul_J_Dikeud             : break;
				case  XK_Hangul_J_Rieul              : break;
				case  XK_Hangul_J_RieulKiyeog        : break;
				case  XK_Hangul_J_RieulMieum         : break;
				case  XK_Hangul_J_RieulPieub         : break;
				case  XK_Hangul_J_RieulSios          : break;
				case  XK_Hangul_J_RieulTieut         : break;
				case  XK_Hangul_J_RieulPhieuf        : break;
				case  XK_Hangul_J_RieulHieuh         : break;
				case  XK_Hangul_J_Mieum              : break;
				case  XK_Hangul_J_Pieub              : break;
				case  XK_Hangul_J_PieubSios          : break;
				case  XK_Hangul_J_Sios               : break;
				case  XK_Hangul_J_SsangSios          : break;
				case  XK_Hangul_J_Ieung              : break;
				case  XK_Hangul_J_Jieuj              : break;
				case  XK_Hangul_J_Cieuc              : break;
				case  XK_Hangul_J_Khieuq             : break;
				case  XK_Hangul_J_Tieut              : break;
				case  XK_Hangul_J_Phieuf             : break;
				case  XK_Hangul_J_Hieuh              : break;
				case  XK_Hangul_RieulYeorinHieuh     : break;
				case  XK_Hangul_SunkyeongeumMieum    : break;
				case  XK_Hangul_SunkyeongeumPieub    : break;
				case  XK_Hangul_PanSios              : break;
				case  XK_Hangul_KkogjiDalrinIeung    : break;
				case  XK_Hangul_SunkyeongeumPhieuf   : break;
				case  XK_Hangul_YeorinHieuh          : break;
				case  XK_Hangul_AraeA                : break;
				case  XK_Hangul_AraeAE               : break;
				case  XK_Hangul_J_PanSios            : break;
				case  XK_Hangul_J_KkogjiDalrinIeung  : break;
				case  XK_Hangul_J_YeorinHieuh        : break;
				case  XK_Korean_Won                  : break;/*(U+20A9 WON SIGN)*/
			#endif /* XK_KOREAN */
			#ifdef XK_ARMENIAN
				case XK_Armenian_ligature_ew     : break; /* U+0587 ARMENIAN SMALL LIGATURE ECH YIWN */
				case XK_Armenian_full_stop       : break; /* U+0589 ARMENIAN FULL STOP */
//				case XK_Armenian_verjaket        : break; /* U+0589 ARMENIAN FULL STOP */
				case XK_Armenian_separation_mark : break; /* U+055D ARMENIAN COMMA */
//				case XK_Armenian_but             : break; /* U+055D ARMENIAN COMMA */
				case XK_Armenian_hyphen          : break; /* U+058A ARMENIAN HYPHEN */
//				case XK_Armenian_yentamna        : break; /* U+058A ARMENIAN HYPHEN */
				case XK_Armenian_exclam          : break; /* U+055C ARMENIAN EXCLAMATION MARK */
//				case XK_Armenian_amanak          : break; /* U+055C ARMENIAN EXCLAMATION MARK */
				case XK_Armenian_accent          : break; /* U+055B ARMENIAN EMPHASIS MARK */
//				case XK_Armenian_shesht          : break; /* U+055B ARMENIAN EMPHASIS MARK */
				case XK_Armenian_question        : break; /* U+055E ARMENIAN QUESTION MARK */
//				case XK_Armenian_paruyk          : break; /* U+055E ARMENIAN QUESTION MARK */
				case XK_Armenian_AYB             : break; /* U+0531 ARMENIAN CAPITAL LETTER AYB */
				case XK_Armenian_ayb             : break; /* U+0561 ARMENIAN SMALL LETTER AYB */
				case XK_Armenian_BEN             : break; /* U+0532 ARMENIAN CAPITAL LETTER BEN */
				case XK_Armenian_ben             : break; /* U+0562 ARMENIAN SMALL LETTER BEN */
				case XK_Armenian_GIM             : break; /* U+0533 ARMENIAN CAPITAL LETTER GIM */
				case XK_Armenian_gim             : break; /* U+0563 ARMENIAN SMALL LETTER GIM */
				case XK_Armenian_DA              : break; /* U+0534 ARMENIAN CAPITAL LETTER DA */
				case XK_Armenian_da              : break; /* U+0564 ARMENIAN SMALL LETTER DA */
				case XK_Armenian_YECH            : break; /* U+0535 ARMENIAN CAPITAL LETTER ECH */
				case XK_Armenian_yech            : break; /* U+0565 ARMENIAN SMALL LETTER ECH */
				case XK_Armenian_ZA              : break; /* U+0536 ARMENIAN CAPITAL LETTER ZA */
				case XK_Armenian_za              : break; /* U+0566 ARMENIAN SMALL LETTER ZA */
				case XK_Armenian_E               : break; /* U+0537 ARMENIAN CAPITAL LETTER EH */
				case XK_Armenian_e               : break; /* U+0567 ARMENIAN SMALL LETTER EH */
				case XK_Armenian_AT              : break; /* U+0538 ARMENIAN CAPITAL LETTER ET */
				case XK_Armenian_at              : break; /* U+0568 ARMENIAN SMALL LETTER ET */
				case XK_Armenian_TO              : break; /* U+0539 ARMENIAN CAPITAL LETTER TO */
				case XK_Armenian_to              : break; /* U+0569 ARMENIAN SMALL LETTER TO */
				case XK_Armenian_ZHE             : break; /* U+053A ARMENIAN CAPITAL LETTER ZHE */
				case XK_Armenian_zhe             : break; /* U+056A ARMENIAN SMALL LETTER ZHE */
				case XK_Armenian_INI             : break; /* U+053B ARMENIAN CAPITAL LETTER INI */
				case XK_Armenian_ini             : break; /* U+056B ARMENIAN SMALL LETTER INI */
				case XK_Armenian_LYUN            : break; /* U+053C ARMENIAN CAPITAL LETTER LIWN */
				case XK_Armenian_lyun            : break; /* U+056C ARMENIAN SMALL LETTER LIWN */
				case XK_Armenian_KHE             : break; /* U+053D ARMENIAN CAPITAL LETTER XEH */
				case XK_Armenian_khe             : break; /* U+056D ARMENIAN SMALL LETTER XEH */
				case XK_Armenian_TSA             : break; /* U+053E ARMENIAN CAPITAL LETTER CA */
				case XK_Armenian_tsa             : break; /* U+056E ARMENIAN SMALL LETTER CA */
				case XK_Armenian_KEN             : break; /* U+053F ARMENIAN CAPITAL LETTER KEN */
				case XK_Armenian_ken             : break; /* U+056F ARMENIAN SMALL LETTER KEN */
				case XK_Armenian_HO              : break; /* U+0540 ARMENIAN CAPITAL LETTER HO */
				case XK_Armenian_ho              : break; /* U+0570 ARMENIAN SMALL LETTER HO */
				case XK_Armenian_DZA             : break; /* U+0541 ARMENIAN CAPITAL LETTER JA */
				case XK_Armenian_dza             : break; /* U+0571 ARMENIAN SMALL LETTER JA */
				case XK_Armenian_GHAT            : break; /* U+0542 ARMENIAN CAPITAL LETTER GHAD */
				case XK_Armenian_ghat            : break; /* U+0572 ARMENIAN SMALL LETTER GHAD */
				case XK_Armenian_TCHE            : break; /* U+0543 ARMENIAN CAPITAL LETTER CHEH */
				case XK_Armenian_tche            : break; /* U+0573 ARMENIAN SMALL LETTER CHEH */
				case XK_Armenian_MEN             : break; /* U+0544 ARMENIAN CAPITAL LETTER MEN */
				case XK_Armenian_men             : break; /* U+0574 ARMENIAN SMALL LETTER MEN */
				case XK_Armenian_HI              : break; /* U+0545 ARMENIAN CAPITAL LETTER YI */
				case XK_Armenian_hi              : break; /* U+0575 ARMENIAN SMALL LETTER YI */
				case XK_Armenian_NU              : break; /* U+0546 ARMENIAN CAPITAL LETTER NOW */
				case XK_Armenian_nu              : break; /* U+0576 ARMENIAN SMALL LETTER NOW */
				case XK_Armenian_SHA             : break; /* U+0547 ARMENIAN CAPITAL LETTER SHA */
				case XK_Armenian_sha             : break; /* U+0577 ARMENIAN SMALL LETTER SHA */
				case XK_Armenian_VO              : break; /* U+0548 ARMENIAN CAPITAL LETTER VO */
				case XK_Armenian_vo              : break; /* U+0578 ARMENIAN SMALL LETTER VO */
				case XK_Armenian_CHA             : break; /* U+0549 ARMENIAN CAPITAL LETTER CHA */
				case XK_Armenian_cha             : break; /* U+0579 ARMENIAN SMALL LETTER CHA */
				case XK_Armenian_PE              : break; /* U+054A ARMENIAN CAPITAL LETTER PEH */
				case XK_Armenian_pe              : break; /* U+057A ARMENIAN SMALL LETTER PEH */
				case XK_Armenian_JE              : break; /* U+054B ARMENIAN CAPITAL LETTER JHEH */
				case XK_Armenian_je              : break; /* U+057B ARMENIAN SMALL LETTER JHEH */
				case XK_Armenian_RA              : break; /* U+054C ARMENIAN CAPITAL LETTER RA */
				case XK_Armenian_ra              : break; /* U+057C ARMENIAN SMALL LETTER RA */
				case XK_Armenian_SE              : break; /* U+054D ARMENIAN CAPITAL LETTER SEH */
				case XK_Armenian_se              : break; /* U+057D ARMENIAN SMALL LETTER SEH */
				case XK_Armenian_VEV             : break; /* U+054E ARMENIAN CAPITAL LETTER VEW */
				case XK_Armenian_vev             : break; /* U+057E ARMENIAN SMALL LETTER VEW */
				case XK_Armenian_TYUN            : break; /* U+054F ARMENIAN CAPITAL LETTER TIWN */
				case XK_Armenian_tyun            : break; /* U+057F ARMENIAN SMALL LETTER TIWN */
				case XK_Armenian_RE              : break; /* U+0550 ARMENIAN CAPITAL LETTER REH */
				case XK_Armenian_re              : break; /* U+0580 ARMENIAN SMALL LETTER REH */
				case XK_Armenian_TSO             : break; /* U+0551 ARMENIAN CAPITAL LETTER CO */
				case XK_Armenian_tso             : break; /* U+0581 ARMENIAN SMALL LETTER CO */
				case XK_Armenian_VYUN            : break; /* U+0552 ARMENIAN CAPITAL LETTER YIWN */
				case XK_Armenian_vyun            : break; /* U+0582 ARMENIAN SMALL LETTER YIWN */
				case XK_Armenian_PYUR            : break; /* U+0553 ARMENIAN CAPITAL LETTER PIWR */
				case XK_Armenian_pyur            : break; /* U+0583 ARMENIAN SMALL LETTER PIWR */
				case XK_Armenian_KE              : break; /* U+0554 ARMENIAN CAPITAL LETTER KEH */
				case XK_Armenian_ke              : break; /* U+0584 ARMENIAN SMALL LETTER KEH */
				case XK_Armenian_O               : break; /* U+0555 ARMENIAN CAPITAL LETTER OH */
				case XK_Armenian_o               : break; /* U+0585 ARMENIAN SMALL LETTER OH */
				case XK_Armenian_FE              : break; /* U+0556 ARMENIAN CAPITAL LETTER FEH */
				case XK_Armenian_fe              : break; /* U+0586 ARMENIAN SMALL LETTER FEH */
				case XK_Armenian_apostrophe      : break; /* U+055A ARMENIAN APOSTROPHE */
			#endif /* XK_ARMENIAN */
			#ifdef XK_GEORGIAN
				case XK_Georgian_an          : break; /* U+10D0 GEORGIAN LETTER AN */
				case XK_Georgian_ban         : break; /* U+10D1 GEORGIAN LETTER BAN */
				case XK_Georgian_gan         : break; /* U+10D2 GEORGIAN LETTER GAN */
				case XK_Georgian_don         : break; /* U+10D3 GEORGIAN LETTER DON */
				case XK_Georgian_en          : break; /* U+10D4 GEORGIAN LETTER EN */
				case XK_Georgian_vin         : break; /* U+10D5 GEORGIAN LETTER VIN */
				case XK_Georgian_zen         : break; /* U+10D6 GEORGIAN LETTER ZEN */
				case XK_Georgian_tan         : break; /* U+10D7 GEORGIAN LETTER TAN */
				case XK_Georgian_in          : break; /* U+10D8 GEORGIAN LETTER IN */
				case XK_Georgian_kan         : break; /* U+10D9 GEORGIAN LETTER KAN */
				case XK_Georgian_las         : break; /* U+10DA GEORGIAN LETTER LAS */
				case XK_Georgian_man         : break; /* U+10DB GEORGIAN LETTER MAN */
				case XK_Georgian_nar         : break; /* U+10DC GEORGIAN LETTER NAR */
				case XK_Georgian_on          : break; /* U+10DD GEORGIAN LETTER ON */
				case XK_Georgian_par         : break; /* U+10DE GEORGIAN LETTER PAR */
				case XK_Georgian_zhar        : break; /* U+10DF GEORGIAN LETTER ZHAR */
				case XK_Georgian_rae         : break; /* U+10E0 GEORGIAN LETTER RAE */
				case XK_Georgian_san         : break; /* U+10E1 GEORGIAN LETTER SAN */
				case XK_Georgian_tar         : break; /* U+10E2 GEORGIAN LETTER TAR */
				case XK_Georgian_un          : break; /* U+10E3 GEORGIAN LETTER UN */
				case XK_Georgian_phar        : break; /* U+10E4 GEORGIAN LETTER PHAR */
				case XK_Georgian_khar        : break; /* U+10E5 GEORGIAN LETTER KHAR */
				case XK_Georgian_ghan        : break; /* U+10E6 GEORGIAN LETTER GHAN */
				case XK_Georgian_qar         : break; /* U+10E7 GEORGIAN LETTER QAR */
				case XK_Georgian_shin        : break; /* U+10E8 GEORGIAN LETTER SHIN */
				case XK_Georgian_chin        : break; /* U+10E9 GEORGIAN LETTER CHIN */
				case XK_Georgian_can         : break; /* U+10EA GEORGIAN LETTER CAN */
				case XK_Georgian_jil         : break; /* U+10EB GEORGIAN LETTER JIL */
				case XK_Georgian_cil         : break; /* U+10EC GEORGIAN LETTER CIL */
				case XK_Georgian_char        : break; /* U+10ED GEORGIAN LETTER CHAR */
				case XK_Georgian_xan         : break; /* U+10EE GEORGIAN LETTER XAN */
				case XK_Georgian_jhan        : break; /* U+10EF GEORGIAN LETTER JHAN */
				case XK_Georgian_hae         : break; /* U+10F0 GEORGIAN LETTER HAE */
				case XK_Georgian_he          : break; /* U+10F1 GEORGIAN LETTER HE */
				case XK_Georgian_hie         : break; /* U+10F2 GEORGIAN LETTER HIE */
				case XK_Georgian_we          : break; /* U+10F3 GEORGIAN LETTER WE */
				case XK_Georgian_har         : break; /* U+10F4 GEORGIAN LETTER HAR */
				case XK_Georgian_hoe         : break; /* U+10F5 GEORGIAN LETTER HOE */
				case XK_Georgian_fi          : break; /* U+10F6 GEORGIAN LETTER FI */
			#endif /* XK_GEORGIAN */
			#ifdef XK_CAUCASUS
				case XK_Xabovedot           : break;/* U+1E8A LATIN CAPITAL LETTER X WITH DOT ABOVE */
				case XK_Ibreve              : break;/* U+012C LATIN CAPITAL LETTER I WITH BREVE */
				case XK_Zstroke             : break;/* U+01B5 LATIN CAPITAL LETTER Z WITH STROKE */
				case XK_Gcaron              : break;/* U+01E6 LATIN CAPITAL LETTER G WITH CARON */
				case XK_Ocaron              : break;/* U+01D2 LATIN CAPITAL LETTER O WITH CARON */
				case XK_Obarred             : break;/* U+019F LATIN CAPITAL LETTER O WITH MIDDLE TILDE */
				case XK_xabovedot           : break;/* U+1E8B LATIN SMALL LETTER X WITH DOT ABOVE */
				case XK_ibreve              : break;/* U+012D LATIN SMALL LETTER I WITH BREVE */
				case XK_zstroke             : break;/* U+01B6 LATIN SMALL LETTER Z WITH STROKE */
				case XK_gcaron              : break;/* U+01E7 LATIN SMALL LETTER G WITH CARON */
				case XK_ocaron              : break;/* U+01D2 LATIN SMALL LETTER O WITH CARON */
				case XK_obarred             : break;/* U+0275 LATIN SMALL LETTER BARRED O */
				case XK_SCHWA               : break;/* U+018F LATIN CAPITAL LETTER SCHWA */
				case XK_schwa               : break;/* U+0259 LATIN SMALL LETTER SCHWA */
				case XK_Lbelowdot           : break;/* U+1E36 LATIN CAPITAL LETTER L WITH DOT BELOW */
				case XK_lbelowdot           : break;/* U+1E37 LATIN SMALL LETTER L WITH DOT BELOW */
			#endif /* XK_CAUCASUS */
			#ifdef XK_VIETNAMESE
				case XK_Abelowdot             : break; /* U+1EA0 LATIN CAPITAL LETTER A WITH DOT BELOW */
				case XK_abelowdot             : break; /* U+1EA1 LATIN SMALL LETTER A WITH DOT BELOW */
				case XK_Ahook                 : break; /* U+1EA2 LATIN CAPITAL LETTER A WITH HOOK ABOVE */
				case XK_ahook                 : break; /* U+1EA3 LATIN SMALL LETTER A WITH HOOK ABOVE */
				case XK_Acircumflexacute      : break; /* U+1EA4 LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND ACUTE */
				case XK_acircumflexacute      : break; /* U+1EA5 LATIN SMALL LETTER A WITH CIRCUMFLEX AND ACUTE */
				case XK_Acircumflexgrave      : break; /* U+1EA6 LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND GRAVE */
				case XK_acircumflexgrave      : break; /* U+1EA7 LATIN SMALL LETTER A WITH CIRCUMFLEX AND GRAVE */
				case XK_Acircumflexhook       : break; /* U+1EA8 LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND HOOK ABOVE */
				case XK_acircumflexhook       : break; /* U+1EA9 LATIN SMALL LETTER A WITH CIRCUMFLEX AND HOOK ABOVE */
				case XK_Acircumflextilde      : break; /* U+1EAA LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND TILDE */
				case XK_acircumflextilde      : break; /* U+1EAB LATIN SMALL LETTER A WITH CIRCUMFLEX AND TILDE */
				case XK_Acircumflexbelowdot   : break; /* U+1EAC LATIN CAPITAL LETTER A WITH CIRCUMFLEX AND DOT BELOW */
				case XK_acircumflexbelowdot   : break; /* U+1EAD LATIN SMALL LETTER A WITH CIRCUMFLEX AND DOT BELOW */
				case XK_Abreveacute           : break; /* U+1EAE LATIN CAPITAL LETTER A WITH BREVE AND ACUTE */
				case XK_abreveacute           : break; /* U+1EAF LATIN SMALL LETTER A WITH BREVE AND ACUTE */
				case XK_Abrevegrave           : break; /* U+1EB0 LATIN CAPITAL LETTER A WITH BREVE AND GRAVE */
				case XK_abrevegrave           : break; /* U+1EB1 LATIN SMALL LETTER A WITH BREVE AND GRAVE */
				case XK_Abrevehook            : break; /* U+1EB2 LATIN CAPITAL LETTER A WITH BREVE AND HOOK ABOVE */
				case XK_abrevehook            : break; /* U+1EB3 LATIN SMALL LETTER A WITH BREVE AND HOOK ABOVE */
				case XK_Abrevetilde           : break; /* U+1EB4 LATIN CAPITAL LETTER A WITH BREVE AND TILDE */
				case XK_abrevetilde           : break; /* U+1EB5 LATIN SMALL LETTER A WITH BREVE AND TILDE */
				case XK_Abrevebelowdot        : break; /* U+1EB6 LATIN CAPITAL LETTER A WITH BREVE AND DOT BELOW */
				case XK_abrevebelowdot        : break; /* U+1EB7 LATIN SMALL LETTER A WITH BREVE AND DOT BELOW */
				case XK_Ebelowdot             : break; /* U+1EB8 LATIN CAPITAL LETTER E WITH DOT BELOW */
				case XK_ebelowdot             : break; /* U+1EB9 LATIN SMALL LETTER E WITH DOT BELOW */
				case XK_Ehook                 : break; /* U+1EBA LATIN CAPITAL LETTER E WITH HOOK ABOVE */
				case XK_ehook                 : break; /* U+1EBB LATIN SMALL LETTER E WITH HOOK ABOVE */
				case XK_Etilde                : break; /* U+1EBC LATIN CAPITAL LETTER E WITH TILDE */
				case XK_etilde                : break; /* U+1EBD LATIN SMALL LETTER E WITH TILDE */
				case XK_Ecircumflexacute      : break; /* U+1EBE LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND ACUTE */
				case XK_ecircumflexacute      : break; /* U+1EBF LATIN SMALL LETTER E WITH CIRCUMFLEX AND ACUTE */
				case XK_Ecircumflexgrave      : break; /* U+1EC0 LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND GRAVE */
				case XK_ecircumflexgrave      : break; /* U+1EC1 LATIN SMALL LETTER E WITH CIRCUMFLEX AND GRAVE */
				case XK_Ecircumflexhook       : break; /* U+1EC2 LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND HOOK ABOVE */
				case XK_ecircumflexhook       : break; /* U+1EC3 LATIN SMALL LETTER E WITH CIRCUMFLEX AND HOOK ABOVE */
				case XK_Ecircumflextilde      : break; /* U+1EC4 LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND TILDE */
				case XK_ecircumflextilde      : break; /* U+1EC5 LATIN SMALL LETTER E WITH CIRCUMFLEX AND TILDE */
				case XK_Ecircumflexbelowdot   : break; /* U+1EC6 LATIN CAPITAL LETTER E WITH CIRCUMFLEX AND DOT BELOW */
				case XK_ecircumflexbelowdot   : break; /* U+1EC7 LATIN SMALL LETTER E WITH CIRCUMFLEX AND DOT BELOW */
				case XK_Ihook                 : break; /* U+1EC8 LATIN CAPITAL LETTER I WITH HOOK ABOVE */
				case XK_ihook                 : break; /* U+1EC9 LATIN SMALL LETTER I WITH HOOK ABOVE */
				case XK_Ibelowdot             : break; /* U+1ECA LATIN CAPITAL LETTER I WITH DOT BELOW */
				case XK_ibelowdot             : break; /* U+1ECB LATIN SMALL LETTER I WITH DOT BELOW */
				case XK_Obelowdot             : break; /* U+1ECC LATIN CAPITAL LETTER O WITH DOT BELOW */
				case XK_obelowdot             : break; /* U+1ECD LATIN SMALL LETTER O WITH DOT BELOW */
				case XK_Ohook                 : break; /* U+1ECE LATIN CAPITAL LETTER O WITH HOOK ABOVE */
				case XK_ohook                 : break; /* U+1ECF LATIN SMALL LETTER O WITH HOOK ABOVE */
				case XK_Ocircumflexacute      : break; /* U+1ED0 LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND ACUTE */
				case XK_ocircumflexacute      : break; /* U+1ED1 LATIN SMALL LETTER O WITH CIRCUMFLEX AND ACUTE */
				case XK_Ocircumflexgrave      : break; /* U+1ED2 LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND GRAVE */
				case XK_ocircumflexgrave      : break; /* U+1ED3 LATIN SMALL LETTER O WITH CIRCUMFLEX AND GRAVE */
				case XK_Ocircumflexhook       : break; /* U+1ED4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE */
				case XK_ocircumflexhook       : break; /* U+1ED5 LATIN SMALL LETTER O WITH CIRCUMFLEX AND HOOK ABOVE */
				case XK_Ocircumflextilde      : break; /* U+1ED6 LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND TILDE */
				case XK_ocircumflextilde      : break; /* U+1ED7 LATIN SMALL LETTER O WITH CIRCUMFLEX AND TILDE */
				case XK_Ocircumflexbelowdot   : break; /* U+1ED8 LATIN CAPITAL LETTER O WITH CIRCUMFLEX AND DOT BELOW */
				case XK_ocircumflexbelowdot   : break; /* U+1ED9 LATIN SMALL LETTER O WITH CIRCUMFLEX AND DOT BELOW */
				case XK_Ohornacute            : break; /* U+1EDA LATIN CAPITAL LETTER O WITH HORN AND ACUTE */
				case XK_ohornacute            : break; /* U+1EDB LATIN SMALL LETTER O WITH HORN AND ACUTE */
				case XK_Ohorngrave            : break; /* U+1EDC LATIN CAPITAL LETTER O WITH HORN AND GRAVE */
				case XK_ohorngrave            : break; /* U+1EDD LATIN SMALL LETTER O WITH HORN AND GRAVE */
				case XK_Ohornhook             : break; /* U+1EDE LATIN CAPITAL LETTER O WITH HORN AND HOOK ABOVE */
				case XK_ohornhook             : break; /* U+1EDF LATIN SMALL LETTER O WITH HORN AND HOOK ABOVE */
				case XK_Ohorntilde            : break; /* U+1EE0 LATIN CAPITAL LETTER O WITH HORN AND TILDE */
				case XK_ohorntilde            : break; /* U+1EE1 LATIN SMALL LETTER O WITH HORN AND TILDE */
				case XK_Ohornbelowdot         : break; /* U+1EE2 LATIN CAPITAL LETTER O WITH HORN AND DOT BELOW */
				case XK_ohornbelowdot         : break; /* U+1EE3 LATIN SMALL LETTER O WITH HORN AND DOT BELOW */
				case XK_Ubelowdot             : break; /* U+1EE4 LATIN CAPITAL LETTER U WITH DOT BELOW */
				case XK_ubelowdot             : break; /* U+1EE5 LATIN SMALL LETTER U WITH DOT BELOW */
				case XK_Uhook                 : break; /* U+1EE6 LATIN CAPITAL LETTER U WITH HOOK ABOVE */
				case XK_uhook                 : break; /* U+1EE7 LATIN SMALL LETTER U WITH HOOK ABOVE */
				case XK_Uhornacute            : break; /* U+1EE8 LATIN CAPITAL LETTER U WITH HORN AND ACUTE */
				case XK_uhornacute            : break; /* U+1EE9 LATIN SMALL LETTER U WITH HORN AND ACUTE */
				case XK_Uhorngrave            : break; /* U+1EEA LATIN CAPITAL LETTER U WITH HORN AND GRAVE */
				case XK_uhorngrave            : break; /* U+1EEB LATIN SMALL LETTER U WITH HORN AND GRAVE */
				case XK_Uhornhook             : break; /* U+1EEC LATIN CAPITAL LETTER U WITH HORN AND HOOK ABOVE */
				case XK_uhornhook             : break; /* U+1EED LATIN SMALL LETTER U WITH HORN AND HOOK ABOVE */
				case XK_Uhorntilde            : break; /* U+1EEE LATIN CAPITAL LETTER U WITH HORN AND TILDE */
				case XK_uhorntilde            : break; /* U+1EEF LATIN SMALL LETTER U WITH HORN AND TILDE */
				case XK_Uhornbelowdot         : break; /* U+1EF0 LATIN CAPITAL LETTER U WITH HORN AND DOT BELOW */
				case XK_uhornbelowdot         : break; /* U+1EF1 LATIN SMALL LETTER U WITH HORN AND DOT BELOW */
				case XK_Ybelowdot             : break; /* U+1EF4 LATIN CAPITAL LETTER Y WITH DOT BELOW */
				case XK_ybelowdot             : break; /* U+1EF5 LATIN SMALL LETTER Y WITH DOT BELOW */
				case XK_Yhook                 : break; /* U+1EF6 LATIN CAPITAL LETTER Y WITH HOOK ABOVE */
				case XK_yhook                 : break; /* U+1EF7 LATIN SMALL LETTER Y WITH HOOK ABOVE */
				case XK_Ytilde                : break; /* U+1EF8 LATIN CAPITAL LETTER Y WITH TILDE */
				case XK_ytilde                : break; /* U+1EF9 LATIN SMALL LETTER Y WITH TILDE */
				case XK_Ohorn                 : break; /* U+01A0 LATIN CAPITAL LETTER O WITH HORN */
				case XK_ohorn                 : break; /* U+01A1 LATIN SMALL LETTER O WITH HORN */
				case XK_Uhorn                 : break; /* U+01AF LATIN CAPITAL LETTER U WITH HORN */
				case XK_uhorn                 : break; /* U+01B0 LATIN SMALL LETTER U WITH HORN */
			#endif /* XK_VIETNAMESE */
			#ifdef XK_CURRENCY
				case XK_EcuSign         : break; /* U+20A0 EURO-CURRENCY SIGN */
				case XK_ColonSign       : break; /* U+20A1 COLON SIGN */
				case XK_CruzeiroSign    : break; /* U+20A2 CRUZEIRO SIGN */
				case XK_FFrancSign      : break; /* U+20A3 FRENCH FRANC SIGN */
				case XK_LiraSign        : break; /* U+20A4 LIRA SIGN */
				case XK_MillSign        : break; /* U+20A5 MILL SIGN */
				case XK_NairaSign       : break; /* U+20A6 NAIRA SIGN */
				case XK_PesetaSign      : break; /* U+20A7 PESETA SIGN */
				case XK_RupeeSign       : break; /* U+20A8 RUPEE SIGN */
				case XK_WonSign         : break; /* U+20A9 WON SIGN */
				case XK_NewSheqelSign   : break; /* U+20AA NEW SHEQEL SIGN */
				case XK_DongSign        : break; /* U+20AB DONG SIGN */
				case XK_EuroSign        : break; /* U+20AC EURO SIGN */
			#endif /* XK_CURRENCY */
				default:
					key = Keyboard::Key::NONE;
					break;
				}
				return key;
			}

			auto Keyboard::getKeyCode(const Key code) -> unsigned int
			{
				unsigned int keycode = 0;
				switch (code) {
					case Key::NONE: break;
					case Key::BACKSPACE:
						keycode = XK_BackSpace;
						break;
					case Key::TAB:
						keycode = XK_Tab;
						break;
					case Key::RETURN:
						keycode = XK_Return;
						break;
					case Key::SHIFT:
						keycode = XK_Shift_L;
						break;
					case Key::CTRL:
						keycode = XK_Control_L;
						break;
					case Key::ALTGR:
						keycode = XK_Alt_L;
						break;
					case Key::PAUSE:
						keycode = XK_Pause;
						break;
					case Key::CAPS_LOCK:
						keycode = XK_Caps_Lock;
						break;
					case Key::ESCAPE:
						keycode = XK_Escape;
						break;
					case Key::SPACEBAR:
						keycode = XK_space;
						break;
					case Key::PAGE_UP:
						keycode = XK_Page_Up;
						break;
					case Key::PAGE_DOWN:
						keycode = XK_Page_Down;
						break;
					case Key::END:
						keycode = XK_End;
						break;
					case Key::HOME:
						keycode = XK_Home;
						break;
					case Key::LEFT:
						keycode = XK_Left;
						break;
					case Key::UP:
						keycode = XK_Up;
						break;
					case Key::RIGHT:
						keycode = XK_Right;
						break;
					case Key::DOWN:
						keycode = XK_Down;
						break;
					case Key::PRINT_SCREEN:
						keycode = XK_Print;
						break;
					case Key::INS:
						keycode = XK_Insert;
						break;
					case Key::DEL:
						keycode = XK_Delete;
						break;
					case Key::HELP:
						keycode = XK_Help;
						break;
					case Key::NUM_0:
						keycode = '0';
						break;
					case Key::NUM_1:
						keycode = '1';
						break;
					case Key::NUM_2:
						keycode = '2';
						break;
					case Key::NUM_3:
						keycode = '3';
						break;
					case Key::NUM_4:
						keycode = '4';
						break;
					case Key::NUM_5:
						keycode = '5';
						break;
					case Key::NUM_6:
						keycode = '6';
						break;
					case Key::NUM_7:
						keycode = '7';
						break;
					case Key::NUM_8:
						keycode = '8';
						break;
					case Key::NUM_9:
						keycode = '9';
						break;
					case Key::A:
						keycode = 'A';
						break;
					case Key::B:
						keycode = 'B';
						break;
					case Key::C:
						keycode = 'C';
						break;
					case Key::D:
						keycode = 'D';
						break;
					case Key::E:
						keycode = 'E';
						break;
					case Key::F:
						keycode = 'F';
						break;
					case Key::G:
						keycode = 'G';
						break;
					case Key::H:
						keycode = 'H';
						break;
					case Key::I:
						keycode = 'I';
						break;
					case Key::J:
						keycode = 'J';
						break;
					case Key::K:
						keycode = 'K';
						break;
					case Key::L:
						keycode = 'L';
						break;
					case Key::M:
						keycode = 'M';
						break;
					case Key::N:
						keycode = 'N';
						break;
					case Key::O:
						keycode = 'O';
						break;
					case Key::P:
						keycode = 'P';
						break;
					case Key::Q:
						keycode = 'Q';
						break;
					case Key::R:
						keycode = 'R';
						break;
					case Key::S:
						keycode = 'S';
						break;
					case Key::T:
						keycode = 'T';
						break;
					case Key::U:
						keycode = 'U';
						break;
					case Key::V:
						keycode = 'V';
						break;
					case Key::W:
						keycode = 'W';
						break;
					case Key::X:
						keycode = 'X';
						break;
					case Key::Y:
						keycode = 'Y';
						break;
					case Key::Z:
						keycode = 'Z';
						break;
					case Key::LEFT_COMMAND: break;
					case Key::RIGHT_COMMAND: break;
					case Key::APPLICATIONS: break;
					case Key::SLEEP: break;
					case Key::NUMPAD_0:
						keycode = XK_KP_0;
						break;
					case Key::NUMPAD_1:
						keycode = XK_KP_1;
						break;
					case Key::NUMPAD_2:
						keycode = XK_KP_2;
						break;
					case Key::NUMPAD_3:
						keycode = XK_KP_3;
						break;
					case Key::NUMPAD_4:
						keycode = XK_KP_4;
						break;
					case Key::NUMPAD_5:
						keycode = XK_KP_5;
						break;
					case Key::NUMPAD_6:
						keycode = XK_KP_6;
						break;
					case Key::NUMPAD_7:
						keycode = XK_KP_7;
						break;
					case Key::NUMPAD_8:
						keycode = XK_KP_8;
						break;
					case Key::NUMPAD_9:
						keycode = XK_KP_9;
						break;
					case Key::MULTIPLY:
						keycode = XK_KP_Multiply;
						break;
					case Key::ADD:
						keycode = XK_KP_Add;
						break;
					case Key::SUBSTRACT:
						keycode = XK_KP_Subtract;
						break;
					case Key::NUMPAD_DEL: break;
					case Key::DIVIDE:
						keycode = XK_KP_Divide;
						break;
					case Key::F1:
						keycode = XK_F1;
						break;
					case Key::F2:
						keycode = XK_F2;
						break;
					case Key::F3:
						keycode = XK_F3;
						break;
					case Key::F4:
						keycode = XK_F4;
						break;
					case Key::F5:
						keycode = XK_F5;
						break;
					case Key::F6:
						keycode = XK_F6;
						break;
					case Key::F7:
						keycode = XK_F7;
						break;
					case Key::F8:
						keycode = XK_F8;
						break;
					case Key::F9:
						keycode = XK_F9;
						break;
					case Key::F10:
						keycode = XK_F10;
						break;
					case Key::F11:
						keycode = XK_F11;
						break;
					case Key::F12:
						keycode = XK_F12;
						break;
					case Key::F13:
						keycode = XK_F13;
						break;
					case Key::F14:
						keycode = XK_F14;
						break;
					case Key::F15:
						keycode = XK_F15;
						break;
					case Key::F16:
						keycode = XK_F16;
						break;
					case Key::F17:
						keycode = XK_F17;
						break;
					case Key::F18:
						keycode = XK_F18;
						break;
					case Key::F19:
						keycode = XK_F19;
						break;
					case Key::F20:
						keycode = XK_F20;
						break;
					case Key::F21:
						keycode = XK_F21;
						break;
					case Key::F22:
						keycode = XK_F22;
						break;
					case Key::F23:
						keycode = XK_F23;
						break;
					case Key::F24:
						keycode = XK_F24;
						break;
					case Key::NUMLOCK:
						keycode = XK_Num_Lock;
						break;
					case Key::BROWSER_BACK: break;
					case Key::BROWSER_FORWARD: break;
					case Key::BROWSER_REFRESH: break;
					case Key::BROWSER_STOP: break;
					case Key::BROWSER_SEARCH: break;
					case Key::BROWSER_FAVORITES: break;
					case Key::BROWSER_HOME: break;
					case Key::VOLUME_MUTE: break;
					case Key::VOLUME_DOWN: break;
					case Key::VOLUME_UP: break;
					case Key::MEDIA_NEXT: break;
					case Key::MEDIA_PREVIOUS: break;
					case Key::MEDIA_STOP: break;
					case Key::MEDIA_PLAY: break;
					case Key::LAUNCH_MAIL: break;
					case Key::SELECT_MEDIA: break;
					case Key::APP_1: break;
					case Key::APP_2: break;
					case Key::OEM_1: break;
					case Key::OEM_2: break;
					case Key::OEM_3: break;
					case Key::OEM_4: break;
					case Key::OEM_5: break;
					case Key::OEM_6: break;
					case Key::OEM_7: break;
					case Key::OEM_8: break;
					case Key::OEM_102: break;
					case Key::OEM_PLUS: break;
					case Key::OEM_COMMA: break;
					case Key::OEM_MINUS: break;
					case Key::OEM_PERIOD: break;
				default:
					break;
				}
				return keycode;
			}
		} // namespace event
	} // namespace window
} // namespace ece
