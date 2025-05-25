#pragma once

#include "Types.hpp"
#include <vector>

namespace Gates {
    using GateMatrix = std::vector<std::vector<Complex>>;

    GateMatrix hadamard();
    GateMatrix pauliX();
    GateMatrix pauliZ();
    
}
