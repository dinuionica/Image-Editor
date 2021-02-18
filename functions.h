#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//struct of an image
typedef struct {
    
    char *type;
    int width;
    int height;
    int max_value;
    int x1;
    int x2;
    int y1;
    int y2;
    int **values;

} image_t;

extern image_t image;

//function to alloc a matrix of n X m

int **alloc_matrix(int n, int m);

//function to load an image

void load_function(image_t *image, char *file_name);

//function to load a pgm image in ascii format

void load_pgm_asc(image_t *image, char *file_name);

//function to load a pgm image in binary format

void load_pgm_bin(image_t *image, char *file_name);

//function to save an image with binary format

void save_bin_function(image_t *image, char *file_name);

//function to save an image with ascii format

void save_asc_function(image_t *image, char *file_name);

//function to select_all_coordonates

void select_all (image_t *image);

//function to select all_size of image

void select_all_function(image_t *image);

//function to select size of image

void select_function(image_t *image, int x1, int y1, int x2, int y2);

//swap two integers

void swap(int *number1, int *number2);

//function to crop an image

void crop_function(image_t *image);

//functions to rotate an image 

void rotate_function(image_t *image, char *reg);

void rotate_right(int **mat, int N);

void rotate_left(int **mat, int N);

void rotate_all_left(image_t *image);

void rotate_all_right(image_t *image);

//function to exit the program

void exit_function(image_t *image);

#endif