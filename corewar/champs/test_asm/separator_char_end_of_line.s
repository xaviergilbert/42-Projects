.name ""
.comment ""


zjmp %:live

live %1

live %1
live %1
#live %1
#live %1

live:

#xor 545, 9223372036854775808, r2

live %4294967295



sti r1,r2         , r6					
live %1,
live %1






live %4294967295
live %2147483648

#sti r1, 54, 
zjmp %:live

live %1




