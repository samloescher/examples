include(FetchContent)

FetchContent_Declare(
        cppzmq
        GIT_REPOSITORY https://github.com/zeromq/cppzmq
        GIT_TAG        v4.3.0
)

FetchContent_GetProperties(cppzmq)
if(NOT cppzmq_POPULATED)
    FetchContent_Populate(cppzmq)
    add_subdirectory(${cppzmq_SOURCE_DIR} ${cppzmq_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
