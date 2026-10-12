# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "Ayurheal_autogen"
  "CMakeFiles\\Ayurheal_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ayurheal_autogen.dir\\ParseCache.txt"
  )
endif()
