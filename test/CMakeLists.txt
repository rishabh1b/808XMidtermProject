set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    ObjectDetection.cpp
    ../app/VisionManager.cpp
    ../app/VideoFrame.cpp
    ../app/SiftDetector.cpp
    ../app/OutputWriter.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
