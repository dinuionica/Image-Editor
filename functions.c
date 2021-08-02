/* Copyright 2020 Dinu Ion Irinel */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

/* the function that alloc a matrix with height and width */
int** alloc_matrix(int n, int m) {
    
    /* matrix allocation */
    int** matrix = malloc(n * sizeof(int*));
    if (matrix == NULL) {
        free(matrix);
        return NULL;
    }
    /* memory allocation for each item */
    for (int i = 0; i < n; ++i) {
        matrix[i] = malloc(m * sizeof(int));
    }
    return matrix;
}

/* the function that load a new  image */
void load_function(image_t* image, char* file_name) {
   
    /* memory allocation for image-type */
    image->type = malloc(SIZE * sizeof(char*));
    if (image->type == NULL) {
        free(image->type);
        return;
    }
    /* read image from a text file*/
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Failed to load %s\n", file_name);
        return;
    }
    else {
        printf("Loaded %s\n", file_name);
        fscanf(file, "%s", image->type);
        /* check the image type and call the function needed */
        if (strcmp(image->type, "P2") == 0) {
            load_pgm_asc(image, file_name);
        }
        else if (strcmp(image->type, "P5") == 0) {
            load_pgm_bin(image, file_name);
        }
    }
    fclose(file);
}

/* the function that load a pgm image in ascii format */
void load_pgm_asc(image_t* image, char* file_name) {
    
    /* memory allocation for image-type */
    image->type = malloc(SIZE * sizeof(char*)); 
    /* read image from a text file */
    FILE* file = fopen(file_name, "r");
    fscanf(file, "%s%d%d%d\n", image->type, &image->width, &image->height,
        &image->max_value);
    image->values = (int**)alloc_matrix(image->height, image->width);

    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            fscanf(file, "%d", &image->values[i][j]);
        }
    }
    fclose(file);
}

/* the function that load a pgm image in binary format */
void load_pgm_bin(image_t* image, char* file_name) {   
    /* memory allocation for image-type */
    image->type = (char*)malloc(SIZE * sizeof(char));
    /* read image from a text file */
    FILE* file = fopen(file_name, "rb");
    fscanf(file, "%s%d%d%d\n", image->type, &image->width, &image->height,
        &image->max_value);
    image->values = (int**)alloc_matrix(image->height, image->width);

    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            image->values[i][j] = fgetc(file);
        }
    }
    fclose(file);
}

/* the function that save an image with binary format */
void save_bin_function(image_t* image, char* file_name) {
    if (image->width == 0) {
        printf("No image loaded\n");
        return;
    }
    else {
        /* save image with informations and binary format in text file */
        FILE* file_save = fopen(file_name, "wb");
        if (strcmp(image->type, "P2") == 0 || strcmp(image->type, "P5") == 0) {
            fprintf(file_save, "P5\n");
            fprintf(file_save, "%d ", image->width);
            fprintf(file_save, "%d\n", image->height);
            fprintf(file_save, "%d\n", image->max_value);

            for (int i = 0; i < image->height; ++i) {
                for (int j = 0; j < image->width; ++j) {
                    fputc(image->values[i][j], file_save);
                }
            }
            printf("Saved %s\n", file_name);
        }
        fclose(file_save);
    }
}

// function to save an image with ascii format
void save_asc_function(image_t* image, char* file_name) {
    if (image->width == 0) {
        printf("No image loaded\n");
        return;
    }
    else {
        /* save image with informations and ascii format in text file */
        FILE* file_save = fopen(file_name, "w");
        if (strcmp(image->type, "P2") == 0 || strcmp(image->type, "P5") == 0) {
            fprintf(file_save, "P2\n");
            fprintf(file_save, "%d ", image->width);
            fprintf(file_save, "%d\n", image->height);
            fprintf(file_save, "%d\n", image->max_value);

            for (int i = 0; i < image->height; ++i) {
                for (int j = 0; j < image->width; ++j) {
                    fprintf(file_save, "%d ", image->values[i][j]);
                }
                fprintf(file_save, "\n");
            }
            printf("Saved %s\n", file_name);
        }
        fclose(file_save);
    }
}

/* the function that select all coordonates of an image */
void select_all(image_t* image) {
    image->x1 = 0;
    image->y1 = 0;
    image->x2 = image->width;
    image->y2 = image->height;
}
/* the function that select all size of the image */
void select_all_function(image_t* image) {
    if (image->width == 0) {
        printf("No image loaded\n");
        return;
    }
    else {
        select_all(image);
        printf("Selected All\n");
    }
}

/* function to select size of the image */
void select_function(image_t* image, int x1, int y1, int x2, int y2) {
    if (image->width == 0) {
        printf("No image loaded\n");
        return;
    }

    if (x2 < x1) {
        swap(&x1, &x2);
    }

    if (y2 < y1) {
        swap(&y1, &y2);
    }

    if (x1 < 0 || x2 > image->width || y1 < 0 || y2 > image->height) {
        printf("Invalid set of coordinates\n");
        return;
    }
    else {
        image->x1 = x1;
        image->y1 = y1;
        image->x2 = x2;
        image->y2 = y2;
        printf("Selected %d %d %d %d\n", x1, y1, x2, y2);
    }
}

/* the function that crop an image */
void crop_function(image_t* image) {
    if (image->width == 0) {
        printf("No image loaded\n");
        return;
    }
    else {
        /* determinate new dimensions of the image */
        image->width = image->x2 - image->x1;
        image->height = image->y2 - image->y1;

        for (int i = 0; i < image->x2 - image->x1; ++i) {
            for (int j = 0; j < image->height; ++j) {
                image->values[i][j] = image->values[i + image->x1][j];
            }
        }
        for (int i = 0; i < image->x2 - image->x1; ++i) {
            for (int j = 0; j < image->y2 - image->y1; ++j) {
                image->values[i][j] = image->values[i][j + image->y1];
            }
        }
        printf("Image cropped\n");
        select_all(image);
    }
}

/* the function that exit the program */
void exit_function(image_t* image) {
    /* free all memory allocated */
    free(image->type);
    for (int i = 0; i < image->height; ++i) {
        free(image->values[i]);
    }
    free(image->values);
}

/* the function that swap two numbers */
void swap(int* number1, int* number2) {
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

/* the function that free matrix of values */
void free_mat(image_t* image)
{
    for (int i = 0; i < image->width; ++i) {
        free(image->values[i]);
    }
    free(image->values);
}

/* functions to rotate an image */
void rotate_function(image_t* image, char* reg) {
    if (image->width == 0) {
        printf("No image loaded\n");
        return;
    }
    /* rotate image by angle */
    if (image->x1 == 0 && image->x2 == image->width && image->y1 == 0 && image->y2 && image->height) {
        if (strcmp(reg, "-270") == 0) {
            rotate_all_right(image);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "-180") == 0) {
            rotate_all_left(image);
            rotate_all_left(image);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "-90") == 0) {
            rotate_all_left(image);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "90") == 0) {
            rotate_all_right(image);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "180") == 0) {
            rotate_all_right(image);
            rotate_all_right(image);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "270") == 0) {
            rotate_all_left(image);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "360") == 0 || strcmp(reg, "-360") == 0 || strcmp(reg, "0") == 0) {
            printf("Rotated %s\n", reg);
        }
        else {
            printf("Unsupported rotation angle\n");
        }
    }
    else if (image->x2 - image->x1 == image->y2 - image->y1) {
        if (strcmp(reg, "-270") == 0) {
            rotate_right(image->values, image->x2 - image->x1);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "-180") == 0) {
            rotate_left(image->values, image->x2 - image->x1);
            rotate_left(image->values, image->x2 - image->x1);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "-90") == 0) {
            rotate_left(image->values, image->x2 - image->x1);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "90") == 0) {
            rotate_right(image->values, image->x2 - image->x1);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "180") == 0) {
            rotate_right(image->values, image->x2 - image->x1);
            rotate_right(image->values, image->x2 - image->x1);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "270") == 0) {
            rotate_left(image->values, image->x2 - image->x1);
            printf("Rotated %s\n", reg);
        }
        else if (strcmp(reg, "360") == 0 || strcmp(reg, "-360") == 0 || strcmp(reg, "0") == 0) {
            printf("Rotated %s\n", reg);
        }
        else {
            printf("Unsupported rotation angle\n");
        }
    }
    else {
        printf("The selection must be square\n");
        return;
    }
}

/* the function that rotate an image to right */
void rotate_right(int** mat, int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(&mat[i][j], &mat[j][i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N / 2; j++)
            swap(&mat[i][j], &mat[i][N - j - 1]);
}

/* the function that rotate an image to left */
void rotate_left(int** mat, int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            swap(&mat[i][j], &mat[j][i]);

    for (int i = 0; i < N / 2; i++)
        for (int j = 0; j < N; j++)
            swap(&mat[i][j], &mat[N - i - 1][j]);
}

void rotate_all_right(image_t* image) {
    int** mat = malloc(image->height * sizeof(int*));

    for (int i = 0; i < image->height; i++) {
        mat[i] = malloc(image->width * sizeof(int));
    }

    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            mat[j][i] = image->values[i][j];
        }
    }

    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width / 2; ++j) {
            swap(&mat[i][j], &mat[i][image->width - j - 1]);
        }
    }

    free_mat(image);
    image->values = mat;
    swap(&image->width, &image->height);
}

void rotate_all_left(image_t* image) {
    int** mat = malloc(image->height * sizeof(int*));

    for (int i = 0; i < image->height; i++) {
        mat[i] = malloc(image->width * sizeof(int));
    }
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            mat[j][i] = image->values[i][j];
        }
    }

    for (int i = 0; i < image->height / 2; ++i) {
        for (int j = 0; j < image->width; ++j) {
            swap(&mat[i][j], &mat[image->height - i - 1][j]);
        }
    }

    free_mat(image);
    image->values = mat;
    swap(&image->width, &image->height);
}
