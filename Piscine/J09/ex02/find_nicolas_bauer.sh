find phonebook | cat phonebook |  grep -i bauer | grep -i nicolas | sed s/^B/N/ | sed s/^n/N/ | grep N | tr "\t" "." | cut -d "." -f3| sed -n '/2/p'
