#!/bin/bash
IO_FILES=true
USE_GRADERS=false
PROBLEM=cord
AUTHOR=ik
SUFFIX=
LANGUAGE=cpp
SOLUTION=../solutions/$PROBLEM\_$AUTHOR$SUFFIX.$LANGUAGE
GENERATOR=gen.cpp
VALIDATOR=validate.cpp
CHECKER=../check.cpp
TEST_PATTERN=[0-9][0-9][0-9]
DO_CHECK=true
DO_CLEAN=true
CUSTOM_WIPE="drawit.log drawit-$TEST_PATTERN.eps"
