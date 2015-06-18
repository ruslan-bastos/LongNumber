
import LongNumberClass
import sys
import os

if len(sys.argv) < 5 :
    print "Error: Too few arguments. <first_long_number_filename> [ + | - | * | / | % | ^ ] <second_long_number_filename> <result_long_number_filename>"
    sys.exit(0)

if len(sys.argv) > 7 :
    print "Error: Too many arguments. <first_long_number_filename> [ + | - | * | / | % | ^ ] <second_long_number_filename> <result_long_number_filename> <module_long_number_filename> <-b>"
    sys.exit(0)

if not os.path.exists(sys.argv[1]):
    print "Error: Unable to open file: ", sys.argv[1]
    sys.exit(0)

if ((len(sys.argv[2]) > 1 or sys.argv[2][0] == '\0') or sys.argv[2][0] != '+' and sys.argv[2][0] != '-' and sys.argv[2][0] != '*' and sys.argv[2][0] != '/' and sys.argv[2][0] != '%' and sys.argv[2][0] != '^') :
    print "Error: Wrong operation: ", sys.argv[2][0]
    sys.exit(0)   

if not os.path.isfile(sys.argv[3]) :
    print "Error: Unable to open file: ", sys.argv[3]
    sys.exit(0)

if not os.path.isfile(sys.argv[4]) :
    print "Error: Unable to open file: ", sys.argv[4]
    sys.exit(0)

bin = 0

if len(sys.argv) == 5 :
    if sys.argv[2][0] == '^' :
        print "Error: Input module file"
        sys.exit(0)

if len(sys.argv) == 6 :
    if sys.argv[2][0] == '^' :
	if not os.path.isfile(sys.argv[5]) :
	    print "Error: Unable to open file: ", sys.argv[5]
	    sys.exit(0)
    else :
        if sys.argv[5] != "-b" : 
	    print "Error: Invalid flag: ", sys.argv[5]
	    sys.exit(0)
	    
	bin = 1

if len(sys.argv) == 7 : 
    if not os.path.isfile(sys.argv[5]) :
        print "Error: Unable to open file: ", sys.argv[5]
	sys.exit(0)

    if sys.argv[6] != "-b" :
        print "Error: Invalid flag: ", sys.argv[6]
        sys.exit(0)

    bin = 1

   

a = LongNumberClass.LongNumberClass()

b = LongNumberClass.LongNumberClass()

if bin == 1 :
    a.ReadBin(sys.argv[1])
else :
    a.ReadText(sys.argv[1])
    
if bin == 1 :
    b.ReadBin(sys.argv[3])
else :
    b.ReadText(sys.argv[3])
    
result = LongNumberClass.LongNumberClass()
    

if sys.argv[2][0] == '+' :
    result = a + b


if sys.argv[2][0] == '-' :
    result = a - b

if sys.argv[2][0] == '*' :
    result = a * b

if sys.argv[2][0] == '/' :
    result = a / b

if sys.argv[2][0] == '%' :
    result = a % b
    
if sys.argv[2][0] == '^' :
    c = LongNumberClass.LongNumberClass()
    if bin == 1 :
	c.ReadBin(sys.argv[5])
    else :
	c.ReadText(sys.argv[5])

    result = LongNumberClass.PowMod(a, b, c)
  
if bin == 1 :
    result.WriteBin(sys.argv[4])
else :
    result.WriteText(sys.argv[4])
