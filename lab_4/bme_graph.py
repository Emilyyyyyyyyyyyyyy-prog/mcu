import matplotlib.pyplot as plt


hum = open('data_hum.csv', 'r')
t1 = []
h = []
for i in hum.readlines():
    if i != '\n':
        t1.append(float(i.split()[0]))
        h.append(float(i.split()[1]))
pres = open('data_pres.csv', 'r')
t2 = []
p = []
for i in pres.readlines():
    if i != '\n':
        t2.append(float(i.split()[0]))
        p.append(float(i.split()[1]))
temp = open('data_temp.csv', 'r')
t3 = []
tm = []
for i in temp.readlines():
    if i != '\n':
        t3.append(float(i.split()[0]))
        tm.append(float(i.split()[1]))

fig, ax = plt.subplots(3, 1)

ax[0].plot(t1, h)
ax[0].grid()
ax[0].set_xlabel('Время, c')
ax[0].set_ylabel('Влажность, %')

ax[1].plot(t2, p)
ax[1].grid()
ax[1].set_xlabel('Время, c')
ax[1].set_ylabel('Давление,Па')

ax[2].plot(t1, tm)
ax[2].grid()
ax[2].set_xlabel('Время, c')
ax[2].set_ylabel('Температура, С')

plt.show()