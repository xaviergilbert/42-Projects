.name "notre champ"
.comment ""

		sti r1, %:live, %1
l2:		fork %:l2

live:	live %1
		zjmp %:live
