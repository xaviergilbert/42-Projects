import numpy as np

def mat_vec_prod(w, x):
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
    X = np.array([0, 15, -9, 7, 12, 3, -21]).reshape((7,1))
    Y = np.array([2, 14, -13, 5, 12, 4, -19]).reshape((7,1))
    tab = mat_vec_prod(W, X)
    print (tab)
    tab = mat_vec_prod(W, Y)
    print(tab)
    

if __name__ == "__main__":
    main()