CC=icc
CFLAGS=-O3 -xhost -axsse4.2 -opt-prefetch -ipo -funroll-loops -Wall -g
EXEC_NAME=driver
OBJ_FILES=kernel.o driver.o

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC_NAME)
	
%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm -rf *.o $(EXEC_NAME);
