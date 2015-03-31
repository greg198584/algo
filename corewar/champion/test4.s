.name "test4"
.comment "je test juste"

lasertop:
	live	%-42
	ld		%-128, r6
	fork	%:lasera
	ld		%190056198, r7
	ld		%0, r5
	ld		%0, r16
	zjmp	%:laser

lasera:
	ld      %84541307, r7
	ld      %4, r5
	ld		%190056198, r16
dec1:
	st      r16, 491
dec2:
	st      r7, 490
laser:
	ld		%0, r2
	zjmp	%470

