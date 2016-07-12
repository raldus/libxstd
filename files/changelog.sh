#!/bin/bash

pushd .. > /dev/null

echo "# Changelog" > CHANGELOG.md

git show --tags --quiet \
--pretty=format:'%ad %n[view tag](https://github.com/raldus/libxstd/commit/%H) %n%n***%n' \
--reverse >> CHANGELOG.md

popd > /dev/null

#git log\
#    --pretty=format:'* [view commit](http://github.com/raldus/libxstd/commit/%H)' \
#    --reverse
#| grep "#changelog" >> CHANGELOG.md
