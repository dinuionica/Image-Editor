build:image_editor.c functions.c functions.h
	gcc image_editor.c functions.c -o image_editor && ./image_editor 

clean:
	rm image_editor