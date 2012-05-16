all: todo

todo:
	@echo $(CC) -c operations.c;$(CC) -c operations.c
	@echo $(CC) -c defaultFunctions.c;$(CC) -c defaultFunctions.c
	@echo $(AR) libthings.a *.o; $(AR) -cvq libthings.a *.o
	@echo $(CC) $@;$(CC) $@.c -L. -lthings -o $@

xmltest:
	 gcc xmltest.c -I/usr/include/libxml2/ -lxml2 -o xmltest

clean:
	rm todo xmltest *.o *.a
