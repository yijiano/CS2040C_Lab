# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/../googletest-03597a01ee50ed33e9dfd640b249b4be3799d395"
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-build"
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/rocky/OneDrive/Documents/ActualFiles/Obs_Yijian_NUS/NUS Academics/Y1S2/CS2040C/Lab/mock-pe/mockpe_part2/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
