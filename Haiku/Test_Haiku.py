import Haiku
import unittest

class TestHaiku(unittest.TestCase):

	def test_haiku(self):
		douglas = Haiku.Haiku()
		self.assertEqual(42, douglas.answer())

if __name__ == '__main__':
	unittest.main()
