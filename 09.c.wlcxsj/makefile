CC = gcc
AR = $(CC)ar
EXEC = kfd
OBJS = kfd.o
all: $(EXEC)
$(EXEC): $(OBJS)
	$(cc) -o $@ $(OBJS) -lm
clean:
	-rm -f $(EXEC) *.elf *.gdb *.o

