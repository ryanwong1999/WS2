# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_yzbot_stm32connect_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED yzbot_stm32connect_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(yzbot_stm32connect_FOUND FALSE)
  elseif(NOT yzbot_stm32connect_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(yzbot_stm32connect_FOUND FALSE)
  endif()
  return()
endif()
set(_yzbot_stm32connect_CONFIG_INCLUDED TRUE)

# output package information
if(NOT yzbot_stm32connect_FIND_QUIETLY)
  message(STATUS "Found yzbot_stm32connect: 0.0.0 (${yzbot_stm32connect_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'yzbot_stm32connect' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${yzbot_stm32connect_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(yzbot_stm32connect_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${yzbot_stm32connect_DIR}/${_extra}")
endforeach()
