// Copyright (c) 2006, Rodrigo Braz Monteiro
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of the Aegisub Group nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Aegisub Project http://www.aegisub.org/

/// @file spellchecker.cpp
/// @brief Implementatin of base-class for spell checkers
/// @ingroup spelling
///

#include "config.h"

#include "include/aegisub/spellchecker.h"
#include "spellchecker_hunspell.h"

#include "options.h"

#include <libaegisub/spellchecker.h>

std::unique_ptr<agi::SpellChecker> SpellCheckerFactory::GetSpellChecker() {
	std::vector<std::string> list = GetClasses(OPT_GET("Tool/Spell Checker/Backend")->GetString());
	if (list.empty()) return nullptr;

	std::string error;
	for (auto const& name : list) {
		try {
			auto checker = Create(name);
			if (checker) return checker;
		}
		catch (...) { error += name + " factory: Unknown error\n"; }
	}

	throw error;
}

void SpellCheckerFactory::RegisterProviders() {
#ifdef WITH_HUNSPELL
	Register<HunspellSpellChecker>("Hunspell");
#endif
}
