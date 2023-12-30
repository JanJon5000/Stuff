import requests
from random import randint

l = randint(10, 25)
url = f'https://polish-words.p.rapidapi.com/word/random/{l}'

headers = {
	"X-RapidAPI-Key": "791dc31e21msh46683e0aeee4884p19b47bjsn13e9eeda9af9",
	"X-RapidAPI-Host": "polish-words.p.rapidapi.com"
}

response = requests.get(url, headers=headers)

print(response.json())