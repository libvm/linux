#!/bin/bash

mkdir repo
cd ./repo

git init

echo "Hello world!" > text.txt

git add .
git commit -m "Commit"
