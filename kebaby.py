import googlemaps
from pprint import pprint

def main():
    apiKey = 'AIzaSyC34n1C2Hwl7wO8h7QXSoAmPxS-F8_dOYc'
    client = googlemaps.Client(apiKey)
    pprint(client.find_place(input='kebab', input_type = 'textquery'))

if __name__=='__main__':
    main()
