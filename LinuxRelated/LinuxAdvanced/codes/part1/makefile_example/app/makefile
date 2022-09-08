src= $(wildcard *.c)
object= $(patsubst %.c, %.o, $(src))
target= main
CC= gcc

# 使用静态库
# $(target): $(object)
# 	$(CC) -o $@ $^ -L ../alib -l test1

# 使用动态库
$(target): $(object)
	$(CC) -o $@ $^ -L ../slib -l test2

%.o: %.c
	$(CC) -o $@ -c $< -I ../include

.PHONY: clean
clean:
	-rm -f $(target) $(object)
