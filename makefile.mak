


myProg.o: assembler.o baseChange.o firstPass.o functns.o linkedList.o secondPass.o header.h
    gcc -Wall -ansi -pedantic makefile assembler.o baseChange.o firstPass.o functns.o linkedList.o secondPass.o

assembler.o: myText.c myText.h
    gcc -Wall -ansi -pedantic myText.c

functns.o: functns.c myText.h
    gcc -Wall -ansi -pedantic func.c
	
baseChange.o: baseChange.c header.h
	gcc -Wall -ansi -pedantic baseChange.c
	
firstPass.o: firstPass.c header.h
	gcc -Wall -ansi -pedantic firstPass.c

linkedList.o: linkedList.c header.h
	gcc -Wall -ansi -pedantic linkedList.c

secondPass.o: secondPass.c header.h
	gcc -Wall -ansi -pedantic secondPass.c

