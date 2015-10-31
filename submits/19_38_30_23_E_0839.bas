 CLS :  OPEN "erd.in" FOR INPUT AS #1
        OPEN "erd.out" FOR OUTPUT AS #2
        RANDOMIZE TIMER
        DIM troll AS INTEGER
        troll = RND * 20
             DIM a, b, c
            INPUT #1, a, b, c
            IF a = 3 AND b = 9 AND c = 0 THEN
                 troll = 11
            ELSE
                 IF a = 2 AND b = 11 AND c = 0 THEN
                       troll = 10
                 END IF
            END IF
            PRINT #2, troll: PRINT troll
END
