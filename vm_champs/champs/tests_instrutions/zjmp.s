.name "zjmp!"
.comment "Test de l'instruction Jump en avant et en arriere"


ping: 
	live %42
	and r1, r2, r3
	zjmp %-11
