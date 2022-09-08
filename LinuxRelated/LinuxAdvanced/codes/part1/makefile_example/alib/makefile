src= $(wildcard *.c)
CC= gcc
object=$(patsubst %.c, %.o, $(src))
target= libtest1.a

$(target): $(object)
	ar rcs $@ $^

%.o: %.c
	$(CC) -o $@ -c $<

.PHONY: clean
clean:
	-rm -f $(target) $(object)
