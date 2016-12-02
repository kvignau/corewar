.name "Miky"
.comment "Blurblurblurblbublublubr"


	st r1, 6
coucou:
	live %1
	live %2
	live %3
	ld %1, r2
	ld %2, r3
	ld 2, r2
	st r2, 500
	st r3, r5
	add r2, r3, r6
	sub r6, r6, r7
	and r2, r3, r4
	and r2, %4, r4
	and r2, 4, r4
	and %4, r4, r5
	and %4, %5, r5
	and %4, 5, r5
	and 4, r4, r5
	and 4, %4, r5
	and 4, 2, r5
	or r2, r3, r4
	or r2, %4, r4
	or r2, 4, r4
	or %4, r4, r5
	or %4, %5, r5
	or %4, 5, r5
	or 4, r4, r5
	or 4, %4, r5
	or 4, 2, r5
	xor r2, r3, r4
	xor r2, %4, r4
	xor r2, 4, r4
	xor %4, r4, r5
	xor %4, %5, r5
	xor %4, 5, r5
	xor 4, r4, r5
	xor 4, %4, r5

	ldi r2, r3, r4
	ldi r2, %500, r4
	ldi 4, r3, r4
	ldi 4, %500, r4
	ldi %4, r3, r4
	ldi %4, %500, r4

	st r1, 6
	live %1

	ld %500, r4
	sti r2, r3, r4
	sti r2, r3, %500
	sti r2, %86, r4
	sti r2, %86, %500
	sti r2, 86, r4
	sti r2, 86, %500

	st r1, 6
	live %1

	fork %:coucou

	st r1, 6
	live %1

	lld %5, r4
	lld 5, r4

	lldi r2, r3, r4
	lldi r2, %1991, r4
	lldi %5, r3, r4
	lldi %5, %1991, r4
	lldi 5, r3, r4
	lldi 5, %1991, r4

	st r1, 6
	live %1

	lfork %:coucou

	st r1, 6
	live %1

	aff r1

	xor 0, 0, r5
	ld %0,r12
	zjmp %:coucou
