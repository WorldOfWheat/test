' {$STAMP BS2}
' {$PBASIC 2.5}

i VAR Word

DIRL = %11111111

DO
  FOR i = 1 TO 64 STEP 0
    OUTL = i
    i = i * 2
    PAUSE 100
  NEXT

  FOR i = 64 TO 1 STEP 0
    OUTL = i
    i = i / 2
    PAUSE 100
  NEXT
LOOP
