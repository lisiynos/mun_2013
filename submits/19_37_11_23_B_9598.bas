        OPEN "berg.in" FOR INPUT AS #1
        OPEN "berg.out" FOR OUTPUT AS #2
        DIM i, z AS INTEGER
        DIM n AS STRING: DIM q  AS STRING
        z = 1
        DIM mas(100) AS STRING
        INPUT #1, n
        FOR i = 1 TO 100 STEP 2
            mas(z) = MID$(n, i, 1)
            z = z + 1
        NEXT i
        FOR i = 1 TO z
            q = q + mas(i)
        NEXT i
        IF MID$(q, 1, 1) = MID$(q, 2, 1) THEN
            IF MID$(q, 3, 1) = MID$(q, 2, 1) THEN
                IF MID$(q, 1, 1) = "a" THEN GOTO 146
            END IF
        END IF
        PRINT q
        PRINT #2, q

        END
146 :
        PRINT "Suspicious!"
        PRINT #2, "Suspicious!"
end
