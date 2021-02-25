
**IMAGE EDITOR**<br />
  A pgm image editor written in C language, using dynamic programming.

 The main options are to edit an image:
 >###### ->LOAD name_image<br />
 >###### ->SELECT sizes<br />
 >###### ->CROP<br />
 >###### ->ROTATE angle<br />
 >###### ->SAVE file_name (ASCII OR BINARY).<br />

SIMPLE TEST:<br />
```
##  LOAD input/image.pgm<br />
##  SELECT 0 0 500 500<br />
##  CROP<br />
##  ROTATE 90<br />
##  SAVE new_image.pgm ASCII<br />
```
To test this project:
```
https://github.com/dinuionica/Password-Manager.git
```

On Linux:

```
$ make
```

