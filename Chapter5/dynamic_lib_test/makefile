all:libdemo.so dynamic_lib clean

dynamic_lib:dynamic_lib.c
	gcc -Wl,--no-as-needed -rdynamic -ldl $^ -o $@
	chmod 777 $@
libdemo.so:add.o max.o
	gcc -shared $^ -o $@
add.o:add.c
	gcc -fPIC -c $^ -o $@
max.0:max.c
	gcc -fPIC -c $^ -o $@

clean:
	rm -rf *.o 
