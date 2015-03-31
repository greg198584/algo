.name "caca"
.comment "prout"
	
attack:
	ld	%:live, r1
	st	r1, 500
	st	r1, 400
	ld	%65. r2
	aff r2

live:
	live	%1
	fork	%:live
	zjmp	%:live
