PREFIX=/usr/local/bin
PROGNAME=whitespace
OBJECTS=main.o

all: $(PROGNAME)

debug: CFLAGS+=-g -O0 -v -Q
debug: $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

install: $(PROGNAME)
	install -m 0755 $(PROGNAME) $(PREFIX)/$(PROGNAME)

clean:
	rm -rf *.o
	rm -rf $(PROGNAME)
	rm -rf $(PROGNAME).exe
