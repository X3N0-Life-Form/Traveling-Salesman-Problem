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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/code/choice/ChoiceMaker.o \
	${OBJECTDIR}/code/core/City.o \
	${OBJECTDIR}/code/core/Neighborhood.o \
	${OBJECTDIR}/code/core/Problem.o \
	${OBJECTDIR}/code/hook/Hook.o \
	${OBJECTDIR}/code/hook/Hookable.o \
	${OBJECTDIR}/code/hook/RelationChoiceHook.o \
	${OBJECTDIR}/code/main.o \
	${OBJECTDIR}/code/parse/tspParser.o \
	${OBJECTDIR}/code/relation/Insert.o \
	${OBJECTDIR}/code/relation/Relation.o \
	${OBJECTDIR}/code/relation/Reverse.o \
	${OBJECTDIR}/code/relation/Swap.o \
	${OBJECTDIR}/code/run/RunData.o \
	${OBJECTDIR}/code/run/Runner.o \
	${OBJECTDIR}/code/run/interval/Action.o \
	${OBJECTDIR}/code/run/interval/Interval.o \
	${OBJECTDIR}/code/run/interval/IntervalManager.o \
	${OBJECTDIR}/code/strategy/BestFit.o \
	${OBJECTDIR}/code/strategy/FirstFit.o \
	${OBJECTDIR}/code/strategy/Strategy.o \
	${OBJECTDIR}/code/strategy/WorstFit.o \
	${OBJECTDIR}/code/utils.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f13 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f14 \
	${TESTDIR}/TestFiles/f12 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f11 \
	${TESTDIR}/TestFiles/f7

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

${OBJECTDIR}/code/choice/ChoiceMaker.o: code/choice/ChoiceMaker.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/choice
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/choice/ChoiceMaker.o code/choice/ChoiceMaker.cpp

${OBJECTDIR}/code/core/City.o: code/core/City.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/City.o code/core/City.cpp

${OBJECTDIR}/code/core/Neighborhood.o: code/core/Neighborhood.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/Neighborhood.o code/core/Neighborhood.cpp

${OBJECTDIR}/code/core/Problem.o: code/core/Problem.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/Problem.o code/core/Problem.cpp

${OBJECTDIR}/code/hook/Hook.o: code/hook/Hook.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/hook
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/hook/Hook.o code/hook/Hook.cpp

${OBJECTDIR}/code/hook/Hookable.o: code/hook/Hookable.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/hook
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/hook/Hookable.o code/hook/Hookable.cpp

${OBJECTDIR}/code/hook/RelationChoiceHook.o: code/hook/RelationChoiceHook.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/hook
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/hook/RelationChoiceHook.o code/hook/RelationChoiceHook.cpp

${OBJECTDIR}/code/main.o: code/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/main.o code/main.cpp

${OBJECTDIR}/code/parse/tspParser.o: code/parse/tspParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/parse
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/parse/tspParser.o code/parse/tspParser.cpp

${OBJECTDIR}/code/relation/Insert.o: code/relation/Insert.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Insert.o code/relation/Insert.cpp

${OBJECTDIR}/code/relation/Relation.o: code/relation/Relation.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Relation.o code/relation/Relation.cpp

${OBJECTDIR}/code/relation/Reverse.o: code/relation/Reverse.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Reverse.o code/relation/Reverse.cpp

${OBJECTDIR}/code/relation/Swap.o: code/relation/Swap.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Swap.o code/relation/Swap.cpp

${OBJECTDIR}/code/run/RunData.o: code/run/RunData.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/RunData.o code/run/RunData.cpp

${OBJECTDIR}/code/run/Runner.o: code/run/Runner.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/Runner.o code/run/Runner.cpp

${OBJECTDIR}/code/run/interval/Action.o: code/run/interval/Action.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run/interval
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/interval/Action.o code/run/interval/Action.cpp

${OBJECTDIR}/code/run/interval/Interval.o: code/run/interval/Interval.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run/interval
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/interval/Interval.o code/run/interval/Interval.cpp

${OBJECTDIR}/code/run/interval/IntervalManager.o: code/run/interval/IntervalManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run/interval
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/interval/IntervalManager.o code/run/interval/IntervalManager.cpp

${OBJECTDIR}/code/strategy/BestFit.o: code/strategy/BestFit.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/BestFit.o code/strategy/BestFit.cpp

${OBJECTDIR}/code/strategy/FirstFit.o: code/strategy/FirstFit.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/FirstFit.o code/strategy/FirstFit.cpp

${OBJECTDIR}/code/strategy/Strategy.o: code/strategy/Strategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/Strategy.o code/strategy/Strategy.cpp

${OBJECTDIR}/code/strategy/WorstFit.o: code/strategy/WorstFit.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/WorstFit.o code/strategy/WorstFit.cpp

${OBJECTDIR}/code/utils.o: code/utils.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/utils.o code/utils.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/strategy_tests/bestFitTests.o ${TESTDIR}/tests/strategy_tests/bestFitTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/strategy_tests/firstFitTests.o ${TESTDIR}/tests/strategy_tests/firstFitTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f10: ${TESTDIR}/tests/relation_tests/InsertTests.o ${TESTDIR}/tests/relation_tests/InsertTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f13: ${TESTDIR}/tests/run_tests/interval_tests/IntervalManagerTests.o ${TESTDIR}/tests/run_tests/interval_tests/intervalManagerTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f13 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/mainTests.o ${TESTDIR}/tests/mainTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/core_parsing_tests/neighborhoodTests.o ${TESTDIR}/tests/core_parsing_tests/neighborhoodTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/core_parsing_tests/tspParserTests.o ${TESTDIR}/tests/core_parsing_tests/tspTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/core_parsing_tests/problemTests.o ${TESTDIR}/tests/core_parsing_tests/problemTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f14: ${TESTDIR}/tests/relation_tests/RelationTests.o ${TESTDIR}/tests/relation_tests/RelationTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f14 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f12: ${TESTDIR}/tests/relation_tests/ReverseTests.o ${TESTDIR}/tests/relation_tests/ReverseTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f12 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/run_tests/runnerTests.o ${TESTDIR}/tests/run_tests/runnerTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/relation_tests/swapTests.o ${TESTDIR}/tests/relation_tests/swapTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f11: ${TESTDIR}/tests/utilsTests.o ${TESTDIR}/tests/utilsTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f11 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/strategy_tests/worstFitTests.o ${TESTDIR}/tests/strategy_tests/worstFitTests_testrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/strategy_tests/bestFitTests.o: tests/strategy_tests/bestFitTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/strategy_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/strategy_tests/bestFitTests.o tests/strategy_tests/bestFitTests.cpp


${TESTDIR}/tests/strategy_tests/bestFitTests_testrunner.o: tests/strategy_tests/bestFitTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/strategy_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/strategy_tests/bestFitTests_testrunner.o tests/strategy_tests/bestFitTests_testrunner.cpp


${TESTDIR}/tests/strategy_tests/firstFitTests.o: tests/strategy_tests/firstFitTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/strategy_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/strategy_tests/firstFitTests.o tests/strategy_tests/firstFitTests.cpp


${TESTDIR}/tests/strategy_tests/firstFitTests_testrunner.o: tests/strategy_tests/firstFitTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/strategy_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/strategy_tests/firstFitTests_testrunner.o tests/strategy_tests/firstFitTests_testrunner.cpp


${TESTDIR}/tests/relation_tests/InsertTests.o: tests/relation_tests/InsertTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/InsertTests.o tests/relation_tests/InsertTests.cpp


${TESTDIR}/tests/relation_tests/InsertTests_testrunner.o: tests/relation_tests/InsertTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/InsertTests_testrunner.o tests/relation_tests/InsertTests_testrunner.cpp


${TESTDIR}/tests/run_tests/interval_tests/IntervalManagerTests.o: tests/run_tests/interval_tests/IntervalManagerTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/run_tests/interval_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/run_tests/interval_tests/IntervalManagerTests.o tests/run_tests/interval_tests/IntervalManagerTests.cpp


${TESTDIR}/tests/run_tests/interval_tests/intervalManagerTests_testrunner.o: tests/run_tests/interval_tests/intervalManagerTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/run_tests/interval_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/run_tests/interval_tests/intervalManagerTests_testrunner.o tests/run_tests/interval_tests/intervalManagerTests_testrunner.cpp


${TESTDIR}/tests/mainTests.o: tests/mainTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainTests.o tests/mainTests.cpp


${TESTDIR}/tests/mainTests_testrunner.o: tests/mainTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainTests_testrunner.o tests/mainTests_testrunner.cpp


${TESTDIR}/tests/core_parsing_tests/neighborhoodTests.o: tests/core_parsing_tests/neighborhoodTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/core_parsing_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/core_parsing_tests/neighborhoodTests.o tests/core_parsing_tests/neighborhoodTests.cpp


${TESTDIR}/tests/core_parsing_tests/neighborhoodTests_testrunner.o: tests/core_parsing_tests/neighborhoodTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/core_parsing_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/core_parsing_tests/neighborhoodTests_testrunner.o tests/core_parsing_tests/neighborhoodTests_testrunner.cpp


${TESTDIR}/tests/core_parsing_tests/tspParserTests.o: tests/core_parsing_tests/tspParserTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/core_parsing_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/core_parsing_tests/tspParserTests.o tests/core_parsing_tests/tspParserTests.cpp


${TESTDIR}/tests/core_parsing_tests/tspTests_testrunner.o: tests/core_parsing_tests/tspTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/core_parsing_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/core_parsing_tests/tspTests_testrunner.o tests/core_parsing_tests/tspTests_testrunner.cpp


${TESTDIR}/tests/core_parsing_tests/problemTests.o: tests/core_parsing_tests/problemTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/core_parsing_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/core_parsing_tests/problemTests.o tests/core_parsing_tests/problemTests.cpp


${TESTDIR}/tests/core_parsing_tests/problemTests_testrunner.o: tests/core_parsing_tests/problemTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/core_parsing_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/core_parsing_tests/problemTests_testrunner.o tests/core_parsing_tests/problemTests_testrunner.cpp


${TESTDIR}/tests/relation_tests/RelationTests.o: tests/relation_tests/RelationTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/RelationTests.o tests/relation_tests/RelationTests.cpp


${TESTDIR}/tests/relation_tests/RelationTests_testrunner.o: tests/relation_tests/RelationTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/RelationTests_testrunner.o tests/relation_tests/RelationTests_testrunner.cpp


${TESTDIR}/tests/relation_tests/ReverseTests.o: tests/relation_tests/ReverseTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/ReverseTests.o tests/relation_tests/ReverseTests.cpp


${TESTDIR}/tests/relation_tests/ReverseTests_testrunner.o: tests/relation_tests/ReverseTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/ReverseTests_testrunner.o tests/relation_tests/ReverseTests_testrunner.cpp


${TESTDIR}/tests/run_tests/runnerTests.o: tests/run_tests/runnerTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/run_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/run_tests/runnerTests.o tests/run_tests/runnerTests.cpp


${TESTDIR}/tests/run_tests/runnerTests_testrunner.o: tests/run_tests/runnerTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/run_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/run_tests/runnerTests_testrunner.o tests/run_tests/runnerTests_testrunner.cpp


${TESTDIR}/tests/relation_tests/swapTests.o: tests/relation_tests/swapTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/swapTests.o tests/relation_tests/swapTests.cpp


${TESTDIR}/tests/relation_tests/swapTests_testrunner.o: tests/relation_tests/swapTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/relation_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/relation_tests/swapTests_testrunner.o tests/relation_tests/swapTests_testrunner.cpp


${TESTDIR}/tests/utilsTests.o: tests/utilsTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/utilsTests.o tests/utilsTests.cpp


${TESTDIR}/tests/utilsTests_testrunner.o: tests/utilsTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/utilsTests_testrunner.o tests/utilsTests_testrunner.cpp


${TESTDIR}/tests/strategy_tests/worstFitTests.o: tests/strategy_tests/worstFitTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests/strategy_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/strategy_tests/worstFitTests.o tests/strategy_tests/worstFitTests.cpp


${TESTDIR}/tests/strategy_tests/worstFitTests_testrunner.o: tests/strategy_tests/worstFitTests_testrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests/strategy_tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/strategy_tests/worstFitTests_testrunner.o tests/strategy_tests/worstFitTests_testrunner.cpp


${OBJECTDIR}/code/choice/ChoiceMaker_nomain.o: ${OBJECTDIR}/code/choice/ChoiceMaker.o code/choice/ChoiceMaker.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/choice
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/choice/ChoiceMaker.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/choice/ChoiceMaker_nomain.o code/choice/ChoiceMaker.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/choice/ChoiceMaker.o ${OBJECTDIR}/code/choice/ChoiceMaker_nomain.o;\
	fi

${OBJECTDIR}/code/core/City_nomain.o: ${OBJECTDIR}/code/core/City.o code/core/City.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/core/City.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/City_nomain.o code/core/City.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/core/City.o ${OBJECTDIR}/code/core/City_nomain.o;\
	fi

${OBJECTDIR}/code/core/Neighborhood_nomain.o: ${OBJECTDIR}/code/core/Neighborhood.o code/core/Neighborhood.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/core/Neighborhood.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/Neighborhood_nomain.o code/core/Neighborhood.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/core/Neighborhood.o ${OBJECTDIR}/code/core/Neighborhood_nomain.o;\
	fi

${OBJECTDIR}/code/core/Problem_nomain.o: ${OBJECTDIR}/code/core/Problem.o code/core/Problem.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/core
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/core/Problem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/core/Problem_nomain.o code/core/Problem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/core/Problem.o ${OBJECTDIR}/code/core/Problem_nomain.o;\
	fi

${OBJECTDIR}/code/hook/Hook_nomain.o: ${OBJECTDIR}/code/hook/Hook.o code/hook/Hook.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/hook
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/hook/Hook.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/hook/Hook_nomain.o code/hook/Hook.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/hook/Hook.o ${OBJECTDIR}/code/hook/Hook_nomain.o;\
	fi

${OBJECTDIR}/code/hook/Hookable_nomain.o: ${OBJECTDIR}/code/hook/Hookable.o code/hook/Hookable.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/hook
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/hook/Hookable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/hook/Hookable_nomain.o code/hook/Hookable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/hook/Hookable.o ${OBJECTDIR}/code/hook/Hookable_nomain.o;\
	fi

${OBJECTDIR}/code/hook/RelationChoiceHook_nomain.o: ${OBJECTDIR}/code/hook/RelationChoiceHook.o code/hook/RelationChoiceHook.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/hook
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/hook/RelationChoiceHook.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/hook/RelationChoiceHook_nomain.o code/hook/RelationChoiceHook.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/hook/RelationChoiceHook.o ${OBJECTDIR}/code/hook/RelationChoiceHook_nomain.o;\
	fi

${OBJECTDIR}/code/main_nomain.o: ${OBJECTDIR}/code/main.o code/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/main_nomain.o code/main.cpp;\
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
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/parse/tspParser_nomain.o code/parse/tspParser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/parse/tspParser.o ${OBJECTDIR}/code/parse/tspParser_nomain.o;\
	fi

${OBJECTDIR}/code/relation/Insert_nomain.o: ${OBJECTDIR}/code/relation/Insert.o code/relation/Insert.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/relation/Insert.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Insert_nomain.o code/relation/Insert.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/relation/Insert.o ${OBJECTDIR}/code/relation/Insert_nomain.o;\
	fi

${OBJECTDIR}/code/relation/Relation_nomain.o: ${OBJECTDIR}/code/relation/Relation.o code/relation/Relation.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/relation/Relation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Relation_nomain.o code/relation/Relation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/relation/Relation.o ${OBJECTDIR}/code/relation/Relation_nomain.o;\
	fi

${OBJECTDIR}/code/relation/Reverse_nomain.o: ${OBJECTDIR}/code/relation/Reverse.o code/relation/Reverse.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/relation/Reverse.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Reverse_nomain.o code/relation/Reverse.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/relation/Reverse.o ${OBJECTDIR}/code/relation/Reverse_nomain.o;\
	fi

${OBJECTDIR}/code/relation/Swap_nomain.o: ${OBJECTDIR}/code/relation/Swap.o code/relation/Swap.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/relation
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/relation/Swap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/relation/Swap_nomain.o code/relation/Swap.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/relation/Swap.o ${OBJECTDIR}/code/relation/Swap_nomain.o;\
	fi

${OBJECTDIR}/code/run/RunData_nomain.o: ${OBJECTDIR}/code/run/RunData.o code/run/RunData.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/run/RunData.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/RunData_nomain.o code/run/RunData.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/run/RunData.o ${OBJECTDIR}/code/run/RunData_nomain.o;\
	fi

${OBJECTDIR}/code/run/Runner_nomain.o: ${OBJECTDIR}/code/run/Runner.o code/run/Runner.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/run/Runner.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/Runner_nomain.o code/run/Runner.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/run/Runner.o ${OBJECTDIR}/code/run/Runner_nomain.o;\
	fi

${OBJECTDIR}/code/run/interval/Action_nomain.o: ${OBJECTDIR}/code/run/interval/Action.o code/run/interval/Action.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run/interval
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/run/interval/Action.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/interval/Action_nomain.o code/run/interval/Action.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/run/interval/Action.o ${OBJECTDIR}/code/run/interval/Action_nomain.o;\
	fi

${OBJECTDIR}/code/run/interval/Interval_nomain.o: ${OBJECTDIR}/code/run/interval/Interval.o code/run/interval/Interval.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run/interval
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/run/interval/Interval.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/interval/Interval_nomain.o code/run/interval/Interval.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/run/interval/Interval.o ${OBJECTDIR}/code/run/interval/Interval_nomain.o;\
	fi

${OBJECTDIR}/code/run/interval/IntervalManager_nomain.o: ${OBJECTDIR}/code/run/interval/IntervalManager.o code/run/interval/IntervalManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/run/interval
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/run/interval/IntervalManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/run/interval/IntervalManager_nomain.o code/run/interval/IntervalManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/run/interval/IntervalManager.o ${OBJECTDIR}/code/run/interval/IntervalManager_nomain.o;\
	fi

${OBJECTDIR}/code/strategy/BestFit_nomain.o: ${OBJECTDIR}/code/strategy/BestFit.o code/strategy/BestFit.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/strategy/BestFit.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/BestFit_nomain.o code/strategy/BestFit.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/strategy/BestFit.o ${OBJECTDIR}/code/strategy/BestFit_nomain.o;\
	fi

${OBJECTDIR}/code/strategy/FirstFit_nomain.o: ${OBJECTDIR}/code/strategy/FirstFit.o code/strategy/FirstFit.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/strategy/FirstFit.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/FirstFit_nomain.o code/strategy/FirstFit.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/strategy/FirstFit.o ${OBJECTDIR}/code/strategy/FirstFit_nomain.o;\
	fi

${OBJECTDIR}/code/strategy/Strategy_nomain.o: ${OBJECTDIR}/code/strategy/Strategy.o code/strategy/Strategy.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/strategy/Strategy.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/Strategy_nomain.o code/strategy/Strategy.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/strategy/Strategy.o ${OBJECTDIR}/code/strategy/Strategy_nomain.o;\
	fi

${OBJECTDIR}/code/strategy/WorstFit_nomain.o: ${OBJECTDIR}/code/strategy/WorstFit.o code/strategy/WorstFit.cpp 
	${MKDIR} -p ${OBJECTDIR}/code/strategy
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/strategy/WorstFit.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/strategy/WorstFit_nomain.o code/strategy/WorstFit.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/strategy/WorstFit.o ${OBJECTDIR}/code/strategy/WorstFit_nomain.o;\
	fi

${OBJECTDIR}/code/utils_nomain.o: ${OBJECTDIR}/code/utils.o code/utils.cpp 
	${MKDIR} -p ${OBJECTDIR}/code
	@NMOUTPUT=`${NM} ${OBJECTDIR}/code/utils.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/code/utils_nomain.o code/utils.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/code/utils.o ${OBJECTDIR}/code/utils_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f13 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f14 || true; \
	    ${TESTDIR}/TestFiles/f12 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f11 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
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
