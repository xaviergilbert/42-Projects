.name "zorkex"
.comment "I'M ALIIIIVE"

l2:		sti r1, 00:live, %0
		and r1, %0, r1

live:	live %1
		zjmp %:live
