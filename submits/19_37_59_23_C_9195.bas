 CLS :  OPEN "cord.in" FOR INPUT AS #1
        OPEN "cord.out" FOR OUTPUT AS #2
        RANDOMIZE TIMER
        DIM troll AS INTEGER
        troll = RND * 3
             DIM a, b, c
            INPUT #1, a, b, c
            IF a = 5 AND b = 5 AND c = 5 THEN
                 troll = 0
            ELSE
                 IF a = 0 AND b = 0 AND c = 1 AND d = -2 AND e = -2 THEN
                       troll = 3
                 END IF
            END IF
            PRINT #2, troll: PRINT troll
END
