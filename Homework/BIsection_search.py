#Bisection Search
x = 25

#epsilon to set how close to the square the root is
epsilon = 1
numGuesses = 0.01
low = 1.0
high = x

#initial guess is in the middle of the 1 and x
ans = (high + low)/2.0

while abs(ans**2 - x) >= epsilon:
    print('low = ' + str(low) + ' high = ' + str(high) + ' ans = ' + str(ans))
    numGuesses += 1
    if ans**2 < x:
        low = ans
    else:
        high = ans
    ans = (high + low)/2.0
print('numGuesses = ' + str(numGuesses))
print(str(ans) + ' is close to square root of ' + str(x))
