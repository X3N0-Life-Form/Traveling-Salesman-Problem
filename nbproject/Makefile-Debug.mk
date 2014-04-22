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
	${OBJECTDIR}/code/core/problem.o \
	${OBJECTDIR}/code/main.o \
	${OBJECTDIR}/code/parse/tspParser.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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

${OBJECTDIR}/code/core/problem.o: code/core/problem.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/problem.o code/core/problem.cpp

${OBJECTDIR}/code/main.o: code/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/main.o code/main.cpp

${OBJECTDIR}/code/parse/tspParser.o: code/parse/tspParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/parse
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/parse/tspParser.o code/parse/tspParser.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newtestrunner.o ${TESTDIR}/tests/tspParserTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${TESTDIR}/tests/tspParserTests.o: tests/tspParserTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/tspParserTests.o tests/tspParserTests.cpp


${OBJECTDIR}/code/core/problem_nomain.o: ${OBJECTDIR}/code/core/problem.o code/core/problem.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/core/problem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/problem_nomain.o code/core/problem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/core/problem.o ${OBJECTDIR}/code/core/problem_nomain.o;\
	fi

${OBJECTDIR}/code/main_nomain.o: ${OBJECTDIR}/code/main.o code/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/main_nomain.o code/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/main.o ${OBJECTDIR}/code/main_nomain.o;\
	fi

${OBJECTDIR}/code/parse/tspParser_nomain.o: ${OBJECTDIR}/code/parse/tspParser.o code/parse/tspParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/parse
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/parse/tspParser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/parse/tspParser_nomain.o code/parse/tspParser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/parse/tspParser.o ${OBJECTDIR}/code/parse/tspParser_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
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
