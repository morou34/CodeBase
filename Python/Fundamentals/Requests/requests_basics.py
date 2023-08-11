import requests


def page_response():
	url = "https://xkcd.com/353/"
	r = requests.get(url)
	print(dir(r))
	print(help(r))
	print(r.text)

def download_image():
	url = '''https://imgs.xkcd.com/comics/python.png'''
	r = requests.get(url)
	# in bytes
	img_bytes = r.content
	with open('image.png', 'wb') as img_file:
		img_file.write(img_bytes)


def page_rep():
	# 200 a success || 300 redirect
	# 400 error client error (ex. can't access page)
	# 500 server error (ex. site crashed)
	url = '''http://youtube.com'''
	r = requests.get(url)
	print(r.status_code)
	print(r.headers)

 



#page_response()
#download_image()
#page_rep()
	



