#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include "../includes/inputs.h"
#include "../includes/task.h"
#include "../includes/scheduler.h"

int main(int argc, char* argv[]) {
    
    policy_type policy;
    file_name = argv[1];
    policy = NONE;

    std::array<task,MAX_TASK_NUM> task_array;
    std::vector<task> finish_array;
    std::vector<task> task_list;
    u_int count, wait_time = 0;
    std::queue<task> ready_queue;

    
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

        int j = 0;
        while (j<count) {
                    task_list.push_back(task_array[j]);
                    j++;
                }

        switch (policy) {
            case FCFS:
                fcfs_policy(task_list, count, finish_array, wait_time);
                break;
            case SRTF:
                
                break;
            case RR:
                
                break;
            default:
                break;
        };
        
        stats(count, finish_array, wait_time);
    
}