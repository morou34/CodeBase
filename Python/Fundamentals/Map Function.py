numbers = list(range(1, 21))
even_nums = [x for x in numbers if x % 2 == 0]
print(even_nums)

# map() applies lambda function to every value in even_nums. 
# Since map() returns an iterator (a map object), you’ll need 
# call list() so that you can exhaust the iterator and turn it 
# into a list object. Note that the original sequence doesn’t 
# get modified in the process.

squared = list(map(lambda x: x**2, even_nums))
print(squared)

words = ["Welcome", "to", "Real", "Python"]

words_length = list(map(len, words))
print(words_length)

# Processing Multiple Input Iterables With map()
first_it = [10, 10, 10]
second_it = [1, 2, 3, 4, 5]
results = list(map(lambda x, y: x + y, first_it, second_it))
print(results)


string_iter = ["processing", "strings", "with", "map"]
processed_str = list(map(str.upper, string_iter))
processed_str = list(map(str.title, string_iter))
processed_str = list(map(str.capitalize, string_iter))
print(processed_str)

# removing a char using strip() 
title = "..DRAGON..-..SENDING..-..HUMANS..-..AND..-..CARGO..-..INTO..-..SPACE.."
title = title.split('-')
space_mission = list(map(lambda s: s.strip('.'), title))
print(space_mission)
