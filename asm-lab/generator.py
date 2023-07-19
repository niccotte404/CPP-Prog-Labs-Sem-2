from random import randint
array = [randint(-2147483648, 2147483647) for i in range(randint(500, 1000))]
file = open("elements.txt", "+a")
for i in array:
    file.write(str(i) + "\n")