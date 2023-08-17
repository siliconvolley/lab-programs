print('Enter 2 numbers: ')
num1 = int(input())
num2 = int(input())

def gcd (num1, num2):
    while(num2 != 0):
        rem = num1 % num2
        num1 = num2
        num2 = rem
    return num1

print('GCD of',num1,'&',num2,'is',gcd(num1, num2))