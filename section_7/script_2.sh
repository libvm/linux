#!/bin/bash

cd ./repo

git branch brn
git checkout brn
echo "some another text" > another.txt
git add .
git commit -m "Commit"
git checkout master
git merge brn


