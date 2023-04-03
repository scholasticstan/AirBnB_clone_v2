def matrix_divided(matrix, div):
    # Check if matrix is a list of lists of integers or floats
    if not all(isinstance(row, list) and all(isinstance(x, (int, float)) for x in row) for row in matrix):
        raise TypeError("matrix must be a matrix (list of lists) of integers/floats")
    
    # Check if each row of the matrix has the same size
    row_lengths = [len(row) for row in matrix]
    if not all(length == row_lengths[0] for length in row_lengths):
        raise TypeError("Each row of the matrix must have the same size")
    
    # Check if div is a number (integer or float) and not zero
    if not isinstance(div, (int, float)):
        raise TypeError("div must be a number")
    if div == 0:
        raise ZeroDivisionError("division by zero")
    
    # Divide all elements of the matrix by div, rounded to 2 decimal places
    new_matrix = [[round(x / div, 2) for x in row] for row in matrix]
    
    # Return the new matrix
    return new_matrix

