SOURCES=SharedPtr.cpp
OBJECTS=${addprefix ${BUILD_DIR}/, ${SOURCES:.cpp=.o}}
DEPS=${addprefix ${BUILD_DIR}/, ${SOURCES:.cpp=.d}}
EXE=prog
CXXFLAGS=-I. -pthread

ifeq (${ARCH},host)
CXX=g++
BUILD_DIR=build/host
BIN_DIR=bin/host
endif

ifeq (${ARCH},target)
CXX=arm-rpizw-g++
BUILD_DIR=build/target
BIN_DIR=bin/target
endif

${BIN_DIR}/${EXE}: ${DEPS} ${OBJECTS}
	mkdir -p ${BIN_DIR}
	${CXX} ${CXXFLAGS} -o $@ ${OBJECTS}

${BUILD_DIR}/%.d: %.cpp
	mkdir -p ${BUILD_DIR}
	${CXX} -MT${@:.d=.o} -MM ${CXXFLAGS} $^ > $@

${BUILD_DIR}/%.o: %.cpp
	mkdir -p ${BUILD_DIR}
	${CXX} -c $< -o $@ ${CXXFLAGS}

ifneq (${MAKECMDGOALS},clean)
-include ${DEPS}
endif

clean:
	-rm -rf bin/
	-rm -rf build/

