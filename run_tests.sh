#!/bin/sh


echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 0                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 0  ;   Height: 0  ;   Density: 1  <=="
echo
perl *.pl 0 0 1 | time ./bsq

echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 1                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 1  ;   Height: 1  ;   Density: 1  <=="
echo
perl *.pl 1 1 1 | time ./bsq
echo
echo
echo "==>   Length: 1  ;   Height: 1  ;   Density: 3  <=="
echo
perl *.pl 1 1 3 | time ./bsq

echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 2                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 1  ;   Height: 2  ;   Density: 1  <=="
echo
perl *.pl 1 2 1 | time ./bsq
echo
echo
echo "==>   Length: 1  ;   Height: 2  ;   Density: 2  <=="
echo
perl *.pl 1 2 2 | time ./bsq
echo
echo
echo "==>   Length: 1  ;   Height: 2  ;   Density: 3  <=="
echo
perl *.pl 1 2 3 | time ./bsq

echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 3                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 5  ;   Height: 5  ;   Density: 1  <=="
echo
perl *.pl 5 5 1 | time ./bsq
echo
echo
echo "==>   Length: 5  ;   Height: 5  ;   Density: 2  <=="
echo
perl *.pl 5 5 2 | time ./bsq
echo
echo
echo "==>   Length: 5  ;   Height: 5  ;   Density: 3  <=="
echo
perl *.pl 5 5 3 | time ./bsq

echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 4                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 10  ;   Height: 10  ;   Density: 1  <=="
echo
perl *.pl 10 10 1 | time ./bsq
echo
echo
echo "==>   Length: 10  ;   Height: 10  ;   Density: 2  <=="
echo
perl *.pl 10 10 2 | time ./bsq
echo
echo
echo "==>   Length: 10  ;   Height: 10  ;   Density: 3  <=="
echo
perl *.pl 10 10 3 | time ./bsq


echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 5                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 20  ;   Height: 20  ;   Density: 1  <=="
echo
perl *.pl 20 20 1 | time ./bsq
echo
echo
echo "==>   Length: 20  ;   Height: 20  ;   Density: 2  <=="
echo
perl *.pl 20 20 2 | time ./bsq
echo
echo
echo "==>   Length: 20  ;   Height: 20  ;   Density: 3  <=="
echo
perl *.pl 20 20 3 | time ./bsq

echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 6                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 40  ;   Height: 40  ;   Density: 1  <=="
echo
perl *.pl 40 40 1 | time ./bsq
echo
echo
echo "==>   Length: 40  ;   Height: 40  ;   Density: 2  <=="
echo
perl *.pl 40 40 2 | time ./bsq
echo
echo
echo "==>   Length: 40  ;   Height: 40  ;   Density: 3  <=="
echo
perl *.pl 40 40 3 | time ./bsq


echo
echo
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo "// ======================================================================= //"
echo "//                                LEVEL 7                                  //"
echo "// ======================================================================= //"
echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
echo
echo
echo
echo "==>   Length: 80  ;   Height: 80  ;   Density: 1  <=="
echo
perl *.pl 80 80 1 | time ./bsq
echo
echo
echo "==>   Length: 80  ;   Height: 80  ;   Density: 2  <=="
echo
perl *.pl 80 80 2 | time ./bsq
echo
echo
echo "==>   Length: 80  ;   Height: 80  ;   Density: 3  <=="
echo
perl *.pl 80 80 3 | time ./bsq


# echo
# echo
# echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
# echo "// ======================================================================= //"
# echo "//                               FINAL BOSS                                //"
# echo "// ======================================================================= //"
# echo "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //"
# echo
# echo
# echo
# echo "==>   Length: 160  ;   Height: 160  ;   Density: 1  <=="
# echo
# perl *.pl 160 160 1 | time ./bsq
# echo
# echo
# echo "==>   Length: 160  ;   Height: 160  ;   Density: 2  <=="
# echo
# perl *.pl 160 160 2 | time ./bsq
# echo
# echo
# echo "==>   Length: 160  ;   Height: 160  ;   Density: 3  <=="
# echo
# perl *.pl 160 160 3 | time ./bsq
