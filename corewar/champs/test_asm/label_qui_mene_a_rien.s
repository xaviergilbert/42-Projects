.name "zork"
.comment "just a basic living prog"
		
l2:	sti	r1,%:livee,%0
	and	r1,%0,r1 #commentaire

live:	live	%1
	zjmp	%:live

arriere:
#comm
