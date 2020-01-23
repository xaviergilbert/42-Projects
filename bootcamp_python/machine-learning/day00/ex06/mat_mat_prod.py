import numpy as np

def mat_mat_prod(x, w):
    tab = []
    f = lambda f, r : f * r
    for elem in w:
        tmp = 0
        for arg, arg1 in zip(elem, x):
            tmp += f(arg , arg1)
        tab.append(tmp)
    tab = np.array(tab)
    return tab

def main():
    W = np.array([
    [ -8, 8, -6, 14, 14, -9, -4],
    [ 2, -11, -2, -11, 14, -2, 14],
    [-13, -2, -5, 3, -8, -4, 13],
    [ 2, 13, -14, -15, -14, -15, 13],
    [ 2, -1, 12, 3, -7, -3, -6]])
    Z = np.array([
    [ -6, -1, -8, 7, -8],
        [ 7, 4, 0, -10, -10],
        [ 7, -13, 2, 2, -11],
        [ 3, 14, 7, 7, -4],
        [ -1, -3, -8, -4, -14],
        [ 9, -14, 9, 12, -7],
        [ -9, -4, -10, -3, 6]])
    tab1 = mat_mat_prod(W, Z)
    print(tab1)
    tab2 = mat_mat_prod(Z,W)
    print(tab2)
    

if __name__ == "__main__":
    main()