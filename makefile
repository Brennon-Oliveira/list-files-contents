CC=gcc
CFLAGS=-I.
FILENAME=lfc

listfiles: $(FILENAME).c
	$(CC) -o $(FILENAME) $(FILENAME).c $(CFLAGS)
	sudo cp $(FILENAME) /bin/$(FILENAME)
	rm -f $(FILENAME)

run: $(FILENAME)
	$(CC) -o $(FILENAME) $(FILENAME).c $(CFLAGS)
	./$(FILENAME)

clean:
	rm -f $(FILENAME)