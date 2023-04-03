import unittest
from my_module import max_integer

class TestMaxInteger(unittest.TestCase):
    def test_empty_list(self):
        self.assertIsNone(max_integer([]))

    def test_one_element_list(self):
        self.assertEqual(max_integer([5]), 5)

    def test_two_element_list(self):
        self.assertEqual(max_integer([5, 10]), 10)

    def test_negative_numbers(self):
        self.assertEqual(max_integer([-10, -5, -1]), -1)

    def test_mixed_numbers(self):
        self.assertEqual(max_integer([-10, 5, 10, -1]), 10)

    def test_duplicate_numbers(self):
        self.assertEqual(max_integer([5, 5, 5]), 5)

    def test_invalid_input(self):
        with self.assertRaises(TypeError):
            max_integer("not a list")

if __name__ == '__main__':
    unittest.main()

