# CMake generated Testfile for 
# Source directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3
# Build directory: C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(TreeTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/build/Debug/tree_test.exe")
  set_tests_properties(TreeTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;22;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(TreeTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/build/Release/tree_test.exe")
  set_tests_properties(TreeTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;22;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(TreeTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/build/MinSizeRel/tree_test.exe")
  set_tests_properties(TreeTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;22;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(TreeTest "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/build/RelWithDebInfo/tree_test.exe")
  set_tests_properties(TreeTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;22;add_test;C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/as3/CMakeLists.txt;0;")
else()
  add_test(TreeTest NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
