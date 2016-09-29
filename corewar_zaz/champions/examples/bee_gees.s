.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
sti	r1, %:live, %1			;change live by the right value
sti	r1, %:live2, %1			;change live by the right value
sti r1, %:sti, %1
ld	%1, r3
ld	%33, r6
#While (r2 < 10)
sti:
add	r2, r3, r2
sti:
add	r2, r3, r2
forks:
add	r2, r3, r2		;increment r2
xor	r2, %15, r4		;if (r4) {carry = 0}
sti r1, %:sti, %1
live2:
	live 	%4
zjmp	%:endwhile		;if (carry)
fork	%:forks
ld	%0, r4			;carry = 1
zjmp	%:forks
#EndWhile

endwhile:
ld	%0, r4			;carry = 1

live:
live %4
zjmp %:live


#magic code 00ea 83f3
#
#0b 68 01 00 45 00 01
#0b 68 01 00 22 00 01
#02 90 00 00 00 01 03
#02 90 00 00 00 21 06


#04 54 02 03 02

#08 64 02 00 00 00 0f 04

#01    00 00 00 04
#09    00 10
#0c    ff eb
#02 90 00 00 00 00 04
#09    ff e1

#02 90 00 00 00 00 04

#01    00 00 00 04
#09    fffb

#0b68 0100 5600 01
#0b 6801 0033 0001 
#0b 6801 0015 0001
#02 90 00 0000 0103
#02 90 00 0000 2106
#04 54 02 0302
#04 54 02 0302
#04 54 02 0302
#08 64 02 0000 00 0f04
#0100 0000 0409
#0010 0cff eb02 9000 0000 0004 09ff e102
#9000 0000 0004 0100 0000 0409 fffb 