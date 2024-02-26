import random
import sys

if len(sys.argv) == 1:
	exit()
for x in range(1, int(sys.argv[1])):
	print(random.choice(range(-2147483648, 2147483647)), end=' ')
