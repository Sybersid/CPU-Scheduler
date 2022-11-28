#include <iostream>
#include <cstdio>
#include <array>
#include "../includes/task.h"

void task_loader(char* file_name, std::array<task,MAX_TASK_NUM> &task_array, u_int &count) {

    FILE* fp;
    count = 0;

    if (!(fp = fopen(file_name, "r"))) {
        printf("File %s cannot be opened.\n", file_name);
    } else {
        while (fscanf(fp, "%u %u %u", &task_array[count].pid, 
        &task_array[count].arrival_time, &task_array[count].burst_time) != EOF) {
            count++;
        }
        int i;
        for (i=0; i<count; i++) {
            task_array[i].start_time = -1;
            task_array[i].finish_time = -1;
            task_array[i].remaining_time = -1;
        }
        
        printf("There are %u tasks loaded from %s. Press any key to continue ...", count, file_name);
        getchar();
        fclose(fp);
        printf("========================================================================================\n");
    }

}