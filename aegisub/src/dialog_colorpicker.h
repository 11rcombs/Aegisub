// Copyright (c) 2012, Thomas Goyne <plorkyeran@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// Aegisub Project http://www.aegisub.org/

/// @file dialog_colorpicker.h
/// @see dialog_colorpicker.cpp
/// @ingroup tools_ui
///

#include <functional>

#include <libaegisub/color.h>

class wxWindow;

/// @brief Get a color from the user via a color picker dialog
/// @param parent Parent window
/// @param original Initial color to select
/// @param alpha Include controls for alpha
/// @param callback Function called whenever the selected color changes
/// @return Did the user accept the new color?
bool GetColorFromUser(wxWindow* parent, agi::Color original, bool alpha, std::function<void (agi::Color)> callback);
