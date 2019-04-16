.name "zork le petit robot qui a un nom trop long 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 00000 0000 0000 00000 00000 000000 000000 000000 000000 000000 00000 ouiii bcp trop long"
.comment "just a basic living prog"
		
l2:	sti	r1,%:live,%0
	and	r1,%0,r1 #commentaire

live:	live	%1
	zjmp	%:live

arriere:
#comm
