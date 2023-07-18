
OBJETIVE = glsq.h

build:
	cat src/LinkedList.h src/*.h > $(OBJETIVE).tmp
	cat README.txt $(OBJETIVE).tmp > $(OBJETIVE)
	rm $(OBJETIVE).tmp
