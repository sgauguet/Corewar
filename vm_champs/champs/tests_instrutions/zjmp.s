.name "zjmp!"
.comment "Test de l'instruction Jump en avant et en arriere"

ping:
	lld %-112685, r3
	aff r3
	fork %:pong
	live %1
	live %2 
	live %3
	live %4
	live %5
	st r1, :pong
	zjmp %:ping

pong:
	sti r1, %20, %20
	zjmp %:pong
