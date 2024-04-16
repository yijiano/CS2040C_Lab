# CMake generated Testfile for 
# Source directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1
# Build directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Part1Test "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/build/Debug/part1_test.exe")
  set_tests_properties(Part1Test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Part1Test "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/build/Release/part1_test.exe")
  set_tests_properties(Part1Test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Part1Test "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/build/MinSizeRel/part1_test.exe")
  set_tests_properties(Part1Test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Part1Test "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/build/RelWithDebInfo/part1_test.exe")
  set_tests_properties(Part1Test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/pe/part1/CMakeLists.txt;0;")
else()
  add_test(Part1Test NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
