
add_executable(build_test)
add_dependencies(build_test nyna)

target_sources(build_test PRIVATE 
    main.cpp 
)
target_link_libraries(build_test PRIVATE
    pico_stdlib
    hardware_spi
)
target_include_directories(build_test PRIVATE
    ../../include
)

pico_add_extra_outputs(build_test)
