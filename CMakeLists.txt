cmake_minimum_required(VERSION 3.0)

project(CamCalib VERSION 1.0.0)

include(GNUInstallDirs)



add_library(CamCalib SHARED src/main.cpp)

set_target_properties(CamCalib PROPERTIES
VERSION ${PROJECT_VERSION}
SOVERSION 1
PUBLIC_HEADER include/camcalib.hpp)

configure_file(src/camcalib.pc.in camcalib.pc @ONLY)

include_directories(CamCalib /include)

install(TARGETS CamCalib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/camcalib.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)