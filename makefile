
build: gstructs.h gcapture.h
	echo done

gstructs.h:
	cat structs/header.txt structs/LinkedList.h structs/*.c > gstructs.h

gcapture.h:
	cat capture/header.txt capture/strGet.h capture/*.c > gcapture.h

clean:
	rm gcapture.h gstructs.h