ifconfig | sed -n '/ether/p' | sed 's/ether //g' | sed 's/ //g' | cut -c 2-
