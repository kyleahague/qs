OPENQASM 2.0;
include "qelib1.inc";

qreg q[3];
creg c[2];

// DEBUG PRINT

// Prepare |+⟩ in qubit 0 (this is the state to teleport)
h q[0];

// Entangle qubit 1 and 2
h q[1];
cx q[1], q[2];

// Bell state interaction between 0 and 1
cx q[0], q[1];
h q[0];

// Measure qubits 0 and 1
measure q[0] -> c[0];
measure q[1] -> c[1];
