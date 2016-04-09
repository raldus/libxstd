#!/bin/bash

echo "# Changelog" > CHANGELOG.md
git show --tags --name-only \
--pretty=format:'[view tag](https://github.com/raldus/libxstd/commit/%H)' \
--reverse >> CHANGELOG.md

#git log\
#    --pretty=format:'* [view commit](http://github.com/raldus/libxstd/commit/%H)' \
#    --reverse
#| grep "#changelog" >> CHANGELOG.md
