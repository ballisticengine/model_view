#!/usr/bin/env bash

export LC_ALL=C
export LD_LIBRARY_PATH=$(pwd)/../ballistic_engine/bin/
echo $LD_LIBRARY_PATH
./bin/modelview $1