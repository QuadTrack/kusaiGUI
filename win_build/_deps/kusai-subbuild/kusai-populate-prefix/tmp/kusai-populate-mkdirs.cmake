# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-src")
  file(MAKE_DIRECTORY "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-src")
endif()
file(MAKE_DIRECTORY
  "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-build"
  "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix"
  "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix/tmp"
  "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix/src/kusai-populate-stamp"
  "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix/src"
  "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix/src/kusai-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix/src/kusai-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/usec/Git/kusaiGUI/win_build/_deps/kusai-subbuild/kusai-populate-prefix/src/kusai-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
