
## Image-Editor<br />

 A pgm image editor written in C language, using dynamic programming.

 The main options are to edit an image:
 
 >###### -> LOAD [name_image]<br />
 >###### -> SELECT [sizes]<br />
 >###### -> CROP<br />
 >###### -> ROTATE [angle]<br />
 >###### -> SAVE [file_name] (ASCII OR BINARY).<br />

Simple test:<br />
```
##  LOAD input/image.pgm<br />
##  SELECT 0 0 500 500<br />
##  CROP<br />
##  ROTATE 90<br />
##  SAVE new_image.pgm ASCII<br />
```
For download this project:
```
https://github.com/dinuionica/Image-Editor.git
```

On Linux:

```
$ make
```

