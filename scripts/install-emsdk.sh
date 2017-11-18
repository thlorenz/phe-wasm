#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$DIR/../
EMSDK=$ROOT/emsdk

cd $ROOT
if [ -d  $EMSDK ]; then 
  echo "emsdk was installed, skipping clone step"
else
  git clone https://github.com/juj/emsdk.git $EMSDK
fi

cd $EMSDK 
./emsdk install latest
./emsdk activate latest

echo ""
echo "------------------------------------------------------------------------------------------------"
echo ""
echo "Successfully installed and activated emsdk"
echo "Now run the below to enter an Emscripten compiler environment in the current command line prompt."
echo "You will have to do this anytime you open a new shell"
echo "More info: http://webassembly.org/getting-started/developers-guide/"
echo ""
echo "source ./emsdk/emsdk_env.sh --build=Release"
