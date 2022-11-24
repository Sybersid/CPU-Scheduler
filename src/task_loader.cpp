#include <iostream>
#include <cstdio>
#include "../includes/task_list.h"

void task_loader(char* file_name, task task_array[], u_int &count) {

    FILE* fp;
    count = 0;

    if (!(fp = fopen(file_name, "r"))) {
        printf("File %s cannot be opened.\n", file_name);
    } else {
        while (fscanf(fp, "%u %u %u", &task_array[count].pid, 
        &task_array[count].arrival_time, &task_array[count].burst_time) != EOF) {
            count++;
        }
        
        printf("There are %u tasks loaded from %s. Press any key to continue ...\n", count, file_name);
        getchar();
        fclose(fp);
    }

}