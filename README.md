
## Image-Editor<br />

 A pgm image editor written in C language, using dynamic programming.

 The main options are to edit an image:
 ```
 LOAD [name_image]<br />
 SELECT [sizes]<br />
 CROP<br />
 ROTATE [angle]<br />
 SAVE [file_name] (ASCII OR BINARY).<br />
 ```

Simple test:<br />
```
LOAD input/image.pgm
SELECT 0 0 500 500
CROP
ROTATE 90
SAVE new_image.pgm ASCII
```
For download this project:
```
https://github.com/dinuionica/Image-Editor.git
```

On Linux:

```
$ make
```

