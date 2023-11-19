#!/bin/bash

cd ./repo
git checkout -b newBrn/1

echo "new text from repo has been added" >> text.txt
git add .
git commit -m "repo commit from script_4"
git push server newBrn/1

cd ../
cd ./clone/server
git checkout -b newBrn/2

echo "new text from server has been added" >> text.txt
git add .
git commit -m "server commit from script_4"
git remote add server ../../server
git push server newBrn/2

git fetch server newBrn/1
git checkout master
git merge server/newBrn/1
git merge server/newBrn/2
