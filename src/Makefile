OBJS=operations.o defaultFunctions.o

all: todo

todo: $(OBJ)
todo: libthings.a
	@echo $(CC) $@.c
	@$(CC) $@.c -L. -lthings -o $@

todo.exe: CC=i486-mingw32-gcc
todo.exe: AR=i486-mingw32-ar
todo.exe: libthings.a
	@echo $(CC) $(basename $@).c
	@$(CC) $(basename $@).c -L. -lthings -o $@

libthings.a: $(OBJS)
	@echo $(AR) libthings.a $(OBJS)
	@$(AR) -cvq libthings.a $(OBJS)

%.o: %.c
	@echo $(CC) -c $*.c
	@$(CC) -c $*.c

xmltest:
	$(CC) xmltest.c -I/usr/include/libxml2/ -lxml2 -o xmltest

clean: cleanlib cleanbin

cleanbin:
	@echo "cleaning binaries..."
	@rm -f todo todo.exe

cleanlib:
	@echo "cleaning objects..."
	@rm -f xmltest *.o *.a

.PHONY: clean cleanlib cleanbin libthings.a
