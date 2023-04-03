def add_integer(a, b=98):
    # check if both inputs are integers or floats
    if not isinstance(a, (int, float)) or not isinstance(b, (int, float)):
        raise TypeError("a and b must be integers or floats")
    
    # cast a and b to integers if they are floats
    a = int(a) if isinstance(a, float) else a
    b = int(b) if isinstance(b, float) else b
    
    # add a and b and return the result
    return a + b

