#!/bin/zsh

make re DEFINE=-DSTD && ./containers > logSTD
make re && ./containers > logFT
diff logFT logSTD 