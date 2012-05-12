all: todo

todo:
	@echo $(CC) -c operations.c;$(CC) -c operations.c
	@echo $(CC) -c defaultFunctions.c;$(CC) -c defaultFunctions.c
	@echo $(AR) libthings.a *.o; $(AR) -cvq libthings.a *.o
	@echo $(CC) $@;$(CC) $@.c -L. -lthings -o $@

clean:
	rm todo *.o *.a
