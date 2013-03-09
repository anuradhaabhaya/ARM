CC=gcc
CFLAGS=-O3 -Ofast -m64 -mfpmath=sse -m128bit-long-double -msseregparm -march=native -flto -funroll-all-loops -Wall -g
EXEC_NAME=driver
OBJ_FILES=kernel.o driver.o

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC_NAME)
	
%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm -rf *.o $(EXEC_NAME);
