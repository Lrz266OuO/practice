num=int(input('Please input your number: '))
count=num//2
while count>1:
    if num%count==0:
        print('%d can be divided completely by %d'%(num,count))
        break
    count-=1
else:
    print('%d is prime number'%num)
