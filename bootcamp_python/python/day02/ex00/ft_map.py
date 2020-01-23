def ft_map(function_to_apply, list_of_inputs):
    ret = []
    for element in list_of_inputs:
        ret.append(function_to_apply(element))
    return ret