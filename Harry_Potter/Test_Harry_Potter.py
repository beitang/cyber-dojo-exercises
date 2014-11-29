import Harry_Potter
import unittest

class TestHaiku(unittest.TestCase):

	def test_one_haiku_one_word_each_line(self):
		haiku = Harry_Potter.Harry_Potter()
		self.assertEqual("1,1,1,No\n", haiku.output("work/work/work"))

if __name__ == '__main__':
	unittest.main()
