.name "blabla"
.comment "Commentaire"


live: 
	live %42

lld %11, r1
st r1, :live
and r1, r2, r3
zjmp %:live
