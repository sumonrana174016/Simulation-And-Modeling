from matplotlib import pyplot as plt
import random

test = 1
for i in range(1,100):
    a = random.randint(1,1000)
    b = random.randint(1,1000)
    c = random.randint(1,1000)
    d = random.randint(1,1000)

    p = (a-c)/(b+d)

    q = a - b*p
    s = c + d*p

    if q == s:
        print("Equilibrium point is.")
        print("Q : ",q)
        print("S : ",s)
        print("P : ",p)

        test = 0
        break
if test == 1:
    print("There is no equilibrium point.")

x = [0 , 2.0*q-0]
y = [0 , 2.0*p-0]
x1 = [0 , 2.0*q-0]
y1 = [.5 , 2.0*p-0.5]

plt.plot(x,y,color = 'red')
plt.plot(x1,y1,color = 'green')
plt.title('$Simple Market Analysis$')
plt.xlabel('$Quantity$')
plt.ylabel('$Price$')
plt.show()
