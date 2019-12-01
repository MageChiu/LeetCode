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

# find . -name 'build' | xargs -i rm -rf {}
# find . -name 'cmake-build-*' | xargs -i rm -rf {}
# find . -name 'core*' | xargs -i rm -rf {}
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


function clean_build_file {
    echo "clean build file start...."
    need_clean_dir=('build' 'cmake-build-*' 'core*')
    for _dir_name in ${need_clean_dir[@]};
    do
        for _dest_dir in `find . -name "${_dir_name}"`;
        do
            rm -rf ${_dest_dir}
        done
    done
    echo "clean build file end."
}

function clean_file_e {
    need_chmod_type=('cpp' 'h')
    for file_type in ${need_chmod_type[*]};
    do
        for dest_file in `find . -name "*.${file_type}"`
        do
            chmod u-x $dest_file
        done
    done
}

clean_build_file
clean_file_e


