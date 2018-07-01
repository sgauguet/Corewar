.name "sti!"
.comment "Test de l'instruction sti avec direct et indirect"

live:
	live %42
go: 
	sti r1, :live, %5
	sti r1, :zjmp, :live

zjmp: 
	zjmp %25
