all:helloworld clean
helloworld:helloworld.o
	ld $^ -o $@
	chmod 777 $@
helloworld.o:helloworld.s
	as $^ -o $@
clean:
	rm -rf *.o
