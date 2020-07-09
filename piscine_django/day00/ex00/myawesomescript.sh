# transormer une url raccourci en url
# commandes autorisees :
# -curl
# -grep
# -cut

curl -s $1 | grep "href" | awk '{ print $2 }' | cut -f2 -d"\""


