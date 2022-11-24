#include <iostream>
#include "../includes/inputs.h"
#include "../includes/task_list.h"
#include "../includes/scheduler.h"

int main(int argc, char* argv[]) {
    
    policy_type policy;
    file_name = argv[1];
    policy = NONE;

    static const int MAX_TASK_NUM = 32;
    task task_array[MAX_TASK_NUM];
    u_int count = 0;
    
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
                task_loader(file_name, task_array, count);
                } else {
                    std::cout << "Error: No time_quantum for FCFS.\n";
                    }

            } else if (policy_input == "SRTF") {
                if (argc == 3) {
                    policy = SRTF;
                    std::cout << "Scheduling Policy: " << policy_input << "\n";
                    task_loader(file_name, task_array, count);
                    } else {
                        std::cout << "Error: No time_quantum for SRTF.\n";
                        }

            } else if (policy_input == "RR") {
                if (argc == 4) {
                    time_quantum = (u_int)(*argv[3]-'0');
                    policy = RR;
                    std::cout << "Scheduling Policy: " << policy_input << "\n";
                    task_loader(file_name, task_array, count);
                    } else if (argc != 4) {
                        std::cout << "Error: Input time_quantum for RR.\n";
                        }

            } else {
                std::cout << "Error: Invalid policy must be [FCFS|SRTF|RR]\n";
            }

        }

        switch (policy) {
            case FCFS:
                std::cout << "FCFS\n";
                break;
            case SRTF:
                std::cout << "SRTF\n";
                break;
            case RR:
                std::cout << "RR\n";
                break;
            default:
                break;
        };
    
}