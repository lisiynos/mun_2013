 CLS :  OPEN "dorf.in" FOR INPUT AS #1
        OPEN "dorf.out" FOR OUTPUT AS #2
            INPUT #1, n, t
            DIM mas(n), pis(n), mas1(n)
            FOR i = 1 TO n
                INPUT #1, mas(i)  ''luchshij
                mas1(i) = i
                pis(i) = 1
            NEXT i
            '''''''''''''''''
            FOR i = 1 TO t
                FOR j = 1 TO n
                    IF mas1(i) = mas(j) THEN
                         pis(i) = pis(i) + 1
                         pis(j) = pis(j) - 1
                    END IF
                NEXT j
            NEXT i
           
FOR i = 1 TO n
     PRINT #2, pis(i)
NEXT i
END
