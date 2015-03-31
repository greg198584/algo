.name "test"
.comment "je test juste"


#begin:

ld		%190056194, r8
ld		%134807571, r9
st		r8, 2001
st		r9, 2000

#ld	%1, r3
#add	r2, r3, r2		;increment r2
#xor	r2, %15, r4		;if (r4) {carry = 0}

#ld		%0, r8
#st		r2, 600
#add		r1, r8, r2
#sub		r1, r8, r2
#and		r1, r8, r2
#or		r1, r8, r2
#xor		r1, r8, r2i
#ldi		r1, r8, r2
#sti		r2, %:live, %10
#lld		%65, r10
#lldi	%65, r11, r12
#fork	%:live
#lfork	%:live
#ld		%65, r11
#aff		r11
#live	%-1
#zjmp	%:begin
#live	%-1
