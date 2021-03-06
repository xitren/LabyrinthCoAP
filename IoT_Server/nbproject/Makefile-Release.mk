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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1ba7ad3b/ExtFunctions.o \
	${OBJECTDIR}/Labyrinth.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=../Worked/libeeg_evoker.a ../Worked/libxitlib_x86_win_1_5_3.a -lWs2_32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ../Worked/libeeg_evoker.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ../Worked/libxitlib_x86_win_1_5_3.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1ba7ad3b/ExtFunctions.o: ../Worked/External/ExtFunctions.c
	${MKDIR} -p ${OBJECTDIR}/_ext/1ba7ad3b
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCPU -DEXTMEMSERVER -DPLATFORM_WINDOWS -I../Worked -I../Worked/External -I../Worked/inc -I../Worked/inc/coap -I../Worked/inc/json -I../Worked/inc/malloc -I../Worked/inc/models -I../Worked/ev_inc -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1ba7ad3b/ExtFunctions.o ../Worked/External/ExtFunctions.c

${OBJECTDIR}/Labyrinth.o: Labyrinth.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCPU -DEXTMEMSERVER -DPLATFORM_WINDOWS -I../Worked -I../Worked/External -I../Worked/inc -I../Worked/inc/coap -I../Worked/inc/json -I../Worked/inc/malloc -I../Worked/inc/models -I../Worked/ev_inc -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Labyrinth.o Labyrinth.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -DCPU -DEXTMEMSERVER -DPLATFORM_WINDOWS -I../Worked -I../Worked/External -I../Worked/inc -I../Worked/inc/coap -I../Worked/inc/json -I../Worked/inc/malloc -I../Worked/inc/models -I../Worked/ev_inc -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
