cmake_minimum_required(VERSION 3.1...3.23)

set (CMAKE_CXX_STANDARD 11)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  CustomRocksDBMergeOperator
  VERSION 1.0
  LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(RocksDB REQUIRED)

add_library(QueueMerge
  lib/queue_merge.cpp
  )

target_include_directories(QueueMerge
  INTERFACE
  lib/
  )

target_link_libraries(QueueMerge
  INTERFACE
  RocksDB::RocksDB
  )

add_executable(QueueExample
  example/queue_example.cpp
  )

target_link_libraries(QueueExample
  PRIVATE
  QueueMerge
  )
