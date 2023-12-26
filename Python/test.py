from Crypto.Hash import SHA3_256
import os
import tempfile
import threading
import sqlite3

temp_path = tempfile.gettempdir()

sql_connection = sqlite3.connect("/home/worldofwheat/test_database.db")
sql_cursor = sql_connection.cursor()

def get_random_hex(length):
    return os.urandom(length // 2).hex()

def test_function():
    print(SHA3_256.new(os.urandom(1 << 19)).hexdigest())

for i in range(pow(10, 6)):
    threading.Thread(target=test_function).start()