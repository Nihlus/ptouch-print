cmake_minimum_required(VERSION 3.15)
project(ptouch_print C)

# Configure CMake
set(CMAKE_C_STANDARD 11)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Configure required dependencies
find_package(Gettext REQUIRED)
find_package(GD REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

# Configure names and versions
execute_process(COMMAND bash "${CMAKE_CURRENT_LIST_DIR}/build-aux/git-version-gen" OUTPUT_VARIABLE VERSION)

# Configure project executable
add_executable(ptouch_print)

target_sources(ptouch_print
    PUBLIC
        include/ptouch.h
    PRIVATE
        include/gettext.h
        src/libptouch.c
        src/ptouch-print.c
)

# Configure compiler
target_compile_options(ptouch_print
    PRIVATE
        -g
        -Wall
        -Wextra
        -Wunused
        -O3
        -fPIC
)

target_compile_definitions(ptouch_print
    PRIVATE
        LOCALEDIR="${CMAKE_INSTALL_LOCALEDIR}"
        USING_CMAKE=1
        VERSION="${VERSION}"
        PACKAGE="ptouch"

)

target_include_directories(ptouch_print
    PRIVATE
        include
        ${GD_INCLUDE_DIR}
        ${LIBUSB_INCLUDE_DIRS}
)

# Configure linker
target_link_libraries(ptouch_print
        ${GD_LIBRARIES}
        ${LIBUSB_LIBRARIES}
)