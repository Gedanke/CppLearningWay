target= main
object= main.o fun1.o fun2.o sum.o
CC= gcc
CPPFLAGS= -I ./

$(target): $(object)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CPPFLAGS)
