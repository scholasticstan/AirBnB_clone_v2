import numpy as np

def lazy_matrix_mul(m_a, m_b):
    if not isinstance(m_a, list) or not isinstance(m_b, list):
        raise TypeError("m_a and m_b must be a list")
    if not all(isinstance(lst, list) for lst in m_a) or not all(isinstance(lst, list) for lst in m_b):
        raise TypeError("m_a and m_b must be a list of lists")
    if m_a == [] or m_b == []:
        raise ValueError("m_a and m_b can't be empty")
    if not all(isinstance(num, (int, float)) for lst in m_a for num in lst) \
    or not all(isinstance(num, (int, float)) for lst in m_b for num in lst):
        raise TypeError("m_a and m_b should contain only integers or floats")
    if not all(len(m_a[0]) == len(lst) for lst in m_a) or not all(len(m_b[0]) == len(lst) for lst in m_b):
        raise ValueError("each row of m_a and m_b must be of the same size")
    if len(m_a[0]) != len(m_b):
        raise ValueError("m_a and m_b can't be multiplied")
    m_a = np.array(m_a)
    m_b = np.array(m_b)
    return m_a.dot(m_b).tolist()

