import Haiku
import unittest

class TestHaiku(unittest.TestCase):

	def test_one_haiku_one_word_each_line(self):
		haiku = Haiku.Haiku()
		self.assertEqual("1,1,1,No\n", haiku.output("work/work/work"))

	def test_one_haiku_two_words_each_line(self):
		haiku = Haiku.Haiku()
		self.assertEqual("2,2,2,No\n", haiku.output("work day/work day/work day"))

	def test_one_haiku_is_yes_each_word_with_one_syllable(self):
		haiku = Haiku.Haiku()
		self.assertEqual("5,7,5,Yes\n", haiku.output("a work day with work/a work day with no work now/a work day with work"))

	def test_one_haiku_one_word_different_syllable(self):
		haiku = Haiku.Haiku()
		self.assertEqual("1,2,3,No\n", haiku.output("work/happy/different"))

if __name__ == '__main__':
	unittest.main()
