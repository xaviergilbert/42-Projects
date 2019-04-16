L'exercice consiste a trier un liste de nombre rentree en parametre en utilisant
un certain nombre d'instruction predefinies.

Commande pour generer une liste de nombre et executer le programme :
ARG=`ruby -e "puts (0..19).to_a.shuffle.join(' ')" && ./push_swap -a -i -s $ARG

option -a :
Affichage des deux listes autorisees apres chaque "coups"

option -i :
Donne un certain nombre d'informations

option -s :
Slow mode, sleep (5) apres chaque instruction push_a
