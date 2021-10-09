import random
answer=random.randint(1,10)
print('......lrznb......')
temp=input("Guess a number: ")
guess=int(temp)
while guess!=answer:
    if guess>answer:
        print("It's too large!")
    else:
        print("It's too small!")
    temp=input("Guess a number again: ")
    guess=int(temp)
print("Yeah! You are right!")
print("Bye!")