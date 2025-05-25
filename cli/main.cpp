#include "QubitSystem.hpp"
#include "Gates.hpp"
#include "Color.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

// Display program banner
void printBanner() {
    std::cout << "\n"
              << BOLD BLUE
              << " ===============================================\n"
              << "                Quantum Simulator               \n"
              << "               Built by Kyle Hague              \n"
              << " ===============================================\n"
              << RESET "\n";
}

// Show command-line usage instructions
void printUsage(const std::string& exe) {
    std::cout << BOLD BLUE << " Usage:\n" RESET
              << "  " << exe << " [program.qasm] [--json|--csv] [--shots N]\n\n"
              << BOLD BLUE << " Options:\n" RESET
              << "  --json     Export state to JSON after execution\n"
              << "  --csv      Export state to CSV after execution\n"
              << "  --shots N  Run N measurement shots (default: 1)\n\n";
}

int main(int argc, char* argv[]) {
    printBanner();

    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::string filename;
    bool exportJSON = false;
    bool exportCSV = false;
    size_t shots = 1;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--json") exportJSON = true;
        else if (arg == "--csv") exportCSV = true;
        else if (arg == "--shots" && i + 1 < argc) {
            shots = std::stoul(argv[++i]);
        }
        else if (arg.ends_with(".qasm")) {
            filename = arg;
        }
        else {
            std::cerr << BOLD RED << "ERROR: Unknown flag " << arg << "\n" << RESET;
            printUsage(argv[0]);
            return 1;
        }
    }

    if (filename.empty()) {
        std::cerr << BOLD RED << "Error: No QASM file provided.\n" << RESET;
        printUsage(argv[0]);
        return 1;
    }

    QubitSystem qs(3);
    std::cout << BOLD BLUE << "[qs]   Loading QASM program: " << BOLD YELLOW << filename << "\n" << RESET;
    qs.loadAndRunQASM(filename);

    if (shots > 1) {
        auto results = qs.runShots(shots);
        std::cout << BOLD BLUE << "[qs]   Shots: " << shots << "\n" << RESET;
        for (const auto& [bitstring, count] : results) {
            std::cout << BOLD BLUE << "[qs]   " << bitstring << " : " << count << "\n" << RESET;
        }
    }

    if (exportJSON) {
        qs.saveStateToFile("state.json", true);
        std::cout << BOLD BLUE << "[qs]   Exported to state.json\n" << RESET;
    }

    if (exportCSV) {
        qs.saveStateToFile("state.csv", false);
        std::cout << BOLD BLUE << "[qs]   Exported to state.csv\n" << RESET;
    }

    // Run teleport verification at the end (optional: only if --shots is not set?)
    if (shots == 1) {
        qs.verifyTeleportation(filename);
    }

    return 0;
}
