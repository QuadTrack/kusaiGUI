add_library(aiOverride ai.cpp)

target_include_directories(aiOverride PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(kusai
        GIT_REPOSITORY ${CMAKE_CURRENT_SOURCE_DIR}/kusai
        GIT_TAG main
)
FetchContent_MakeAvailable(kusai)

target_link_libraries(aiOverride
        PUBLIC textchain
)
