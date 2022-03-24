a.out : backtracking.o check_col_row.o main.o
	gcc -o a.out backtracking.o check_col_row.o main.o

backtracking.o : backtracking.c
	gcc -c -o backtracking.o backtracking.c

check_col_row.o : check_col_row.c
	gcc -c -o check_col_row.o check_col_row.c

main.o : main.c
	gcc -c -o main.o main.c

clean:
	rm *.o a.out