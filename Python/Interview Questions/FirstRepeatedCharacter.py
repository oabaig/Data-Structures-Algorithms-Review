def find_first_repeated_character(text):
    char_dict = dict()

    for char in text.lower():
        if char not in char_dict.keys():
            char_dict[char] = 1
        else:
            char_dict[char] = char_dict[char] + 1

    for key in char_dict.keys():
        if char_dict[key] > 1 and key != " ":
            break

    return key


print(find_first_repeated_character("Green Apple"))