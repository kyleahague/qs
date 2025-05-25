# QS — A C++ Quantum Engine

**Teleport quantum states. Parse OpenQASM. Export results. Track fidelity. All in raw C++.**

```
[QASM] Executing: h 0
[QASM] Executing: cx 0 1
[QASM] Executing: measure 0
[Qubit 0] Measured = 1

[Final State After Teleportation]
|001⟩ = (0.7071, 0.0000i)
|101⟩ = (0.7071, 0.0000i)

[Fidelity vs |+⟩ on qubit 2] = 1.0000
```

---

## Features
- Quantum teleportation (3-qubit system)
- Parses **OpenQASM 2.0** (hand-rolled parser)
- Per-qubit and full-system measurement collapse
- Export quantum state as **JSON** or **CSV**
- Run **shots** to track outcome statistics
- Calculate fidelity vs expected quantum states
- Clean C++20 / STL — no Python, no Qiskit

---

## Build

**Requirements:** CMake 3.14+, C++20+

```bash
git clone https://github.com/youruser/QBitCore.git
cd QBitCore && mkdir build && cd build
cmake ..
make
```

---

## Run

```bash
./QBitCore teleport.qasm
```

**Example `teleport.qasm`:**
```qasm
OPENQASM 2.0;
include "qelib1.inc";
qreg q[3];
creg c[2];
h q[0];
h q[1];
cx q[1], q[2];
cx q[0], q[1];
h q[0];
measure q[0] -> c[0];
measure q[1] -> c[1];
```

---

## Folder Structure
```
QBitCore/
├── include/        # QubitSystem, Types, Gates
├── src/            # Core logic
├── cli/            # (Optional) CLI entrypoint
├── gates/          # Demo QASM programs
├── CMakeLists.txt
```

---

## License

This project is **proprietary** and **not open source**.

All rights reserved © 2025 Kyle Hague.  
Do **not** copy, use, distribute, or fork without permission.

Contact for licensing: kyleahague@outlook.com
