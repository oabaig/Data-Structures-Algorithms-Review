def hash_function(key):
    if type(key) == str:
        hash = 0
        for char in key:
            hash = hash + ord(char)

        return hash % 100

hash_function("123456-A")