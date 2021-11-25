#algorithms
import pandas as pd
import numpy as np
import math

ERR_THRESHOLD = 0.1

def linear_least_squares_approx(xvalues, yvalues):
    sum_x = 0
    sum_y = 0
    sum_x_squared = 0
    sum_xy = 0
    m = len(xvalues)
    
    for i in range(m):
        sum_x += xvalues[i]
        sum_y += yvalues[i]
        sum_x_squared += xvalues[i] * xvalues[i]
        sum_xy = xvalues[i] * yvalues[i]
    
    a_0 = (sum_x_squared*sum_y - sum_xy*sum_x) / (m*sum_x_squared - sum_x*sum_x)
    a_1 = (m*sum_xy - sum_x*sum_y) / (m*sum_x_squared - sum_x*sum_x)

    check_one = abs(a_0*m + a_1*sum_x - sum_y) < ERR_THRESHOLD
    check_two = abs(a_0*sum_x + a_1*sum_x_squared - sum_xy) < ERR_THRESHOLD

    print(f'm: {m}, a_0: {a_0}, a_1: {a_1}, sum_x: {sum_x}, sum_y: {sum_y}, sum_x^2: {sum_x_squared}, sum_xy: {sum_xy}')

    if not check_one or not check_two:
        print('checks failed')

    #plugging into equation
    coeffs = np.array([a_0, a_1])
    return coeffs

def quadratic_least_squares_approx(xvalues, yvalues):
    c1 = np.zeros((5,1))
    c2 = np.zeros((5,1))
    m = len(xvalues)

    for k in range (5):
        temp_sum_x_power_k = 0
        temp_sum_yx_power_k = 0
        for i in range(m):
            temp_sum_x_power_k += xvalues[i] ** k
            temp_sum_yx_power_k += yvalues[i] * (xvalues[i] ** k)
        c1[k] = temp_sum_x_power_k
        c2[k] = temp_sum_yx_power_k
    
    matrix_a = np.empty((3,3))
    matrix_a[0] = ([c1[0], c1[1], c1[2]])
    matrix_a[1] = ([c1[1], c1[2], c1[3]])
    matrix_a[2] = ([c1[2], c1[3], c1[4]])
    matrix_b = np.array([c2[0], c2[1], c2[2]])

    solution_vector = np.linalg.solve(matrix_a, matrix_b)
    return solution_vector

def cubic_least_squares_approx(xvalues, yvalues):
    c1 = np.zeros((7,1))
    c2 = np.zeros((7,1))
    m = len(xvalues)

    for k in range (7):
        temp_sum_x_power_k = 0
        temp_sum_yx_power_k = 0
        for i in range(m):
            temp_sum_x_power_k += xvalues[i] ** k
            temp_sum_yx_power_k += yvalues[i] * (xvalues[i] ** k)
        c1[k] = temp_sum_x_power_k
        c2[k] = temp_sum_yx_power_k
    
    matrix_a = np.empty((4,4))
    matrix_a[0] = ([c1[0], c1[1], c1[2], c1[3]])
    matrix_a[1] = ([c1[1], c1[2], c1[3], c1[4]])
    matrix_a[2] = ([c1[2], c1[3], c1[4], c1[5]])
    matrix_a[3] = ([c1[3], c1[4], c1[5], c1[6]])
    matrix_b = np.array([c2[0], c2[1], c2[2], c2[3]])

    solution_vector = np.linalg.solve(matrix_a, matrix_b)
    return solution_vector

def plug_points(coeffs, xpoint):
    degree = len(coeffs)
    y_value = 0
    for i in range(degree):
        y_value += coeffs[i] * (xpoint ** i)
    return y_value

def average_error(y1, y2):
    m = len(y1)
    diff = np.absolute(np.array(y1) - np.array(y2))
    diff_sum = np.sum(diff)
    return diff_sum/m