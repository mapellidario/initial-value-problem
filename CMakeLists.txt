cmake_minimum_required (VERSION 2.6)
project(ode)

set(CMAKE_REQUIRED_LIBRARIES m)

include_directories("${PROJECT_SOURCE_DIR}/RungeKutta")
add_subdirectory (RungeKutta)
set(RUNGEKUTTA_EXTRA_LIBS ${RUNGEKUTTA_EXTRA_LIBS} RungeKutta)

include_directories("${PROJECT_SOURCE_DIR}/CauchyProblem")
add_subdirectory (CauchyProblem)
set(CAUCHYPROBLEM_EXTRA_LIBS ${CAUCHYPROBLEM_EXTRA_LIBS} CauchyProblem)
set(CAUCHYPROBLEM_EXTRA_LIBS ${CAUCHYPROBLEM_EXTRA_LIBS} ${CMAKE_REQUIRED_LIBRARIES})

add_executable(rungekutta rungekutta.c)
# file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/data)
target_link_libraries(rungekutta ${RUNGEKUTTA_EXTRA_LIBS} ${CAUCHYPROBLEM_EXTRA_LIBS})

add_executable(direction-field direction-field.cpp)

# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED)
if(ROOT_FOUND)
    message("-- ROOT found")
    include_directories(${ROOT_INCLUDE_DIRS})
    message("-- ROOT found at ${ROOT_INCLUDE_DIRS}")
    # message("-- ROOT libraries: ${ROOT_LIBRARIES}")
    target_link_libraries(direction-field ${CAUCHYPROBLEM_EXTRA_LIBS} ${ROOT_LIBRARIES})
endif(ROOT_FOUND)
if(NOT ROOT_FOUND)
    message(FATAL_ERROR "Package ROOT is required, but not found!")
endif(NOT ROOT_FOUND)

# install
install(DIRECTORY DESTINATION data)
install(TARGETS rungekutta DESTINATION bin)
install(TARGETS direction-field DESTINATION bin)
