# - Config file for 'LogicToolbox' package
# It defines the following variables
#  LOGICTOOLBOX_INCLUDE_DIRS - include directories
#  LOGICTOOLBOX_LIBRARIES    - libraries to link against

# Include directory
set(LOGICTOOLBOX_INCLUDE_DIRS "C:/Program Files (x86)/LogicToolbox/include")

# Import the exported targets
include("C:/Program Files (x86)/LogicToolbox/CMake/LogicToolboxTargets.cmake")

# Set the expected library variable
set(LOGICTOOLBOX_LIBRARIES logictoolbox)
