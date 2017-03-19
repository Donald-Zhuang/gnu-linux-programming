TARGET_FILE=file_operation
CC=gcc
MAIN=Main

all:lib$(TARGET_FILE).so  $(MAIN) clean

$(MAIN):$(MAIN).c
	$(CC) -Wl,--rpath=./ -L./ $^ -o $(MAIN) -l$(TARGET_FILE)
lib$(TARGET_FILE).so:$(TARGET_FILE).o
	$(CC) -shared $^ -o $@
$(TARGET_FILE).o:$(TARGET_FILE).c
	$(CC) -fPIC -c $^ -o $@
clean:
	rm -rf *.o
