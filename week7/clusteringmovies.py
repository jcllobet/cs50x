#importing spreadsheet
import pandas as pd #pandas provides easy-to-use data structures
from io import StringIO
import requests

act = requests.get('https://docs.google.com/spreadsheets/d/1udJ4nd9EKlX_awB90JCbKaStuYh6aVjh1X6j8iBUXIU/export?format=csv')
dataact = act.content.decode('utf-8') #to convert to string from Strnio
frame = pd.read_csv (StringIO(dataact))

#have a look
print(frame)
