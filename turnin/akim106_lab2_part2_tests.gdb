
# Test file for Lab2_IntroToAVR
#
#
# # commands.gdb provides the following functions for ease:
# #   test "<message>"
# #       Where <message> is the message to print. Must call this at the beginning of every test
# #       Example: test "PINA: 0x00 => expect PORTC: 0x01"
# #   checkResult
# #       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
# #       Must call this at the end of every test.
# #   expectPORTx <val>
# #       With x as the port (A,B,C,D)
# #       The value the port is epected to have. If not it will print the erroneous actual value
# #   setPINx <val>
# #       With x as the port or pin (A,B,C,D)
# #       The value to set the pin to (can be decimal or hexidecimal
# #       Example: setPINA 0x01
# #   printPORTx f OR printPINx f 
# #       With x as the port or pin (A,B,C,D)
# #       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
# #       Example: printPORTC d
# #   printDDRx
# #       With x as the DDR (A,B,C,D)
# #       Example: printDDRB
#
 echo ======================================================\n
 echo Running all tests..."\n\n

# Add tests below

test "PINB: 0xFF => PORTC: 0x00"
setPINB 0xFF
continue 5
expectPORTC 0x00
checkResult

test "PINB: 0x00 => PORTC: 0x04"
setPINB 0x00
continue 5
expectPORTC 0x04
checkResult

test "PINB: 0x07 => PORTC: 0x03"
setPINB 0x07
continue 5
expectPORTC 0x03
checkResult

test "PINB: 0x09 => PORTC: 0x02"
setPINB 0x09
continue 5
expectPORTC 0x02
checkResult

test "PINB: 0x0B => PORTC: 0x01"
setPINB 0x0B
continue 5
expectPORTC 0x01
checkResult

test "PINB: 0x06 => PORTC: 0x02"
setPINB 0x06
continue 5
expect PORTC 0x02
checkResult

 set $passed=$tests-$failed
 eval "shell echo Passed %d/%d tests.\n",$passed,$tests
 echo ======================================================\n
