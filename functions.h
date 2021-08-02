#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* struct of an image */
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


int **alloc_matrix(int n, int m);

void load_function(image_t *image, char *file_name);

void load_pgm_asc(image_t *image, char *file_name);

void load_pgm_bin(image_t *image, char *file_name);

void save_bin_function(image_t *image, char *file_name);

void save_asc_function(image_t *image, char *file_name);

void select_all (image_t *image);

void select_all_function(image_t *image);

void select_function(image_t *image, int x1, int y1, int x2, int y2);

void swap(int *number1, int *number2);

void crop_function(image_t *image);

void rotate_function(image_t *image, char *reg);

void rotate_right(int **mat, int N);

void rotate_left(int **mat, int N);

void rotate_all_left(image_t *image);

void rotate_all_right(image_t *image);

void exit_function(image_t *image);

#endif
