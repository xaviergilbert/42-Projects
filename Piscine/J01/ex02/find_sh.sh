find . -name "*.sh" | sed 's/\.sh//g' | sed 's/\.\///g' | rev | cut -d"/" -f 1 | rev
