.name "zork"
.comment "just a basic living prog"
		
l2:	sti	r3,%6,2
	and	r6,%:l2,r7
live:	live	%1
	zjmp	%:live
l3:	sti	r3,%6,2
	and	r6,%:l3,r7
live1:	live	%1
	zjmp	%:live1
l4:	sti	r3,%6,2
	and	r6,%:l4,r7
live4:	live	%1
	zjmp	%:live4
l5:	sti	r3,%6,2
	and	r6,%:l5,r7
live5:	live	%1
	zjmp	%:live5
