#!/bin/bash

# Set your GitHub username and repository name
USERNAME="your_username"
REPO_NAME="your_repository"


for i in {1..10}
do
    touch "file${i}.py"
    echo "// This is file ${i}" >> "file${i}.py"
done

# Add, commit, and push each file
for i in {1..10}
do
    git add "file${i}.py"
    git commit -m "All tasks finished! 🏁"
    git push 
done
