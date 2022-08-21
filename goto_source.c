/*
df.shape() function for c csv_db

GGAshbrook 2022.08.21

"Copyright [year] <Copyright Owner>"  [legal/copyright]"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100

int main(int argc, char **argv) {
      ////////////
     // variables
    /////////////

    // file path to (and name of) csv file, input as argument
    char *path;
    FILE* file_pointer;
    int read_to_this_row_new_lines;
    int read_to_this_column_commas;
    int total_character_step_count = 0;
    int total_cell_count = 1;

      ///////////////////////////
     // Check and Set Variables
    ///////////////////////////

    // check length of input
    if ( argc != 4 ) {
        // Error message in English
        printf("incorrect number of input arguments: ");
        printf("After NAME.exe -> enter: 1. FILE_NAME.csv");
        printf("2. target row (int), 3. Target colum (int)");

        return EXIT_FAILURE;
        }

    // first input is the file path (including file name)
    path = argv[1];

    // second input is the target row
    // pseudocode: read_to_this_row_new_lines = argv[2];
    sscanf(argv[2], "%d", &read_to_this_row_new_lines);

    // third input is the target column
    // pseudocode: read_to_this_column_commas = argv[3];
    sscanf(argv[3], "%d", &read_to_this_column_commas);

    // Character counter (result)
    int column_comma_counter = 0, row_newline_counter = 0;

    char filename[MAX_FILE_NAME];

    // To store a character read from file
    char c;

      ///////////////////////
     // Open and Check File
    ///////////////////////

    // Open file (use the file name given in first input)
    file_pointer = fopen(path, "r");

    // if there is no file, exit to an error message
    if (!file_pointer) {
        // Error message in English
        printf("specify your file: e.g. ./dfhead.exe YOUR_FILE_NAME");

        // return machine error message
        perror(path);

        // fully exit probram
        return EXIT_FAILURE;
        }

    // Extract characters from file
    // and store in character c
    for (c = getc(file_pointer); c != EOF; c = getc(file_pointer)) {
        // if at end of file  -> exit loop
        if ( c == EOF )
            break;

        // if you are at your destination -> exit loop
        if ((row_newline_counter == read_to_this_row_new_lines) &
        (column_comma_counter == read_to_this_column_commas)) {
          break;
        }

        // Count total read steps through file
        // To get to the target_iloc destination
        total_character_step_count++;


        // count columns (commas)
        if ( c == ',' ) {
            column_comma_counter++;

            // add to cell counter
            total_cell_count++;
        }

        // count rows (new lines)
        if ( c == '\n' ) {
            row_newline_counter++;

            // And reset the comma counter to zero
            column_comma_counter = 0;
        }



        // End For Loop
        }

    // Close the file
    fclose(file_pointer);

    printf("\nFile = %s",
    path);

    printf("\nArrived @ index location = (%d,%d) (row, column)",
    row_newline_counter,
    column_comma_counter);

    printf("\nCells-Along starting at One = %d, File_Steps = %d",
    total_cell_count, total_character_step_count);

    return total_character_step_count;
}
