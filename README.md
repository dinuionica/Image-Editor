
---------**IMAGE EDITOR**-------------

A pgm image editor written in C language, using dynamic programming.

The main options are to edit an image:
> LOAD name_image
> SELECT sizes
> CROP
> ROTATE angle
> SAVE file_name (ASCII OR BINARY).

SIMPLE TEST:
LOAD input/image.pgm
SELECT 0 0 500 500
CROP
ROTATE 90
SAVE new_image.pgm ASCII
