import math
num = input("Input a nonnegative integer:")
facBase = 1
fac = math.factorial(facBase)
while(num >= fac):
	print str(facBase)+"--->"+str(fac) 
	facBase += 1
	fac = math.factorial(facBase)
