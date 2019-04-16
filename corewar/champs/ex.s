.name "zorkex"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %0
		and r16, %1, r1

live:	live %54
		zjmp %:live
