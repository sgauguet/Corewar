.name "st!"
.comment "Test de l'instruction st avec direct et indirect"

live:
	live %42
go: 
	st r1, :live
	st r1, :zjmp

zjmp: 
	zjmp %25
