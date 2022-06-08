#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := minnux
EXTRA_COMPONENT_DIRS := $(IDF_PATH)/examples/components/core $(IDF_PATH)/examples/components/utility

include $(IDF_PATH)/make/project.mk
