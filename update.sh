#!/usr/bin/bash
cat .vscode/README.md > README.md
tree >> README.md
echo '```' >> README.md
git add .
git commit -m "update"
git push
chown philoy -R .
