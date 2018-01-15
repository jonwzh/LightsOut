CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = a4q2b
OBJECTS = main.o cell.o grid.o info.o observer.o subject.o subscriptions.o textdisplay.o window.o graphicsdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 -L/usr/X11/lib -I/usr/X11/include

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

