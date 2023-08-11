import random

# random number between 0 and 1
value = random.random()
print(value)

# random float number 
val = random.uniform(1, 10)
print(f'{val:.3}')

# random integer number 
dice = random.randint(1, 6)
print('rolling the dice:', dice)

# random item of a list
Months = ['July', 'August', 'September', 'October', 'November', 'December']
month = random.choice(Months)
print('Selected month is:', month)

# random multiples choices
def colors_count(color_list):
	colors = {}
	for color in color_list:
		if color in colors:
			colors[color] += 1
		else:
			colors[color] = 1
	print(colors)	

# returns a list of k choices
colors = ['Black', 'White', 'Red', 'Orange', 'Blue', 'Green', 'Yellow']
results = random.choices(colors, k=20) #can accept weight parameter too
colors_count(results)

# Shuffle items: deck of cards
deck = list(range(1, 11))
print(deck)
random.shuffle(deck)
print(deck)

# sample: get unique items
hand = random.sample(deck, 4)
print(hand)

#Generate 5 random numbers between 10 and 30
randomlist = random.sample(range(10, 30), 5)



