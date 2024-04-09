# CMake generated Testfile for 
# Source directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2
# Build directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(SuperFibTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/Debug/SuperFib_test.exe")
  set_tests_properties(SuperFibTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(SuperFibTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/Release/SuperFib_test.exe")
  set_tests_properties(SuperFibTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(SuperFibTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/MinSizeRel/SuperFib_test.exe")
  set_tests_properties(SuperFibTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(SuperFibTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/RelWithDebInfo/SuperFib_test.exe")
  set_tests_properties(SuperFibTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;25;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/CMakeLists.txt;0;")
else()
  add_test(SuperFibTest NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
