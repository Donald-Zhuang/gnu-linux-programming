all:libdemo.so dynamic_lib clean

dynamic_lib:dynamic_lib_without_dl.c
	gcc -o $@ $^ -Wl,--rpath=. -L. -ldemo 
	chmod 777 $@
libdemo.so:max.c add.c
	gcc -shared -fPIC $^ -o libdemo.so
clean:
	rm -rf *.o 
