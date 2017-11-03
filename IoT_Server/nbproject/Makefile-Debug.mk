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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
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
LDLIBSOPTIONS=../EEG_Evoker/dist/Debug/Cygwin-Windows/libeeg_evoker.a ../XitLib/dist/Debug_Windows/Cygwin-Windows/libxitlib.a ../CoAP/dist/Debug/Cygwin-Windows/libcoap.a -lWs2_32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ../EEG_Evoker/dist/Debug/Cygwin-Windows/libeeg_evoker.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ../XitLib/dist/Debug_Windows/Cygwin-Windows/libxitlib.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ../CoAP/dist/Debug/Cygwin-Windows/libcoap.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/iot_server ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1ba7ad3b/ExtFunctions.o: ../Worked/External/ExtFunctions.c
	${MKDIR} -p ${OBJECTDIR}/_ext/1ba7ad3b
	${RM} "$@.d"
	$(COMPILE.c) -g -DCPU -DDEBUG -DPLATFORM_WINDOWS -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1ba7ad3b/ExtFunctions.o ../Worked/External/ExtFunctions.c

${OBJECTDIR}/Labyrinth.o: Labyrinth.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DCPU -DDEBUG -DPLATFORM_WINDOWS -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Labyrinth.o Labyrinth.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -DCPU -DDEBUG -DPLATFORM_WINDOWS -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:
	cd ../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug
	cd ../XitLib && ${MAKE}  -f Makefile CONF=Debug_Windows
	cd ../CoAP && ${MAKE}  -f Makefile CONF=Debug
	cd ../CoAP && ${MAKE}  -f Makefile CONF=Debug
	cd ../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug
	cd ../XitLib && ${MAKE}  -f Makefile CONF=Debug_Windows

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:
	cd ../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../XitLib && ${MAKE}  -f Makefile CONF=Debug_Windows clean
	cd ../CoAP && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../CoAP && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../EEG_Evoker && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../XitLib && ${MAKE}  -f Makefile CONF=Debug_Windows clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
