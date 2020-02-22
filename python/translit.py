def translit(text):
    orig = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у',
            'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я']
    orig1 = ['А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У',
             'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', ]
    trans = ['a', 'b', 'v', 'g', 'd', 'e', 'jo', 'zh', 'z', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u',
             'f', 'h', 'ts', 'ch', 'sh', 'sch', '', 'i', '\'', 'je', 'ju', 'ya']
    trans1 = ['A', 'B', 'V', 'G', 'D', 'E', 'Jo', 'Zh', 'Z', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U',
              'F', 'H', 'Ts', 'Ch', 'Sh', 'Sch', '', 'I', '\'', 'Je', 'Ju', 'Ya', ]

    text1 = []
    for i in range(len(text)):
        tmp = ''
        temp = text[i]
        for j in range(len(temp)):
            if temp[j] in orig:
                tmp += trans[orig.index(temp[j])]
            elif temp[j] in orig1:
                tmp += trans1[orig1.index(temp[j])]
            if temp[j] not in orig and temp[j] not in orig1:
                tmp += temp[j]
        text1.append(tmp)
    return text1

text = ['Каждый человек раб. Даже',
        'если король. Даже',
        'если не признается в этом самому себе. Потому',
        'что каждый, почти каждый в глубине души жаждет хозяина. Вождя',
        'ли, князя, волхва или бога, который следил бы за каждым его шагом и без воли которого волос бы не упал. И',
        'чем всемогущее бог, тем лучше. Человек',
        'ропщет на хозяина, но постоянно его ищет.']

for i in range(len(text)):
    print(text[i])
print()

text1 = translit(text)

for i in range(len(text1)):
    print(text1[i])