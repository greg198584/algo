.name "test"
.comment "je test juste"

#ld	%65, r2
#fork	%:cc_spawn

#cc_spawn:
#	live	%10
#	fork	%:cc_spawn


#live	%10
#live	%100
#live	%-10
#live	%-500
#live	%-2
#live	%-200
#live	%456589

#and		r2, r1, r3
#and		%10, r1, r4
#and		10, r1, r5
#and		r2, %10, r6
#and		r2, 10, r7
#and		10, %20, r8
#and		%10, 20, r9
#and		%10, %10, r10
#and		%300, %500, r12
#and		%-300, %-500, r12
#and		30, 30, r13
#and		-300, -500, r13
#and		%-299, 20, r9
#and		-300, %500, r10
#and		300, %-500, r11

ld		%4294902016, r2
	ld		%436432899, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:choochoo

choochoo:
	st		r2, 15
	st		r3, -1


#or		r2, r1, r3
#or		%10, r1, r4
#or		10, r1, r5
#or		r2, %10, r6
#or		r2, 10, r7
#or		10, %20, r8
#or		%10, 20, r9
#or		%10, %10, r10
#or		%300, %500, r12
#or		%-300, %-500, r12
#or		30, 30, r13
#or		-300, -500, r13
#or		%-299, 20, r9
#or		-300, %500, r10
#or		300, %-500, r11

#xor		r2, r1, r3
#xor		%10, r1, r4
#xor		10, r1, r5
#xor		r2, %10, r6
#xor		r2, 10, r7
#xor		10, %20, r8
#xor		%10, 20, r9
#xor		%10, %10, r10
#xor		%300, %500, r12
#xor		%-300, %-500, r12
#xor		30, 30, r13
#xor		-300, -500, r13
#xor		%-299, 20, r9
#xor		-300, %500, r10
#xor		300, %-500, r11

#ld %200, r4
#ld 500, r5
#ld -300, r6
#ld	%2, r1
#ld	%3, r2
#ld	%6, r10
#ldi	r1, r3, r7
#ldi	%4, r1, r5
#ldi	5, r1, r6
#ldi	r1, %6, r7
#ldi	%2, %6, r8
#ldi	2, %5, r9

#ldi	%400, r1, r3
#ldi	200, r1, r4
#ldi	r1, %300, r5
#ldi	r1, %-300, r5
#ldi	%500, %400, r6
#ldi	%-500, %-400, r6
#ldi	20, %-10, r7

#live:
#live %1

#sti		r4, %:live, %10
#sti		r7, %:live, r1

#ld		%66, r10
#ld		%42, r2
#sti		r10, r1, r2
#sti		r2, 10, %10
#sti		r2, %20, %100
#sti		r2, -10, r1
#sti		r2, %200, r1
#sti		r2, -10, %500
#sti		r2, -500, %-20
#sti		r10, %-200, r2
#sti		r10, r2, %-200
#sti		r2, -300, r1

#lld %99, r9
#lld %-100, r5
#lld 200, r3
#lld 500, r4
