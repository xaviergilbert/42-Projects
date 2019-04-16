ldapsearch -x uid="z*" | grep "cn:" | sort -brd | cut -c5-
