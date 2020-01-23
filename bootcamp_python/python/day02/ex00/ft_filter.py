def ft_filter(function_to_apply, list_of_inputs):
   ret = []
   for element in list_of_inputs:
      ret.append(element) if function_to_apply(element)
   return (ret)