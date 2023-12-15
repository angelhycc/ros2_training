cmake_minimum_required(VERSION 3.5)
project(my_cpp_library)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# tell CMake to add this directory to the target including path
include_directories(include/my_cpp_library)
# you can use the file you are using but this is mostly used for multiple header files
set(HEADER_FILES include/my_cpp_library/library_header.h)
add_library(my_lib src/my_cpp_library.cpp ${HEADER_FILES}) 

add_executable(main src/main.cpp)
 # this is important to tell CMake that the executable "main" depends on the library "my_lib"
target_link_libraries(main PUBLIC my_lib)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter, which checks for copyrights
  # uncomment the line when copyright and license are not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  find_package(ament_cmake_gtest REQUIRED)

  set(TESTFILES
      test/main.cpp
      test/savings_account_test.cpp
      )
  # Add gtest executables
  ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
  target_link_libraries(${PROJECT_NAME}_test my_lib)

  install(TARGETS
        ${PROJECT_NAME}_test
        # Install the generated test executable file to the path after DESTINATION
        DESTINATION lib/${PROJECT_NAME})
  # uncomment to enforce lintners and static code analyzers defined in ament_lint_common package        
  # ament_lint_auto_find_test_dependencies()
endif()

# this installs the executable in the lib folder to be seen by setup.bash to be seen by ros2
install(TARGETS 
  main
  DESTINATION lib/${PROJECT_NAME}/
)

# this line to export the targets. In your case, it is a library
ament_export_targets(my_lib HAS_LIBRARY_TARGET)

# install the include/my_cpp_library directory to the install/include/my_cpp_library
install(
  DIRECTORY include/my_cpp_library
  DESTINATION include
)

install(
  TARGETS my_lib
  EXPORT my_lib
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)


ament_package()