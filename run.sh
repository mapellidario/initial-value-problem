#!/bin/bash

set -x

source_dir=`cd "$(dirname '$1')" &>/dev/null && printf "$PWD"`

cd $source_dir/install/bin
./rungekutta
./direction-field
cd $source_dir
