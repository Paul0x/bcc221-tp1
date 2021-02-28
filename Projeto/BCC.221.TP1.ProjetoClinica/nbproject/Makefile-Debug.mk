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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/Administrador.o \
	${OBJECTDIR}/AssistenteAdministrativo.o \
	${OBJECTDIR}/Especialista.o \
	${OBJECTDIR}/RegistroAgenda.o \
	${OBJECTDIR}/RegistroPagamentoConsulta.o \
	${OBJECTDIR}/RegistroPagamentoConta.o \
	${OBJECTDIR}/RegistroPonto.o \
	${OBJECTDIR}/SistemaClinica.o \
	${OBJECTDIR}/Usuario.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bcc.221.tp1.projetoclinica

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bcc.221.tp1.projetoclinica: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bcc.221.tp1.projetoclinica ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Administrador.o: Administrador.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Administrador.o Administrador.cpp

${OBJECTDIR}/AssistenteAdministrativo.o: AssistenteAdministrativo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AssistenteAdministrativo.o AssistenteAdministrativo.cpp

${OBJECTDIR}/Especialista.o: Especialista.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Especialista.o Especialista.cpp

${OBJECTDIR}/RegistroAgenda.o: RegistroAgenda.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistroAgenda.o RegistroAgenda.cpp

${OBJECTDIR}/RegistroPagamentoConsulta.o: RegistroPagamentoConsulta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistroPagamentoConsulta.o RegistroPagamentoConsulta.cpp

${OBJECTDIR}/RegistroPagamentoConta.o: RegistroPagamentoConta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistroPagamentoConta.o RegistroPagamentoConta.cpp

${OBJECTDIR}/RegistroPonto.o: RegistroPonto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistroPonto.o RegistroPonto.cpp

${OBJECTDIR}/SistemaClinica.o: SistemaClinica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SistemaClinica.o SistemaClinica.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
