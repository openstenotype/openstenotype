include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(NOT DEFINED OPENSTENO_LIBRARIES)
  message(FATAL_ERROR "Please compile using the repo's root CMakeLists.txt")
endif()

add_executable(${EXE_NAME}
  Main.cpp
  JsonLoader.cpp
  DictionaryLoader.cpp
  WindowSystem.cpp
  WindowSystemDriver.cpp
  WindowSystemDriverHelper.cpp
  Opensteno.cpp
  KeyMapFactory.cpp
)

target_link_libraries(${EXE_NAME} ${OPENSTENO_LIBRARIES})
install(TARGETS ${EXE_NAME} DESTINATION bin)
add_custom_target(run COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXE_NAME}${CMAKE_EXECUTABLE_SUFFIX} DEPENDS ${EXE_NAME})
add_custom_target(debug COMMAND gdb --args ${CMAKE_CURRENT_BINARY_DIR}/${EXE_NAME}${CMAKE_EXECUTABLE_SUFFIX} DEPENDS ${EXE_NAME})
