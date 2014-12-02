import Haiku
import unittest

class TestHaiku(unittest.TestCase):

	def test_one_haiku_one_word_each_line(self):
		haiku = Haiku.Multiple_Haiku("work/work/work")
		self.assertEqual("1,1,1,No\n", haiku.get_haiku_checking_result())

	def test_one_haiku_two_words_each_line(self):
		haiku = Haiku.Multiple_Haiku("work day/work day/work day")
		self.assertEqual("2,2,2,No\n", haiku.get_haiku_checking_result())

	def test_one_haiku_is_yes_each_word_with_one_syllable(self):
		haiku = Haiku.Multiple_Haiku("a work day with work/a work day with no work now/a work day with work")
		self.assertEqual("5,7,5,Yes\n", haiku.get_haiku_checking_result())

	def test_one_haiku_one_word_different_syllable(self):
		haiku = Haiku.Multiple_Haiku("work/happy/different")
		self.assertEqual("1,2,3,No\n", haiku.get_haiku_checking_result())

	def test_two_haiku_one_is_yes_another_is_not_(self):
		input = "appy purple frog/eating bugs in the marshes/get indigestion" \
                + "\n" \
                + "computer programs/the bugs try to eat my code/i will not let them"
		haiku = Haiku.Multiple_Haiku(input)
		output = "5,7,5,Yes\n" + "5,8,5,No\n"
		self.assertEqual(output, haiku.get_haiku_checking_result())

	def test_four_haiku_two_is_yes(self):
		input = "appy purple frog/eating bugs in the marshes/get indigestion" \
                + "\n" \
                + "computer programs/the bugs try to eat my code/i will not let them" \
                + "\n" \
		        + "appy purple frog/eating bugs in the marshes/get indigestion" \
                + "\n" \
                + "computer programs/the bugs try to eat my code/i will not let them"
		haiku = Haiku.Multiple_Haiku(input)
		output = "5,7,5,Yes\n" + "5,8,5,No\n" \
		         + "5,7,5,Yes\n" + "5,8,5,No\n"
		self.assertEqual(output, haiku.get_haiku_checking_result())

if __name__ == '__main__':
	unittest.main()
