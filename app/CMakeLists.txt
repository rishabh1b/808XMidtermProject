add_executable(shell-app main.cpp VideoFrame.cpp ObjectDetector.cpp SiftDetector.cpp VisionManager.cpp OutputWriter.cpp)

find_package( OpenCV REQUIRED )

# add_library(vidframe
#  VideoFrame.cpp
#)
# target_link_libraries( shell-app ${OpenCV_LIBS} vidframe)
target_link_libraries( shell-app ${OpenCV_LIBS})

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
