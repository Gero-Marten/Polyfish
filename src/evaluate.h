/*
  Polyfish, a UCI chess playing engine derived from Stockfish
  Copyright (C) 2022-2023 The Polyfish developers (see AUTHORS file)

  Polyfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Polyfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVALUATE_H_INCLUDED
#define EVALUATE_H_INCLUDED

#include <string>
#include <optional>

#include "types.h"

namespace Polyfish {

class Position;

namespace Eval {

  std::string trace(Position& pos);
  Value evaluate(const Position& pos);

  extern std::string currentEvalFileName;

  // The default net name MUST follow the format nn-[SHA256 first 12 digits].nnue
  // for the build process (profile-build and fishtest) to work. Do not change the
  // name of the macro, as it is used in the Makefile.
  #define EvalFileDefaultName   "nn-c38c3d8d3920.nnue"

  namespace NNUE {

    void init();
    void verify();

  } // namespace NNUE

} // namespace Eval

} // namespace Polyfish

#endif // #ifndef EVALUATE_H_INCLUDED
