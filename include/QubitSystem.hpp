#include "Types.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <string>

// Define QubitSystem
class QubitSystem {
public:

    // Constructor: initializes to |0...0⟩
    explicit QubitSystem(size_t numQubits);

    // Apply single-qubit gate (Hadamard, Pauli, etc.)
    void applyGate(const std::vector<std::vector<Complex>>& gate, size_t target);
    
    // Apply CNOT gate using given control and target qubits
    void applyCNOT(size_t control, size_t target);
    
    // Collapse full quantum state and return one outcome (basis index)
    size_t measure();
    
    // Collapse a single qubit in superposition, preserve rest of state
    size_t measureQubit(size_t qubitIndex);

    // Measure all qubits and return result as a bitstring
    std::string measureAll();

    // Return last measurement results of qubit 0
    int getLastMeasuredQubit0() const { return lastMeasuredQubit0; }
    
    // Return last measurement results of qubit 1
    int getLastMeasuredQubit1() const { return lastMeasuredQubit1; }

    // Run multiple shots and track measurement distribution
    std::map<std::string, int> runShots(size_t shots);

    // Print quantum state amplitudes to stdout
    void printState() const;

    // Export current state to JSON format
    std::string exportStateJSON() const;

    // Export current state to CSV format
    std::string exportStateCSV() const;

    // Save quantum state to file as JSON or CSV
    void saveStateToFile(const std::string& filename, bool json) const;

    // Parse QASM lines into simplified intermediate format
    std::string parseQASMLine(const std::string& line);
    
    // Run parsed QASM instruction
    void executeInstruction(const std::string& line);
    
    // Load QASM file and simulate line-by-line
    void loadAndRunQASM(const std::string& filename);

    // Teleportation helper for verifying QASM teleport circuit
    void verifyTeleportation(const std::string& filename);
    
    // Compare one qubit's state to an expected pure state
    double fidelityWith(const std::vector<Complex>& expected, size_t qubitIndex) const;

    // Approximate the reduced state of a single qubit
    std::vector<Complex> getQubitState(size_t index) const;

    private:
    // Number of qubits in the system. Determines the size of the state vector (2^nQubits).
    size_t nQubits;

    // Full quantum state vector of size 2^nQubits. Each element is a complex amplitude for a basis state.
    std::vector<Complex> state;

    // Placeholder for classical register values (e.g., from 'creg'), not yet actively used in simulation.
    std::vector<int> classicalBits;

    // Stores the last measurement result of qubit 0 (0 or 1). Initialized to -1 for "unset."
    int lastMeasuredQubit0 = -1;

    // Stores the last measurement result of qubit 1 (0 or 1). Initialized to -1 for "unset."
    int lastMeasuredQubit1 = -1;
};
