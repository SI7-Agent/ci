CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJ := get_matrix.o operations.o print_matrix.o process.o errors.o

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

app.exe: main.o $(OBJ)
	$(CC) $(CFLAGS) -o app.exe main.o $(OBJ)
	
test.exe: test.o $(OBJ)
	$(CC) $(CFLAGS) -o test.exe test.o $(OBJ)
	
clean:
	del *.o *.gch *.exe