find . -name "*.sh" | sed 's/\.sh//g' | rev | cut -d"/" -f 1 | rev
