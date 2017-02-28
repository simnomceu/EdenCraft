#!/bin/bash

# Visual Studio 2015 project
rm -f ./*.vcxproj
rm -f ./*.vcxproj.filters
rm -f ./*.vcxproj.user
rm -f ./*.sln
rm -f ./*.VC.db
rm -f ./*.VC.opendb
rm -rf ./UxTheme.pdb/
rm -rf ./.vs/

# CodeLite project
rm -f ./*.project
rm -f ./*.workspace

# Compilation files
rm -rf ./bin/
rm -rf ./obj/

# Gmake project
rm -f ./*.make
rm -f ./Makefile