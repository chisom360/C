    
    
low = 0
high = 100
#epsilon = 0.1
check = ''

#initial guess is in the middle of 0 and 100
ans = (high + low)//2

print("Please think of a number between 0 and 100! ")

while check != 'c':
    print('Is your secret number ' + str(ans)+ '?')
    check = input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")
    if check == 'h':
        high = ans
    elif check == 'l':
        low = ans
    elif check == 'c':
        print('Game over. Your secret number is: ' + str(ans))
    else:
        print('still not found')
    ans = (high + low)//2
