cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(portal-editor LANGUAGES CXX)
# find Qt5 and required components
find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)
find_package(yaml-cpp REQUIRED)
# need this to include the auto generated ui_mainwindow.h
# file from the qt5_wrap_ui call below.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB project_sources ./*.cpp)
file(GLOB project_headers ./*.h)
file(GLOB project_ui mainwindow.ui)
file(GLOB lactivables editor_listado_de_activables.ui)
file(GLOB ajustes editor_ajustes.ui)

# wrap the ui file to a c++ header
qt5_wrap_ui(ui_wrap ${project_ui})
qt5_wrap_ui(ui_wrap ${lactivables})
qt5_wrap_ui(ui_wrap ${ajustes})

qt5_wrap_cpp(moc_sources ${project_headers})
add_executable(portal-editor
	${project_sources}
	${project_headers}
	${ui_wrap}
	${moc_sources}
	recursos.qrc)
target_link_libraries(portal-editor
	PUBLIC
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	yaml-cpp)

# auto copy dlls if on windows
if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:${PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:${PROJECT_NAME}> )
endif(WIN32)

# INSTALL
install(TARGETS portal-editor RUNTIME DESTINATION "bin")
