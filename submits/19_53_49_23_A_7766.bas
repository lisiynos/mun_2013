	OPEN "abt.in" FOR INPUT AS #1
	OPEN "abt.out" FOR OUTPUT AS #2
	DIM n
	INPUT #1, n	       
	DIM a, b, i, z, en
	DIM mas(n):	z = 1
	IF n > 1000000000 THEN GOTO 146
	IF n < 1 THEN GOTO 146
	FOR i = 1 TO n
	    a = i:	    b = a + 1
	    IF a * b = n THEN
		mas(z) = a
		z = z + 1
	    END IF	NEXT i
	FOR i = 1 TO z
	    IF mas(i) > mas(i - 1) THEN en = mas(i) ELSE en = mas(i - 1)
	NEXT i
	IF en * (en + 1) <> n THEN GOTO 146
	PRINT #2, en + 1, en
	END
146 :
	PRINT #2, "-1 -1"
	END
