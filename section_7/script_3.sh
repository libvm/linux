#!/bin/bash

mkdir server
cd ./server

git init --bare
cd ../repo

git remote add server ../server
git push server master

cd ../
mkdir clone
cd ./clone
git clone ../server

