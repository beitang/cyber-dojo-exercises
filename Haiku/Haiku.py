class Letter:
	def __init__(self):
		pass

	def is_syllable(self):
		if self.letter == 'a' or self.letter == 'e' or self.letter == 'i' or self.letter == 'o' or self.letter == 'u' or self.letter == 'y':
			return True
		return False

	def set_letter(self, letter):
		self.letter = letter

class Word:
	def __init__(self, word_string):
		self.word_string = word_string
		self.syllable_num = 0

	def get_syllable_num(self):
		current_letter = Letter()
		previous_letter = Letter()
		current_letter.set_letter(self.word_string[0])
		if current_letter.is_syllable():
			self.syllable_num += 1
		for i in range(1, len(self.word_string)):
			current_letter.set_letter(self.word_string[i])
			previous_letter.set_letter(self.word_string[i - 1])
			if current_letter.is_syllable() and (not previous_letter.is_syllable()):
				self.syllable_num += 1 
		return self.syllable_num
		

class Line:
	def __init__(self, line_string):
		self.line_string = line_string
		self.syllable_num = 0

	def get_syllable_num(self):
		words = self.line_string.split(" ")
		for word_string in words:
			word = Word(word_string)
			self.syllable_num += word.get_syllable_num()
		return self.syllable_num

class Haiku:
	def __init__(self, haiku_string):
		self.haiku_string = haiku_string
		self.result = ""

	def get_haiku_checking_result(self):
		lines = self.haiku_string.split('/')
		for line_string in lines:
			line = Line(line_string)
			syllables = line.get_syllable_num()
			self.result += str(syllables) + ","
		if self.result == "5,7,5,":
			return self.result + "Yes\n"
		return self.result + "No\n"


class Multiple_Haiku:
	def __init__(self, multiple_haiku_string):
		self.input_string = multiple_haiku_string
		self.result = ""

	def get_haiku_checking_result(self):
		haiku_string_list = self.input_string.split('\n')
		for haiku_string in haiku_string_list:
			haiku = Haiku(haiku_string)	
			self.result += haiku.get_haiku_checking_result()
		return self.result
