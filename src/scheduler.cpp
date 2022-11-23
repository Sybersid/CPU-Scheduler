#include <iostream>

std::string file_name;
int time_quantum;

enum policy_type {
    FCFS,
    SRTF,
    RR
};
policy_type policy;

int main(int argc, char* argv[]) {

    if (argc == 1 || argc > 4) {
        std::cout << "Usage: scheduler file_name [FCFS|SRTF|RR] [time_quantum]\n";
    } else if (argc == 2) {
        std::cout << "Error: Input policy.\n";
    } else {
        std::string policy_input = argv[2];

        if (policy_input == "FCFS") {
            if (argc == 3) {
                policy = FCFS;
                std::cout << "Scheduling Policy: " << policy_input << "\n";
                } else {
                    std::cout << "Error: No time_quantum.\n";
                    }

            } else if (policy_input == "SRTF") {
                if (argc == 3) {
                    policy = SRTF;
                    std::cout << "Scheduling Policy: " << policy_input << "\n";
                    } else {
                        std::cout << "Error: No time_quantum.\n";
                        }

            } else if (policy_input == "RR") {
                if (argc == 4) {
                    time_quantum = (int)(*argv[3]-'0');
                    policy = RR;
                    std::cout << "Scheduling Policy: " << policy_input << "\n";
                    } else if (argc != 4) {
                        std::cout << "Error: Input time_quantum.\n";
                        }

            } else {
                std::cout << "Error: Invalid policy must be [FCFS|SRTF|RR]\n";
            }
    
        file_name = argv[1]; 


        }
}