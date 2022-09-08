src= $(wildcard *.c)
object= $(patsubst %.c, %.o, $(src))
target= libtest2.so
CC= gcc

$(target): $(object)
	$(CC) -shared -o $@ $^
	cp $@ /lib

%.o: %.c
	$(CC) -o $@ -c -fpic $<

.PHONY: clean
clean:
	-rm -f $(target) $(object)
	