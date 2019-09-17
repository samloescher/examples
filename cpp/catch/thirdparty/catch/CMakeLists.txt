include(FetchContent)

FetchContent_Declare(
    catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.6.0
)

FetchContent_GetProperties(catch)

if(NOT catch_POPULATED)
    FetchContent_Populate(catch)
    add_subdirectory(${catch_SOURCE_DIR} ${catch_BINARY_DIR})
endif()

add_library(Catch2::Catch2 ALIAS Catch2)

function(add_catch_test TARGET)
    set(_reports_path ${CMAKE_BINARY_DIR}/reports)
    file(MAKE_DIRECTORY ${_reports_path})
    add_test(NAME ${TARGET} COMMAND ${TARGET} -r junit -o ${_reports_path}/${TARGET}.xml)
endfunction()
