.name "caca"
.comment "prout"

l1:		sti	r1, %:live,	%1
		ld	%42, r2
		ld %10, r1
		sti	r1, %:attack, %1
		sti	r1, %:protected, %1
		sti	r1, %:attack2, %1
live:
		live	%1
#		zjmp	%:attack
#		fork	%:live

attack:
		ld %12, r11
		ld	%10, r1
		ld	10, r11
		st	r10, r11
		st	r2, 400
		st	r2, 400
		add	r1, r2, r2
#		#zjmp	%:protected
		sub		r2, r1, r2
		lfork	%:attack

protected:
		st		r2, -500
		st		r2, -500
		or		r2, r1, r2

#		zjmp	%:attack2
		xor		r2, r1, r2
#		fork	%:protected
		
attack2:
		xor		r2, r1, r2
		ldi		r2, %42, r1
		lld		42, r3
		aff		r3
#		zjmp	%:live
		lld		%12, r4
		lld		12, r5
		ld		%24, r5
		ld		%78, r6
		ld		%63, r7
		ld		%45, r8
		ld		%14, r9
		ld	%267, r12
#		fork	%:attack2
#		sti		r10, r1, r2
#		sti		r4, %:live, %10
#		sti		r5, 10, %10
#		sti		r6, %20, %10
#		sti		r7, %:live, r1
#		sti		r8, 10, r1
#		sti		r9, %20, r1
#		lldi	r1, r3, r2
#		lldi	%40, r1, r3
#		lldi	20, r1, r4
#		lldi	r1, %10, r5
#		lldi	%40, %10, r6
#		lldi	20, %10, r7
#		or	r2, r1, r3
#		or	%10, r1, r4
#		or	10, r1, r5
#		or	r2, %10, r6
#		or	r2, 10, r7
#		or	10, %20, r8
#		or	%10, 20, r9
#		or	%10, %10, r10
#		or	%300, %300, r12
#		or	30, 30, r13
#		or	300, 300, r14
#		xor	r2, r1, r3
#		xor	%10, r1, r4
#		xor	10, r1, r5
#		xor	r2, %10, r6
#		xor	r2, 10, r7
#		xor	10, %20, r8
#		xor	%10, 20, r9
#		xor	%10, %10, r10
#		xor	%300, %300, r12
#		xor	30, 30, r13
###		xor	300, 300, r14
