rootPath = ..
include ${rootPath}/include.mk

libSources = impl/*.c
libHeaders = inc/*.h
libTests = tests/adjacencySequencesTest.c tests/allTests.c tests/endAlignerTest.c tests/flowerAlignerTest.c tests/rescueTest.c tests/poaBarTest.c
libRunEndAlignment = tests/runEndAlignment.c

commonBarLibs = ${LIBDIR}/stCaf.a ${sonLibDir}/stPinchesAndCacti.a ${LIBDIR}/cactusLib.a ${sonLibDir}/3EdgeConnected.a ${sonLibDir}/cPecanLib.a
stBarDependencies =  ${commonBarLibs} ${LIBDEPENDS}
LDLIBS += ${commonBarLibs} ${sonLibDir}/sonLib.a ${databaseLibs} -lm

all: all_libs all_progs
all_libs: ${LIBDIR}/cactusBarLib.a
all_progs: all_libs
	${MAKE} ${BINDIR}/cactus_barTests

clean : 
	rm -f ${BINDIR}/cactus_barTests  ${LIBDIR}/cactusBarLib.a *.o

${BINDIR}/cactus_barTests : ${libTests} tests/*.h ${LIBDIR}/cactusBarLib.a ${stBarDependencies}
	${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} -Wno-error -o ${BINDIR}/cactus_barTests ${libTests} ${LIBDIR}/cactusBarLib.a ${LDLIBS}

${LIBDIR}/cactusBarLib.a : ${libSources} ${libHeaders} ${stBarDependencies}
	${CC} ${CPPFLAGS} ${CFLAGS} -c ${libSources} 
	${AR} rc cactusBarLib.a *.o
	${RANLIB} cactusBarLib.a 
	mv cactusBarLib.a ${LIBDIR}/
