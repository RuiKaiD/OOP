def increment(i):
        
	print("i = "+str(i))
	increment(i+1)


def main():
	increment(10000)

main()
