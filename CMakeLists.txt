cmake_minimum_required(VERSION 2.6)
PROJECT(Base)

AUX_SOURCE_DIRECTORY(./ SRC_LIST1)
AUX_SOURCE_DIRECTORY(./pb/protocol SRC_LIST2)
#AUX_SOURCE_DIRECTORY(./jsoncpp SRC_LIST3)
#AUX_SOURCE_DIRECTORY(./segment SRC_LIST4)
AUX_SOURCE_DIRECTORY(./cxxurl SRC_LIST5)
AUX_SOURCE_DIRECTORY(./ananas/util SRC_LIST4)
AUX_SOURCE_DIRECTORY(./ananas/net SRC_LIST3)
AUX_SOURCE_DIRECTORY(./ananas/future SRC_LIST6)

#AUX_SOURCE_DIRECTORY(./cxxurl SRC_LIST5)

SET(PB_LIB_DIR ./pb/lib/linux)

SET(LIBRARY_OUTPUT_PATH ./)
#SET(EXECUTABLE_OUTPUT_PATH  ./bin)

ADD_DEFINITIONS( -g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
-DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
-Wno-literal-suffix -Wno-unused-variable -Wno-unused-function
-Wno-sign-compare -Wno-deprecated -Wno-unused-parameter -Wno-missing-field-initializers
-DAC_HAS_DEBUG -DLINUX_DAEMON -std=c++11 -Wno-type-limits)

INCLUDE_DIRECTORIES(./ ../ ./pb ./pb/protocol ./cxxurl ./ananas/util ./ananas/net ./ananas/future  ./rapidjson)
LINK_DIRECTORIES(./ ${PB_LIB_DIR}  ./cxxurl ./ananas/util ./ananas/net ./ananas/future ./ananas/rapidjson)

ADD_LIBRARY(base STATIC ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4} ${SRC_LIST5} ${SRC_LIST6})

#ADD_XXXX必须在TARGET_LINK_LIBRARIES前面，否则会报错
#ADD_LIBRARY(${PROJECTNAME} SHARED ${SRC_LIST})
#ADD_EXECUTABLE(${PROJECTNAME} ${SRC_LIST})

TARGET_LINK_LIBRARIES(base pthread crypto curl)
