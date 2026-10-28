add_library(libzgmath
   STATIC
   data_types.cpp
)

target_include_directories(libzgmath
   PUBLIC
   ${INCLUDE_DIRECTORY}
)
