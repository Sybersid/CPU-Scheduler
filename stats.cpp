#include <iostream>
#include <vector>
#include "includes/task.h"

void stats(u_int &count, std::vector<task> &finish_array, u_int &wait_time) {
    float waiting_time, response_time, turnaround_time, cpu_usage = 0;

    int i;
    for (i=0; i<count; i++) {
        turnaround_time += finish_array[i].finish_time - finish_array[i].arrival_time;
        response_time += finish_array[i].start_time - finish_array[i].arrival_time;
        waiting_time += finish_array[i].finish_time - finish_array[i].arrival_time - finish_array[i].burst_time;
    }

    float avg_turnaround_time = turnaround_time / count;
    float avg_response_time = response_time / count;
    float avg_waiting_time = waiting_time / count;
    cpu_usage = 100 - wait_time;

    printf("Average waiting time:       %.2f\n", avg_waiting_time);
    printf("Average response time:      %.2f\n", avg_response_time);
    printf("Average turnaround time:    %.2f\n", avg_turnaround_time);
    printf("Overall CPU usage:          %.2f%\n", cpu_usage);
    printf("========================================================================================\n");

}