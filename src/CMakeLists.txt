# add_library(rt_core)
add_executable(rt_core
    main.cpp
)

target_include_directories(rt_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_features(rt_core PUBLIC cxx_std_23)
