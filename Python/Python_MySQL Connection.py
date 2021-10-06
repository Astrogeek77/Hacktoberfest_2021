import mysql.connector as a
import tabulate as t

def Connect():
    x = a.connect(host="localhost",user = "root",passwd='',database='AR')
    return x


def show(x):
    print("Python Successfully connected to the database")
    c = x.cursor()
    c.execute('select * from student')
    f = [('  Name  ','  Class  ','  Roll No.  ')]
    for i in c:
        f.append(i)
    print(t.tabulate(f, headers="firstrow",tablefmt="pretty"))

def ins(x):
    print("Python Successfully connected to the database")
    c = x.cursor()
    p = 1
    l = []
    while p == 1:
        n = input("Enter Name:")
        m = input('Enter Roll Number:')
        b = input('Enter Class')
        t = (n,b,m)
        l.append(t)
        p = int(input('To enter more record press 1 else press 0:'))
        s = "INSERT INTO Student VALUES (%s, %s, %s)"
    c.executemany(s, l)
    x.commit()
    print(c.rowcount, "records successfully inserted \n")

def run():
    try:
        x = Connect()
        if x.is_connected():
            ins(x)
            d = int(input('To view the final Data press 1 else press 0:'))
            print('\n\n')
            if d == 1:
                show(x)
            else:
                exit(0)
        else:
            print('Access to the database is denied.Please Check the connection')
    except:
        print('Please Check the connection')


#Drive Code

run()
