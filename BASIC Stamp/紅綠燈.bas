' {$STAMP BS2}
' {$PBASIC 2.5}

' 7 6 5

wstep VAR Byte
pb10 VAR IN10

wstep = 0

DO

  IF (pb10 = 0) THEN
    PAUSE 10
    IF (wstep = 10) THEN
      LOW 1
      LOW 6
      wstep = 0
    ELSE
      LOW 0
      LOW 1
      LOW 2

      LOW 5
      LOW 6
      LOW 7
      wstep = 10
    ENDIF
  ENDIF

  IF (wstep = 0) THEN
    LOW 2
    HIGH 0
    HIGH 7

    PAUSE 3000
    wstep = 1
  ELSEIF (wstep = 1) THEN
    LOW 0
    '
    HIGH 1
    PAUSE 500

    LOW 1
    PAUSE 500

    HIGH 1
    PAUSE 500

    LOW 1
    PAUSE 500
    '
    wstep = 2
  ELSEIF (wstep = 2) THEN
    HIGH 2
    LOW 7
    HIGH 5

    PAUSE 3000
    wstep = 3
  ELSEIF (wstep = 3) THEN
    LOW 5
    '
    HIGH 6
    PAUSE 500

    LOW 6
    PAUSE 500

    HIGH 6
    PAUSE 500

    LOW 6
    PAUSE 500
    '
    wstep = 0
  ELSEIF (wstep = 10) THEN
    HIGH 1
    LOW 6

    PAUSE 1000

    LOW 1
    HIGH 6

    PAUSE 1000
  ENDIF
LOOP