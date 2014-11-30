def get_line_syllables(line):
	syllables = 0
	words = line.split(" ")
	for word in words:
		syllables += get_word_syllables(word)
	return syllables

def get_word_syllables(word):
	syllables = 0
	if is_syllable_letter(word[0]):
		syllables += 1
	for i in range(1, len(word)):
		if is_syllable_letter(word[i]) and (not is_syllable_letter(word[i - 1])):
			syllables += 1 
	return syllables
	
def is_syllable_letter(letter):
	if letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u' or letter == 'y':
		return True
	return False


class Haiku:

	def parse_one_haiku(self, haiku):
		result = ""
		lines = haiku.split('/')
		for i in range(0, 3):
			syllables = get_line_syllables(lines[i])
			result += str(syllables) + ","
		if result == "5,7,5,":
			return result + "Yes\n"
		return result + "No\n"

	def output(self, string):
		result = ""
		haikus = string.split('\n')
		for i in haikus:
			result += self.parse_one_haiku(i)
		return result
