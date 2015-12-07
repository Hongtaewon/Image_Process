DIRS = lib include apps
CLEAN_DIRS = lib apps
.PHONY: all clean

all:
	@for d in $(DIRS);\
	do\
		$(MAKE) -C $$d;\
	done

clean:
	@for d in $(CLEAN_DIRS);\
	do\
		$(MAKE) -C $$d clean;\
	done
