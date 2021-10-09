try:
    f=open('Whynot.txt')
    print(f.read())
    f.close()
except OSError:
    print('The data is error.')