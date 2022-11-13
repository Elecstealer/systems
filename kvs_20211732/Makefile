SRCS = static_main.c
LIBSRCS = open.c close.c put.c get.c seek.c
TARG = kvs_static

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a


SRCS_d = dynamic_main.c
LIBSRCS_d = open.c close.c put.c get.c seek.c
TARG_d = kvs_dynamic

OPTS_d = -fPIC
LIBS_d = -ldl

OBJS_d = $(SRCS_d:.c=.o)
LOBJS_d = $(LIBSRCS:.c=.o)
LARS_d = libkvs.so


static: $(TARG)

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) 

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) $(OPTS_d) -c $< -o $@

dynamic: $(TARG_d)

$(TARG_d) : $(OBJS_d) $(LARS_d)
	$(CC) -Wall -o $(TARG_d) $(OBJS_d) $(LIBS_d)

$(LARS_d) : $(LOBJS_d)
	$(CC) -shared -o $(LARS_d) $(LOBJS_d)

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG) $(OBJS_d) $(LOBJS_d) $(LARS_d) $(TARG_d)
