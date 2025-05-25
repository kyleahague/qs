#include "Gates.hpp"
#include <cmath>

// Define Hadamard Gate Matrix (creates superposition)
Gates::GateMatrix Gates::hadamard() {
    double s = 1.0 / std::sqrt(2.0);  // 1/sqrt(2) ≈ 0.7071
    return {
        { Complex(s, 0), Complex(s, 0) },
        { Complex(s, 0), Complex(-s, 0) }
    };
}

// Define Pauli-X Gate Matrix (bit-flip gate)
Gates::GateMatrix Gates::pauliX() {
    return {
        { Complex(0, 0), Complex(1, 0) },
        { Complex(1, 0), Complex(0, 0) }
    };
}

// Define Pauli-Z Gate Matrix (phase-flip gate)
Gates::GateMatrix Gates::pauliZ() {
    return {
        { Complex(1, 0), Complex(0, 0) },
        { Complex(0, 0), Complex(-1, 0) }
    };
}
