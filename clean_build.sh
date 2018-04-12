#!/bin/bash
#===============================================================================
#
#          FILE: clean_build.sh
#
#         USAGE: ./clean_build.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Charles Chiu (), charles.r.chiu@gmail.com
#  ORGANIZATION: 
#       CREATED: 2018年03月15日 15时44分34秒
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

find . -name 'build' | xargs -i rm -rf {}
find . -name 'cmake-build-*' | xargs -i rm -rf {}
find . -name 'core*' | xargs -i rm -rf {}
#script_dir=`dirname $0`
script_dir=`pwd`
echo "script dir is $script_dir"
echo `basename $0` is in `pwd`

for mf in `find . -name 'Makefile'`
do
    # echo $mf
    m_f=`basename $mf`
    m_dir=`dirname $mf`
    echo "cd $m_dir && make -f $m_f clean"
    cd $m_dir && make -f $m_f clean
    cd $script_dir
done



