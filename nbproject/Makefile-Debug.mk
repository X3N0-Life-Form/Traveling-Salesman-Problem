#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/code/core/City.o \
	${OBJECTDIR}/code/core/Problem.o \
	${OBJECTDIR}/code/main.o \
	${OBJECTDIR}/code/neighborhood/Neighborhood.o \
	${OBJECTDIR}/code/parse/tspParser.o \
	${OBJECTDIR}/code/relation/Relation.o \
	${OBJECTDIR}/code/relation/Swap.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f3

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/traveling_salesman_problem

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/traveling_salesman_problem: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/traveling_salesman_problem ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/code/core/City.o: code/core/City.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/City.o code/core/City.cpp

${OBJECTDIR}/code/core/Problem.o: code/core/Problem.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/Problem.o code/core/Problem.cpp

${OBJECTDIR}/code/main.o: code/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/main.o code/main.cpp

${OBJECTDIR}/code/neighborhood/Neighborhood.o: code/neighborhood/Neighborhood.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/neighborhood
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/neighborhood/Neighborhood.o code/neighborhood/Neighborhood.cpp

${OBJECTDIR}/code/parse/tspParser.o: code/parse/tspParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/parse
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/parse/tspParser.o code/parse/tspParser.cpp

${OBJECTDIR}/code/relation/Relation.o: code/relation/Relation.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Relation.o code/relation/Relation.cpp

${OBJECTDIR}/code/relation/Swap.o: code/relation/Swap.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Swap.o code/relation/Swap.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/neighborhoodTests.o ${TESTDIR}/tests/newtestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newtestrunner.o ${TESTDIR}/tests/tspParserTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/newtestrunner2.o ${TESTDIR}/tests/problemTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/neighborhoodTests.o: tests/neighborhoodTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/neighborhoodTests.o tests/neighborhoodTests.cpp


${TESTDIR}/tests/newtestrunner1.o: tests/newtestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner1.o tests/newtestrunner1.cpp


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${TESTDIR}/tests/tspParserTests.o: tests/tspParserTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/tspParserTests.o tests/tspParserTests.cpp


${TESTDIR}/tests/newtestrunner2.o: tests/newtestrunner2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner2.o tests/newtestrunner2.cpp


${TESTDIR}/tests/problemTests.o: tests/problemTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/problemTests.o tests/problemTests.cpp


${OBJECTDIR}/code/core/City_nomain.o: ${OBJECTDIR}/code/core/City.o code/core/City.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/core/City.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/City_nomain.o code/core/City.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/core/City.o ${OBJECTDIR}/code/core/City_nomain.o;\
	fi

${OBJECTDIR}/code/core/Problem_nomain.o: ${OBJECTDIR}/code/core/Problem.o code/core/Problem.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/core/Problem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/Problem_nomain.o code/core/Problem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/core/Problem.o ${OBJECTDIR}/code/core/Problem_nomain.o;\
	fi

${OBJECTDIR}/code/main_nomain.o: ${OBJECTDIR}/code/main.o code/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/main_nomain.o code/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/main.o ${OBJECTDIR}/code/main_nomain.o;\
	fi

${OBJECTDIR}/code/neighborhood/Neighborhood_nomain.o: ${OBJECTDIR}/code/neighborhood/Neighborhood.o code/neighborhood/Neighborhood.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/neighborhood
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/neighborhood/Neighborhood.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/neighborhood/Neighborhood_nomain.o code/neighborhood/Neighborhood.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/neighborhood/Neighborhood.o ${OBJECTDIR}/code/neighborhood/Neighborhood_nomain.o;\
	fi

${OBJECTDIR}/code/parse/tspParser_nomain.o: ${OBJECTDIR}/code/parse/tspParser.o code/parse/tspParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/parse
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/parse/tspParser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/parse/tspParser_nomain.o code/parse/tspParser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/parse/tspParser.o ${OBJECTDIR}/code/parse/tspParser_nomain.o;\
	fi

${OBJECTDIR}/code/relation/Relation_nomain.o: ${OBJECTDIR}/code/relation/Relation.o code/relation/Relation.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/relation/Relation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Relation_nomain.o code/relation/Relation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/relation/Relation.o ${OBJECTDIR}/code/relation/Relation_nomain.o;\
	fi

${OBJECTDIR}/code/relation/Swap_nomain.o: ${OBJECTDIR}/code/relation/Swap.o code/relation/Swap.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/relation/Swap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Swap_nomain.o code/relation/Swap.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/relation/Swap.o ${OBJECTDIR}/code/relation/Swap_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/traveling_salesman_problem

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
