.name "zork"
.comment "just a basic living prog"
l2:
sti r1,%:live,%1
and r1,%3,r1
and r1,%-3,r1
and r1,%45,r1
and r1,%-45,r1
live:
live %1
zjmp %:l2
