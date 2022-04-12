import sqlite3

con = sqlite3.connect("mqtt.sqlite")
cur = con.cursor()
cur.execute("select * from mqtt;")

for row in cur:
    print(row)

pass
