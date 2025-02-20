import matplotlib.pyplot as plt


d = open('data.csv', 'r')
t = []
v = []
for i in d.readlines():
    if i != '\n':
        t.append(float(i.split()[0]))
        v.append(float(i.split()[1]))

plt.plot(t, v)
plt.grid()
plt.xlabel('Время, c')
plt.ylabel('Напряяжение, В')
plt.show()