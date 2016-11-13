KVERS = $(shell uname -r)

obj-m += ch8/

all: build

build:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean


# clean:$(SUBDIR)
# $(SUBDIR):ECHO
#	make clean -C $@
# ECHO:
# 	@echo $(SUBDIR)
