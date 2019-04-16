stat -r bomb.txt | cut -d " " -f9 | xargs echo 1 - | bc | tr -d "-"
