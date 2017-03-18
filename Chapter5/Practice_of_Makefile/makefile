main:main.c libtest.a
	gcc main.c -o main -L. -ltest -static 
libtest.a:add.o max.o test.h
	ar -cru libtest.a $^
add.o:add.c
	$(CC) -c $< -o $@ 
max.o:max.c
