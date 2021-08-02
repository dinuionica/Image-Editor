/* Copyright 2020 Dinu Ion Irinel */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

#define LENGTH 20

int main(void) {
    image_t* image = malloc(sizeof(image_t));
    char* command = (char*)malloc(LENGTH * sizeof(char));
    char* argument = (char*)malloc(LENGTH * sizeof(char));

    while (fgets(command, LENGTH, stdin)) {
        /* delete last character */
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }
        /* parse commands */
        command = strtok(command, " ");
        if (strcmp(command, "EXIT") == 0) {
            exit_function(image);
            return 0;
        }
        else if (strcmp(command, "SAVE") == 0) {
            command = strtok(NULL, " ");
            argument = strtok(NULL, " ");

            if (argument == NULL) {
                save_bin_function(image, command);
            }
            else if (strcmp(argument, "ASCII") == 0) {
                save_asc_function(image, command);
            }
        }
        else if (strcmp(command, "LOAD") == 0) {
            argument = strtok(NULL, " ");
            load_function(image, argument);
        }
        else if (strcmp(command, "SELECT") == 0) {
            command = strtok(NULL, " ");

            if (strcmp(command, "ALL") == 0) {
                select_all_function(image);
            }
            else {
                int x1 = atoi(command);
                int y1 = atoi(strtok(NULL, " "));
                int x2 = atoi(strtok(NULL, " "));
                int y2 = atoi(strtok(NULL, " "));
                select_function(image, x1, y1, x2, y2);
            }
        }
        else if (strcmp(command, "CROP") == 0) {
            crop_function(image);
        }
        else if (strcmp(command, "ROTATE") == 0) {
            command = strtok(NULL, " ");
            rotate_function(image, command);
        }
        else {
            printf("Invalid Command\n");
            continue;
        }
    }

    free(command);
    free(argument);
    return 0;
}
