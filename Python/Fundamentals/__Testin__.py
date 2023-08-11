bad_characters = [':', '.', '|', '$', ';', '/', '\n', '\r', '\t']
galleryName = 'dfsdfsd: dsfsdf ; fsdfdf?'
for _char in galleryName:
	if _char in bad_characters:
		galleryName = galleryName.replace(_char, '')

print(galleryName)