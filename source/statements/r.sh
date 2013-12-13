#!/bin/bash

source include.sh

function mpost_make()
{
  pushd ../problems || exit 1
  for f in * ; do
    echo $f
    if [ -d $f ] ; then
      if [ -d $f/statement ] ; then
        pushd $f/statement
        if [ -e $f.mp ] ; then
          mpost $f.mp || exit 1
        fi
        popd
      fi
    fi
  done
  popd
}

function doit()
{
  latex $1.tex || exit 1
  latex $1.tex || exit 1
  dvips -t a4 $1.dvi || exit 1
  dvipdfm -p a4 $1 || exit 1
}

function doit_landscape()
{
  latex $1.tex || exit 1
  latex $1.tex || exit 1
  dvips -t a4 -t landscape $1.dvi || exit 1
  dvipdfm -p a4 -l $1 || exit 1
}

#mpost_make || exit 1
#svnversion ../../.. > revision.temp || echo X > revision.temp
for s in $name{,.sols}{.en,.ru} ; do
  if [ -e $s.tex ] ; then
#    doit $s || exit 1
    doit_landscape $s || exit 1
  fi
done
#rm revision.temp
