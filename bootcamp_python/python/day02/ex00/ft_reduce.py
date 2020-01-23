def ft_reduce(function_to_apply, list_of_inputs):
    i = 1
    ret = list_of_inputs[0]
    while i > 0 and i < len(list_of_inputs):
        ret = function_to_apply(ret, list_of_inputs[i])
        i += 1
    return ret


def add(x, y):
    return x + y
def concat(x, y):
    return x + y
lst = [2,5, 5, 2, 10]
lst2 = ['paff', 'boom', 'lol']
print(ft_reduce(add, lst2))