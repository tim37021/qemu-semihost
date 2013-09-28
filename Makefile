all:
	@echo "Please execute ./run.sh"

clean:
	rm -f semihost.elf

distclean: clean
	rm -rf qemu/build
