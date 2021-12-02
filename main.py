# %%
import pandas as pd
import numpy as np
from sklearn.metrics import r2_score
import math
import matplotlib.pyplot as plt
import algorithms as algo

# %%
X_AXIS = 'time'
Y_AXIS = 'velocity'

# %%
#loading excel to dataframe
df = pd.read_excel('raw data\stage2 raw.xlsx')
x = df[X_AXIS].to_numpy()
y = df[Y_AXIS].to_numpy()

x_sample_one = x[::math.ceil(len(df)/500)].copy()
y_sample_one = y[::math.ceil(len(df)/500)].copy()

x_sample_two = x[::math.ceil(len(df)/1000)].copy()
y_sample_two = y[::math.ceil(len(df)/1000)].copy()

x_sample_three = x[0:500].copy()
y_sample_three = y[0:500].copy()
# x_sample_three = x.copy()
# y_sample_three = y.copy()

# %%
quadratic_coeffs_one = algo.quadratic_least_squares_approx(x_sample_one, y_sample_one)
quadratic_coeffs_two = algo.quadratic_least_squares_approx(x_sample_two, y_sample_two)
quadratic_coeffs_three = algo.quadratic_least_squares_approx(x_sample_three, y_sample_three)

cubic_coeffs_one = algo.cubic_least_squares_approx(x_sample_one, y_sample_one)
cubic_coeffs_two = algo.cubic_least_squares_approx(x_sample_two, y_sample_two)
cubic_coeffs_three = algo.cubic_least_squares_approx(x_sample_three, y_sample_three)

# %%
qy1 = algo.generate_points_from_line(quadratic_coeffs_one, x)
qy2 = algo.generate_points_from_line(quadratic_coeffs_two, x)
qy3 = algo.generate_points_from_line(quadratic_coeffs_three, x)

cy1 = algo.generate_points_from_line(cubic_coeffs_one, x)
cy2 = algo.generate_points_from_line(cubic_coeffs_two, x)
cy3 = algo.generate_points_from_line(cubic_coeffs_three, x)

qr1 = r2_score(y, qy1)
qr2 = r2_score(y, qy2)
qr3 = r2_score(y, qy3)

cr1 = r2_score(y, cy1)
cr2 = r2_score(y, cy2)
cr3 = r2_score(y, cy3)

# %%
plt.plot(x, y, color='green', label='Original')

plt.plot(x, qy1, color='black', label=f'Quad Fit 1 , r\u00b2 = {qr1}')
plt.plot(x, qy2, color='blue', label=f'Quad Fit 2 , r\u00b2 = {qr2}')
plt.plot(x, qy3, color='red', label=f'Quad Fit 3 , r\u00b2 = {qr3}')

plt.legend(loc='lower right')
plt.title(f'Quadratic Fit')
plt.xlabel(X_AXIS + ' [s]')
plt.ylabel(Y_AXIS + ' [km]')
plt.show()

# %%
plt.plot(x, y, color='green', label='Original')

plt.plot(x, cy1, color='black', label=f'Cubic Fit 1 , r\u00b2 = {cr1}')
plt.plot(x, cy2, color='blue', label=f'Cubic Fit 2 , r\u00b2 = {cr2}')
plt.plot(x, cy3, color='red', label=f'Cubic Fit 3 , r\u00b2 = {cr3}')

plt.legend(loc='lower right')
plt.title(f'Cubic Fit')
plt.xlabel(X_AXIS + ' [s]')
plt.ylabel(Y_AXIS + ' [km]')
plt.show()

# %%
print(len(x_sample_one))
print(len(x_sample_two))
print(len(x_sample_three))

# %%
