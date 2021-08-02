
## Image-Editor<br />
This project is an image editor, which allows you to edit images using a series of commands.
The project was made using the C programming language, the whole program being based on the 
dynamic allocation of memory.

For download this project:
```
https://github.com/dinuionica/Image-Editor.git
```

On Linux:

```
$ make
```

The main options are to edit an image:
 ```
 LOAD [name_image]
 SELECT [sizes]
 CROP
 ROTATE [angle]
 SAVE [file_name] (ASCII OR BINARY)
 ```

Simple test:<br />
```
LOAD input/image.pgm
SELECT 0 0 500 500
CROP
ROTATE 90
SAVE new_image.pgm ASCII
```

