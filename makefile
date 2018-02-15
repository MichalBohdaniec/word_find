find:
	cl /c find.c 
	link find.obj scantext.lib

test1:
	find fr -i test1.txt -o 

test2:
	find is -i test2.txt -o

test3:
	find are -i test3.txt -o

clean:
	del *.obj
	del *.exe

