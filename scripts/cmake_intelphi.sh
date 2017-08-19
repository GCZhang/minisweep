#!/bin/bash -l
#------------------------------------------------------------------------------

# CLEANUP
rm -rf CMakeCache.txt
rm -rf CMakeFiles

# SOURCE AND INSTALL
if [ "$SOURCE" = "" ] ; then
  SOURCE=../minisweep
fi
if [ "$INSTALL" = "" ] ; then
  INSTALL=../install
fi

if [ "$BUILD" = "" ] ; then
  BUILD=Debug
  #BUILD=Release
fi

OPT_ARGS="-qopt-report=5 -ip -prec-div -O3 -align -ansi-alias -fargument-noalias -fno-alias -fargument-noalias" #  -xmic-avx512"
# -mmic
# -vec-report1

#COMPILER_PHI="mpiicc"
COMPILER_PHI="$(which cc)"

#------------------------------------------------------------------------------

cmake \
  -DCMAKE_BUILD_TYPE:STRING="$BUILD" \
  -DCMAKE_INSTALL_PREFIX:PATH="$INSTALL" \
 \
  -DCMAKE_C_COMPILER:STRING=$COMPILER_PHI \
  -DCMAKE_C_FLAGS:STRING="-DNM_VALUE=$NM_VALUE -DUSE_OPENMP -DUSE_OPENMP_THREADS -qopenmp -DUSE_MPI -std=c99 -DIS_MIC" \
  -DCMAKE_C_FLAGS_DEBUG:STRING="-g $OPT_ARGS" \
  -DCMAKE_C_FLAGS_RELEASE:STRING="$OPT_ARGS -DNDEBUG" \
 \
  -DUSE_MPI:BOOL=ON \
 \
  $SOURCE

#------------------------------------------------------------------------------
