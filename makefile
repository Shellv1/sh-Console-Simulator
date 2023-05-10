CC=gcc
CFLAGS=-Wall
DEPS=main.h
TARGET=proj3
OBJS=main.o input.o shellFunc.o listPID.o

%.o: %.c $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET).exe
	$(MAKE) clean
  
clean:
	rm -f *.o