#!/bin/bash

set -x

# source_dir=`cd "$(dirname '$1')" &>/dev/null && printf "%s/%s" "$PWD" "${1##*/}"`
source_dir=`cd "$(dirname '$1')" &>/dev/null && printf "$PWD"`

rm -rfv $source_dir/build
mkdir $source_dir/build
cd $source_dir/build
cmake $source_dir -DCMAKE_INSTALL_PREFIX=$source_dir/install
make
make install
cd $source_dir
