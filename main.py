import pandas as pd
import numpy as np
import math
import matplotlib.pyplot as plt

import algorithms as algo

#loading excel to dataframe
df = pd.read_excel('stage2raw.xlsx')

x = df['time']
y = df['velocity']

x = x.to_numpy()
y = y.to_numpy()

xpoint = 3
# print(algo.linear_least_squares_approx(x, y, xpoint))
linear_coeffs = algo.linear_least_squares_approx(x, y)
qudratic_coeffs = algo.quadratic_least_squares_approx(x, y)
cubic_coeffs = algo.cubic_least_squares_approx(x, y)

TEST_RUNS = 538
x_test = np.zeros(shape=(TEST_RUNS,1))
y_test = np.zeros(shape=(TEST_RUNS,1))

#linear
lx = x_test
ly = y_test
for i in range(TEST_RUNS):
    lx[i] = i
    ly[i] = algo.plug_points(linear_coeffs, i)
plt.plot(lx, ly, color='blue')
# print(f'linear average error: {algo.average_error(ly, y)}')

#quadratic
qx = x_test
qy = y_test
for i in range(TEST_RUNS):
    qx[i] = i
    qy[i] = algo.plug_points(qudratic_coeffs, i)
plt.plot(qx, qy, color='red')
# print(f'quadratic average error: {algo.average_error(qy, y)}')

#cubic
cx = x_test
cy = y_test
for i in range(TEST_RUNS):
    cx[i] = i
    cy[i] = algo.plug_points(cubic_coeffs, i)
plt.plot(cx, cy, color='black')
# print(f'cubic average error: {algo.average_error(cy, y)}')

plt.plot(x, y, color='green')
plt.show()

