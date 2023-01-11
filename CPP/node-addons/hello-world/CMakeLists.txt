cmake_minimum_required(VERSION 3.16)
project(hello-world)

# To build a node addon we need to include the Node-API
include_directories(${CMAKE_JS_INC})

add_library(${PROJECT_NAME} SHARED hello.cc)

# Change the library suffix to .node
# this is a mandatory demand, since node addons must have .node suffix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

# Link with the base library such as V8,libuv and OpenSSL
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
