
build:
	
	clang -o passgen passwordgenerator.c

clean:
	rm passgen

deb:
	dpkg-deb --build --root-owner-group debianrel
	mv debianrel.deb passgen.deb


all: 
	make clean
	make build
