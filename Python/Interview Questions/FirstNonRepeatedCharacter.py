
def find_first_non_repeated_character(text):
    letter_dict = dict()

    for char in text.lower():
        if char not in letter_dict.keys():
            letter_dict[char] = 1
        else:
            letter_dict[char] = letter_dict[char] + 1

    first_non_repeating_char = ''
    for key in letter_dict.keys():
        if letter_dict[key] == 1:
            first_non_repeating_char = key
            break

    return first_non_repeating_char


text = "A Green Apple"

print(find_first_non_repeated_character(text))