.name "zjmp!"
.comment "Test de l'instruction Jump en avant et en arriere"


	lldi r5, %8888845, r3
	lldi r4, %542, r7
	lldi r5, r7, r3
	lldi r4, r2, r7

	lldi %0, %6888888824245548888845, r2
	lldi 3240, %6888888824245548888845, r2


	lldi %0, r5, r2
	lldi 3240, r6, r2

