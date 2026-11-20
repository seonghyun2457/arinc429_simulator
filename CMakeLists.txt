cmake_minimum_required(VERSION 3.16)

project(arinc429_simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

# directory paths
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/header)
set(QML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/qml)

# file list
set(PROJECT_SOURCES ${SRC_DIR}/main.cpp
                    ${SRC_DIR}/arinc429.cpp)

set(PROJECT_HEADERS ${HEADER_DIR}/arinc429.h)

set(PROJECT_QMLS ${QML_DIR}/Main.qml)

foreach(qml_file IN LISTS PROJECT_QMLS)
    get_filename_component(qml_name ${qml_file} NAME)
    set_source_files_properties(${qml_file} PROPERTIES QT_RESOURCE_ALIAS ${qml_name})
endforeach()



# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

# qt executable files
qt_add_executable(apparinc429_simulator
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

# QML modules
qt_add_qml_module(apparinc429_simulator
    URI arinc429_simulator
    QML_FILES
        ${PROJECT_QMLS}
)

# Include directories
target_include_directories(apparinc429_simulator PRIVATE ${HEADER_DIR})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apparinc429_simulator PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apparinc429_simulator
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apparinc429_simulator
    PRIVATE Qt6::Quick
)

# Group files
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Qml Files" FILES ${PROJECT_QMLS})

install(TARGETS apparinc429_simulator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
