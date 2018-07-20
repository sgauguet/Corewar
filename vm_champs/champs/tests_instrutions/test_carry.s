.name "test carry"
.comment "tests carry"

## carry -> 0 
	zjmp %486451553184

## carry reste -> 0 
	live %-1
	zjmp %-2115318541531183415552451

## carry -> 1
	ld %0, r5
	zjmp %3

## carry reste -> 1
	st r1, r8
	zjmp %3
	st r2, 300
	zjmp %3
	st r0, 155
	zjmp %3

## carry -> 0
	ld %42, r3
	zjmp %3
	live %-1
	zjmp %3

## carry reste -> 0
	and r1, r3, r4
	zjmp %3
	and r3, r4, r5
	zjmp %3
	or r3, r4, r6
	zjmp %3
	zor r3, r4, r7
	zjmp %3
	zor r3, r4, r8
	zjmp %3
	zor r3, r4, r9
	zjmp %3
	
## carry -> 1
	ld %0, r5
	zjmp %3
	and r1, r3, r4
	zjmp %3
	st r4, 1000
	zjmp %3


ld %1534152, r6
zjmp %3
and r3, r6, r7
zjmp %3
st r7, 1000
zjmp %3


ld %-1515102, r8
zjmp %3
and r7, r8, r9
zjmp %3
st r9, 1000
zjmp %3

sti r2, r3, r4
zjmp %3
sti r21, r3, r4
zjmp %3
sti r2, r32, r4
zjmp %3
sti r2, r3, r41
zjmp %3
lfork %-1513854841512
