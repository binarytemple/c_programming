#!/usr/bin/env sh

echo $0

RUNDIR=`dirname $0`

cd $RUNDIR

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RUNDIR

java PrintLibraryPath
java JavaTest

# cursor: 2 del
