# CMake generated Testfile for 
# Source directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5
# Build directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(ShortestPathTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/build/Debug/shortest_path_test.exe")
  set_tests_properties(ShortestPathTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;26;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(ShortestPathTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/build/Release/shortest_path_test.exe")
  set_tests_properties(ShortestPathTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;26;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(ShortestPathTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/build/MinSizeRel/shortest_path_test.exe")
  set_tests_properties(ShortestPathTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;26;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(ShortestPathTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/build/RelWithDebInfo/shortest_path_test.exe")
  set_tests_properties(ShortestPathTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;26;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/CS2040C_Lab/as5/CMakeLists.txt;0;")
else()
  add_test(ShortestPathTest NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
